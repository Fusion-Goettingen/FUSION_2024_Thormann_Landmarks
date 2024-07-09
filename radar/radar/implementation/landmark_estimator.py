import numpy as np
import torch

import radar.config.radar_config as radar_config
from radar.utilities.data_preprocessor import DataPreprocessor
from radar.algorithms.cnn_regression import HeatmapLandmarkDetector
from radar.utilities.utils import log_and_normalize_image


class LandmarkEstimator:
    def __init__(self, path_to_model, angle_estimator_approach=0):
        # angle estimator approach setting:
        #     0: max, 1: weighted average

        self._raw_data_processor = DataPreprocessor()
        if not torch.cuda.is_available():
            self._model: HeatmapLandmarkDetector \
                = HeatmapLandmarkDetector.load_from_checkpoint(checkpoint_path=path_to_model, map_location='cpu')
        else:
            self._model: HeatmapLandmarkDetector \
                = HeatmapLandmarkDetector.load_from_checkpoint(checkpoint_path=path_to_model)
        self._model.to(torch.device('cuda' if torch.cuda.is_available() else 'cpu'))

        self._max_angle_degree = radar_config.MAX_ANGLE_DEGREE
        self._n_beams = radar_config.N_BEAMS

        self._angle_estimator_approach = angle_estimator_approach

    def generate_estimated_ranges_heatmap_angles(self, raw_data):
        radar_image_complex = self._raw_data_processor.process_data(raw_data, abs_values=False)
        return (self.__generate_radar_bins(radar_image_complex),
                self.__generate_range_estimation_heatmap(radar_image_complex),
                self.__generate_angle_estimates_per_bin(radar_image_complex))

    def __generate_radar_bins(self, radar_image_complex):
        return np.linspace(0, self._raw_data_processor.get_max_range_m(), radar_image_complex.shape[1],
                           endpoint=False)

    def __generate_range_estimation_heatmap(self, radar_image_complex):
        radar_image = log_and_normalize_image(abs(radar_image_complex))
        heatmap = torch.sigmoid(self._model.forward(
            torch.Tensor(radar_image[np.newaxis, ...]).to(self._model.device))).cpu().detach().numpy().flatten()
        heatmap /= np.sum(heatmap)
        return heatmap

    def __generate_angle_estimates_per_bin(self, radar_image_complex):
        nr_rx_horizontal = np.min([3, radar_image_complex.shape[0]])
        angles_degree = np.linspace(-self._max_angle_degree, self._max_angle_degree, self._n_beams)

        angle_weights = np.array(
            [np.exp(1j * np.pi * i * np.sin(np.deg2rad(angles_degree))) for i in range(nr_rx_horizontal)])
        angle_intensities_range_doppler = (np.einsum('ra, rbx -> bxa',
                                                     angle_weights,
                                                     radar_image_complex[radar_config.HORIZONTAL_MAP])**2
                                           / nr_rx_horizontal)
        angle_intensities_per_bin = np.linalg.norm(angle_intensities_range_doppler, axis=1)

        if self._angle_estimator_approach == 0:
            max_angle_ids = np.argmax(angle_intensities_per_bin, axis=1)
            angles_per_bin = angles_degree[max_angle_ids]
        elif self._angle_estimator_approach == 1:
            angle_bin_weights_normalized = (angle_intensities_per_bin
                                            / np.sum(angle_intensities_per_bin, axis=1)[:, None])
            angles_per_bin = np.sum(angles_degree[None, :] * angle_bin_weights_normalized, axis=1)
        elif self._angle_estimator_approach == 2:
            # use max, but when calculating the angle intensities per bin, ignore the 20% around 0 range rate
            d_dim = angle_intensities_range_doppler.shape[1]
            angle_intensities_per_bin_only_doppler \
                = (np.linalg.norm(angle_intensities_range_doppler[:, :int(0.4*d_dim), :], axis=1)
                   + np.linalg.norm(angle_intensities_range_doppler[:, int(0.6*d_dim):, :], axis=1))
            max_angle_ids = np.argmax(angle_intensities_per_bin_only_doppler, axis=1)
            angles_per_bin = angles_degree[max_angle_ids]
        elif self._angle_estimator_approach == 3:
            # use weighted average, but when calculating the angle intensities per bin, ignore the 20% around 0 range rate
            d_dim = angle_intensities_range_doppler.shape[1]
            angle_intensities_per_bin_only_doppler \
                = (np.linalg.norm(angle_intensities_range_doppler[:, :int(0.4*d_dim), :], axis=1)
                   + np.linalg.norm(angle_intensities_range_doppler[:, int(0.6*d_dim):, :], axis=1))
            angle_bin_weights_normalized = (angle_intensities_per_bin_only_doppler
                                            / np.sum(angle_intensities_per_bin_only_doppler, axis=1)[:, None])
            angles_per_bin = np.sum(angles_degree[None, :] * angle_bin_weights_normalized, axis=1)
        else:
            raise ValueError("Invalid angle estimator approach specified in Landmark Estimator.")

        return angles_per_bin

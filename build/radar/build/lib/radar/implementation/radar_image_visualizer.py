import radar.config.radar_config as radar_config
from radar.utilities.utils import log_and_normalize_image
from radar.utilities.data_preprocessor import DataPreprocessor
from scipy.constants import speed_of_light

from radar.utilities.DBF import DBF

import numpy as np
import matplotlib.pyplot as plt
from scipy.signal import find_peaks


class RadarImageVisualizer:

    def __init__(self):
        # collect radar parameters
        self.chirpsamples = radar_config.CHIRPSAMPLES
        self.num_chirps = radar_config.NUM_CHIRPS
        self.nr_rx = radar_config.NR_RX
        self.virtual_antenna = radar_config.VIRTUAL_ANTENNA  # additional virtual Rx created using the second Tx
        bandwidth = radar_config.BANDWIDTH
        lam = speed_of_light / (58 * 1e9 + 0.5 * radar_config.BANDWIDTH)
        prt = radar_config.POST_CHIRP_DELAY + 0.08 * 1e-3  # post chirp delay, assuming the chirp time is around 0.08ms without chirp end delay according to GUI specification guide
        if self.virtual_antenna:
            prt *= 2  # second tx is used
        self.max_range_m = speed_of_light * 0.5 * self.chirpsamples * 0.5 / bandwidth  # note: chirp_duration x 2
        self.n_beams = 181
        self.max_angle_degrees = 45  # 30
        self.max_speed = lam * 0.25 / prt
        self.num_antenna = self.nr_rx + (self.virtual_antenna * (1 + radar_config.VERTICAL_ANTENNA))
        self.data_history = np.zeros((self.num_antenna, self.num_chirps, self.chirpsamples))

        self._data_preprocessor = DataPreprocessor()

        # setup plotting
        self.fig, self.axs = plt.subplots(1, 2, sharey=True)
        self.axs = self.axs.flatten()
        self.dist_points = np.linspace(0, self.max_range_m, self.chirpsamples)
        self.dbf = DBF(self.nr_rx + self.virtual_antenna, self.n_beams, self.max_angle_degrees)
        self.pln = []

        # setup ground truth and prediction
        self._landmark_ranges = None
        self._prediction_map = None

        # saved data
        self._prediction_array = []
        self._gt_array = []
        self._radar_array = []

    def get_current_state_dict(self):
        """Return a bunch of internal variables as dict, e.g. for saving to JSON"""
        return dict(
            prediction_array=self._prediction_array,
            gt_array=self._gt_array,
            radar_array=self._radar_array,
        )

    def set_landmark_ranges(self, landmark_ranges):
        self._landmark_ranges = landmark_ranges
        self._gt_array.append(np.array(landmark_ranges))

    def set_prediction_heatmap(self, prediction_heatmap):
        self._prediction_map = prediction_heatmap
        self._prediction_array.append(np.array(prediction_heatmap))

    def plot_radar_image_from_data(self, data):
        radar_image = self.__calculate_radar_image(data)
        self._radar_array.append(np.array(radar_image))
        self.__draw_image_with_ground_truth_and_prediction(radar_image)

    def __calculate_radar_image(self, data):
        radar_image = self._data_preprocessor.process_data(data, abs_values=True)
        return log_and_normalize_image(radar_image)

    def __draw_image_with_ground_truth_and_prediction(self, radar_image):
        self.__draw_image_and_ground_truth(radar_image)
        if self._prediction_map is not None:
            self.__draw_prediction_and_ground_truth(len(radar_image[0]))

        plt.tight_layout()
        plt.draw()
        plt.pause(1e-3)

    def __draw_image_and_ground_truth(self, image):
        plt.sca(self.axs[0])
        plt.cla()
        plt.imshow(image[0],
                   origin='lower',
                   )
        plt.xlabel('speed / $m/s$')
        plt.ylabel('range / $m$')
        plt.yticks(np.arange(0, len(image[0]), 16),
                   labels=np.round(np.arange(0, len(image[0]), 16) / len(image[0]) * self.max_range_m, decimals=2))

        self.__add_ground_truth(len(image[0]))

    def __add_ground_truth(self, range_dimension):
        if self._landmark_ranges is not None:
            for true_range in self._landmark_ranges:
                plt.axhline(true_range / self.max_range_m * range_dimension, c='blue')

    def __draw_prediction_and_ground_truth(self, range_dimension):
        plt.sca(self.axs[1])
        plt.cla()
        prediction = self._prediction_map.flatten()
        assert len(prediction) == range_dimension
        plt.barh(np.arange(len(prediction)),
                 prediction,
                 1.0,
                 align='edge')
        plt.ylim(0, len(prediction))
        plt.xlabel('intensity')
        heatmap = prediction / np.sum(prediction)
        peaks = find_peaks(heatmap, threshold=1e-2)[0]
        for p in peaks:
            plt.axhline(p, c='orange')

        heatmap = prediction / np.sum(prediction)
        peaks = find_peaks(heatmap, threshold=1e-2)[0]
        for p in peaks:
            plt.axhline(p, c='orange')

        plt.yticks(np.arange(0, range_dimension, 16),
                   labels=np.round(np.arange(0, range_dimension, 16) / range_dimension * self.max_range_m, decimals=2))

        self.__add_ground_truth(range_dimension)

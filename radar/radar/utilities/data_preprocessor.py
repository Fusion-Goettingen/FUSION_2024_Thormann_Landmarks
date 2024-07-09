import numpy as np
from scipy import signal
from scipy.constants import speed_of_light

import radar.config.radar_config as radar_config


class DataPreprocessor:
    def __init__(self):

        self._nr_rx = radar_config.NR_RX
        self._chirpsamples = radar_config.CHIRPSAMPLES
        self._num_chirps = radar_config.NUM_CHIRPS
        self._max_range_m = speed_of_light * 0.25 * self._chirpsamples / radar_config.BANDWIDTH
        self._max_speed = speed_of_light * 0.25 / ((58 * 1e9 + 0.5 * radar_config.BANDWIDTH)
                                                   * (radar_config.POST_CHIRP_DELAY + 0.08 * 1e-3))

    def get_max_range_m(self):
        return self._max_range_m

    def process_data(self, raw_data: np.ndarray, abs_values=True):
        raw_data = np.asarray(raw_data)
        if len(raw_data.shape) == 1:
            raw_data = self.__sort_radar_data_stream_into_channels_chirps_samples(raw_data)
        data = self.__calculate_radar_images_per_antenna(raw_data)

        return abs(data) if abs_values else data

    def __sort_radar_data_stream_into_channels_chirps_samples(self, data):
        frame_data = np.zeros((self._nr_rx, self._num_chirps, self._chirpsamples))
        for j in range(self._num_chirps):
            for i in range(self._nr_rx):
                frame_data[i, j] = data[i+j*(self._chirpsamples*self._nr_rx):
                                        (self._chirpsamples*self._nr_rx)+j*(self._chirpsamples*self._nr_rx):self._nr_rx]

        return frame_data

    def __calculate_radar_images_per_antenna(self, raw_data):
        data = np.zeros((self._nr_rx, self._chirpsamples, 2 * self._num_chirps), dtype=complex)
        for i in range(self._nr_rx):
            data[i, :, :] = self.__get_fft_spectrum_doppler(raw_data[i])
        return data

    def __get_fft_spectrum_doppler(self, frame_data):
        # from distance_fft.py
        data = frame_data - np.average(frame_data)

        data = np.multiply(data, signal.blackmanharris(self._chirpsamples).reshape(1, self._chirpsamples))

        data_zp = np.pad(data, ((0, 0), (0, self._chirpsamples)), 'constant')

        fft_range = np.fft.fft(data_zp) / self._chirpsamples

        # ignore negative spectrum
        fft_range = 2.0 * fft_range[:, :self._chirpsamples]

        # Transpose
        # Distance is now indicated on y-axis
        fft_range = np.transpose(fft_range)

        fft_range = np.multiply(fft_range, signal.blackmanharris(self._num_chirps).reshape(1, self._num_chirps))

        fft_range_zp = np.pad(fft_range, ((0, 0), (0, self._num_chirps)), 'constant')
        fft_range_doppler = np.fft.fft(fft_range_zp) / self._num_chirps

        return np.fft.fftshift(fft_range_doppler, (1,))

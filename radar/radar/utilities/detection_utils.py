import numpy as np
from scipy.signal import find_peaks
from scipy.stats import norm
from radar.utilities.utils import pol2cart, rot_mat


def get_local_polar_lm_obs(heatmap, range_bins, angles_degree):
    # return get_naive_local_polar_lm_obs(heatmap, range_bins, angles_degree)
    return get_gaussian_local_polar_lm_obs(heatmap, range_bins, angles_degree)


def get_naive_local_polar_lm_obs(heatmap, range_bins, angles_degree):
    # normalize heatmap and extract peaks, determining landmark locations
    heatmap /= np.sum(heatmap)
    peaks = find_peaks(heatmap, threshold=1e-2)[0]
    # use extracted local landmark as index for range/angle bin combinations to acquire local polar landmarks
    local_polar_lm_obs = [np.array([range_bins[ix], np.deg2rad(angles_degree[ix])])
                          for ix in peaks]
    return local_polar_lm_obs


def get_gaussian_local_polar_lm_obs(heatmap, range_bins, angles_degree):
    # parameters
    n_samples = 100
    variance = 0.05 ** 2
    rng = np.random.default_rng(42)

    # normalize heatmap and extract peaks, determining landmark locations
    heatmap /= np.sum(heatmap)
    peaks = find_peaks(heatmap, threshold=1e-2)[0]

    # ranges are simply range_bins[peak_index], and angles are computed for angle sampling
    local_polar_lm_obs = []
    for peak_index in peaks:
        distance = range_bins[peak_index]

        samples = rng.normal(loc=distance, scale=np.sqrt(variance), size=n_samples)
        samples = np.clip(samples, 0, range_bins[-1])
        sample_bin_id_list = np.digitize(samples, range_bins, right=True).astype(int)

        angle = compute_mean_of_angles(np.deg2rad(np.array(angles_degree)[sample_bin_id_list]))

        local_polar_lm_obs.append(np.array([distance, angle]))

    return local_polar_lm_obs


def compute_mean_of_angles(angles_radians, weights=None):
    return np.arctan2(
        *np.average(np.array([np.sin(angles_radians), np.cos(angles_radians)]),
                    axis=1, weights=weights)
    )


def get_angle_from_gaussian_sampled_range_angle_bins(range_bins: np.ndarray,
                                                     angles_per_bin: np.ndarray,
                                                     estimated_range: float,
                                                     n_samples=100,
                                                     variance=0.05 ** 2,
                                                     apply_weighting=False,
                                                     rng: np.random.Generator = None,
                                                     ) -> float:
    """
    Determines the angle based on the angles per bin and an estimated range.
    Considers the adjacent bins as well as the actually matched bin.
    :param range_bins:          array providing for each bin the maximum range and most likely angle
    :param angles_per_bin:      array providing for each bin the most likely angles per velocity
    :param estimated_range:     the estimated range of the detected landmark
    :param n_samples: Number of samples to draw
    :param variance: Variance of Gaussian to sample
    :param apply_weighting: If True, will weigh each sample by its likelihood
    :param rng: numpy Generator to use or None to create a new one
    :return:                    the estimated angle of the detected landmark
    """
    rng = np.random.default_rng() if rng is None else rng
    samples = rng.normal(loc=estimated_range, scale=np.sqrt(variance), size=n_samples)
    samples = np.clip(samples, 0, range_bins[-1])
    values = [
        get_angle_from_range_angle_bins(range_bins, angles_per_bin, sample)
        for sample in samples
    ]
    if apply_weighting:
        pdf = norm(loc=estimated_range, scale=np.sqrt(variance)).pdf(samples)
        weights = pdf / np.sum(pdf)
    else:
        weights = [1 / len(values)] * len(values)
    return np.average(values, weights=weights)


def get_upsampled_cartesian_landmarks(polar_lm):
    lm_width = 0.22  # cm
    lm_depth = 0.16  # cm
    n_pts = 5  # how many landmarks to sample along width
    base_points = np.vstack([np.zeros(n_pts), np.linspace(-lm_width / 2, -lm_width / 2, num=n_pts)]).T

    # currently not sampling across depth dimension

    cart_lm = np.array([pol2cart(lm[0], np.deg2rad(lm[1])) for lm in polar_lm])
    upsampled_landmark_array = []
    for pol, cart in zip(polar_lm, cart_lm):
        rmat = rot_mat(np.deg2rad(pol[1]))
        lms = [rmat @ p + np.array(cart) for p in base_points]
        upsampled_landmark_array.extend(lms)
    return np.array(upsampled_landmark_array)

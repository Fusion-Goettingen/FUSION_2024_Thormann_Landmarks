import sys

import matplotlib.pyplot as plt
import numpy as np

from radar.utilities.utils import pol2cart, cart2pol, rot_mat
from scipy.optimize import linear_sum_assignment
from scipy.special import logsumexp
from scipy.stats import multivariate_normal as mvn
from radar.config.constants import GATE
from radar.utilities.detection_utils import get_local_polar_lm_obs

IX_X, IX_Y, IX_THETA, IX_WEIGHT = 0, 1, 2, 3
IXS_LOCATION = [IX_X, IX_Y]
IXS_POSE = [IX_X, IX_Y, IX_THETA]


class ParticleFilterLocalizer:
    """
    Implements a localization system which generates pose measurements using nonlinear least squares and subsequently
    filters these.
    """

    def __init__(self,
                 landmark_locations: np.ndarray,
                 radar_offset: np.ndarray,
                 n_particles: int = 1000,
                 rng: np.random.Generator = None,
                 ):
        # save parameters
        self.global_polar_landmark_locations = np.array(landmark_locations)
        self.global_cartesian_landmark_locations = np.array([pol2cart(lm[0], np.deg2rad(lm[1]))
                                                             for lm in self.global_polar_landmark_locations])
        print(f"Launched ParticleFilterLocalizer for {len(self.global_cartesian_landmark_locations)} LMs")
        sys.stdout.flush()
        self.radar_offset = np.array(radar_offset)

        self.rng = rng if rng is not None else np.random.default_rng(42)
        self._n_particles = n_particles
        self.particles = np.zeros((self._n_particles, 4))
        self.particles[:, IX_WEIGHT] = 1 / self._n_particles
        self._importance_sampling_covariance = np.diag([0.05, 0.05, np.pi / 64]) ** 2
        self._meas_noise_cov = np.diag([0.04, np.deg2rad(10)]) ** 2

    def _resample(self):
        """
        Resample all particles, resetting weights to uniform values.
        """
        # pick n_particles-many random rows from the particle array, with replacement, with prob. according to weights
        self.particles = self.particles[self.rng.choice(len(self.particles),
                                                        size=len(self.particles),
                                                        p=self.particles[:, IX_WEIGHT].astype(float),
                                                        replace=True)]
        self.particles[:, IX_WEIGHT] = 1 / len(self.particles)

    def _importance_sampling(self, time_difference_seconds):
        """Perform importance sampling for all particles"""
        # sample and add process noise, multiplied with time delta
        gaussian_shift = self.rng.multivariate_normal(
            mean=[0, 0, 0],
            cov=self._importance_sampling_covariance,
            size=len(self.particles)
        ) * time_difference_seconds
        self.particles[:, :IX_WEIGHT] += gaussian_shift
        # ensure angle is in [0, 2pi]
        self.particles[:, IX_THETA] = self.particles[:, IX_THETA] % (2 * np.pi)

    def _update_likelihood(self, range_bins, heatmap, angles_degree):
        """
        Update the likelihood for all particles given measurements as
        :param range_bins: ndarray of length N containing the distances of the range bins
        :param heatmap: ndarray of length N containing the estimated probability for each bin to contain a landmark
        :param angles_degree: ndarray of length N containing the angle estimates in degrees for each range bin
        """

        def expected_observation(cart_lm, robot_pose):
            # transform landmark into local cartesian
            lm = cart_lm - robot_pose[:2]
            lm = rot_mat(-1 * robot_pose[2]) @ lm

            # return polar version
            return cart2pol(lm)

        # normalize heatmap and extract peaks, determining landmark locations
        local_polar_lm_obs = get_local_polar_lm_obs(heatmap, range_bins, angles_degree)

        n_lm = len(self.global_cartesian_landmark_locations)
        n_det = len(local_polar_lm_obs)

        for p_ix in range(len(self.particles)):
            # compute (log-)likelihood array
            log_likelihood = np.zeros((n_lm, n_det))
            global_dists = np.zeros((n_lm, n_det))
            for lm_ix in range(n_lm):
                for det_ix in range(n_det):
                    log_likelihood[lm_ix, det_ix] = mvn(
                        mean=expected_observation(self.global_cartesian_landmark_locations[lm_ix],
                                                  self.particles[p_ix, IXS_POSE]),
                        cov=self._meas_noise_cov
                    ).logpdf(local_polar_lm_obs[det_ix])

                    # GATING:
                    # convert landmark to global frame given this particle location
                    current_lm_local_cartesian_location = pol2cart(local_polar_lm_obs[det_ix])
                    rmat = rot_mat(self.particles[p_ix, IX_THETA])
                    trans_vec = self.particles[p_ix, IXS_LOCATION]
                    current_lm_global_cartesian_location = rmat @ current_lm_local_cartesian_location + trans_vec
                    global_dists[lm_ix, det_ix] = np.linalg.norm(self.global_cartesian_landmark_locations[lm_ix] -
                                                                 current_lm_global_cartesian_location)
                    if global_dists[lm_ix, det_ix] > GATE:
                        # set likelihood to very low value, and take log for log-likelihood
                        log_likelihood[lm_ix, det_ix] = np.log(1e-100)

            # perform association on negative log likelihood
            # must be log because we look at a sum not a product, and negative because we want the min
            row_ind, col_ind = linear_sum_assignment(-log_likelihood)

            # weight is exp(sum(likelihood of associations))
            # self.particles[p_ix, IX_WEIGHT] = np.exp(log_likelihood[row_ind, col_ind].sum())
            self.particles[p_ix, IX_WEIGHT] = log_likelihood[row_ind, col_ind].sum()

    def predict_and_update(self, time_difference_seconds, range_bins, heatmap, angles_degree) -> np.ndarray:
        """

        :param time_difference_seconds: Time difference since last update in seconds
        :param range_bins: ndarray of length N containing the distances of the range bins
        :param heatmap: ndarray of length N containing the estimated probability for each bin to contain a landmark
        :param angles_degree: ndarray of length N containing the angle estimates in degrees for each range bin
        :return: Current pose estimate as ndarray in format [x, y, theta]
        """
        # 1. sample new particle locations
        self._importance_sampling(time_difference_seconds)

        # 2. compute particle weights
        self._update_likelihood(range_bins, heatmap, angles_degree)

        # 3. normalize particle weights
        self._normalize_weights()

        # 4. resample particles
        self._resample()

        sys.stdout.flush()

        return self.get_pose_estimate()

    def get_pose_estimate(self) -> np.ndarray:
        """Return [x, y, theta] pose estimate"""
        # x,y are just standard weighted averages
        x = np.average(self.particles[:, IX_X], weights=self.particles[:, IX_WEIGHT])
        y = np.average(self.particles[:, IX_Y], weights=self.particles[:, IX_WEIGHT])

        # orientations must be averaged accounting for the angle
        # convert to sin/cos representation, then pass the average of that to arctan2 to get the angle
        theta = np.arctan2(
            *np.average(np.array([np.sin(self.particles[:, IX_THETA]), np.cos(self.particles[:, IX_THETA])]),
                        axis=1,
                        weights=self.particles[:, IX_WEIGHT]),
        )
        return np.array([x, y, theta])

    def _normalize_weights(self):
        """Normalize the particle weights"""
        self.particles[:, IX_WEIGHT] -= logsumexp(self.particles[:, IX_WEIGHT])
        self.particles[:, IX_WEIGHT] = np.exp(self.particles[:, IX_WEIGHT])

    def plot(self):
        plt.scatter(self.particles[:, IX_X], self.particles[:, IX_Y],
                    alpha=np.clip(self.particles[:, IX_WEIGHT], 0.2, 1), c='k', marker='.')

        plt.scatter(self.global_cartesian_landmark_locations[:, 0],
                    self.global_cartesian_landmark_locations[:, 1],
                    c='k', marker='d')

        x, y, _ = self.get_pose_estimate()
        plt.scatter(x, y, c='red', marker='*')

        plt.axis('equal')
        plt.show()

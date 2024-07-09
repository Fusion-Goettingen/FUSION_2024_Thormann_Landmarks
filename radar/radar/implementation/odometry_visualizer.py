from collections import deque

import matplotlib.pyplot as plt
from matplotlib import patches
import numpy as np
from radar.utilities.utils import pol2cart, rot_mat
from scipy.signal import find_peaks
from radar.config.constants import GATE


class OdometryVisualizer:
    LANDMARK_COLOR = 'black'
    LANDMARK_MARKER = "D"  # "D" -> diamond

    COLOR_ESTIMATE = 'red'
    COLOR_GROUND_TRUTH = 'blue'

    ARROW_SIZE = 0.03

    HISTORY_LINESTYLE = '-'

    SHOW_LANDMARKS_WITH_EXTENT = True

    def __init__(self,
                 landmark_locations: np.ndarray,
                 radar_offset: np.ndarray,
                 disable_visualization: bool = False,
                 trajectory_max_length: int = None
                 ):
        """
        Create a new instance of the odometry visualization system.
        :param landmark_locations: Nx2 shaped ndarray of polar coordinates of landmarks in global coordinates w.r.t.
        the global origin, corresponding to the initial pose of the robot
        :param radar_offset: Offset of radar to robot base in local coordinates as ndarray, containing [x, y]-offset.
        :param disable_visualization: Boolean indicating whether to disable the visualization. Note that this does not
        affect, e.g., printing error statistics
        :param trajectory_max_length: Maximum length of saved trajectory as int. If less than 1, will use 1 anyway
        """
        # save parameters
        self.polar_landmark_locations = np.array(landmark_locations)
        self.cartesian_landmark_locations = np.array(
            [pol2cart(polar_landmark[0], np.deg2rad(polar_landmark[1]))
             for polar_landmark in self.polar_landmark_locations])
        self.radar_offset = np.array(radar_offset)
        self.disable_visualization = disable_visualization
        self._maxlen = max(1, int(trajectory_max_length)) if trajectory_max_length is not None else None

        # initialize instance variables
        self._estimate_array = deque(maxlen=self._maxlen)
        self._timestamps_estimates = deque(maxlen=self._maxlen)
        self._ground_truth_array = deque(maxlen=self._maxlen)
        self._timestamps_ground_truth = deque(maxlen=self._maxlen)

        self.xlims, self.ylims = None, None

        self.cart_errors = []
        self.ang_errors = []
        self.all_detections = []
        self.last_detections = None
        self._start_gt_stamp = None

    def get_current_state_dict(self):
        """Return a bunch of internal variables as dict, e.g. for saving to JSON"""
        return dict(
            polar_landmark_locations=self.polar_landmark_locations,
            cartesian_landmark_locations=self.cartesian_landmark_locations,
            radar_offset=self.radar_offset,
            cartesian_errors=self.cart_errors,
            angular_errors=self.ang_errors,
            estimate_array=self._estimate_array,
            ground_truth_array=self._ground_truth_array,
            timestamps_estimates=self._timestamps_estimates,
            timestamps_ground_truth=self._timestamps_ground_truth,
            all_detections=self.all_detections
        )

    def update_odom_estimate_on_visualization(self,
                                              odom_estimate_xytheta: np.ndarray,
                                              time_stamp: float):
        """

        :param odom_estimate_xytheta: Current position estimate ndarray in form [x, y, theta] consisting of the
        cartesian position [x, y] and the current yaw angle [theta] in radians.
        :param time_stamp: Time stamp of odometry estimate  # TODO: clarify time stamp formatting
        """
        if self._start_gt_stamp is None:
            # only save messages if some ground truth has been received already
            return
        time_diff = time_stamp - self._start_gt_stamp
        self._estimate_array.append(np.array(odom_estimate_xytheta)[:3])
        self._timestamps_estimates.append(time_diff)
        self.draw_odometry_visuals()

    def update_ground_truth_on_visualization(self,
                                             ground_truth_xytheta: np.ndarray,
                                             time_stamp: float):
        """
        Update the current ground truth state

        :param ground_truth_xytheta: Current ground truth position ndarray in form [x, y, theta] consisting of the
        cartesian position [x, y] and the current yaw angle [theta] in radians.
        :param time_stamp: Time stamp of ground truth estimate  # TODO: clarify time stamp formatting
        """
        if len(self._timestamps_ground_truth) == 0:  # first ground truth msg
            self._timestamps_ground_truth.append(0)
            self._start_gt_stamp = time_stamp
            self._ground_truth_array.append(np.array(ground_truth_xytheta)[:3])
        else:
            # compute time difference to initial stamp
            time_diff = time_stamp - self._start_gt_stamp
            # ensure time diff is larger than before s.t. time is strictly monotonically increasing
            if time_diff > self._timestamps_ground_truth[-1]:
                # save data and time_diff
                self._timestamps_ground_truth.append(time_diff)
                self._ground_truth_array.append(np.array(ground_truth_xytheta)[:3])
        self.draw_odometry_visuals()

    def update_heatmap(self,
                       range_bins,
                       heatmap,
                       angles_degree):
        heatmap /= np.sum(heatmap)
        peaks = find_peaks(heatmap, threshold=1e-2)[0]
        # use extracted local landmark as index for range/angle bin combinations to acquire local polar landmarks
        self.last_detections = [np.array([range_bins[ix], np.deg2rad(angles_degree[ix])])
                                for ix in peaks]
        self.all_detections.append(self.last_detections)

    def compute_current_landmark_estimates(self, reference_pose):
        rmat = rot_mat(reference_pose[-1])
        translation = np.array(reference_pose[:2])
        return np.array([
            rmat @ lm + translation
            for lm in self.last_detections
        ]).reshape((-1, 2))

    def get_current_error_statistics(self) -> np.ndarray:
        """
        Returns error statistics for current estimate and ground truth.
        TODO Simon: add average point displacement as a metric capturing both location and angular error as a scalar

        :return: ndarray in form [cartesian distance, angular error]
        """
        assert len(self._estimate_array) > 0 and len(self._ground_truth_array) > 0, \
            "Odometry: Ground Truth or estimate were not set before computing error statistics"
        cartesian_distance = np.linalg.norm(self._estimate_array[-1][:2] - self._ground_truth_array[-1][:2])
        absolute_angular_error = np.abs(self._estimate_array[-1][2] - self._ground_truth_array[-1][2])
        return np.array([cartesian_distance, absolute_angular_error])

    def return_error_statistic_string(self):
        """
        Automatically print a formatted version of the return value of self.get_current_error_statistics
        """
        full_str = (f"Odometry Error:"
                    f"\n\tNow: {self.cart_errors[-1]:.3f} m | {np.rad2deg(self.ang_errors[-1]):.1f} deg"
                    f"\n\tAvg: {np.mean(self.cart_errors):.3f} m | {np.mean(self.ang_errors):.1f} deg"
                    f"\n\tMax: {np.max(self.cart_errors):.3f} m | {np.max(self.ang_errors):.1f} deg")
        return full_str

    def compute_error_statistics_step(self):
        cartesian_distance, absolute_angular_error = self.get_current_error_statistics()[:2]
        self.cart_errors.append(cartesian_distance)
        self.ang_errors.append(np.rad2deg(absolute_angular_error))

    def compute_total_trajectory_length(self):
        return np.sum(
            [np.linalg.norm(self._ground_truth_array[i][:2] - self._ground_truth_array[i - 1][:2])
             for i in range(1, len(self._ground_truth_array))
             ]
        )

    def draw_odometry_visuals(self):
        if self.disable_visualization or len(self._estimate_array) == 0 or len(self._ground_truth_array) == 0:
            return

        plt.cla()

        # visualize landmarks in global reference frame
        if self.SHOW_LANDMARKS_WITH_EXTENT:
            for i, xy in enumerate(self.cartesian_landmark_locations[:, :2]):
                # landmarks are actually elliptical, and the landmark center does not coincide with the labeled center
                # (label is offset towards front, near actual fan center)
                # a circle is used as an approximation
                # note that to plot elliptical landmarks, a rotation would need to be recorded, and offsets and rotation
                # would need to be compared to initial robot pose etc
                # the fan width is around 22cm, the depth of the full landmark around 16cm.
                # the label center is the midpoint of the width, but at a depth around 4cm (not 8 as a circle would
                # suggest)
                # using a circle of diameter 15cm to approximate this
                landmark_patch = patches.Circle(xy,
                                                radius=0.075,
                                                fill=True,
                                                color=self.LANDMARK_COLOR,
                                                label="Landmark" if i == 0 else None)
                plt.gca().add_patch(landmark_patch)
        else:
            plt.scatter(self.cartesian_landmark_locations[:, 0], self.cartesian_landmark_locations[:, 1],
                        marker=self.LANDMARK_MARKER, color=self.LANDMARK_COLOR, label="Landmarks")
        # add gates
        for i, xy in enumerate(self.cartesian_landmark_locations[:, :2]):
            gating_patch = patches.Circle(xy,
                                          radius=GATE,
                                          fill=False,
                                          color=self.LANDMARK_COLOR,
                                          label='Detection Gating' if i == 0 else None,
                                          linestyle='--')

            plt.gca().add_patch(gating_patch)

        # visualize current position
        current_est_pose = self._estimate_array[-1]
        plt.arrow(current_est_pose[0], current_est_pose[1],
                  self.ARROW_SIZE * np.cos(current_est_pose[2]), self.ARROW_SIZE * np.sin(current_est_pose[2]),
                  width=2e-2, color=self.COLOR_ESTIMATE, label="Estimate")

        # visualize estimated landmarks in global reference frame
        estimated_cartesian_landmark_locations = self.compute_current_landmark_estimates(self._ground_truth_array[-1])
        plt.scatter(estimated_cartesian_landmark_locations[:, 0], estimated_cartesian_landmark_locations[:, 1],
                    marker=self.LANDMARK_MARKER, color=self.COLOR_GROUND_TRUTH, label="Detections (Global Frame)")
        estimated_cartesian_landmark_locations = self.compute_current_landmark_estimates(self._estimate_array[-1])
        plt.scatter(estimated_cartesian_landmark_locations[:, 0], estimated_cartesian_landmark_locations[:, 1],
                    marker=self.LANDMARK_MARKER, color=self.COLOR_ESTIMATE, label="Detections (Local Frame)")

        # visualize current ground truth
        current_gt_pose = self._ground_truth_array[-1]
        plt.arrow(current_gt_pose[0], current_gt_pose[1],
                  self.ARROW_SIZE * np.cos(current_gt_pose[2]), self.ARROW_SIZE * np.sin(current_gt_pose[2]),
                  width=2e-2, color=self.COLOR_GROUND_TRUTH, label="True")

        if self.HISTORY_LINESTYLE is not None:
            plt.plot(*np.array(self._estimate_array)[:, :2].T,
                     linestyle=self.HISTORY_LINESTYLE, color=self.COLOR_ESTIMATE)
            plt.plot(*np.array(self._ground_truth_array)[:, :2].T,
                     linestyle=self.HISTORY_LINESTYLE, color=self.COLOR_GROUND_TRUTH)

        plt.axis('equal')

        plt.legend(bbox_to_anchor=(1.04, 0.9), loc="center left")
        plt.title("Landmark-based Localization")

        if len(self.cart_errors) > 0:
            plt.text(1.04, 0.5,
                     f"Odometry Error:"
                     f"\nNow: {self.cart_errors[-1]:.3f} m | {self.ang_errors[-1]:.1f} deg"
                     f"\nAvg:  {np.mean(self.cart_errors):.3f} m | {np.mean(self.ang_errors):.1f} deg"
                     f"\nMax: {np.max(self.cart_errors):.3f} m | {np.max(self.ang_errors):.1f} deg"
                     f"\n(Trajectory Length: {self.compute_total_trajectory_length():.3f} m",
                     transform=plt.gca().transAxes)

        plt.tight_layout()
        plt.draw()
        plt.pause(0.01)

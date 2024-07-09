from radar.utilities.utils import rot_mat

import numpy as np
import json
from scipy.spatial.transform import Rotation


# elements of landmark_location array
LANDMARK_RANGE = 0
LANDMARK_ANGLE = 1

# elements of odometry_changes array
ODOM_X = 0
ODOM_Y = 1
ODOM_THETA = 2

# thresholds
ODOMETRY_IS_MOVING_THRESHOLD = 1e-3


class GroundTruthPublisher:
    def __init__(self, landmark_path, radar_offset=np.zeros(2)):
        # keep track of locations relative to initial landmark locations ground truth
        with open(landmark_path) as f:
            landmark_parameters: dict = json.load(f)
        self._initial_landmark_location = np.array([np.array(landmark_parameters.get('range')),
                                                    np.array(landmark_parameters.get('angle_degree'))])
        self._landmark_location = self._initial_landmark_location.copy()
        self._radar_offset = np.array(radar_offset)
        self._compensate_ground_truth_via_odom = bool(landmark_parameters.get('compensate_ground_truth_via_odom'))

        # for tracking changes to initial position
        self._odometry = np.zeros(3)  # offset in 2D position and orientation towards initial pose
        self._initial_pose = None
        self._is_moving = False

    def get_current_ground_truth(self):
        ground_truth = {
            'relative_position': list(self._odometry),
            'relative_landmark_range': list(self._landmark_location[LANDMARK_RANGE]),
            'relative_landmark_angle': list(self._landmark_location[LANDMARK_ANGLE]),
            'is_moving': self._is_moving
        }
        return ground_truth

    def update_ground_truth_from_pose_and_orientation(self, pose_xy, orientation_xyzw):
        if self._initial_pose is None:
            self._initial_pose = self.__calculate_pose_xytheta(pose_xy, orientation_xyzw)
            odometry_at_last_timestep = self._initial_pose.copy()
        else:
            odometry_at_last_timestep = self._odometry.copy()

        self.__set_odometry(pose_xy, orientation_xyzw)
        self.__set_moving_flag(odometry_at_last_timestep)
        self.__set_landmark_location()

    def __calculate_pose_xytheta(self, pose_xy, orientation_xyzw):
        current_pose = np.zeros(len(self._odometry))
        current_pose[ODOM_X] = pose_xy[0]
        current_pose[ODOM_Y] = pose_xy[1]
        current_pose[ODOM_THETA] = Rotation.from_quat(orientation_xyzw).as_euler('xyz')[2]
        return current_pose

    def __set_odometry(self, pose_xy, orientation_xyzw):
        self._odometry = self.__calculate_pose_xytheta(pose_xy, orientation_xyzw) - self._initial_pose
        self._odometry[[ODOM_X, ODOM_Y]] \
            = rot_mat(self._initial_pose[ODOM_THETA]).T @ self._odometry[[ODOM_X, ODOM_Y]]

    def __set_moving_flag(self, odometry_at_last_timestep):
        self._is_moving = bool(np.linalg.norm(self._odometry - odometry_at_last_timestep) > ODOMETRY_IS_MOVING_THRESHOLD)

    def __set_landmark_location(self):
        if self._compensate_ground_truth_via_odom:
            landmark_location_cartesian = (np.array([np.cos(np.deg2rad(self._initial_landmark_location[LANDMARK_ANGLE])),
                                                     np.sin(np.deg2rad(self._initial_landmark_location[LANDMARK_ANGLE]))]).T
                                           * self._initial_landmark_location[LANDMARK_RANGE][:, None])
            landmark_location_cartesian += self._radar_offset[None, :]
            landmark_location_cartesian = landmark_location_cartesian - self._odometry[[ODOM_X, ODOM_Y]][None, :]
            landmark_location_cartesian = landmark_location_cartesian @ rot_mat(self._odometry[ODOM_THETA])
            landmark_location_cartesian -= self._radar_offset[None, :]
            self._landmark_location[LANDMARK_RANGE] = np.linalg.norm(landmark_location_cartesian, axis=1)
            self._landmark_location[LANDMARK_ANGLE] = np.rad2deg(np.arctan2(landmark_location_cartesian[:, 1],
                                                                            landmark_location_cartesian[:, 0]))

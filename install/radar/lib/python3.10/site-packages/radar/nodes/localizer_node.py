import numpy as np
import json
from scipy.spatial.transform import Rotation
import radar.config.radar_config as radar_config
import radar.config.topics as topics
import radar.config.file_locations as file_locations
from radar.utilities.time_keeper import TimeKeeper
from radar.implementation.pf_localizer import ParticleFilterLocalizer
from radar_interfaces.msg import LandmarkEstimate
from std_msgs.msg import Header
from nav_msgs.msg import Odometry
from geometry_msgs.msg import PoseWithCovariance, Pose, Point, Quaternion

import rclpy
from rclpy.node import Node


class LocalizerNode(Node):
    def __init__(self, odom_estimate_topic, heatmap_topic, landmark_path, radar_offset=np.zeros(2)):
        super().__init__('localizer')
        self._odom_estimate_topic = odom_estimate_topic
        self._heatmap_topic = heatmap_topic

        with open(landmark_path) as f:
            landmark_parameters: dict = json.load(f)
        initial_landmark_location = np.array([np.array(landmark_parameters.get('range')),
                                              np.array(landmark_parameters.get('angle_degree'))]).T
        radar_offset = np.array(radar_offset)

        self._localizer = ParticleFilterLocalizer(initial_landmark_location, radar_offset)

        self.publisher_ = self.create_publisher(Odometry, self._odom_estimate_topic, 1)
        self.heatmap_subscription = self.create_subscription(
            LandmarkEstimate,
            self._heatmap_topic,
            self.heatmap_callback,
            1
        )

        self._time_keeper = TimeKeeper()

    def heatmap_callback(self, landmark_msg):
        odom_estimate_msg = Odometry()
        odom_estimate_msg.header = Header()

        odom_estimate_msg.header.frame_id = landmark_msg.header.frame_id
        odom_estimate_msg.header.frame_id = "odom"  # for rviz visualization purposes, a frame is hardcoded
        odom_estimate_msg.header.stamp = landmark_msg.header.stamp

        odom_estimate_msg.pose = PoseWithCovariance()
        odom_estimate_msg.pose.pose = Pose()
        odom_estimate_msg.pose.pose.position = Point()
        odom_estimate_msg.pose.pose.orientation = Quaternion()

        range_bins, heatmap, angles_degree = landmark_msg.range_bin, landmark_msg.heatmap, landmark_msg.angles_degree

        time_difference_seconds \
            = self._time_keeper.calculate_time_difference_and_update_internal_timestamp(odom_estimate_msg.header.stamp)
        pose_xytheta = self._localizer.predict_and_update(time_difference_seconds, range_bins, heatmap, angles_degree)
        odom_estimate_msg.pose.pose.position.x = pose_xytheta[0]
        odom_estimate_msg.pose.pose.position.y = pose_xytheta[1]

        orientation_quaternion = Rotation.from_euler('z', pose_xytheta[2]).as_quat()
        odom_estimate_msg.pose.pose.orientation.x = orientation_quaternion[0]
        odom_estimate_msg.pose.pose.orientation.y = orientation_quaternion[1]
        odom_estimate_msg.pose.pose.orientation.z = orientation_quaternion[2]
        odom_estimate_msg.pose.pose.orientation.w = orientation_quaternion[3]

        self.publisher_.publish(odom_estimate_msg)


def main(args=None):
    rclpy.init(args=args)

    landmark_path = file_locations.LANDMARK_PATH

    localizer = LocalizerNode(topics.MULTI_ODOM_ESTIMATE_TOPIC_DICT["FilteredNLS"]["topic"],
                              topics.HEATMAP_TOPIC,
                              landmark_path,
                              radar_config.RADAR_OFFSET)

    try:
        rclpy.spin(localizer)
    except KeyboardInterrupt:
        pass

    localizer.destroy_node()


if __name__ == '__main__':
    main()

import radar.config.topics as topics
import radar.config.file_locations as file_locations
import radar.config.radar_config as radar_config
from radar.implementation.ground_truth_publisher import GroundTruthPublisher

import numpy as np

import rclpy
from rclpy.node import Node

from radar_interfaces.msg import GroundTruth
from nav_msgs.msg import Odometry
from std_msgs.msg import Header


class GroundTruthPublisherNode(Node):
    def __init__(self, topic, odom_topic, landmark_path, radar_offset=np.zeros(2)):
        super().__init__('ground_truth_publisher')
        self._topic = topic
        self._odom_topic = odom_topic

        self._ground_truth_publisher = GroundTruthPublisher(landmark_path, radar_offset)

        self._current_id = 0
        self.publisher_ = self.create_publisher(GroundTruth, self._topic, 1)

        self.qos_policy = rclpy.qos.QoSProfile(reliability=rclpy.qos.ReliabilityPolicy.BEST_EFFORT,
                                               history=rclpy.qos.HistoryPolicy.KEEP_LAST, depth=1)
        if self._odom_topic is not None:
            self.odom_subscription = self.create_subscription(
                Odometry,
                self._odom_topic,
                self.odom_callback,
                qos_profile=self.qos_policy,
            )

    def publish_ground_truth(self):
        ground_truth = self._ground_truth_publisher.get_current_ground_truth()

        msg = GroundTruth()
        msg.header = Header()
        
        msg.relative_position = ground_truth['relative_position']
        msg.relative_landmark_range = ground_truth['relative_landmark_range']
        msg.relative_landmark_angle = ground_truth['relative_landmark_angle']
        msg.is_moving = ground_truth['is_moving']
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = radar_config.RADAR_FRAME_ID
        
        self.publisher_.publish(msg)
        self._current_id += 1

    def odom_callback(self, msg):
        pose_xy = np.array([msg.pose.pose.position.x, msg.pose.pose.position.y])
        orientation_xyzw = np.array([msg.pose.pose.orientation.x, msg.pose.pose.orientation.y,
                                     msg.pose.pose.orientation.z, msg.pose.pose.orientation.w])
        self._ground_truth_publisher.update_ground_truth_from_pose_and_orientation(pose_xy, orientation_xyzw)

        self.publish_ground_truth()


def main(args=None):
    rclpy.init(args=args)
    
    ground_truth_publisher = GroundTruthPublisherNode(topics.GROUND_TRUTH_TOPIC, topics.ODOM_TOPIC,
                                                      file_locations.LANDMARK_PATH, radar_config.RADAR_OFFSET)
    
    try:
        rclpy.spin(ground_truth_publisher)
    except KeyboardInterrupt:
        pass

    ground_truth_publisher.destroy_node()
    

if __name__ == '__main__':
    main()

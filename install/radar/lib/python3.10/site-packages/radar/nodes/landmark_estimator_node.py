import os.path

import radar.config.topics as topics
from radar.config.file_locations import CNN_MODEL_PATH
from radar.implementation.landmark_estimator import LandmarkEstimator
from radar_interfaces.msg import Radar, LandmarkEstimate
from std_msgs.msg import Header
from ament_index_python.packages import get_package_share_directory

import rclpy
from rclpy.node import Node


ANGLE_ESTIMATION_APPROACH = 3  # 0: max, 1: weighted average, 2: max, but ignoring the 20% around 0 range rate, 3: same as before but with weighted average


class LandmarkEstimatorNode(Node):
    def __init__(self, radar_topic, heatmap_topic):
        super().__init__('landmark_estimator')
        self._radar_topic = radar_topic
        self._heatmap_topic = heatmap_topic
        try:
            self._model_abs_path = CNN_MODEL_PATH
        except:
            raise ValueError(f"Error determining absolute path to model to load")
        self._landmark_estimator = LandmarkEstimator(self._model_abs_path, ANGLE_ESTIMATION_APPROACH)
        self.get_logger().info(f"Landmark estimator established, CNN loaded.")

        self.publisher_ = self.create_publisher(LandmarkEstimate, self._heatmap_topic, 1)
        self.radar_subscription = self.create_subscription(
            Radar,
            self._radar_topic,
            self.radar_callback,
            1
        )

    def radar_callback(self, radar_msg):
        landmark_msg = LandmarkEstimate()
        landmark_msg.header = Header()

        landmark_msg.header.frame_id = radar_msg.header.frame_id
        landmark_msg.header.stamp = radar_msg.header.stamp

        range_bins, heatmap, angle_per_range_bin_degree \
            = self._landmark_estimator.generate_estimated_ranges_heatmap_angles(radar_msg.data)

        landmark_msg.range_bin = range_bins.tolist()
        landmark_msg.heatmap = heatmap.tolist()
        landmark_msg.angles_degree = angle_per_range_bin_degree.tolist()

        self.publisher_.publish(landmark_msg)


def main(args=None):
    rclpy.init(args=args)

    landmark_estimator = LandmarkEstimatorNode(topics.RADAR_TOPIC, topics.HEATMAP_TOPIC)

    try:
        rclpy.spin(landmark_estimator)
    except KeyboardInterrupt:
        pass

    landmark_estimator.destroy_node()


if __name__ == '__main__':
    main()

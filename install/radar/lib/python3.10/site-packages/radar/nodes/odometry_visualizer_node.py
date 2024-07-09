import numpy as np
import json
from scipy.spatial.transform import Rotation
import os.path
import radar.config.radar_config as radar_config
import radar.config.topics as topics
import radar.config.file_locations as file_locations
from radar.utilities.utils import ExpandedJSONEncoder, timestamp_msg_to_seconds
from radar.implementation.odometry_visualizer import OdometryVisualizer
from radar_interfaces.msg import GroundTruth, LandmarkEstimate
from nav_msgs.msg import Odometry

import rclpy
from rclpy.node import Node


class OdometryVisualizerNode(Node):
    def __init__(self,
                 odom_estimate_topic,
                 ground_truth_topic,
                 heatmap_topic,
                 landmark_path,
                 radar_offset=np.zeros(2)):
        super().__init__('odometry_visualizer')
        self._odom_estimate_topic = odom_estimate_topic
        self._ground_truth_topic = ground_truth_topic
        self._heatmap_topic = heatmap_topic

        with open(landmark_path) as f:
            landmark_parameters: dict = json.load(f)
        initial_landmark_location = np.array([np.array(landmark_parameters.get('range')),
                                              np.array(landmark_parameters.get('angle_degree'))]).T
        radar_offset = np.array(radar_offset)

        self._odometry_visualizer = OdometryVisualizer(initial_landmark_location, radar_offset)

        self.odom_estimate_subscription = self.create_subscription(
            Odometry,
            self._odom_estimate_topic,
            self.odom_estimate_callback,
            1
        )
        self.ground_truth_subscription = self.create_subscription(
            GroundTruth,
            self._ground_truth_topic,
            self.ground_truth_callback,
            1
        )

        self.heatmap_subscription = self.create_subscription(
            LandmarkEstimate,
            self._heatmap_topic,
            self.heatmap_callback,
            1
        )

    def heatmap_callback(self, msg):
        self._odometry_visualizer.update_heatmap(np.array(msg.range_bin),
                                                 np.array(msg.heatmap),
                                                 np.array(msg.angles_degree))

    def odom_estimate_callback(self, msg):
        pose_xytheta = np.zeros(3)

        pose_xytheta[0] = msg.pose.pose.position.x
        pose_xytheta[1] = msg.pose.pose.position.y
        orientation_xyzw = np.array([msg.pose.pose.orientation.x, msg.pose.pose.orientation.y,
                                     msg.pose.pose.orientation.z, msg.pose.pose.orientation.w])
        pose_xytheta[2] = Rotation.from_quat(orientation_xyzw).as_euler('xyz')[2]

        self._odometry_visualizer.update_odom_estimate_on_visualization(pose_xytheta,
                                                                        float(timestamp_msg_to_seconds(msg.header.stamp)))
        self._odometry_visualizer.compute_error_statistics_step()

    def ground_truth_callback(self, msg):
        self._odometry_visualizer.update_ground_truth_on_visualization(np.array(msg.relative_position),
                                                                       float(timestamp_msg_to_seconds(msg.header.stamp)))

    def shutdown_hook(self, target_dir=None):
        if target_dir is not None:
            with open(os.path.join(target_dir, "last_results_odometry_visualizer.json"), "w") as f:
                json.dump(obj=self._odometry_visualizer.get_current_state_dict(),
                          fp=f,
                          indent=4,
                          cls=ExpandedJSONEncoder)


def main(args=None):
    rclpy.init(args=args)

    landmark_path = file_locations.LANDMARK_PATH

    odometry_visualizer = OdometryVisualizerNode(odom_estimate_topic=topics.ODOM_ESTIMATE_TOPIC,
                                                 ground_truth_topic=topics.GROUND_TRUTH_TOPIC,
                                                 heatmap_topic=topics.HEATMAP_TOPIC,
                                                 landmark_path=landmark_path,
                                                 radar_offset=radar_config.RADAR_OFFSET)

    try:
        rclpy.spin(odometry_visualizer)
    except KeyboardInterrupt:
        odometry_visualizer.shutdown_hook(target_dir="./")

    odometry_visualizer.destroy_node()


if __name__ == '__main__':
    main()

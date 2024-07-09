import numpy as np
import radar.config.topics as topics
from radar.implementation.radar_image_visualizer import RadarImageVisualizer

import rclpy
from rclpy.node import Node

from radar_interfaces.msg import Radar, GroundTruth
from radar_interfaces.msg import LandmarkEstimate
import os
import json
from radar.utilities.utils import ExpandedJSONEncoder


class RadarImageVisualizerNode(Node):

    def __init__(self, radar_topic, ground_truth_topic=None, heatmap_topic=None):
        super().__init__('radar_image_visualizer')
        self._radar_topic = radar_topic
        self._ground_truth_topic = ground_truth_topic
        self._heatmap_topic = heatmap_topic

        self._radar_image_visualizer = RadarImageVisualizer()

        self.radar_subscription = self.create_subscription(
            Radar,
            self._radar_topic,
            self.listener_callback,
            1)

        if self._ground_truth_topic is not None:
            self.ground_truth_subscription = self.create_subscription(
                GroundTruth,
                self._ground_truth_topic,
                self.ground_truth_callback,
                1
            )
        if self._heatmap_topic is not None:
            self.heatmap_subscription = self.create_subscription(
                LandmarkEstimate,
                self._heatmap_topic,
                self.heatmap_callback,
                1
            )

    def listener_callback(self, msg):
        self._radar_image_visualizer.plot_radar_image_from_data(msg.data)

    def ground_truth_callback(self, msg):
        self._radar_image_visualizer.set_landmark_ranges(msg.relative_landmark_range)

    def heatmap_callback(self, msg):
        heatmap = np.array(msg.heatmap)
        self._radar_image_visualizer.set_prediction_heatmap(heatmap)

    def shutdown_hook(self, target_dir=None):
        if target_dir is not None:
            with open(os.path.join(target_dir, "last_results_radar_images.json"), "w") as f:
                json.dump(obj=self._radar_image_visualizer.get_current_state_dict(),
                          fp=f,
                          indent=4,
                          cls=ExpandedJSONEncoder)


def main(args=None):
    rclpy.init(args=args)

    radar_plotter = RadarImageVisualizerNode(topics.RADAR_TOPIC,
                                             ground_truth_topic=topics.GROUND_TRUTH_TOPIC,
                                             heatmap_topic=topics.HEATMAP_TOPIC)

    try:
        rclpy.spin(radar_plotter)
    except KeyboardInterrupt:
        radar_plotter.shutdown_hook(target_dir="./")

    radar_plotter.destroy_node()


if __name__ == '__main__':
    main()

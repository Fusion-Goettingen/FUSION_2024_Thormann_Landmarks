"""
Load a JSON file dumped by the odometry_visualizer and create figures given the loaded content
"""
import numpy as np
import json
import matplotlib.pyplot as plt
from matplotlib import patches

from radar.scripts.functions import plot_trajectory, setup_bev_plot, compute_stamp_matched_errors

PATH_TO_FILE = "/home/simon/ros_ws/last_results_odometry_visualizer.json"
PATH_TO_DIR = "../../resource/output/"

YMAX_M = 0.35
YMAX_RAD = 45


def plot_overall_trajectory(fp, vertical=False):
    with open(fp, "r") as f:
        data = json.load(f)
    # print(f"Read data with keys: {data.keys()}")

    # create plot
    if not vertical:
        fig, axs = plt.subplots(1, 3, figsize=(21, 6.5))
        # fig, axs = plt.subplots(1, 3, figsize=(24, 9))
    else:
        fig, axs = plt.subplots(3, 1, figsize=(4, 10))

    # -- trajectory plot
    plt.sca(axs[0])
    plot_trajectory(data["estimate_array"], data["ground_truth_array"])
    for i, xy in enumerate(np.array(data["cartesian_landmark_locations"])[:, :2]):
        landmark_patch = patches.Circle(xy,
                                        radius=0.075,
                                        fill=True,
                                        color='k',
                                        label="Landmark" if i == 0 else None)
        plt.gca().add_patch(landmark_patch)
    setup_bev_plot()

    # -- cartesian error plot
    cartesian_errors, angular_errors = compute_stamp_matched_errors(data["estimate_array"],
                                                                    data["timestamps_estimates"],
                                                                    data["ground_truth_array"],
                                                                    data["timestamps_ground_truth"],
                                                                    )
    plt.sca(axs[1])
    plt.plot(data["cartesian_errors"])
    print(f"Mean: {np.mean(data['cartesian_errors']):.4f}")
    plt.axhline(np.mean(cartesian_errors), linestyle='--')
    # plt.xlabel("Measurement time step index")
    plt.xlabel("Time Step")
    plt.ylabel("Absolute Cartesian error / m")
    plt.ylim(0, YMAX_M)

    # -- angular error plot
    plt.sca(axs[2])
    plt.plot(angular_errors)
    # plt.xlabel("Measurement time step index")
    plt.xlabel("Time Step")
    plt.ylabel("Absolute angular error / deg.")
    plt.axhline(np.mean(angular_errors), linestyle='--')
    plt.ylim(0, YMAX_RAD)

    # -- overall formatting
    plt.tight_layout()
    plt.show()


if __name__ == '__main__':
    plt.style.use("../../files/paper.mplstyle")
    # plot_overall_trajectory(PATH_TO_FILE)
    # print(f"Read {PATH_TO_FILE}")

    for fn in [
        "odom_seq1.json", "odom_seq2.json", "odom_seq3.json",
        # "odom_old1.json", "odom_old2.json", "odom_old3.json",
    ]:
        plot_overall_trajectory(PATH_TO_DIR + fn, vertical=True)

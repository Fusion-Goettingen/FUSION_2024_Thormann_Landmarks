"""
Loads a set of JSON files and creates an overall plot from these
"""
import numpy as np
import json
import matplotlib.pyplot as plt
from matplotlib import patches

from radar.scripts.functions import plot_trajectory, setup_bev_plot, get_color_cycle

PATH_TO_FILE = "/home/simon/ros_ws/last_results_odometry_visualizer.json"
PATH_TO_DIR = "../../resource/output/"

YMAX_M = 0.3
YMAX_RAD = 35
FIGSIZE = (21, 6.5)  # (24, 9)
PLOT_MEAN_HLINES = False


def create_trajectory_plots(PATH_TO_DIR, file_list):
    plt.style.use("../../files/paper.mplstyle")
    colors = get_color_cycle()
    n_traj = len(file_list)
    fig, axs = plt.subplots(1, n_traj, figsize=FIGSIZE)
    for i in range(n_traj):
        fp = PATH_TO_DIR + file_list[i]
        plt.sca(axs[i])
        with open(fp, "r") as f:
            data = json.load(f)
        plot_trajectory(data["estimate_array"], data["ground_truth_array"],
                        gt_color='black',
                        est_color=colors[i])
        for i, xy in enumerate(np.array(data["cartesian_landmark_locations"])[:, :2]):
            landmark_patch = patches.Circle(xy,
                                            radius=0.075,
                                            fill=True,
                                            color='k',
                                            label="Landmark" if i == 0 else None)
            plt.gca().add_patch(landmark_patch)
        setup_bev_plot()
    plt.draw()
    plt.savefig(PATH_TO_DIR + f"trajectories.pdf")


def create_individual_trajectory_plots(PATH_TO_DIR, file_list):
    plt.style.use("../../files/paper.mplstyle")
    colors = get_color_cycle()
    n_traj = len(file_list)
    for traj_ix in range(n_traj):
        fig, axs = plt.subplots(1, 1, figsize=(10, 5))
        fp = PATH_TO_DIR + file_list[traj_ix]
        with open(fp, "r") as f:
            data = json.load(f)
        plot_trajectory(data["estimate_array"], data["ground_truth_array"],
                        gt_color='black',
                        est_color=colors[traj_ix])
        for i, xy in enumerate(np.array(data["cartesian_landmark_locations"])[:, :2]):
            landmark_patch = patches.Circle(xy,
                                            radius=0.075,
                                            fill=True,
                                            color='k',
                                            label="Landmark" if i == 0 else None)
            plt.gca().add_patch(landmark_patch)
        setup_bev_plot()
        plt.draw()
        plt.savefig(PATH_TO_DIR + f"traj_{traj_ix}.pdf")


def create_error_plots(PATH_TO_DIR, file_list):
    plt.style.use("../../files/paper.mplstyle")
    plt.rcParams["font.size"] = 20
    colors = get_color_cycle()
    n_traj = len(file_list)
    fig, axs = plt.subplots(1, 2, figsize=FIGSIZE)
    for i in range(n_traj):
        fp = PATH_TO_DIR + file_list[i]
        with open(fp, "r") as f:
            data = json.load(f)
        plt.sca(axs[0])
        plt.plot(data["cartesian_errors"], c=colors[i])
        if PLOT_MEAN_HLINES:
            plt.axhline(np.mean(data["cartesian_errors"]), linestyle='--', c=colors[i])
        plt.sca(axs[1])
        plt.plot(data["angular_errors"], c=colors[i])
        if PLOT_MEAN_HLINES:
            plt.axhline(np.mean(data["angular_errors"]), linestyle='--', c=colors[i])
        print(
            f"Mean ({file_list[i]}): {np.mean(data['cartesian_errors']):.4f}m / {np.mean(data['angular_errors']):.4f}°")

    plt.sca(axs[0])
    plt.xlabel("Time Step")
    plt.ylabel("Cartesian error / m")
    plt.ylim(0, YMAX_M)

    plt.sca(axs[1])
    plt.xlabel("Time Step")
    plt.ylabel("Angular error / deg.")
    plt.ylim(0, YMAX_RAD)

    plt.tight_layout()
    plt.draw()
    plt.savefig(PATH_TO_DIR + f"errors.pdf")


if __name__ == '__main__':
    file_list = ["odom_seq1.json", "odom_seq2.json", "odom_seq3.json"]

    # create_trajectory_plots(PATH_TO_DIR, file_list)
    # create_individual_trajectory_plots(PATH_TO_DIR, file_list)
    create_error_plots(PATH_TO_DIR, file_list)

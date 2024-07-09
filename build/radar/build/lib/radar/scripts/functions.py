import numpy as np
from matplotlib import pyplot as plt
from matplotlib.ticker import FormatStrFormatter


def plot_trajectory(estimates, gt,
                    est_label='Estimate', est_color='orange',
                    gt_label='Ground Truth', gt_color='blue',
                    ):
    estimates = np.array(estimates)
    gt = np.array(gt)
    plt.plot(estimates[:, 0], estimates[:, 1], c=est_color, label=est_label)
    plt.plot(gt[:, 0], gt[:, 1], c=gt_color, label=gt_label)


def setup_bev_plot():
    plt.axis([-0.1, 1.75, -0.8, 0.8])
    plt.xlabel(r"$m_1$ / m")
    plt.ylabel(r"$m_2$ / m")
    # plt.gca().set_aspect('equal', adjustable='box')
    plt.axis('equal')
    plt.gca().yaxis.set_major_formatter(FormatStrFormatter('%.2f'))
    # plt.legend(bbox_to_anchor=(0.5, -0.1), loc='upper center')
    plt.tight_layout()


def compute_stamp_matched_errors(estimates,
                                 stamps_est,
                                 ground_truth,
                                 stamps_gt):
    estimates = np.array(estimates)
    stamps_est = np.array(stamps_est)
    ground_truth = np.array(ground_truth)
    stamps_gt = np.array(stamps_gt)

    cartesian_errors = []
    angular_errors = []

    assert len(estimates) == len(stamps_est)

    for est, stamp in zip(estimates, stamps_est):
        ix_gt = np.argmin(np.abs(stamps_gt - stamp))  # index of ground truth that is closest to current stamp
        cartesian_errors.append(np.linalg.norm(ground_truth[ix_gt, :2] - est[:2]))
        angular_errors.append(np.rad2deg(
            np.abs(ground_truth[ix_gt, 2] - est[2])
        ))

    return np.asarray(cartesian_errors), np.asarray(angular_errors)


def get_color_cycle():
    prop_cycle = plt.rcParams['axes.prop_cycle']
    return prop_cycle.by_key()['color']

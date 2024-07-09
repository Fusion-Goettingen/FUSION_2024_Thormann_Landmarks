import numpy as np
import json
from collections import deque


def timestamp_msg_to_seconds(timestamp_msg):
    return timestamp_msg.sec * 1.0 + nanoseconds_to_seconds(timestamp_msg.nanosec)


def nanoseconds_to_seconds(nanoseconds):
    return nanoseconds * 1e-9


def rot_mat(al: float) -> np.ndarray:
    return np.array([
        [np.cos(al), -np.sin(al)],
        [np.sin(al), np.cos(al)],
    ])


def log_and_normalize_image(range_doppler_image):
    log_image = np.log(range_doppler_image)
    log_image -= np.min(log_image)
    log_image /= np.max(log_image)
    return log_image


def pol2cart(rho: float, phi: float = None) -> np.ndarray:
    """
    Convert Polar coordinates to Cartesian
    :param rho: Distance to origin or [distance, angle] if phi is None
    :param phi: Angle to x-Axis or None (signaling that rho contains distance and angle)
    :return: [x, y] in Cartesian Coordinates as numpy array
    """
    if phi is None:
        rho, phi = rho
    x = rho * np.cos(phi)
    y = rho * np.sin(phi)
    return np.array([x, y])


def cart2pol(x: float, y: float = None) -> np.ndarray:
    """
    Convert Cartesian coordinates to polar
    :param x: x position or position as array if y is None
    :param y: y position or None (signaling that x contains both distances)
    :return: ndarray [rho phi] where rho is the distance to the origin and phi the angle to the x-axis
    """
    if y is None:
        x, y = x
    rho = np.sqrt(x ** 2 + y ** 2)
    phi = np.arctan2(y, x)

    return np.array([rho, phi])


def invert(value):
    if isinstance(value, np.ndarray):
        return np.linalg.inv(value)
    elif value != 0:
        return 1.0 / value
    else:
        raise ValueError('Illegal division by zero in inversion!')


class ExpandedJSONEncoder(json.JSONEncoder):
    def default(self, obj):
        if isinstance(obj, np.ndarray):
            return obj.tolist()
        if isinstance(obj, deque):
            return list(obj)
        return json.JSONEncoder.default(self, obj)

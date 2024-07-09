# Array for storing the ground truth consisting of landmarks relative to the sensor as well as the odometry changes since the initial time frame as arrays. Provides header with time stamp and ID information.

std_msgs/Header header

float64[] relative_landmark_range
float64[] relative_landmark_angle
bool is_moving
float64[] relative_position

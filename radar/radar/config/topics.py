GROUND_TRUTH_TOPIC = '/ground_truth'
ODOM_TOPIC = '/odom'
RADAR_TOPIC = '/radar'
HEATMAP_TOPIC = '/heatmap'
ODOM_ESTIMATE_TOPIC = '/filteredNLS/odom_estimate'
MULTI_ODOM_ESTIMATE_TOPIC_DICT = {
    "FilteredNLS": {'topic': "/filteredNLS/odom_estimate", 'color': 'red'},
    "NLS Measurements": {'topic': "/pureNLS/odom_estimate", 'color': 'brown'},
}

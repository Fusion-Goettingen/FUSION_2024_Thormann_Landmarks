# FUSION_2024_Thormann_Landmarks

## use colcon build and source on top level
## use launch_radar_visuals to visualize radar image + estimation heatmap
## use launch_localization_pipeline to visualize the ground truth and estimation of a sequence (provide the proper path to the .json containing the true landmarks locations in "radar/radar/config/file_locations.py"
## start launch script first and wait until CNN is loaded before starting the rosbag
## depending on hardware, package loss can occur, so it might be necessary to slow down the playback of rosbags by setting --rate parameter to, e.g., 0.1

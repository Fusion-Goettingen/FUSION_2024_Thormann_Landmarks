import os
from glob import glob
from setuptools import find_packages, setup

package_name = 'radar'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
    	('share/ament_index/resource_index/packages',
         ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob('launch/*.xml')),
        (os.path.join('share', package_name, 'resources'), glob('resource/HeatmapLandmarkDetector/*ckpt'))
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Kolja Thormann',
    maintainer_email='kolja.thormann@cs.uni-goettingen.de',
    description='Reads raw radar data from Infineon radar BGT60ATR24C from radar topic and true landmark locations from ground_truth topic (included in rosbags). Calculates and publishes the position of the robot relative to pre-defined landmarks.',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'radar_image_visualizer = radar.nodes.radar_image_visualizer_node:main',
            'landmark_estimator = radar.nodes.landmark_estimator_node:main',
            'localizer = radar.nodes.localizer_node:main',
            'odometry_visualizer = radar.nodes.odometry_visualizer_node:main',
        ],
    },
)

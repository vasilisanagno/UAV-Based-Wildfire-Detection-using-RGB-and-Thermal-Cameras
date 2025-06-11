from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        # Declare arguments
        DeclareLaunchArgument(
            'tracker_type',
            default_value='deepsort',
            description='The type of tracker to use for rgb detection'
        ),
        # Declare argument
        DeclareLaunchArgument(
            'tracker_type',
            default_value='deepsort',
            description='The type of tracker to use for thermal detection'
        ),
        # Flight Controller Node
        Node(
            package='flight_controller_pkg',
            executable='flight_controller_node',
            name='flight_controller_node',
            output='screen'
        ),
        # Node(
        #     package='flight_controller_pkg',
        #     executable='fire_centering_node',
        #     name='fire_centering_node',
        #     output='screen'
        # ),
        # Sensor Processing Nodes
        Node(
            package='sensor_processing_pkg',
            executable='sensor_data_collector_node',
            name='sensor_data_collector_node',
            output='screen'
        ),
        Node(
            package='sensor_processing_pkg',
            executable='preprocessing_node',
            name='preprocessing_node',
            output='screen'
        ),
        # Object Detection Nodes
        Node(
            package='object_detection_and_tracking_pkg',
            executable='rgb_detection_and_tracking_node',
            name='rgb_detection_and_tracking_node',
            output='screen',
            parameters=[{'tracker_type': LaunchConfiguration('tracker_type')}]
        ),
        Node(
            package='object_detection_and_tracking_pkg',
            executable='thermal_detection_and_tracking_node',
            name='thermal_detection_and_tracking_node',
            output='screen',
            parameters=[{'tracker_type': LaunchConfiguration('tracker_type')}]
        ),
        Node(
            package='object_detection_and_tracking_pkg',
            executable='data_fusion_node',
            name='data_fusion_node',
            output='screen'
        ),
        # Alert and Visualization Nodes
        Node(
            package='alert_and_visualization_pkg',
            executable='visualization_node',
            name='visualization_node',
            output='screen'
        ),
        Node(
            package='alert_and_visualization_pkg',
            executable='alert_system_node',
            name='alert_system_node',
            output='screen'
        )
    ])

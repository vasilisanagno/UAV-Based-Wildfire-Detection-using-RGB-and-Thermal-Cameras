import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/ubuntu/vanagnostop-thesis/python-code/scripts-for-drone/ROS2_scripts/src/install/alert_and_visualization_pkg'

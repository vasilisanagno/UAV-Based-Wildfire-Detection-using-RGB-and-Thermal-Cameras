from setuptools import find_packages, setup

package_name = 'object_detection_and_tracking_pkg'


setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/object_detection_and_tracking_pkg/weights', ['weights/yolo_rgb.engine']),
        ('share/object_detection_and_tracking_pkg/weights', ['weights/yolo_thermal.engine']),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='ubuntu',
    maintainer_email='ubuntu@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    extras_require={
        'test': ['pytest'],
    },
    entry_points={
        'console_scripts': [
            'rgb_detection_and_tracking_node = object_detection_and_tracking_pkg.rgb_detection_and_tracking_node:main',
            'thermal_detection_and_tracking_node = object_detection_and_tracking_pkg.thermal_detection_and_tracking_node:main',
            'data_fusion_node = object_detection_and_tracking_pkg.data_fusion_node:main'
        ],
    },
)

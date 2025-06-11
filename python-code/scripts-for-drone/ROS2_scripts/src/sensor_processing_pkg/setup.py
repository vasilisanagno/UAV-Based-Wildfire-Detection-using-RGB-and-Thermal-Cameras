from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'sensor_processing_pkg'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/sensor_processing_pkg/config', ['config/homography_matrix.npz']),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', glob('launch/*.py'))
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
            'sensor_data_collector_node = sensor_processing_pkg.sensor_data_collector_node:main',
            'preprocessing_node = sensor_processing_pkg.preprocessing_node:main'
        ],
    },
)

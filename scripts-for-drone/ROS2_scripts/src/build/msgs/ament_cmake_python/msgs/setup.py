from setuptools import find_packages
from setuptools import setup

setup(
    name='msgs',
    version='0.0.0',
    packages=find_packages(
        include=('msgs', 'msgs.*')),
)

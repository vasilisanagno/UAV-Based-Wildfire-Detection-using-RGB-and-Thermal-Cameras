cmake_minimum_required(VERSION 3.8)
project(msgs)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)

set(ROSIDL_GENERATOR_LANGUAGES "c;cpp")

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/SensorData.msg"
  "msg/ImageWithGPS.msg"
  "msg/DetectionWithGPS.msg"
  "msg/TrackedObject.msg"
  "msg/TrackedDetections.msg"
  DEPENDENCIES sensor_msgs std_msgs
)

ament_package()

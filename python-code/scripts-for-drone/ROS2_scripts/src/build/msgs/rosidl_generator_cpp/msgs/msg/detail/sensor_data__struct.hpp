// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from msgs:msg/SensorData.idl
// generated code does not contain a copyright notice

#ifndef MSGS__MSG__DETAIL__SENSOR_DATA__STRUCT_HPP_
#define MSGS__MSG__DETAIL__SENSOR_DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'rgb_image'
// Member 'thermal_image'
#include "sensor_msgs/msg/detail/image__struct.hpp"
// Member 'gps'
#include "sensor_msgs/msg/detail/nav_sat_fix__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__msgs__msg__SensorData __attribute__((deprecated))
#else
# define DEPRECATED__msgs__msg__SensorData __declspec(deprecated)
#endif

namespace msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SensorData_
{
  using Type = SensorData_<ContainerAllocator>;

  explicit SensorData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : rgb_image(_init),
    thermal_image(_init),
    gps(_init)
  {
    (void)_init;
  }

  explicit SensorData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : rgb_image(_alloc, _init),
    thermal_image(_alloc, _init),
    gps(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _rgb_image_type =
    sensor_msgs::msg::Image_<ContainerAllocator>;
  _rgb_image_type rgb_image;
  using _thermal_image_type =
    sensor_msgs::msg::Image_<ContainerAllocator>;
  _thermal_image_type thermal_image;
  using _gps_type =
    sensor_msgs::msg::NavSatFix_<ContainerAllocator>;
  _gps_type gps;

  // setters for named parameter idiom
  Type & set__rgb_image(
    const sensor_msgs::msg::Image_<ContainerAllocator> & _arg)
  {
    this->rgb_image = _arg;
    return *this;
  }
  Type & set__thermal_image(
    const sensor_msgs::msg::Image_<ContainerAllocator> & _arg)
  {
    this->thermal_image = _arg;
    return *this;
  }
  Type & set__gps(
    const sensor_msgs::msg::NavSatFix_<ContainerAllocator> & _arg)
  {
    this->gps = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    msgs::msg::SensorData_<ContainerAllocator> *;
  using ConstRawPtr =
    const msgs::msg::SensorData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<msgs::msg::SensorData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<msgs::msg::SensorData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      msgs::msg::SensorData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<msgs::msg::SensorData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      msgs::msg::SensorData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<msgs::msg::SensorData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<msgs::msg::SensorData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<msgs::msg::SensorData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__msgs__msg__SensorData
    std::shared_ptr<msgs::msg::SensorData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__msgs__msg__SensorData
    std::shared_ptr<msgs::msg::SensorData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SensorData_ & other) const
  {
    if (this->rgb_image != other.rgb_image) {
      return false;
    }
    if (this->thermal_image != other.thermal_image) {
      return false;
    }
    if (this->gps != other.gps) {
      return false;
    }
    return true;
  }
  bool operator!=(const SensorData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SensorData_

// alias to use template instance with default allocator
using SensorData =
  msgs::msg::SensorData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace msgs

#endif  // MSGS__MSG__DETAIL__SENSOR_DATA__STRUCT_HPP_

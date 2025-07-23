// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from msgs:msg/TrackedDetections.idl
// generated code does not contain a copyright notice

#ifndef MSGS__MSG__DETAIL__TRACKED_DETECTIONS__STRUCT_HPP_
#define MSGS__MSG__DETAIL__TRACKED_DETECTIONS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'gps'
#include "sensor_msgs/msg/detail/nav_sat_fix__struct.hpp"
// Member 'tracks'
#include "msgs/msg/detail/tracked_object__struct.hpp"
// Member 'rgb_image'
// Member 'thermal_image'
#include "sensor_msgs/msg/detail/image__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__msgs__msg__TrackedDetections __attribute__((deprecated))
#else
# define DEPRECATED__msgs__msg__TrackedDetections __declspec(deprecated)
#endif

namespace msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TrackedDetections_
{
  using Type = TrackedDetections_<ContainerAllocator>;

  explicit TrackedDetections_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : gps(_init),
    rgb_image(_init),
    thermal_image(_init)
  {
    (void)_init;
  }

  explicit TrackedDetections_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : gps(_alloc, _init),
    rgb_image(_alloc, _init),
    thermal_image(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _gps_type =
    sensor_msgs::msg::NavSatFix_<ContainerAllocator>;
  _gps_type gps;
  using _tracks_type =
    std::vector<msgs::msg::TrackedObject_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<msgs::msg::TrackedObject_<ContainerAllocator>>>;
  _tracks_type tracks;
  using _rgb_image_type =
    sensor_msgs::msg::Image_<ContainerAllocator>;
  _rgb_image_type rgb_image;
  using _thermal_image_type =
    sensor_msgs::msg::Image_<ContainerAllocator>;
  _thermal_image_type thermal_image;

  // setters for named parameter idiom
  Type & set__gps(
    const sensor_msgs::msg::NavSatFix_<ContainerAllocator> & _arg)
  {
    this->gps = _arg;
    return *this;
  }
  Type & set__tracks(
    const std::vector<msgs::msg::TrackedObject_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<msgs::msg::TrackedObject_<ContainerAllocator>>> & _arg)
  {
    this->tracks = _arg;
    return *this;
  }
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

  // constant declarations

  // pointer types
  using RawPtr =
    msgs::msg::TrackedDetections_<ContainerAllocator> *;
  using ConstRawPtr =
    const msgs::msg::TrackedDetections_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<msgs::msg::TrackedDetections_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<msgs::msg::TrackedDetections_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      msgs::msg::TrackedDetections_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<msgs::msg::TrackedDetections_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      msgs::msg::TrackedDetections_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<msgs::msg::TrackedDetections_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<msgs::msg::TrackedDetections_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<msgs::msg::TrackedDetections_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__msgs__msg__TrackedDetections
    std::shared_ptr<msgs::msg::TrackedDetections_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__msgs__msg__TrackedDetections
    std::shared_ptr<msgs::msg::TrackedDetections_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TrackedDetections_ & other) const
  {
    if (this->gps != other.gps) {
      return false;
    }
    if (this->tracks != other.tracks) {
      return false;
    }
    if (this->rgb_image != other.rgb_image) {
      return false;
    }
    if (this->thermal_image != other.thermal_image) {
      return false;
    }
    return true;
  }
  bool operator!=(const TrackedDetections_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TrackedDetections_

// alias to use template instance with default allocator
using TrackedDetections =
  msgs::msg::TrackedDetections_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace msgs

#endif  // MSGS__MSG__DETAIL__TRACKED_DETECTIONS__STRUCT_HPP_

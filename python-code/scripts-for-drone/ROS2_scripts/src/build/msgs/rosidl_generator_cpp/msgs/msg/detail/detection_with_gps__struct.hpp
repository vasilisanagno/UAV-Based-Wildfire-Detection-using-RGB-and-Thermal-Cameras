// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from msgs:msg/DetectionWithGPS.idl
// generated code does not contain a copyright notice

#ifndef MSGS__MSG__DETAIL__DETECTION_WITH_GPS__STRUCT_HPP_
#define MSGS__MSG__DETAIL__DETECTION_WITH_GPS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'gps'
#include "sensor_msgs/msg/detail/nav_sat_fix__struct.hpp"
// Member 'image'
#include "sensor_msgs/msg/detail/image__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__msgs__msg__DetectionWithGPS __attribute__((deprecated))
#else
# define DEPRECATED__msgs__msg__DetectionWithGPS __declspec(deprecated)
#endif

namespace msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DetectionWithGPS_
{
  using Type = DetectionWithGPS_<ContainerAllocator>;

  explicit DetectionWithGPS_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    gps(_init),
    image(_init)
  {
    (void)_init;
  }

  explicit DetectionWithGPS_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    gps(_alloc, _init),
    image(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _labels_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _labels_type labels;
  using _confidences_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _confidences_type confidences;
  using _boxes_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _boxes_type boxes;
  using _tracking_ids_type =
    std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>>;
  _tracking_ids_type tracking_ids;
  using _gps_type =
    sensor_msgs::msg::NavSatFix_<ContainerAllocator>;
  _gps_type gps;
  using _image_type =
    sensor_msgs::msg::Image_<ContainerAllocator>;
  _image_type image;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__labels(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->labels = _arg;
    return *this;
  }
  Type & set__confidences(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->confidences = _arg;
    return *this;
  }
  Type & set__boxes(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->boxes = _arg;
    return *this;
  }
  Type & set__tracking_ids(
    const std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> & _arg)
  {
    this->tracking_ids = _arg;
    return *this;
  }
  Type & set__gps(
    const sensor_msgs::msg::NavSatFix_<ContainerAllocator> & _arg)
  {
    this->gps = _arg;
    return *this;
  }
  Type & set__image(
    const sensor_msgs::msg::Image_<ContainerAllocator> & _arg)
  {
    this->image = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    msgs::msg::DetectionWithGPS_<ContainerAllocator> *;
  using ConstRawPtr =
    const msgs::msg::DetectionWithGPS_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<msgs::msg::DetectionWithGPS_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<msgs::msg::DetectionWithGPS_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      msgs::msg::DetectionWithGPS_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<msgs::msg::DetectionWithGPS_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      msgs::msg::DetectionWithGPS_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<msgs::msg::DetectionWithGPS_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<msgs::msg::DetectionWithGPS_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<msgs::msg::DetectionWithGPS_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__msgs__msg__DetectionWithGPS
    std::shared_ptr<msgs::msg::DetectionWithGPS_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__msgs__msg__DetectionWithGPS
    std::shared_ptr<msgs::msg::DetectionWithGPS_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DetectionWithGPS_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->labels != other.labels) {
      return false;
    }
    if (this->confidences != other.confidences) {
      return false;
    }
    if (this->boxes != other.boxes) {
      return false;
    }
    if (this->tracking_ids != other.tracking_ids) {
      return false;
    }
    if (this->gps != other.gps) {
      return false;
    }
    if (this->image != other.image) {
      return false;
    }
    return true;
  }
  bool operator!=(const DetectionWithGPS_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DetectionWithGPS_

// alias to use template instance with default allocator
using DetectionWithGPS =
  msgs::msg::DetectionWithGPS_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace msgs

#endif  // MSGS__MSG__DETAIL__DETECTION_WITH_GPS__STRUCT_HPP_

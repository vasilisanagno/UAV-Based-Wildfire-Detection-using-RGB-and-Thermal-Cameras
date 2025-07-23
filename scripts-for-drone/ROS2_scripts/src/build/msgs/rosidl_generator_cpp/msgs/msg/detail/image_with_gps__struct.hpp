// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from msgs:msg/ImageWithGPS.idl
// generated code does not contain a copyright notice

#ifndef MSGS__MSG__DETAIL__IMAGE_WITH_GPS__STRUCT_HPP_
#define MSGS__MSG__DETAIL__IMAGE_WITH_GPS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'image'
#include "sensor_msgs/msg/detail/image__struct.hpp"
// Member 'gps'
#include "sensor_msgs/msg/detail/nav_sat_fix__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__msgs__msg__ImageWithGPS __attribute__((deprecated))
#else
# define DEPRECATED__msgs__msg__ImageWithGPS __declspec(deprecated)
#endif

namespace msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ImageWithGPS_
{
  using Type = ImageWithGPS_<ContainerAllocator>;

  explicit ImageWithGPS_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : image(_init),
    gps(_init)
  {
    (void)_init;
  }

  explicit ImageWithGPS_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : image(_alloc, _init),
    gps(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _image_type =
    sensor_msgs::msg::Image_<ContainerAllocator>;
  _image_type image;
  using _gps_type =
    sensor_msgs::msg::NavSatFix_<ContainerAllocator>;
  _gps_type gps;

  // setters for named parameter idiom
  Type & set__image(
    const sensor_msgs::msg::Image_<ContainerAllocator> & _arg)
  {
    this->image = _arg;
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
    msgs::msg::ImageWithGPS_<ContainerAllocator> *;
  using ConstRawPtr =
    const msgs::msg::ImageWithGPS_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<msgs::msg::ImageWithGPS_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<msgs::msg::ImageWithGPS_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      msgs::msg::ImageWithGPS_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<msgs::msg::ImageWithGPS_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      msgs::msg::ImageWithGPS_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<msgs::msg::ImageWithGPS_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<msgs::msg::ImageWithGPS_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<msgs::msg::ImageWithGPS_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__msgs__msg__ImageWithGPS
    std::shared_ptr<msgs::msg::ImageWithGPS_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__msgs__msg__ImageWithGPS
    std::shared_ptr<msgs::msg::ImageWithGPS_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ImageWithGPS_ & other) const
  {
    if (this->image != other.image) {
      return false;
    }
    if (this->gps != other.gps) {
      return false;
    }
    return true;
  }
  bool operator!=(const ImageWithGPS_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ImageWithGPS_

// alias to use template instance with default allocator
using ImageWithGPS =
  msgs::msg::ImageWithGPS_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace msgs

#endif  // MSGS__MSG__DETAIL__IMAGE_WITH_GPS__STRUCT_HPP_

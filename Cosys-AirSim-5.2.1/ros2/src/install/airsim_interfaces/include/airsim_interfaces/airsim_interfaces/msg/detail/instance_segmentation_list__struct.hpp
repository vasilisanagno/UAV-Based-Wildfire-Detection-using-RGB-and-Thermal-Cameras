// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from airsim_interfaces:msg/InstanceSegmentationList.idl
// generated code does not contain a copyright notice

#ifndef AIRSIM_INTERFACES__MSG__DETAIL__INSTANCE_SEGMENTATION_LIST__STRUCT_HPP_
#define AIRSIM_INTERFACES__MSG__DETAIL__INSTANCE_SEGMENTATION_LIST__STRUCT_HPP_

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
// Member 'labels'
#include "airsim_interfaces/msg/detail/instance_segmentation_label__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__airsim_interfaces__msg__InstanceSegmentationList __attribute__((deprecated))
#else
# define DEPRECATED__airsim_interfaces__msg__InstanceSegmentationList __declspec(deprecated)
#endif

namespace airsim_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct InstanceSegmentationList_
{
  using Type = InstanceSegmentationList_<ContainerAllocator>;

  explicit InstanceSegmentationList_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit InstanceSegmentationList_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _labels_type =
    std::vector<airsim_interfaces::msg::InstanceSegmentationLabel_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<airsim_interfaces::msg::InstanceSegmentationLabel_<ContainerAllocator>>>;
  _labels_type labels;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__labels(
    const std::vector<airsim_interfaces::msg::InstanceSegmentationLabel_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<airsim_interfaces::msg::InstanceSegmentationLabel_<ContainerAllocator>>> & _arg)
  {
    this->labels = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    airsim_interfaces::msg::InstanceSegmentationList_<ContainerAllocator> *;
  using ConstRawPtr =
    const airsim_interfaces::msg::InstanceSegmentationList_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<airsim_interfaces::msg::InstanceSegmentationList_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<airsim_interfaces::msg::InstanceSegmentationList_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      airsim_interfaces::msg::InstanceSegmentationList_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<airsim_interfaces::msg::InstanceSegmentationList_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      airsim_interfaces::msg::InstanceSegmentationList_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<airsim_interfaces::msg::InstanceSegmentationList_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<airsim_interfaces::msg::InstanceSegmentationList_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<airsim_interfaces::msg::InstanceSegmentationList_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__airsim_interfaces__msg__InstanceSegmentationList
    std::shared_ptr<airsim_interfaces::msg::InstanceSegmentationList_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__airsim_interfaces__msg__InstanceSegmentationList
    std::shared_ptr<airsim_interfaces::msg::InstanceSegmentationList_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const InstanceSegmentationList_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->labels != other.labels) {
      return false;
    }
    return true;
  }
  bool operator!=(const InstanceSegmentationList_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct InstanceSegmentationList_

// alias to use template instance with default allocator
using InstanceSegmentationList =
  airsim_interfaces::msg::InstanceSegmentationList_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace airsim_interfaces

#endif  // AIRSIM_INTERFACES__MSG__DETAIL__INSTANCE_SEGMENTATION_LIST__STRUCT_HPP_

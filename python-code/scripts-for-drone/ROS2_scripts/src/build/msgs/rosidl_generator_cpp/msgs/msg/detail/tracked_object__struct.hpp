// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from msgs:msg/TrackedObject.idl
// generated code does not contain a copyright notice

#ifndef MSGS__MSG__DETAIL__TRACKED_OBJECT__STRUCT_HPP_
#define MSGS__MSG__DETAIL__TRACKED_OBJECT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__msgs__msg__TrackedObject __attribute__((deprecated))
#else
# define DEPRECATED__msgs__msg__TrackedObject __declspec(deprecated)
#endif

namespace msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TrackedObject_
{
  using Type = TrackedObject_<ContainerAllocator>;

  explicit TrackedObject_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->label = "";
      this->confidence = 0.0f;
      std::fill<typename std::array<float, 4>::iterator, float>(this->box.begin(), this->box.end(), 0.0f);
      this->source = "";
    }
  }

  explicit TrackedObject_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : label(_alloc),
    box(_alloc),
    source(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->label = "";
      this->confidence = 0.0f;
      std::fill<typename std::array<float, 4>::iterator, float>(this->box.begin(), this->box.end(), 0.0f);
      this->source = "";
    }
  }

  // field types and members
  using _id_type =
    int32_t;
  _id_type id;
  using _label_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _label_type label;
  using _confidence_type =
    float;
  _confidence_type confidence;
  using _box_type =
    std::array<float, 4>;
  _box_type box;
  using _source_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _source_type source;

  // setters for named parameter idiom
  Type & set__id(
    const int32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__label(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->label = _arg;
    return *this;
  }
  Type & set__confidence(
    const float & _arg)
  {
    this->confidence = _arg;
    return *this;
  }
  Type & set__box(
    const std::array<float, 4> & _arg)
  {
    this->box = _arg;
    return *this;
  }
  Type & set__source(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->source = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    msgs::msg::TrackedObject_<ContainerAllocator> *;
  using ConstRawPtr =
    const msgs::msg::TrackedObject_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<msgs::msg::TrackedObject_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<msgs::msg::TrackedObject_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      msgs::msg::TrackedObject_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<msgs::msg::TrackedObject_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      msgs::msg::TrackedObject_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<msgs::msg::TrackedObject_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<msgs::msg::TrackedObject_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<msgs::msg::TrackedObject_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__msgs__msg__TrackedObject
    std::shared_ptr<msgs::msg::TrackedObject_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__msgs__msg__TrackedObject
    std::shared_ptr<msgs::msg::TrackedObject_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TrackedObject_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->label != other.label) {
      return false;
    }
    if (this->confidence != other.confidence) {
      return false;
    }
    if (this->box != other.box) {
      return false;
    }
    if (this->source != other.source) {
      return false;
    }
    return true;
  }
  bool operator!=(const TrackedObject_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TrackedObject_

// alias to use template instance with default allocator
using TrackedObject =
  msgs::msg::TrackedObject_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace msgs

#endif  // MSGS__MSG__DETAIL__TRACKED_OBJECT__STRUCT_HPP_

// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from msgs:msg/TrackedObject.idl
// generated code does not contain a copyright notice

#ifndef MSGS__MSG__DETAIL__TRACKED_OBJECT__BUILDER_HPP_
#define MSGS__MSG__DETAIL__TRACKED_OBJECT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "msgs/msg/detail/tracked_object__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace msgs
{

namespace msg
{

namespace builder
{

class Init_TrackedObject_source
{
public:
  explicit Init_TrackedObject_source(::msgs::msg::TrackedObject & msg)
  : msg_(msg)
  {}
  ::msgs::msg::TrackedObject source(::msgs::msg::TrackedObject::_source_type arg)
  {
    msg_.source = std::move(arg);
    return std::move(msg_);
  }

private:
  ::msgs::msg::TrackedObject msg_;
};

class Init_TrackedObject_box
{
public:
  explicit Init_TrackedObject_box(::msgs::msg::TrackedObject & msg)
  : msg_(msg)
  {}
  Init_TrackedObject_source box(::msgs::msg::TrackedObject::_box_type arg)
  {
    msg_.box = std::move(arg);
    return Init_TrackedObject_source(msg_);
  }

private:
  ::msgs::msg::TrackedObject msg_;
};

class Init_TrackedObject_confidence
{
public:
  explicit Init_TrackedObject_confidence(::msgs::msg::TrackedObject & msg)
  : msg_(msg)
  {}
  Init_TrackedObject_box confidence(::msgs::msg::TrackedObject::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return Init_TrackedObject_box(msg_);
  }

private:
  ::msgs::msg::TrackedObject msg_;
};

class Init_TrackedObject_label
{
public:
  explicit Init_TrackedObject_label(::msgs::msg::TrackedObject & msg)
  : msg_(msg)
  {}
  Init_TrackedObject_confidence label(::msgs::msg::TrackedObject::_label_type arg)
  {
    msg_.label = std::move(arg);
    return Init_TrackedObject_confidence(msg_);
  }

private:
  ::msgs::msg::TrackedObject msg_;
};

class Init_TrackedObject_id
{
public:
  Init_TrackedObject_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TrackedObject_label id(::msgs::msg::TrackedObject::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_TrackedObject_label(msg_);
  }

private:
  ::msgs::msg::TrackedObject msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::msgs::msg::TrackedObject>()
{
  return msgs::msg::builder::Init_TrackedObject_id();
}

}  // namespace msgs

#endif  // MSGS__MSG__DETAIL__TRACKED_OBJECT__BUILDER_HPP_

// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from msgs:msg/TrackedDetections.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "msgs/msg/detail/tracked_detections__functions.h"
#include "msgs/msg/detail/tracked_detections__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void TrackedDetections_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) msgs::msg::TrackedDetections(_init);
}

void TrackedDetections_fini_function(void * message_memory)
{
  auto typed_message = static_cast<msgs::msg::TrackedDetections *>(message_memory);
  typed_message->~TrackedDetections();
}

size_t size_function__TrackedDetections__tracks(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<msgs::msg::TrackedObject> *>(untyped_member);
  return member->size();
}

const void * get_const_function__TrackedDetections__tracks(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<msgs::msg::TrackedObject> *>(untyped_member);
  return &member[index];
}

void * get_function__TrackedDetections__tracks(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<msgs::msg::TrackedObject> *>(untyped_member);
  return &member[index];
}

void fetch_function__TrackedDetections__tracks(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const msgs::msg::TrackedObject *>(
    get_const_function__TrackedDetections__tracks(untyped_member, index));
  auto & value = *reinterpret_cast<msgs::msg::TrackedObject *>(untyped_value);
  value = item;
}

void assign_function__TrackedDetections__tracks(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<msgs::msg::TrackedObject *>(
    get_function__TrackedDetections__tracks(untyped_member, index));
  const auto & value = *reinterpret_cast<const msgs::msg::TrackedObject *>(untyped_value);
  item = value;
}

void resize_function__TrackedDetections__tracks(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<msgs::msg::TrackedObject> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember TrackedDetections_message_member_array[4] = {
  {
    "gps",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<sensor_msgs::msg::NavSatFix>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs::msg::TrackedDetections, gps),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "tracks",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<msgs::msg::TrackedObject>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs::msg::TrackedDetections, tracks),  // bytes offset in struct
    nullptr,  // default value
    size_function__TrackedDetections__tracks,  // size() function pointer
    get_const_function__TrackedDetections__tracks,  // get_const(index) function pointer
    get_function__TrackedDetections__tracks,  // get(index) function pointer
    fetch_function__TrackedDetections__tracks,  // fetch(index, &value) function pointer
    assign_function__TrackedDetections__tracks,  // assign(index, value) function pointer
    resize_function__TrackedDetections__tracks  // resize(index) function pointer
  },
  {
    "rgb_image",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<sensor_msgs::msg::Image>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs::msg::TrackedDetections, rgb_image),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "thermal_image",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<sensor_msgs::msg::Image>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs::msg::TrackedDetections, thermal_image),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers TrackedDetections_message_members = {
  "msgs::msg",  // message namespace
  "TrackedDetections",  // message name
  4,  // number of fields
  sizeof(msgs::msg::TrackedDetections),
  TrackedDetections_message_member_array,  // message members
  TrackedDetections_init_function,  // function to initialize message memory (memory has to be allocated)
  TrackedDetections_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t TrackedDetections_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &TrackedDetections_message_members,
  get_message_typesupport_handle_function,
  &msgs__msg__TrackedDetections__get_type_hash,
  &msgs__msg__TrackedDetections__get_type_description,
  &msgs__msg__TrackedDetections__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<msgs::msg::TrackedDetections>()
{
  return &::msgs::msg::rosidl_typesupport_introspection_cpp::TrackedDetections_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, msgs, msg, TrackedDetections)() {
  return &::msgs::msg::rosidl_typesupport_introspection_cpp::TrackedDetections_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

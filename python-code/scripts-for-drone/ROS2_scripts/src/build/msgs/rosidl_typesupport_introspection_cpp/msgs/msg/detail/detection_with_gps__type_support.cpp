// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from msgs:msg/DetectionWithGPS.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "msgs/msg/detail/detection_with_gps__functions.h"
#include "msgs/msg/detail/detection_with_gps__struct.hpp"
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

void DetectionWithGPS_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) msgs::msg::DetectionWithGPS(_init);
}

void DetectionWithGPS_fini_function(void * message_memory)
{
  auto typed_message = static_cast<msgs::msg::DetectionWithGPS *>(message_memory);
  typed_message->~DetectionWithGPS();
}

size_t size_function__DetectionWithGPS__labels(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return member->size();
}

const void * get_const_function__DetectionWithGPS__labels(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void * get_function__DetectionWithGPS__labels(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void fetch_function__DetectionWithGPS__labels(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const std::string *>(
    get_const_function__DetectionWithGPS__labels(untyped_member, index));
  auto & value = *reinterpret_cast<std::string *>(untyped_value);
  value = item;
}

void assign_function__DetectionWithGPS__labels(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<std::string *>(
    get_function__DetectionWithGPS__labels(untyped_member, index));
  const auto & value = *reinterpret_cast<const std::string *>(untyped_value);
  item = value;
}

void resize_function__DetectionWithGPS__labels(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std::string> *>(untyped_member);
  member->resize(size);
}

size_t size_function__DetectionWithGPS__confidences(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__DetectionWithGPS__confidences(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__DetectionWithGPS__confidences(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__DetectionWithGPS__confidences(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__DetectionWithGPS__confidences(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__DetectionWithGPS__confidences(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__DetectionWithGPS__confidences(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__DetectionWithGPS__confidences(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

size_t size_function__DetectionWithGPS__boxes(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__DetectionWithGPS__boxes(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__DetectionWithGPS__boxes(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__DetectionWithGPS__boxes(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__DetectionWithGPS__boxes(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__DetectionWithGPS__boxes(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__DetectionWithGPS__boxes(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__DetectionWithGPS__boxes(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

size_t size_function__DetectionWithGPS__tracking_ids(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<int32_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__DetectionWithGPS__tracking_ids(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<int32_t> *>(untyped_member);
  return &member[index];
}

void * get_function__DetectionWithGPS__tracking_ids(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<int32_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__DetectionWithGPS__tracking_ids(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int32_t *>(
    get_const_function__DetectionWithGPS__tracking_ids(untyped_member, index));
  auto & value = *reinterpret_cast<int32_t *>(untyped_value);
  value = item;
}

void assign_function__DetectionWithGPS__tracking_ids(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int32_t *>(
    get_function__DetectionWithGPS__tracking_ids(untyped_member, index));
  const auto & value = *reinterpret_cast<const int32_t *>(untyped_value);
  item = value;
}

void resize_function__DetectionWithGPS__tracking_ids(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<int32_t> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember DetectionWithGPS_message_member_array[7] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs::msg::DetectionWithGPS, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "labels",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs::msg::DetectionWithGPS, labels),  // bytes offset in struct
    nullptr,  // default value
    size_function__DetectionWithGPS__labels,  // size() function pointer
    get_const_function__DetectionWithGPS__labels,  // get_const(index) function pointer
    get_function__DetectionWithGPS__labels,  // get(index) function pointer
    fetch_function__DetectionWithGPS__labels,  // fetch(index, &value) function pointer
    assign_function__DetectionWithGPS__labels,  // assign(index, value) function pointer
    resize_function__DetectionWithGPS__labels  // resize(index) function pointer
  },
  {
    "confidences",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs::msg::DetectionWithGPS, confidences),  // bytes offset in struct
    nullptr,  // default value
    size_function__DetectionWithGPS__confidences,  // size() function pointer
    get_const_function__DetectionWithGPS__confidences,  // get_const(index) function pointer
    get_function__DetectionWithGPS__confidences,  // get(index) function pointer
    fetch_function__DetectionWithGPS__confidences,  // fetch(index, &value) function pointer
    assign_function__DetectionWithGPS__confidences,  // assign(index, value) function pointer
    resize_function__DetectionWithGPS__confidences  // resize(index) function pointer
  },
  {
    "boxes",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs::msg::DetectionWithGPS, boxes),  // bytes offset in struct
    nullptr,  // default value
    size_function__DetectionWithGPS__boxes,  // size() function pointer
    get_const_function__DetectionWithGPS__boxes,  // get_const(index) function pointer
    get_function__DetectionWithGPS__boxes,  // get(index) function pointer
    fetch_function__DetectionWithGPS__boxes,  // fetch(index, &value) function pointer
    assign_function__DetectionWithGPS__boxes,  // assign(index, value) function pointer
    resize_function__DetectionWithGPS__boxes  // resize(index) function pointer
  },
  {
    "tracking_ids",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs::msg::DetectionWithGPS, tracking_ids),  // bytes offset in struct
    nullptr,  // default value
    size_function__DetectionWithGPS__tracking_ids,  // size() function pointer
    get_const_function__DetectionWithGPS__tracking_ids,  // get_const(index) function pointer
    get_function__DetectionWithGPS__tracking_ids,  // get(index) function pointer
    fetch_function__DetectionWithGPS__tracking_ids,  // fetch(index, &value) function pointer
    assign_function__DetectionWithGPS__tracking_ids,  // assign(index, value) function pointer
    resize_function__DetectionWithGPS__tracking_ids  // resize(index) function pointer
  },
  {
    "gps",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<sensor_msgs::msg::NavSatFix>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs::msg::DetectionWithGPS, gps),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "image",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<sensor_msgs::msg::Image>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs::msg::DetectionWithGPS, image),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers DetectionWithGPS_message_members = {
  "msgs::msg",  // message namespace
  "DetectionWithGPS",  // message name
  7,  // number of fields
  sizeof(msgs::msg::DetectionWithGPS),
  DetectionWithGPS_message_member_array,  // message members
  DetectionWithGPS_init_function,  // function to initialize message memory (memory has to be allocated)
  DetectionWithGPS_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t DetectionWithGPS_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DetectionWithGPS_message_members,
  get_message_typesupport_handle_function,
  &msgs__msg__DetectionWithGPS__get_type_hash,
  &msgs__msg__DetectionWithGPS__get_type_description,
  &msgs__msg__DetectionWithGPS__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<msgs::msg::DetectionWithGPS>()
{
  return &::msgs::msg::rosidl_typesupport_introspection_cpp::DetectionWithGPS_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, msgs, msg, DetectionWithGPS)() {
  return &::msgs::msg::rosidl_typesupport_introspection_cpp::DetectionWithGPS_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

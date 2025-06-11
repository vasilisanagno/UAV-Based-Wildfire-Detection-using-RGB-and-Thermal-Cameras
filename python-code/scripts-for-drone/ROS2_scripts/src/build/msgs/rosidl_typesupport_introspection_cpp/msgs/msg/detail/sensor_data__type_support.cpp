// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from msgs:msg/SensorData.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "msgs/msg/detail/sensor_data__functions.h"
#include "msgs/msg/detail/sensor_data__struct.hpp"
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

void SensorData_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) msgs::msg::SensorData(_init);
}

void SensorData_fini_function(void * message_memory)
{
  auto typed_message = static_cast<msgs::msg::SensorData *>(message_memory);
  typed_message->~SensorData();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember SensorData_message_member_array[3] = {
  {
    "rgb_image",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<sensor_msgs::msg::Image>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs::msg::SensorData, rgb_image),  // bytes offset in struct
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
    offsetof(msgs::msg::SensorData, thermal_image),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "gps",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<sensor_msgs::msg::NavSatFix>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs::msg::SensorData, gps),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers SensorData_message_members = {
  "msgs::msg",  // message namespace
  "SensorData",  // message name
  3,  // number of fields
  sizeof(msgs::msg::SensorData),
  SensorData_message_member_array,  // message members
  SensorData_init_function,  // function to initialize message memory (memory has to be allocated)
  SensorData_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t SensorData_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &SensorData_message_members,
  get_message_typesupport_handle_function,
  &msgs__msg__SensorData__get_type_hash,
  &msgs__msg__SensorData__get_type_description,
  &msgs__msg__SensorData__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<msgs::msg::SensorData>()
{
  return &::msgs::msg::rosidl_typesupport_introspection_cpp::SensorData_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, msgs, msg, SensorData)() {
  return &::msgs::msg::rosidl_typesupport_introspection_cpp::SensorData_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

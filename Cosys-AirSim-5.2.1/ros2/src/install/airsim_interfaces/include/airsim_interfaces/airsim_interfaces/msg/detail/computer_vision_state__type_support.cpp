// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from airsim_interfaces:msg/ComputerVisionState.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "airsim_interfaces/msg/detail/computer_vision_state__functions.h"
#include "airsim_interfaces/msg/detail/computer_vision_state__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace airsim_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void ComputerVisionState_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) airsim_interfaces::msg::ComputerVisionState(_init);
}

void ComputerVisionState_fini_function(void * message_memory)
{
  auto typed_message = static_cast<airsim_interfaces::msg::ComputerVisionState *>(message_memory);
  typed_message->~ComputerVisionState();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ComputerVisionState_message_member_array[3] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(airsim_interfaces::msg::ComputerVisionState, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "pose",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::PoseWithCovariance>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(airsim_interfaces::msg::ComputerVisionState, pose),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "twist",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::TwistWithCovariance>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(airsim_interfaces::msg::ComputerVisionState, twist),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ComputerVisionState_message_members = {
  "airsim_interfaces::msg",  // message namespace
  "ComputerVisionState",  // message name
  3,  // number of fields
  sizeof(airsim_interfaces::msg::ComputerVisionState),
  ComputerVisionState_message_member_array,  // message members
  ComputerVisionState_init_function,  // function to initialize message memory (memory has to be allocated)
  ComputerVisionState_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ComputerVisionState_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ComputerVisionState_message_members,
  get_message_typesupport_handle_function,
  &airsim_interfaces__msg__ComputerVisionState__get_type_hash,
  &airsim_interfaces__msg__ComputerVisionState__get_type_description,
  &airsim_interfaces__msg__ComputerVisionState__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace airsim_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<airsim_interfaces::msg::ComputerVisionState>()
{
  return &::airsim_interfaces::msg::rosidl_typesupport_introspection_cpp::ComputerVisionState_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, airsim_interfaces, msg, ComputerVisionState)() {
  return &::airsim_interfaces::msg::rosidl_typesupport_introspection_cpp::ComputerVisionState_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

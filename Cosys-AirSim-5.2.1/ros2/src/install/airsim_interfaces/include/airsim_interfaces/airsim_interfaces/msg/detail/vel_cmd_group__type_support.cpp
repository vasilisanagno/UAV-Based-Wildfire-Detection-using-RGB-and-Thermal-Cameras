// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from airsim_interfaces:msg/VelCmdGroup.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "airsim_interfaces/msg/detail/vel_cmd_group__functions.h"
#include "airsim_interfaces/msg/detail/vel_cmd_group__struct.hpp"
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

void VelCmdGroup_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) airsim_interfaces::msg::VelCmdGroup(_init);
}

void VelCmdGroup_fini_function(void * message_memory)
{
  auto typed_message = static_cast<airsim_interfaces::msg::VelCmdGroup *>(message_memory);
  typed_message->~VelCmdGroup();
}

size_t size_function__VelCmdGroup__vehicle_names(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return member->size();
}

const void * get_const_function__VelCmdGroup__vehicle_names(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void * get_function__VelCmdGroup__vehicle_names(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void fetch_function__VelCmdGroup__vehicle_names(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const std::string *>(
    get_const_function__VelCmdGroup__vehicle_names(untyped_member, index));
  auto & value = *reinterpret_cast<std::string *>(untyped_value);
  value = item;
}

void assign_function__VelCmdGroup__vehicle_names(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<std::string *>(
    get_function__VelCmdGroup__vehicle_names(untyped_member, index));
  const auto & value = *reinterpret_cast<const std::string *>(untyped_value);
  item = value;
}

void resize_function__VelCmdGroup__vehicle_names(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std::string> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember VelCmdGroup_message_member_array[2] = {
  {
    "vel_cmd",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<airsim_interfaces::msg::VelCmd>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(airsim_interfaces::msg::VelCmdGroup, vel_cmd),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "vehicle_names",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(airsim_interfaces::msg::VelCmdGroup, vehicle_names),  // bytes offset in struct
    nullptr,  // default value
    size_function__VelCmdGroup__vehicle_names,  // size() function pointer
    get_const_function__VelCmdGroup__vehicle_names,  // get_const(index) function pointer
    get_function__VelCmdGroup__vehicle_names,  // get(index) function pointer
    fetch_function__VelCmdGroup__vehicle_names,  // fetch(index, &value) function pointer
    assign_function__VelCmdGroup__vehicle_names,  // assign(index, value) function pointer
    resize_function__VelCmdGroup__vehicle_names  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers VelCmdGroup_message_members = {
  "airsim_interfaces::msg",  // message namespace
  "VelCmdGroup",  // message name
  2,  // number of fields
  sizeof(airsim_interfaces::msg::VelCmdGroup),
  VelCmdGroup_message_member_array,  // message members
  VelCmdGroup_init_function,  // function to initialize message memory (memory has to be allocated)
  VelCmdGroup_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t VelCmdGroup_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &VelCmdGroup_message_members,
  get_message_typesupport_handle_function,
  &airsim_interfaces__msg__VelCmdGroup__get_type_hash,
  &airsim_interfaces__msg__VelCmdGroup__get_type_description,
  &airsim_interfaces__msg__VelCmdGroup__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace airsim_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<airsim_interfaces::msg::VelCmdGroup>()
{
  return &::airsim_interfaces::msg::rosidl_typesupport_introspection_cpp::VelCmdGroup_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, airsim_interfaces, msg, VelCmdGroup)() {
  return &::airsim_interfaces::msg::rosidl_typesupport_introspection_cpp::VelCmdGroup_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

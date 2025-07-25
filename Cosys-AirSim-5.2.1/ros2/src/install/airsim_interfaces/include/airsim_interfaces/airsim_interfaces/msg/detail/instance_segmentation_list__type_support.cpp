// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from airsim_interfaces:msg/InstanceSegmentationList.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "airsim_interfaces/msg/detail/instance_segmentation_list__functions.h"
#include "airsim_interfaces/msg/detail/instance_segmentation_list__struct.hpp"
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

void InstanceSegmentationList_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) airsim_interfaces::msg::InstanceSegmentationList(_init);
}

void InstanceSegmentationList_fini_function(void * message_memory)
{
  auto typed_message = static_cast<airsim_interfaces::msg::InstanceSegmentationList *>(message_memory);
  typed_message->~InstanceSegmentationList();
}

size_t size_function__InstanceSegmentationList__labels(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<airsim_interfaces::msg::InstanceSegmentationLabel> *>(untyped_member);
  return member->size();
}

const void * get_const_function__InstanceSegmentationList__labels(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<airsim_interfaces::msg::InstanceSegmentationLabel> *>(untyped_member);
  return &member[index];
}

void * get_function__InstanceSegmentationList__labels(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<airsim_interfaces::msg::InstanceSegmentationLabel> *>(untyped_member);
  return &member[index];
}

void fetch_function__InstanceSegmentationList__labels(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const airsim_interfaces::msg::InstanceSegmentationLabel *>(
    get_const_function__InstanceSegmentationList__labels(untyped_member, index));
  auto & value = *reinterpret_cast<airsim_interfaces::msg::InstanceSegmentationLabel *>(untyped_value);
  value = item;
}

void assign_function__InstanceSegmentationList__labels(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<airsim_interfaces::msg::InstanceSegmentationLabel *>(
    get_function__InstanceSegmentationList__labels(untyped_member, index));
  const auto & value = *reinterpret_cast<const airsim_interfaces::msg::InstanceSegmentationLabel *>(untyped_value);
  item = value;
}

void resize_function__InstanceSegmentationList__labels(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<airsim_interfaces::msg::InstanceSegmentationLabel> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember InstanceSegmentationList_message_member_array[2] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(airsim_interfaces::msg::InstanceSegmentationList, header),  // bytes offset in struct
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
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<airsim_interfaces::msg::InstanceSegmentationLabel>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(airsim_interfaces::msg::InstanceSegmentationList, labels),  // bytes offset in struct
    nullptr,  // default value
    size_function__InstanceSegmentationList__labels,  // size() function pointer
    get_const_function__InstanceSegmentationList__labels,  // get_const(index) function pointer
    get_function__InstanceSegmentationList__labels,  // get(index) function pointer
    fetch_function__InstanceSegmentationList__labels,  // fetch(index, &value) function pointer
    assign_function__InstanceSegmentationList__labels,  // assign(index, value) function pointer
    resize_function__InstanceSegmentationList__labels  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers InstanceSegmentationList_message_members = {
  "airsim_interfaces::msg",  // message namespace
  "InstanceSegmentationList",  // message name
  2,  // number of fields
  sizeof(airsim_interfaces::msg::InstanceSegmentationList),
  InstanceSegmentationList_message_member_array,  // message members
  InstanceSegmentationList_init_function,  // function to initialize message memory (memory has to be allocated)
  InstanceSegmentationList_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t InstanceSegmentationList_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &InstanceSegmentationList_message_members,
  get_message_typesupport_handle_function,
  &airsim_interfaces__msg__InstanceSegmentationList__get_type_hash,
  &airsim_interfaces__msg__InstanceSegmentationList__get_type_description,
  &airsim_interfaces__msg__InstanceSegmentationList__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace airsim_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<airsim_interfaces::msg::InstanceSegmentationList>()
{
  return &::airsim_interfaces::msg::rosidl_typesupport_introspection_cpp::InstanceSegmentationList_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, airsim_interfaces, msg, InstanceSegmentationList)() {
  return &::airsim_interfaces::msg::rosidl_typesupport_introspection_cpp::InstanceSegmentationList_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

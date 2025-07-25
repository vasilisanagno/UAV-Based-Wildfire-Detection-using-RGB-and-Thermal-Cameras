// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from airsim_interfaces:msg/VelCmdGroup.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "airsim_interfaces/msg/detail/vel_cmd_group__rosidl_typesupport_introspection_c.h"
#include "airsim_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "airsim_interfaces/msg/detail/vel_cmd_group__functions.h"
#include "airsim_interfaces/msg/detail/vel_cmd_group__struct.h"


// Include directives for member types
// Member `vel_cmd`
#include "airsim_interfaces/msg/vel_cmd.h"
// Member `vel_cmd`
#include "airsim_interfaces/msg/detail/vel_cmd__rosidl_typesupport_introspection_c.h"
// Member `vehicle_names`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void airsim_interfaces__msg__VelCmdGroup__rosidl_typesupport_introspection_c__VelCmdGroup_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  airsim_interfaces__msg__VelCmdGroup__init(message_memory);
}

void airsim_interfaces__msg__VelCmdGroup__rosidl_typesupport_introspection_c__VelCmdGroup_fini_function(void * message_memory)
{
  airsim_interfaces__msg__VelCmdGroup__fini(message_memory);
}

size_t airsim_interfaces__msg__VelCmdGroup__rosidl_typesupport_introspection_c__size_function__VelCmdGroup__vehicle_names(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * airsim_interfaces__msg__VelCmdGroup__rosidl_typesupport_introspection_c__get_const_function__VelCmdGroup__vehicle_names(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * airsim_interfaces__msg__VelCmdGroup__rosidl_typesupport_introspection_c__get_function__VelCmdGroup__vehicle_names(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void airsim_interfaces__msg__VelCmdGroup__rosidl_typesupport_introspection_c__fetch_function__VelCmdGroup__vehicle_names(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    airsim_interfaces__msg__VelCmdGroup__rosidl_typesupport_introspection_c__get_const_function__VelCmdGroup__vehicle_names(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void airsim_interfaces__msg__VelCmdGroup__rosidl_typesupport_introspection_c__assign_function__VelCmdGroup__vehicle_names(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    airsim_interfaces__msg__VelCmdGroup__rosidl_typesupport_introspection_c__get_function__VelCmdGroup__vehicle_names(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool airsim_interfaces__msg__VelCmdGroup__rosidl_typesupport_introspection_c__resize_function__VelCmdGroup__vehicle_names(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember airsim_interfaces__msg__VelCmdGroup__rosidl_typesupport_introspection_c__VelCmdGroup_message_member_array[2] = {
  {
    "vel_cmd",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(airsim_interfaces__msg__VelCmdGroup, vel_cmd),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vehicle_names",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(airsim_interfaces__msg__VelCmdGroup, vehicle_names),  // bytes offset in struct
    NULL,  // default value
    airsim_interfaces__msg__VelCmdGroup__rosidl_typesupport_introspection_c__size_function__VelCmdGroup__vehicle_names,  // size() function pointer
    airsim_interfaces__msg__VelCmdGroup__rosidl_typesupport_introspection_c__get_const_function__VelCmdGroup__vehicle_names,  // get_const(index) function pointer
    airsim_interfaces__msg__VelCmdGroup__rosidl_typesupport_introspection_c__get_function__VelCmdGroup__vehicle_names,  // get(index) function pointer
    airsim_interfaces__msg__VelCmdGroup__rosidl_typesupport_introspection_c__fetch_function__VelCmdGroup__vehicle_names,  // fetch(index, &value) function pointer
    airsim_interfaces__msg__VelCmdGroup__rosidl_typesupport_introspection_c__assign_function__VelCmdGroup__vehicle_names,  // assign(index, value) function pointer
    airsim_interfaces__msg__VelCmdGroup__rosidl_typesupport_introspection_c__resize_function__VelCmdGroup__vehicle_names  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers airsim_interfaces__msg__VelCmdGroup__rosidl_typesupport_introspection_c__VelCmdGroup_message_members = {
  "airsim_interfaces__msg",  // message namespace
  "VelCmdGroup",  // message name
  2,  // number of fields
  sizeof(airsim_interfaces__msg__VelCmdGroup),
  airsim_interfaces__msg__VelCmdGroup__rosidl_typesupport_introspection_c__VelCmdGroup_message_member_array,  // message members
  airsim_interfaces__msg__VelCmdGroup__rosidl_typesupport_introspection_c__VelCmdGroup_init_function,  // function to initialize message memory (memory has to be allocated)
  airsim_interfaces__msg__VelCmdGroup__rosidl_typesupport_introspection_c__VelCmdGroup_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t airsim_interfaces__msg__VelCmdGroup__rosidl_typesupport_introspection_c__VelCmdGroup_message_type_support_handle = {
  0,
  &airsim_interfaces__msg__VelCmdGroup__rosidl_typesupport_introspection_c__VelCmdGroup_message_members,
  get_message_typesupport_handle_function,
  &airsim_interfaces__msg__VelCmdGroup__get_type_hash,
  &airsim_interfaces__msg__VelCmdGroup__get_type_description,
  &airsim_interfaces__msg__VelCmdGroup__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_airsim_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, airsim_interfaces, msg, VelCmdGroup)() {
  airsim_interfaces__msg__VelCmdGroup__rosidl_typesupport_introspection_c__VelCmdGroup_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, airsim_interfaces, msg, VelCmd)();
  if (!airsim_interfaces__msg__VelCmdGroup__rosidl_typesupport_introspection_c__VelCmdGroup_message_type_support_handle.typesupport_identifier) {
    airsim_interfaces__msg__VelCmdGroup__rosidl_typesupport_introspection_c__VelCmdGroup_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &airsim_interfaces__msg__VelCmdGroup__rosidl_typesupport_introspection_c__VelCmdGroup_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

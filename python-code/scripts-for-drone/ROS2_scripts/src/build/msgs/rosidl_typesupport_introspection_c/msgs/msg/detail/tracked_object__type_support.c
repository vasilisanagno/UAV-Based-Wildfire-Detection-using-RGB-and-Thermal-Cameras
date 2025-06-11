// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from msgs:msg/TrackedObject.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "msgs/msg/detail/tracked_object__rosidl_typesupport_introspection_c.h"
#include "msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "msgs/msg/detail/tracked_object__functions.h"
#include "msgs/msg/detail/tracked_object__struct.h"


// Include directives for member types
// Member `label`
// Member `source`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void msgs__msg__TrackedObject__rosidl_typesupport_introspection_c__TrackedObject_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  msgs__msg__TrackedObject__init(message_memory);
}

void msgs__msg__TrackedObject__rosidl_typesupport_introspection_c__TrackedObject_fini_function(void * message_memory)
{
  msgs__msg__TrackedObject__fini(message_memory);
}

size_t msgs__msg__TrackedObject__rosidl_typesupport_introspection_c__size_function__TrackedObject__box(
  const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * msgs__msg__TrackedObject__rosidl_typesupport_introspection_c__get_const_function__TrackedObject__box(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * msgs__msg__TrackedObject__rosidl_typesupport_introspection_c__get_function__TrackedObject__box(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void msgs__msg__TrackedObject__rosidl_typesupport_introspection_c__fetch_function__TrackedObject__box(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    msgs__msg__TrackedObject__rosidl_typesupport_introspection_c__get_const_function__TrackedObject__box(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void msgs__msg__TrackedObject__rosidl_typesupport_introspection_c__assign_function__TrackedObject__box(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    msgs__msg__TrackedObject__rosidl_typesupport_introspection_c__get_function__TrackedObject__box(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember msgs__msg__TrackedObject__rosidl_typesupport_introspection_c__TrackedObject_message_member_array[5] = {
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs__msg__TrackedObject, id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "label",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs__msg__TrackedObject, label),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "confidence",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs__msg__TrackedObject, confidence),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "box",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(msgs__msg__TrackedObject, box),  // bytes offset in struct
    NULL,  // default value
    msgs__msg__TrackedObject__rosidl_typesupport_introspection_c__size_function__TrackedObject__box,  // size() function pointer
    msgs__msg__TrackedObject__rosidl_typesupport_introspection_c__get_const_function__TrackedObject__box,  // get_const(index) function pointer
    msgs__msg__TrackedObject__rosidl_typesupport_introspection_c__get_function__TrackedObject__box,  // get(index) function pointer
    msgs__msg__TrackedObject__rosidl_typesupport_introspection_c__fetch_function__TrackedObject__box,  // fetch(index, &value) function pointer
    msgs__msg__TrackedObject__rosidl_typesupport_introspection_c__assign_function__TrackedObject__box,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "source",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs__msg__TrackedObject, source),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers msgs__msg__TrackedObject__rosidl_typesupport_introspection_c__TrackedObject_message_members = {
  "msgs__msg",  // message namespace
  "TrackedObject",  // message name
  5,  // number of fields
  sizeof(msgs__msg__TrackedObject),
  msgs__msg__TrackedObject__rosidl_typesupport_introspection_c__TrackedObject_message_member_array,  // message members
  msgs__msg__TrackedObject__rosidl_typesupport_introspection_c__TrackedObject_init_function,  // function to initialize message memory (memory has to be allocated)
  msgs__msg__TrackedObject__rosidl_typesupport_introspection_c__TrackedObject_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t msgs__msg__TrackedObject__rosidl_typesupport_introspection_c__TrackedObject_message_type_support_handle = {
  0,
  &msgs__msg__TrackedObject__rosidl_typesupport_introspection_c__TrackedObject_message_members,
  get_message_typesupport_handle_function,
  &msgs__msg__TrackedObject__get_type_hash,
  &msgs__msg__TrackedObject__get_type_description,
  &msgs__msg__TrackedObject__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, msgs, msg, TrackedObject)() {
  if (!msgs__msg__TrackedObject__rosidl_typesupport_introspection_c__TrackedObject_message_type_support_handle.typesupport_identifier) {
    msgs__msg__TrackedObject__rosidl_typesupport_introspection_c__TrackedObject_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &msgs__msg__TrackedObject__rosidl_typesupport_introspection_c__TrackedObject_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

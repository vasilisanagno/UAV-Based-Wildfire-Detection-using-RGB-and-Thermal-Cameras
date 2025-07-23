// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from msgs:msg/DetectionWithGPS.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "msgs/msg/detail/detection_with_gps__rosidl_typesupport_introspection_c.h"
#include "msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "msgs/msg/detail/detection_with_gps__functions.h"
#include "msgs/msg/detail/detection_with_gps__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `labels`
#include "rosidl_runtime_c/string_functions.h"
// Member `confidences`
// Member `boxes`
// Member `tracking_ids`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `gps`
#include "sensor_msgs/msg/nav_sat_fix.h"
// Member `gps`
#include "sensor_msgs/msg/detail/nav_sat_fix__rosidl_typesupport_introspection_c.h"
// Member `image`
#include "sensor_msgs/msg/image.h"
// Member `image`
#include "sensor_msgs/msg/detail/image__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__DetectionWithGPS_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  msgs__msg__DetectionWithGPS__init(message_memory);
}

void msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__DetectionWithGPS_fini_function(void * message_memory)
{
  msgs__msg__DetectionWithGPS__fini(message_memory);
}

size_t msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__size_function__DetectionWithGPS__labels(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__get_const_function__DetectionWithGPS__labels(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__get_function__DetectionWithGPS__labels(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__fetch_function__DetectionWithGPS__labels(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__get_const_function__DetectionWithGPS__labels(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__assign_function__DetectionWithGPS__labels(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__get_function__DetectionWithGPS__labels(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__resize_function__DetectionWithGPS__labels(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

size_t msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__size_function__DetectionWithGPS__confidences(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__get_const_function__DetectionWithGPS__confidences(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__get_function__DetectionWithGPS__confidences(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__fetch_function__DetectionWithGPS__confidences(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__get_const_function__DetectionWithGPS__confidences(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__assign_function__DetectionWithGPS__confidences(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__get_function__DetectionWithGPS__confidences(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__resize_function__DetectionWithGPS__confidences(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__size_function__DetectionWithGPS__boxes(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__get_const_function__DetectionWithGPS__boxes(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__get_function__DetectionWithGPS__boxes(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__fetch_function__DetectionWithGPS__boxes(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__get_const_function__DetectionWithGPS__boxes(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__assign_function__DetectionWithGPS__boxes(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__get_function__DetectionWithGPS__boxes(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__resize_function__DetectionWithGPS__boxes(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__size_function__DetectionWithGPS__tracking_ids(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__get_const_function__DetectionWithGPS__tracking_ids(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__get_function__DetectionWithGPS__tracking_ids(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__fetch_function__DetectionWithGPS__tracking_ids(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__get_const_function__DetectionWithGPS__tracking_ids(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__assign_function__DetectionWithGPS__tracking_ids(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__get_function__DetectionWithGPS__tracking_ids(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__resize_function__DetectionWithGPS__tracking_ids(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__DetectionWithGPS_message_member_array[7] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs__msg__DetectionWithGPS, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "labels",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs__msg__DetectionWithGPS, labels),  // bytes offset in struct
    NULL,  // default value
    msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__size_function__DetectionWithGPS__labels,  // size() function pointer
    msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__get_const_function__DetectionWithGPS__labels,  // get_const(index) function pointer
    msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__get_function__DetectionWithGPS__labels,  // get(index) function pointer
    msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__fetch_function__DetectionWithGPS__labels,  // fetch(index, &value) function pointer
    msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__assign_function__DetectionWithGPS__labels,  // assign(index, value) function pointer
    msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__resize_function__DetectionWithGPS__labels  // resize(index) function pointer
  },
  {
    "confidences",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs__msg__DetectionWithGPS, confidences),  // bytes offset in struct
    NULL,  // default value
    msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__size_function__DetectionWithGPS__confidences,  // size() function pointer
    msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__get_const_function__DetectionWithGPS__confidences,  // get_const(index) function pointer
    msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__get_function__DetectionWithGPS__confidences,  // get(index) function pointer
    msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__fetch_function__DetectionWithGPS__confidences,  // fetch(index, &value) function pointer
    msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__assign_function__DetectionWithGPS__confidences,  // assign(index, value) function pointer
    msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__resize_function__DetectionWithGPS__confidences  // resize(index) function pointer
  },
  {
    "boxes",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs__msg__DetectionWithGPS, boxes),  // bytes offset in struct
    NULL,  // default value
    msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__size_function__DetectionWithGPS__boxes,  // size() function pointer
    msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__get_const_function__DetectionWithGPS__boxes,  // get_const(index) function pointer
    msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__get_function__DetectionWithGPS__boxes,  // get(index) function pointer
    msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__fetch_function__DetectionWithGPS__boxes,  // fetch(index, &value) function pointer
    msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__assign_function__DetectionWithGPS__boxes,  // assign(index, value) function pointer
    msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__resize_function__DetectionWithGPS__boxes  // resize(index) function pointer
  },
  {
    "tracking_ids",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs__msg__DetectionWithGPS, tracking_ids),  // bytes offset in struct
    NULL,  // default value
    msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__size_function__DetectionWithGPS__tracking_ids,  // size() function pointer
    msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__get_const_function__DetectionWithGPS__tracking_ids,  // get_const(index) function pointer
    msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__get_function__DetectionWithGPS__tracking_ids,  // get(index) function pointer
    msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__fetch_function__DetectionWithGPS__tracking_ids,  // fetch(index, &value) function pointer
    msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__assign_function__DetectionWithGPS__tracking_ids,  // assign(index, value) function pointer
    msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__resize_function__DetectionWithGPS__tracking_ids  // resize(index) function pointer
  },
  {
    "gps",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs__msg__DetectionWithGPS, gps),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "image",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs__msg__DetectionWithGPS, image),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__DetectionWithGPS_message_members = {
  "msgs__msg",  // message namespace
  "DetectionWithGPS",  // message name
  7,  // number of fields
  sizeof(msgs__msg__DetectionWithGPS),
  msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__DetectionWithGPS_message_member_array,  // message members
  msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__DetectionWithGPS_init_function,  // function to initialize message memory (memory has to be allocated)
  msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__DetectionWithGPS_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__DetectionWithGPS_message_type_support_handle = {
  0,
  &msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__DetectionWithGPS_message_members,
  get_message_typesupport_handle_function,
  &msgs__msg__DetectionWithGPS__get_type_hash,
  &msgs__msg__DetectionWithGPS__get_type_description,
  &msgs__msg__DetectionWithGPS__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, msgs, msg, DetectionWithGPS)() {
  msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__DetectionWithGPS_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__DetectionWithGPS_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, NavSatFix)();
  msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__DetectionWithGPS_message_member_array[6].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, Image)();
  if (!msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__DetectionWithGPS_message_type_support_handle.typesupport_identifier) {
    msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__DetectionWithGPS_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &msgs__msg__DetectionWithGPS__rosidl_typesupport_introspection_c__DetectionWithGPS_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

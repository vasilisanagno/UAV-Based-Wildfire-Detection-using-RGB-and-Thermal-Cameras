// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from msgs:msg/SensorData.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "msgs/msg/detail/sensor_data__rosidl_typesupport_introspection_c.h"
#include "msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "msgs/msg/detail/sensor_data__functions.h"
#include "msgs/msg/detail/sensor_data__struct.h"


// Include directives for member types
// Member `rgb_image`
// Member `thermal_image`
#include "sensor_msgs/msg/image.h"
// Member `rgb_image`
// Member `thermal_image`
#include "sensor_msgs/msg/detail/image__rosidl_typesupport_introspection_c.h"
// Member `gps`
#include "sensor_msgs/msg/nav_sat_fix.h"
// Member `gps`
#include "sensor_msgs/msg/detail/nav_sat_fix__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void msgs__msg__SensorData__rosidl_typesupport_introspection_c__SensorData_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  msgs__msg__SensorData__init(message_memory);
}

void msgs__msg__SensorData__rosidl_typesupport_introspection_c__SensorData_fini_function(void * message_memory)
{
  msgs__msg__SensorData__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember msgs__msg__SensorData__rosidl_typesupport_introspection_c__SensorData_message_member_array[3] = {
  {
    "rgb_image",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs__msg__SensorData, rgb_image),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "thermal_image",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs__msg__SensorData, thermal_image),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "gps",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs__msg__SensorData, gps),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers msgs__msg__SensorData__rosidl_typesupport_introspection_c__SensorData_message_members = {
  "msgs__msg",  // message namespace
  "SensorData",  // message name
  3,  // number of fields
  sizeof(msgs__msg__SensorData),
  msgs__msg__SensorData__rosidl_typesupport_introspection_c__SensorData_message_member_array,  // message members
  msgs__msg__SensorData__rosidl_typesupport_introspection_c__SensorData_init_function,  // function to initialize message memory (memory has to be allocated)
  msgs__msg__SensorData__rosidl_typesupport_introspection_c__SensorData_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t msgs__msg__SensorData__rosidl_typesupport_introspection_c__SensorData_message_type_support_handle = {
  0,
  &msgs__msg__SensorData__rosidl_typesupport_introspection_c__SensorData_message_members,
  get_message_typesupport_handle_function,
  &msgs__msg__SensorData__get_type_hash,
  &msgs__msg__SensorData__get_type_description,
  &msgs__msg__SensorData__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, msgs, msg, SensorData)() {
  msgs__msg__SensorData__rosidl_typesupport_introspection_c__SensorData_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, Image)();
  msgs__msg__SensorData__rosidl_typesupport_introspection_c__SensorData_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, Image)();
  msgs__msg__SensorData__rosidl_typesupport_introspection_c__SensorData_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, NavSatFix)();
  if (!msgs__msg__SensorData__rosidl_typesupport_introspection_c__SensorData_message_type_support_handle.typesupport_identifier) {
    msgs__msg__SensorData__rosidl_typesupport_introspection_c__SensorData_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &msgs__msg__SensorData__rosidl_typesupport_introspection_c__SensorData_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

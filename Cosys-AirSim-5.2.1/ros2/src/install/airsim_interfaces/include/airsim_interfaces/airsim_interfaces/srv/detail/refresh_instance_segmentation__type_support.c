// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from airsim_interfaces:srv/RefreshInstanceSegmentation.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "airsim_interfaces/srv/detail/refresh_instance_segmentation__rosidl_typesupport_introspection_c.h"
#include "airsim_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "airsim_interfaces/srv/detail/refresh_instance_segmentation__functions.h"
#include "airsim_interfaces/srv/detail/refresh_instance_segmentation__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void airsim_interfaces__srv__RefreshInstanceSegmentation_Request__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  airsim_interfaces__srv__RefreshInstanceSegmentation_Request__init(message_memory);
}

void airsim_interfaces__srv__RefreshInstanceSegmentation_Request__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Request_fini_function(void * message_memory)
{
  airsim_interfaces__srv__RefreshInstanceSegmentation_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember airsim_interfaces__srv__RefreshInstanceSegmentation_Request__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Request_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(airsim_interfaces__srv__RefreshInstanceSegmentation_Request, structure_needs_at_least_one_member),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers airsim_interfaces__srv__RefreshInstanceSegmentation_Request__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Request_message_members = {
  "airsim_interfaces__srv",  // message namespace
  "RefreshInstanceSegmentation_Request",  // message name
  1,  // number of fields
  sizeof(airsim_interfaces__srv__RefreshInstanceSegmentation_Request),
  airsim_interfaces__srv__RefreshInstanceSegmentation_Request__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Request_message_member_array,  // message members
  airsim_interfaces__srv__RefreshInstanceSegmentation_Request__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  airsim_interfaces__srv__RefreshInstanceSegmentation_Request__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t airsim_interfaces__srv__RefreshInstanceSegmentation_Request__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Request_message_type_support_handle = {
  0,
  &airsim_interfaces__srv__RefreshInstanceSegmentation_Request__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Request_message_members,
  get_message_typesupport_handle_function,
  &airsim_interfaces__srv__RefreshInstanceSegmentation_Request__get_type_hash,
  &airsim_interfaces__srv__RefreshInstanceSegmentation_Request__get_type_description,
  &airsim_interfaces__srv__RefreshInstanceSegmentation_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_airsim_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, airsim_interfaces, srv, RefreshInstanceSegmentation_Request)() {
  if (!airsim_interfaces__srv__RefreshInstanceSegmentation_Request__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Request_message_type_support_handle.typesupport_identifier) {
    airsim_interfaces__srv__RefreshInstanceSegmentation_Request__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &airsim_interfaces__srv__RefreshInstanceSegmentation_Request__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "airsim_interfaces/srv/detail/refresh_instance_segmentation__rosidl_typesupport_introspection_c.h"
// already included above
// #include "airsim_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "airsim_interfaces/srv/detail/refresh_instance_segmentation__functions.h"
// already included above
// #include "airsim_interfaces/srv/detail/refresh_instance_segmentation__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void airsim_interfaces__srv__RefreshInstanceSegmentation_Response__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  airsim_interfaces__srv__RefreshInstanceSegmentation_Response__init(message_memory);
}

void airsim_interfaces__srv__RefreshInstanceSegmentation_Response__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Response_fini_function(void * message_memory)
{
  airsim_interfaces__srv__RefreshInstanceSegmentation_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember airsim_interfaces__srv__RefreshInstanceSegmentation_Response__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Response_message_member_array[1] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(airsim_interfaces__srv__RefreshInstanceSegmentation_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers airsim_interfaces__srv__RefreshInstanceSegmentation_Response__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Response_message_members = {
  "airsim_interfaces__srv",  // message namespace
  "RefreshInstanceSegmentation_Response",  // message name
  1,  // number of fields
  sizeof(airsim_interfaces__srv__RefreshInstanceSegmentation_Response),
  airsim_interfaces__srv__RefreshInstanceSegmentation_Response__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Response_message_member_array,  // message members
  airsim_interfaces__srv__RefreshInstanceSegmentation_Response__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  airsim_interfaces__srv__RefreshInstanceSegmentation_Response__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t airsim_interfaces__srv__RefreshInstanceSegmentation_Response__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Response_message_type_support_handle = {
  0,
  &airsim_interfaces__srv__RefreshInstanceSegmentation_Response__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Response_message_members,
  get_message_typesupport_handle_function,
  &airsim_interfaces__srv__RefreshInstanceSegmentation_Response__get_type_hash,
  &airsim_interfaces__srv__RefreshInstanceSegmentation_Response__get_type_description,
  &airsim_interfaces__srv__RefreshInstanceSegmentation_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_airsim_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, airsim_interfaces, srv, RefreshInstanceSegmentation_Response)() {
  if (!airsim_interfaces__srv__RefreshInstanceSegmentation_Response__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Response_message_type_support_handle.typesupport_identifier) {
    airsim_interfaces__srv__RefreshInstanceSegmentation_Response__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &airsim_interfaces__srv__RefreshInstanceSegmentation_Response__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "airsim_interfaces/srv/detail/refresh_instance_segmentation__rosidl_typesupport_introspection_c.h"
// already included above
// #include "airsim_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "airsim_interfaces/srv/detail/refresh_instance_segmentation__functions.h"
// already included above
// #include "airsim_interfaces/srv/detail/refresh_instance_segmentation__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "airsim_interfaces/srv/refresh_instance_segmentation.h"
// Member `request`
// Member `response`
// already included above
// #include "airsim_interfaces/srv/detail/refresh_instance_segmentation__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  airsim_interfaces__srv__RefreshInstanceSegmentation_Event__init(message_memory);
}

void airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Event_fini_function(void * message_memory)
{
  airsim_interfaces__srv__RefreshInstanceSegmentation_Event__fini(message_memory);
}

size_t airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__size_function__RefreshInstanceSegmentation_Event__request(
  const void * untyped_member)
{
  const airsim_interfaces__srv__RefreshInstanceSegmentation_Request__Sequence * member =
    (const airsim_interfaces__srv__RefreshInstanceSegmentation_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__get_const_function__RefreshInstanceSegmentation_Event__request(
  const void * untyped_member, size_t index)
{
  const airsim_interfaces__srv__RefreshInstanceSegmentation_Request__Sequence * member =
    (const airsim_interfaces__srv__RefreshInstanceSegmentation_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__get_function__RefreshInstanceSegmentation_Event__request(
  void * untyped_member, size_t index)
{
  airsim_interfaces__srv__RefreshInstanceSegmentation_Request__Sequence * member =
    (airsim_interfaces__srv__RefreshInstanceSegmentation_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__fetch_function__RefreshInstanceSegmentation_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const airsim_interfaces__srv__RefreshInstanceSegmentation_Request * item =
    ((const airsim_interfaces__srv__RefreshInstanceSegmentation_Request *)
    airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__get_const_function__RefreshInstanceSegmentation_Event__request(untyped_member, index));
  airsim_interfaces__srv__RefreshInstanceSegmentation_Request * value =
    (airsim_interfaces__srv__RefreshInstanceSegmentation_Request *)(untyped_value);
  *value = *item;
}

void airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__assign_function__RefreshInstanceSegmentation_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  airsim_interfaces__srv__RefreshInstanceSegmentation_Request * item =
    ((airsim_interfaces__srv__RefreshInstanceSegmentation_Request *)
    airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__get_function__RefreshInstanceSegmentation_Event__request(untyped_member, index));
  const airsim_interfaces__srv__RefreshInstanceSegmentation_Request * value =
    (const airsim_interfaces__srv__RefreshInstanceSegmentation_Request *)(untyped_value);
  *item = *value;
}

bool airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__resize_function__RefreshInstanceSegmentation_Event__request(
  void * untyped_member, size_t size)
{
  airsim_interfaces__srv__RefreshInstanceSegmentation_Request__Sequence * member =
    (airsim_interfaces__srv__RefreshInstanceSegmentation_Request__Sequence *)(untyped_member);
  airsim_interfaces__srv__RefreshInstanceSegmentation_Request__Sequence__fini(member);
  return airsim_interfaces__srv__RefreshInstanceSegmentation_Request__Sequence__init(member, size);
}

size_t airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__size_function__RefreshInstanceSegmentation_Event__response(
  const void * untyped_member)
{
  const airsim_interfaces__srv__RefreshInstanceSegmentation_Response__Sequence * member =
    (const airsim_interfaces__srv__RefreshInstanceSegmentation_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__get_const_function__RefreshInstanceSegmentation_Event__response(
  const void * untyped_member, size_t index)
{
  const airsim_interfaces__srv__RefreshInstanceSegmentation_Response__Sequence * member =
    (const airsim_interfaces__srv__RefreshInstanceSegmentation_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__get_function__RefreshInstanceSegmentation_Event__response(
  void * untyped_member, size_t index)
{
  airsim_interfaces__srv__RefreshInstanceSegmentation_Response__Sequence * member =
    (airsim_interfaces__srv__RefreshInstanceSegmentation_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__fetch_function__RefreshInstanceSegmentation_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const airsim_interfaces__srv__RefreshInstanceSegmentation_Response * item =
    ((const airsim_interfaces__srv__RefreshInstanceSegmentation_Response *)
    airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__get_const_function__RefreshInstanceSegmentation_Event__response(untyped_member, index));
  airsim_interfaces__srv__RefreshInstanceSegmentation_Response * value =
    (airsim_interfaces__srv__RefreshInstanceSegmentation_Response *)(untyped_value);
  *value = *item;
}

void airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__assign_function__RefreshInstanceSegmentation_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  airsim_interfaces__srv__RefreshInstanceSegmentation_Response * item =
    ((airsim_interfaces__srv__RefreshInstanceSegmentation_Response *)
    airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__get_function__RefreshInstanceSegmentation_Event__response(untyped_member, index));
  const airsim_interfaces__srv__RefreshInstanceSegmentation_Response * value =
    (const airsim_interfaces__srv__RefreshInstanceSegmentation_Response *)(untyped_value);
  *item = *value;
}

bool airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__resize_function__RefreshInstanceSegmentation_Event__response(
  void * untyped_member, size_t size)
{
  airsim_interfaces__srv__RefreshInstanceSegmentation_Response__Sequence * member =
    (airsim_interfaces__srv__RefreshInstanceSegmentation_Response__Sequence *)(untyped_member);
  airsim_interfaces__srv__RefreshInstanceSegmentation_Response__Sequence__fini(member);
  return airsim_interfaces__srv__RefreshInstanceSegmentation_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(airsim_interfaces__srv__RefreshInstanceSegmentation_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(airsim_interfaces__srv__RefreshInstanceSegmentation_Event, request),  // bytes offset in struct
    NULL,  // default value
    airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__size_function__RefreshInstanceSegmentation_Event__request,  // size() function pointer
    airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__get_const_function__RefreshInstanceSegmentation_Event__request,  // get_const(index) function pointer
    airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__get_function__RefreshInstanceSegmentation_Event__request,  // get(index) function pointer
    airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__fetch_function__RefreshInstanceSegmentation_Event__request,  // fetch(index, &value) function pointer
    airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__assign_function__RefreshInstanceSegmentation_Event__request,  // assign(index, value) function pointer
    airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__resize_function__RefreshInstanceSegmentation_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(airsim_interfaces__srv__RefreshInstanceSegmentation_Event, response),  // bytes offset in struct
    NULL,  // default value
    airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__size_function__RefreshInstanceSegmentation_Event__response,  // size() function pointer
    airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__get_const_function__RefreshInstanceSegmentation_Event__response,  // get_const(index) function pointer
    airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__get_function__RefreshInstanceSegmentation_Event__response,  // get(index) function pointer
    airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__fetch_function__RefreshInstanceSegmentation_Event__response,  // fetch(index, &value) function pointer
    airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__assign_function__RefreshInstanceSegmentation_Event__response,  // assign(index, value) function pointer
    airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__resize_function__RefreshInstanceSegmentation_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Event_message_members = {
  "airsim_interfaces__srv",  // message namespace
  "RefreshInstanceSegmentation_Event",  // message name
  3,  // number of fields
  sizeof(airsim_interfaces__srv__RefreshInstanceSegmentation_Event),
  airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Event_message_member_array,  // message members
  airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Event_message_type_support_handle = {
  0,
  &airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Event_message_members,
  get_message_typesupport_handle_function,
  &airsim_interfaces__srv__RefreshInstanceSegmentation_Event__get_type_hash,
  &airsim_interfaces__srv__RefreshInstanceSegmentation_Event__get_type_description,
  &airsim_interfaces__srv__RefreshInstanceSegmentation_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_airsim_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, airsim_interfaces, srv, RefreshInstanceSegmentation_Event)() {
  airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, airsim_interfaces, srv, RefreshInstanceSegmentation_Request)();
  airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, airsim_interfaces, srv, RefreshInstanceSegmentation_Response)();
  if (!airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Event_message_type_support_handle.typesupport_identifier) {
    airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "airsim_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "airsim_interfaces/srv/detail/refresh_instance_segmentation__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers airsim_interfaces__srv__detail__refresh_instance_segmentation__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_service_members = {
  "airsim_interfaces__srv",  // service namespace
  "RefreshInstanceSegmentation",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // airsim_interfaces__srv__detail__refresh_instance_segmentation__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Request_message_type_support_handle,
  NULL,  // response message
  // airsim_interfaces__srv__detail__refresh_instance_segmentation__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Response_message_type_support_handle
  NULL  // event_message
  // airsim_interfaces__srv__detail__refresh_instance_segmentation__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Response_message_type_support_handle
};


static rosidl_service_type_support_t airsim_interfaces__srv__detail__refresh_instance_segmentation__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_service_type_support_handle = {
  0,
  &airsim_interfaces__srv__detail__refresh_instance_segmentation__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_service_members,
  get_service_typesupport_handle_function,
  &airsim_interfaces__srv__RefreshInstanceSegmentation_Request__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Request_message_type_support_handle,
  &airsim_interfaces__srv__RefreshInstanceSegmentation_Response__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Response_message_type_support_handle,
  &airsim_interfaces__srv__RefreshInstanceSegmentation_Event__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    airsim_interfaces,
    srv,
    RefreshInstanceSegmentation
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    airsim_interfaces,
    srv,
    RefreshInstanceSegmentation
  ),
  &airsim_interfaces__srv__RefreshInstanceSegmentation__get_type_hash,
  &airsim_interfaces__srv__RefreshInstanceSegmentation__get_type_description,
  &airsim_interfaces__srv__RefreshInstanceSegmentation__get_type_description_sources,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, airsim_interfaces, srv, RefreshInstanceSegmentation_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, airsim_interfaces, srv, RefreshInstanceSegmentation_Response)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, airsim_interfaces, srv, RefreshInstanceSegmentation_Event)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_airsim_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, airsim_interfaces, srv, RefreshInstanceSegmentation)() {
  if (!airsim_interfaces__srv__detail__refresh_instance_segmentation__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_service_type_support_handle.typesupport_identifier) {
    airsim_interfaces__srv__detail__refresh_instance_segmentation__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)airsim_interfaces__srv__detail__refresh_instance_segmentation__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, airsim_interfaces, srv, RefreshInstanceSegmentation_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, airsim_interfaces, srv, RefreshInstanceSegmentation_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, airsim_interfaces, srv, RefreshInstanceSegmentation_Event)()->data;
  }

  return &airsim_interfaces__srv__detail__refresh_instance_segmentation__rosidl_typesupport_introspection_c__RefreshInstanceSegmentation_service_type_support_handle;
}

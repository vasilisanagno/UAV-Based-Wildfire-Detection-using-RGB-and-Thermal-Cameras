// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from airsim_interfaces:srv/Takeoff.idl
// generated code does not contain a copyright notice

#ifndef AIRSIM_INTERFACES__SRV__DETAIL__TAKEOFF__STRUCT_H_
#define AIRSIM_INTERFACES__SRV__DETAIL__TAKEOFF__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/Takeoff in the package airsim_interfaces.
typedef struct airsim_interfaces__srv__Takeoff_Request
{
  bool wait_on_last_task;
} airsim_interfaces__srv__Takeoff_Request;

// Struct for a sequence of airsim_interfaces__srv__Takeoff_Request.
typedef struct airsim_interfaces__srv__Takeoff_Request__Sequence
{
  airsim_interfaces__srv__Takeoff_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} airsim_interfaces__srv__Takeoff_Request__Sequence;

// Constants defined in the message

/// Struct defined in srv/Takeoff in the package airsim_interfaces.
typedef struct airsim_interfaces__srv__Takeoff_Response
{
  bool success;
} airsim_interfaces__srv__Takeoff_Response;

// Struct for a sequence of airsim_interfaces__srv__Takeoff_Response.
typedef struct airsim_interfaces__srv__Takeoff_Response__Sequence
{
  airsim_interfaces__srv__Takeoff_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} airsim_interfaces__srv__Takeoff_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  airsim_interfaces__srv__Takeoff_Event__request__MAX_SIZE = 1
};
// response
enum
{
  airsim_interfaces__srv__Takeoff_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/Takeoff in the package airsim_interfaces.
typedef struct airsim_interfaces__srv__Takeoff_Event
{
  service_msgs__msg__ServiceEventInfo info;
  airsim_interfaces__srv__Takeoff_Request__Sequence request;
  airsim_interfaces__srv__Takeoff_Response__Sequence response;
} airsim_interfaces__srv__Takeoff_Event;

// Struct for a sequence of airsim_interfaces__srv__Takeoff_Event.
typedef struct airsim_interfaces__srv__Takeoff_Event__Sequence
{
  airsim_interfaces__srv__Takeoff_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} airsim_interfaces__srv__Takeoff_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AIRSIM_INTERFACES__SRV__DETAIL__TAKEOFF__STRUCT_H_

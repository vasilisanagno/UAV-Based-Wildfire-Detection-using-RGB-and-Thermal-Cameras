// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from airsim_interfaces:srv/SetGPSPosition.idl
// generated code does not contain a copyright notice

#include "airsim_interfaces/srv/detail/set_gps_position__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_type_hash_t *
airsim_interfaces__srv__SetGPSPosition__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x21, 0xe1, 0x5e, 0x00, 0xe7, 0xb0, 0xce, 0xe6,
      0x33, 0x37, 0x2c, 0x4a, 0x97, 0x85, 0xcf, 0xc7,
      0xa4, 0x84, 0xb6, 0x33, 0xab, 0x71, 0xf1, 0x07,
      0xe5, 0xc9, 0x8d, 0xfa, 0xe7, 0xb6, 0xbd, 0x69,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_type_hash_t *
airsim_interfaces__srv__SetGPSPosition_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x68, 0xe3, 0xbb, 0xd9, 0xea, 0x74, 0x2d, 0x67,
      0x8f, 0xf6, 0xf6, 0x2e, 0x3a, 0xc9, 0x4f, 0x33,
      0x5a, 0x6c, 0x83, 0x99, 0x10, 0x77, 0x0b, 0xc7,
      0x28, 0x7c, 0x93, 0xd8, 0x44, 0xce, 0x5f, 0xb9,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_type_hash_t *
airsim_interfaces__srv__SetGPSPosition_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xbf, 0x76, 0x51, 0x56, 0xf0, 0xbd, 0x07, 0xf3,
      0x27, 0xd5, 0x7d, 0xa2, 0x6c, 0xc7, 0xce, 0xc0,
      0x43, 0x7c, 0x2d, 0x89, 0xf2, 0xa9, 0x8f, 0x83,
      0xc4, 0xb2, 0xe7, 0x61, 0xf0, 0xf2, 0x5c, 0x73,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_type_hash_t *
airsim_interfaces__srv__SetGPSPosition_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x9d, 0x2b, 0x5d, 0x83, 0xc6, 0xe1, 0x74, 0x86,
      0xc3, 0xb7, 0xf6, 0x63, 0x52, 0xab, 0xb7, 0x5d,
      0xff, 0xa8, 0xaf, 0xe2, 0x2e, 0x48, 0xf3, 0x76,
      0x42, 0x6d, 0x6c, 0x86, 0x11, 0x9b, 0x04, 0xc4,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char airsim_interfaces__srv__SetGPSPosition__TYPE_NAME[] = "airsim_interfaces/srv/SetGPSPosition";
static char airsim_interfaces__srv__SetGPSPosition_Event__TYPE_NAME[] = "airsim_interfaces/srv/SetGPSPosition_Event";
static char airsim_interfaces__srv__SetGPSPosition_Request__TYPE_NAME[] = "airsim_interfaces/srv/SetGPSPosition_Request";
static char airsim_interfaces__srv__SetGPSPosition_Response__TYPE_NAME[] = "airsim_interfaces/srv/SetGPSPosition_Response";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char airsim_interfaces__srv__SetGPSPosition__FIELD_NAME__request_message[] = "request_message";
static char airsim_interfaces__srv__SetGPSPosition__FIELD_NAME__response_message[] = "response_message";
static char airsim_interfaces__srv__SetGPSPosition__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field airsim_interfaces__srv__SetGPSPosition__FIELDS[] = {
  {
    {airsim_interfaces__srv__SetGPSPosition__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {airsim_interfaces__srv__SetGPSPosition_Request__TYPE_NAME, 44, 44},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__SetGPSPosition__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {airsim_interfaces__srv__SetGPSPosition_Response__TYPE_NAME, 45, 45},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__SetGPSPosition__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {airsim_interfaces__srv__SetGPSPosition_Event__TYPE_NAME, 42, 42},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription airsim_interfaces__srv__SetGPSPosition__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {airsim_interfaces__srv__SetGPSPosition_Event__TYPE_NAME, 42, 42},
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__SetGPSPosition_Request__TYPE_NAME, 44, 44},
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__SetGPSPosition_Response__TYPE_NAME, 45, 45},
    {NULL, 0, 0},
  },
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
airsim_interfaces__srv__SetGPSPosition__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {airsim_interfaces__srv__SetGPSPosition__TYPE_NAME, 36, 36},
      {airsim_interfaces__srv__SetGPSPosition__FIELDS, 3, 3},
    },
    {airsim_interfaces__srv__SetGPSPosition__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    description.referenced_type_descriptions.data[0].fields = airsim_interfaces__srv__SetGPSPosition_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = airsim_interfaces__srv__SetGPSPosition_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = airsim_interfaces__srv__SetGPSPosition_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char airsim_interfaces__srv__SetGPSPosition_Request__FIELD_NAME__latitude[] = "latitude";
static char airsim_interfaces__srv__SetGPSPosition_Request__FIELD_NAME__longitude[] = "longitude";
static char airsim_interfaces__srv__SetGPSPosition_Request__FIELD_NAME__altitude[] = "altitude";
static char airsim_interfaces__srv__SetGPSPosition_Request__FIELD_NAME__yaw[] = "yaw";
static char airsim_interfaces__srv__SetGPSPosition_Request__FIELD_NAME__vehicle_name[] = "vehicle_name";

static rosidl_runtime_c__type_description__Field airsim_interfaces__srv__SetGPSPosition_Request__FIELDS[] = {
  {
    {airsim_interfaces__srv__SetGPSPosition_Request__FIELD_NAME__latitude, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__SetGPSPosition_Request__FIELD_NAME__longitude, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__SetGPSPosition_Request__FIELD_NAME__altitude, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__SetGPSPosition_Request__FIELD_NAME__yaw, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__SetGPSPosition_Request__FIELD_NAME__vehicle_name, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
airsim_interfaces__srv__SetGPSPosition_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {airsim_interfaces__srv__SetGPSPosition_Request__TYPE_NAME, 44, 44},
      {airsim_interfaces__srv__SetGPSPosition_Request__FIELDS, 5, 5},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char airsim_interfaces__srv__SetGPSPosition_Response__FIELD_NAME__success[] = "success";

static rosidl_runtime_c__type_description__Field airsim_interfaces__srv__SetGPSPosition_Response__FIELDS[] = {
  {
    {airsim_interfaces__srv__SetGPSPosition_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
airsim_interfaces__srv__SetGPSPosition_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {airsim_interfaces__srv__SetGPSPosition_Response__TYPE_NAME, 45, 45},
      {airsim_interfaces__srv__SetGPSPosition_Response__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char airsim_interfaces__srv__SetGPSPosition_Event__FIELD_NAME__info[] = "info";
static char airsim_interfaces__srv__SetGPSPosition_Event__FIELD_NAME__request[] = "request";
static char airsim_interfaces__srv__SetGPSPosition_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field airsim_interfaces__srv__SetGPSPosition_Event__FIELDS[] = {
  {
    {airsim_interfaces__srv__SetGPSPosition_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__SetGPSPosition_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {airsim_interfaces__srv__SetGPSPosition_Request__TYPE_NAME, 44, 44},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__SetGPSPosition_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {airsim_interfaces__srv__SetGPSPosition_Response__TYPE_NAME, 45, 45},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription airsim_interfaces__srv__SetGPSPosition_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {airsim_interfaces__srv__SetGPSPosition_Request__TYPE_NAME, 44, 44},
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__SetGPSPosition_Response__TYPE_NAME, 45, 45},
    {NULL, 0, 0},
  },
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
airsim_interfaces__srv__SetGPSPosition_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {airsim_interfaces__srv__SetGPSPosition_Event__TYPE_NAME, 42, 42},
      {airsim_interfaces__srv__SetGPSPosition_Event__FIELDS, 3, 3},
    },
    {airsim_interfaces__srv__SetGPSPosition_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    description.referenced_type_descriptions.data[0].fields = airsim_interfaces__srv__SetGPSPosition_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = airsim_interfaces__srv__SetGPSPosition_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float64 latitude\n"
  "float64 longitude\n"
  "float64 altitude\n"
  "float64 yaw\n"
  "string vehicle_name\n"
  "---\n"
  "#Response : return success=true, (if async=false && if setpoint reached before timeout = 30sec) || (if async=true && command sent to autopilot)\n"
  "bool success";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
airsim_interfaces__srv__SetGPSPosition__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {airsim_interfaces__srv__SetGPSPosition__TYPE_NAME, 36, 36},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 244, 244},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
airsim_interfaces__srv__SetGPSPosition_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {airsim_interfaces__srv__SetGPSPosition_Request__TYPE_NAME, 44, 44},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
airsim_interfaces__srv__SetGPSPosition_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {airsim_interfaces__srv__SetGPSPosition_Response__TYPE_NAME, 45, 45},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
airsim_interfaces__srv__SetGPSPosition_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {airsim_interfaces__srv__SetGPSPosition_Event__TYPE_NAME, 42, 42},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
airsim_interfaces__srv__SetGPSPosition__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *airsim_interfaces__srv__SetGPSPosition__get_individual_type_description_source(NULL),
    sources[1] = *airsim_interfaces__srv__SetGPSPosition_Event__get_individual_type_description_source(NULL);
    sources[2] = *airsim_interfaces__srv__SetGPSPosition_Request__get_individual_type_description_source(NULL);
    sources[3] = *airsim_interfaces__srv__SetGPSPosition_Response__get_individual_type_description_source(NULL);
    sources[4] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
airsim_interfaces__srv__SetGPSPosition_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *airsim_interfaces__srv__SetGPSPosition_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
airsim_interfaces__srv__SetGPSPosition_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *airsim_interfaces__srv__SetGPSPosition_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
airsim_interfaces__srv__SetGPSPosition_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *airsim_interfaces__srv__SetGPSPosition_Event__get_individual_type_description_source(NULL),
    sources[1] = *airsim_interfaces__srv__SetGPSPosition_Request__get_individual_type_description_source(NULL);
    sources[2] = *airsim_interfaces__srv__SetGPSPosition_Response__get_individual_type_description_source(NULL);
    sources[3] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

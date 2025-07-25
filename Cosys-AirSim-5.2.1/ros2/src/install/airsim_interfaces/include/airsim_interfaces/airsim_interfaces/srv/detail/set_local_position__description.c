// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from airsim_interfaces:srv/SetLocalPosition.idl
// generated code does not contain a copyright notice

#include "airsim_interfaces/srv/detail/set_local_position__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_type_hash_t *
airsim_interfaces__srv__SetLocalPosition__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x7c, 0x3f, 0xbb, 0x14, 0xbd, 0xbf, 0xff, 0x1f,
      0x07, 0x52, 0x60, 0x49, 0xbb, 0x2e, 0x07, 0xea,
      0xcc, 0xe2, 0x12, 0xc0, 0x5a, 0x0e, 0xba, 0x31,
      0xfd, 0x57, 0xd1, 0xc2, 0x3b, 0x34, 0x03, 0x9d,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_type_hash_t *
airsim_interfaces__srv__SetLocalPosition_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xba, 0xfa, 0x9e, 0x11, 0x2b, 0x30, 0x6b, 0xdd,
      0x8a, 0xd6, 0xf7, 0xa8, 0x32, 0x2b, 0xd9, 0xa0,
      0x02, 0x7b, 0x8f, 0xa6, 0x32, 0x6c, 0x82, 0xbe,
      0xa6, 0xb0, 0xe2, 0xc7, 0x4e, 0xce, 0xa8, 0x55,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_type_hash_t *
airsim_interfaces__srv__SetLocalPosition_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x7e, 0x29, 0x0d, 0x4f, 0x07, 0xe5, 0x95, 0xc2,
      0xb5, 0xab, 0x50, 0xd7, 0x44, 0xbb, 0xf0, 0x99,
      0xe3, 0x7e, 0x55, 0xad, 0x71, 0x7a, 0xf6, 0x6e,
      0x41, 0x3c, 0x1e, 0x3d, 0xfd, 0x2e, 0x81, 0x7d,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_type_hash_t *
airsim_interfaces__srv__SetLocalPosition_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x24, 0x12, 0x47, 0x04, 0x40, 0xb1, 0xe9, 0xd8,
      0xc8, 0xbe, 0x18, 0x69, 0xa3, 0xb5, 0x55, 0x14,
      0x8a, 0x2c, 0x59, 0x1c, 0xda, 0xda, 0x82, 0x1b,
      0x80, 0xb6, 0xef, 0x53, 0xbc, 0xfc, 0xe6, 0xd1,
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

static char airsim_interfaces__srv__SetLocalPosition__TYPE_NAME[] = "airsim_interfaces/srv/SetLocalPosition";
static char airsim_interfaces__srv__SetLocalPosition_Event__TYPE_NAME[] = "airsim_interfaces/srv/SetLocalPosition_Event";
static char airsim_interfaces__srv__SetLocalPosition_Request__TYPE_NAME[] = "airsim_interfaces/srv/SetLocalPosition_Request";
static char airsim_interfaces__srv__SetLocalPosition_Response__TYPE_NAME[] = "airsim_interfaces/srv/SetLocalPosition_Response";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char airsim_interfaces__srv__SetLocalPosition__FIELD_NAME__request_message[] = "request_message";
static char airsim_interfaces__srv__SetLocalPosition__FIELD_NAME__response_message[] = "response_message";
static char airsim_interfaces__srv__SetLocalPosition__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field airsim_interfaces__srv__SetLocalPosition__FIELDS[] = {
  {
    {airsim_interfaces__srv__SetLocalPosition__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {airsim_interfaces__srv__SetLocalPosition_Request__TYPE_NAME, 46, 46},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__SetLocalPosition__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {airsim_interfaces__srv__SetLocalPosition_Response__TYPE_NAME, 47, 47},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__SetLocalPosition__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {airsim_interfaces__srv__SetLocalPosition_Event__TYPE_NAME, 44, 44},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription airsim_interfaces__srv__SetLocalPosition__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {airsim_interfaces__srv__SetLocalPosition_Event__TYPE_NAME, 44, 44},
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__SetLocalPosition_Request__TYPE_NAME, 46, 46},
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__SetLocalPosition_Response__TYPE_NAME, 47, 47},
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
airsim_interfaces__srv__SetLocalPosition__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {airsim_interfaces__srv__SetLocalPosition__TYPE_NAME, 38, 38},
      {airsim_interfaces__srv__SetLocalPosition__FIELDS, 3, 3},
    },
    {airsim_interfaces__srv__SetLocalPosition__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    description.referenced_type_descriptions.data[0].fields = airsim_interfaces__srv__SetLocalPosition_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = airsim_interfaces__srv__SetLocalPosition_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = airsim_interfaces__srv__SetLocalPosition_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char airsim_interfaces__srv__SetLocalPosition_Request__FIELD_NAME__x[] = "x";
static char airsim_interfaces__srv__SetLocalPosition_Request__FIELD_NAME__y[] = "y";
static char airsim_interfaces__srv__SetLocalPosition_Request__FIELD_NAME__z[] = "z";
static char airsim_interfaces__srv__SetLocalPosition_Request__FIELD_NAME__yaw[] = "yaw";
static char airsim_interfaces__srv__SetLocalPosition_Request__FIELD_NAME__vehicle_name[] = "vehicle_name";

static rosidl_runtime_c__type_description__Field airsim_interfaces__srv__SetLocalPosition_Request__FIELDS[] = {
  {
    {airsim_interfaces__srv__SetLocalPosition_Request__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__SetLocalPosition_Request__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__SetLocalPosition_Request__FIELD_NAME__z, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__SetLocalPosition_Request__FIELD_NAME__yaw, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__SetLocalPosition_Request__FIELD_NAME__vehicle_name, 12, 12},
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
airsim_interfaces__srv__SetLocalPosition_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {airsim_interfaces__srv__SetLocalPosition_Request__TYPE_NAME, 46, 46},
      {airsim_interfaces__srv__SetLocalPosition_Request__FIELDS, 5, 5},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char airsim_interfaces__srv__SetLocalPosition_Response__FIELD_NAME__success[] = "success";
static char airsim_interfaces__srv__SetLocalPosition_Response__FIELD_NAME__message[] = "message";

static rosidl_runtime_c__type_description__Field airsim_interfaces__srv__SetLocalPosition_Response__FIELDS[] = {
  {
    {airsim_interfaces__srv__SetLocalPosition_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__SetLocalPosition_Response__FIELD_NAME__message, 7, 7},
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
airsim_interfaces__srv__SetLocalPosition_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {airsim_interfaces__srv__SetLocalPosition_Response__TYPE_NAME, 47, 47},
      {airsim_interfaces__srv__SetLocalPosition_Response__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char airsim_interfaces__srv__SetLocalPosition_Event__FIELD_NAME__info[] = "info";
static char airsim_interfaces__srv__SetLocalPosition_Event__FIELD_NAME__request[] = "request";
static char airsim_interfaces__srv__SetLocalPosition_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field airsim_interfaces__srv__SetLocalPosition_Event__FIELDS[] = {
  {
    {airsim_interfaces__srv__SetLocalPosition_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__SetLocalPosition_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {airsim_interfaces__srv__SetLocalPosition_Request__TYPE_NAME, 46, 46},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__SetLocalPosition_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {airsim_interfaces__srv__SetLocalPosition_Response__TYPE_NAME, 47, 47},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription airsim_interfaces__srv__SetLocalPosition_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {airsim_interfaces__srv__SetLocalPosition_Request__TYPE_NAME, 46, 46},
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__SetLocalPosition_Response__TYPE_NAME, 47, 47},
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
airsim_interfaces__srv__SetLocalPosition_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {airsim_interfaces__srv__SetLocalPosition_Event__TYPE_NAME, 44, 44},
      {airsim_interfaces__srv__SetLocalPosition_Event__FIELDS, 3, 3},
    },
    {airsim_interfaces__srv__SetLocalPosition_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    description.referenced_type_descriptions.data[0].fields = airsim_interfaces__srv__SetLocalPosition_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = airsim_interfaces__srv__SetLocalPosition_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "#Request : expects position setpoint via x, y, z\n"
  "#Request : expects yaw setpoint via yaw (send yaw_valid=true)\n"
  "float64 x\n"
  "float64 y\n"
  "float64 z\n"
  "float64 yaw\n"
  "string vehicle_name\n"
  "---\n"
  "#Response : success=true - (if async=false && if setpoint reached before timeout = 30sec) || (if async=true)\n"
  "bool success\n"
  "string message";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
airsim_interfaces__srv__SetLocalPosition__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {airsim_interfaces__srv__SetLocalPosition__TYPE_NAME, 38, 38},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 313, 313},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
airsim_interfaces__srv__SetLocalPosition_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {airsim_interfaces__srv__SetLocalPosition_Request__TYPE_NAME, 46, 46},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
airsim_interfaces__srv__SetLocalPosition_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {airsim_interfaces__srv__SetLocalPosition_Response__TYPE_NAME, 47, 47},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
airsim_interfaces__srv__SetLocalPosition_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {airsim_interfaces__srv__SetLocalPosition_Event__TYPE_NAME, 44, 44},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
airsim_interfaces__srv__SetLocalPosition__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *airsim_interfaces__srv__SetLocalPosition__get_individual_type_description_source(NULL),
    sources[1] = *airsim_interfaces__srv__SetLocalPosition_Event__get_individual_type_description_source(NULL);
    sources[2] = *airsim_interfaces__srv__SetLocalPosition_Request__get_individual_type_description_source(NULL);
    sources[3] = *airsim_interfaces__srv__SetLocalPosition_Response__get_individual_type_description_source(NULL);
    sources[4] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
airsim_interfaces__srv__SetLocalPosition_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *airsim_interfaces__srv__SetLocalPosition_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
airsim_interfaces__srv__SetLocalPosition_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *airsim_interfaces__srv__SetLocalPosition_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
airsim_interfaces__srv__SetLocalPosition_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *airsim_interfaces__srv__SetLocalPosition_Event__get_individual_type_description_source(NULL),
    sources[1] = *airsim_interfaces__srv__SetLocalPosition_Request__get_individual_type_description_source(NULL);
    sources[2] = *airsim_interfaces__srv__SetLocalPosition_Response__get_individual_type_description_source(NULL);
    sources[3] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

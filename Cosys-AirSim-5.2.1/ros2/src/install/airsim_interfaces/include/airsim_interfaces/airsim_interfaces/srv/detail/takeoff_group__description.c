// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from airsim_interfaces:srv/TakeoffGroup.idl
// generated code does not contain a copyright notice

#include "airsim_interfaces/srv/detail/takeoff_group__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_type_hash_t *
airsim_interfaces__srv__TakeoffGroup__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xeb, 0x39, 0x13, 0x19, 0x5f, 0x4f, 0x1c, 0x9f,
      0x0d, 0xbb, 0x86, 0x9d, 0x1f, 0x76, 0xba, 0x4b,
      0x66, 0xe8, 0x3c, 0x94, 0xcf, 0x11, 0x6a, 0x68,
      0x8c, 0xe7, 0xa8, 0x4a, 0xee, 0xe2, 0x29, 0x16,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_type_hash_t *
airsim_interfaces__srv__TakeoffGroup_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x2e, 0xf5, 0x86, 0xbe, 0x2f, 0x83, 0x8c, 0x1c,
      0x43, 0x3c, 0xdb, 0x1f, 0x0f, 0x74, 0x40, 0xb3,
      0x6e, 0x2c, 0x9d, 0x2c, 0xae, 0x57, 0xb7, 0x48,
      0xd5, 0x96, 0x76, 0x99, 0xd8, 0xad, 0xda, 0xf2,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_type_hash_t *
airsim_interfaces__srv__TakeoffGroup_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xe5, 0xd0, 0xc4, 0xbb, 0xc2, 0x65, 0x0b, 0xc4,
      0xd3, 0xca, 0xda, 0x78, 0x29, 0x46, 0x52, 0x8a,
      0x88, 0xdd, 0x88, 0xb4, 0x17, 0x86, 0xbb, 0xb5,
      0x87, 0x98, 0xd3, 0x2f, 0xe9, 0xc6, 0x11, 0xcf,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_type_hash_t *
airsim_interfaces__srv__TakeoffGroup_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x17, 0x15, 0x09, 0xd7, 0x48, 0x3c, 0xa3, 0x06,
      0x32, 0x48, 0xc8, 0x7d, 0xc0, 0xfe, 0x0a, 0x5f,
      0x5e, 0x1a, 0x57, 0x32, 0x3c, 0xad, 0x86, 0xf1,
      0x2f, 0xf1, 0xb3, 0x91, 0x83, 0x00, 0xd8, 0xf4,
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

static char airsim_interfaces__srv__TakeoffGroup__TYPE_NAME[] = "airsim_interfaces/srv/TakeoffGroup";
static char airsim_interfaces__srv__TakeoffGroup_Event__TYPE_NAME[] = "airsim_interfaces/srv/TakeoffGroup_Event";
static char airsim_interfaces__srv__TakeoffGroup_Request__TYPE_NAME[] = "airsim_interfaces/srv/TakeoffGroup_Request";
static char airsim_interfaces__srv__TakeoffGroup_Response__TYPE_NAME[] = "airsim_interfaces/srv/TakeoffGroup_Response";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char airsim_interfaces__srv__TakeoffGroup__FIELD_NAME__request_message[] = "request_message";
static char airsim_interfaces__srv__TakeoffGroup__FIELD_NAME__response_message[] = "response_message";
static char airsim_interfaces__srv__TakeoffGroup__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field airsim_interfaces__srv__TakeoffGroup__FIELDS[] = {
  {
    {airsim_interfaces__srv__TakeoffGroup__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {airsim_interfaces__srv__TakeoffGroup_Request__TYPE_NAME, 42, 42},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__TakeoffGroup__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {airsim_interfaces__srv__TakeoffGroup_Response__TYPE_NAME, 43, 43},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__TakeoffGroup__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {airsim_interfaces__srv__TakeoffGroup_Event__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription airsim_interfaces__srv__TakeoffGroup__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {airsim_interfaces__srv__TakeoffGroup_Event__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__TakeoffGroup_Request__TYPE_NAME, 42, 42},
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__TakeoffGroup_Response__TYPE_NAME, 43, 43},
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
airsim_interfaces__srv__TakeoffGroup__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {airsim_interfaces__srv__TakeoffGroup__TYPE_NAME, 34, 34},
      {airsim_interfaces__srv__TakeoffGroup__FIELDS, 3, 3},
    },
    {airsim_interfaces__srv__TakeoffGroup__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    description.referenced_type_descriptions.data[0].fields = airsim_interfaces__srv__TakeoffGroup_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = airsim_interfaces__srv__TakeoffGroup_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = airsim_interfaces__srv__TakeoffGroup_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char airsim_interfaces__srv__TakeoffGroup_Request__FIELD_NAME__vehicle_names[] = "vehicle_names";
static char airsim_interfaces__srv__TakeoffGroup_Request__FIELD_NAME__wait_on_last_task[] = "wait_on_last_task";

static rosidl_runtime_c__type_description__Field airsim_interfaces__srv__TakeoffGroup_Request__FIELDS[] = {
  {
    {airsim_interfaces__srv__TakeoffGroup_Request__FIELD_NAME__vehicle_names, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__TakeoffGroup_Request__FIELD_NAME__wait_on_last_task, 17, 17},
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
airsim_interfaces__srv__TakeoffGroup_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {airsim_interfaces__srv__TakeoffGroup_Request__TYPE_NAME, 42, 42},
      {airsim_interfaces__srv__TakeoffGroup_Request__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char airsim_interfaces__srv__TakeoffGroup_Response__FIELD_NAME__success[] = "success";

static rosidl_runtime_c__type_description__Field airsim_interfaces__srv__TakeoffGroup_Response__FIELDS[] = {
  {
    {airsim_interfaces__srv__TakeoffGroup_Response__FIELD_NAME__success, 7, 7},
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
airsim_interfaces__srv__TakeoffGroup_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {airsim_interfaces__srv__TakeoffGroup_Response__TYPE_NAME, 43, 43},
      {airsim_interfaces__srv__TakeoffGroup_Response__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char airsim_interfaces__srv__TakeoffGroup_Event__FIELD_NAME__info[] = "info";
static char airsim_interfaces__srv__TakeoffGroup_Event__FIELD_NAME__request[] = "request";
static char airsim_interfaces__srv__TakeoffGroup_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field airsim_interfaces__srv__TakeoffGroup_Event__FIELDS[] = {
  {
    {airsim_interfaces__srv__TakeoffGroup_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__TakeoffGroup_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {airsim_interfaces__srv__TakeoffGroup_Request__TYPE_NAME, 42, 42},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__TakeoffGroup_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {airsim_interfaces__srv__TakeoffGroup_Response__TYPE_NAME, 43, 43},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription airsim_interfaces__srv__TakeoffGroup_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {airsim_interfaces__srv__TakeoffGroup_Request__TYPE_NAME, 42, 42},
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__TakeoffGroup_Response__TYPE_NAME, 43, 43},
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
airsim_interfaces__srv__TakeoffGroup_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {airsim_interfaces__srv__TakeoffGroup_Event__TYPE_NAME, 40, 40},
      {airsim_interfaces__srv__TakeoffGroup_Event__FIELDS, 3, 3},
    },
    {airsim_interfaces__srv__TakeoffGroup_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    description.referenced_type_descriptions.data[0].fields = airsim_interfaces__srv__TakeoffGroup_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = airsim_interfaces__srv__TakeoffGroup_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string[] vehicle_names\n"
  "bool wait_on_last_task\n"
  "---\n"
  "bool success";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
airsim_interfaces__srv__TakeoffGroup__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {airsim_interfaces__srv__TakeoffGroup__TYPE_NAME, 34, 34},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 62, 62},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
airsim_interfaces__srv__TakeoffGroup_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {airsim_interfaces__srv__TakeoffGroup_Request__TYPE_NAME, 42, 42},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
airsim_interfaces__srv__TakeoffGroup_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {airsim_interfaces__srv__TakeoffGroup_Response__TYPE_NAME, 43, 43},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
airsim_interfaces__srv__TakeoffGroup_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {airsim_interfaces__srv__TakeoffGroup_Event__TYPE_NAME, 40, 40},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
airsim_interfaces__srv__TakeoffGroup__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *airsim_interfaces__srv__TakeoffGroup__get_individual_type_description_source(NULL),
    sources[1] = *airsim_interfaces__srv__TakeoffGroup_Event__get_individual_type_description_source(NULL);
    sources[2] = *airsim_interfaces__srv__TakeoffGroup_Request__get_individual_type_description_source(NULL);
    sources[3] = *airsim_interfaces__srv__TakeoffGroup_Response__get_individual_type_description_source(NULL);
    sources[4] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
airsim_interfaces__srv__TakeoffGroup_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *airsim_interfaces__srv__TakeoffGroup_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
airsim_interfaces__srv__TakeoffGroup_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *airsim_interfaces__srv__TakeoffGroup_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
airsim_interfaces__srv__TakeoffGroup_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *airsim_interfaces__srv__TakeoffGroup_Event__get_individual_type_description_source(NULL),
    sources[1] = *airsim_interfaces__srv__TakeoffGroup_Request__get_individual_type_description_source(NULL);
    sources[2] = *airsim_interfaces__srv__TakeoffGroup_Response__get_individual_type_description_source(NULL);
    sources[3] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from airsim_interfaces:srv/Takeoff.idl
// generated code does not contain a copyright notice

#include "airsim_interfaces/srv/detail/takeoff__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_type_hash_t *
airsim_interfaces__srv__Takeoff__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x4c, 0x96, 0xc6, 0x12, 0xd4, 0x27, 0x38, 0x6f,
      0xc7, 0x57, 0xd2, 0x65, 0xa4, 0xcf, 0xc0, 0x40,
      0x50, 0xaf, 0x4a, 0x4c, 0x66, 0x09, 0x30, 0xed,
      0xe3, 0xd7, 0x66, 0x2e, 0xfc, 0x9e, 0xac, 0x37,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_type_hash_t *
airsim_interfaces__srv__Takeoff_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x8d, 0xd9, 0x09, 0xe9, 0xa9, 0x8c, 0xfb, 0xff,
      0xfd, 0xbf, 0x95, 0xb1, 0x8e, 0xc4, 0x18, 0xda,
      0x58, 0x4b, 0x61, 0x1e, 0xe8, 0x4c, 0xea, 0xb0,
      0xc8, 0xc7, 0x5d, 0x11, 0xc3, 0xee, 0xaf, 0x99,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_type_hash_t *
airsim_interfaces__srv__Takeoff_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x93, 0xce, 0x3c, 0xd9, 0xea, 0x6a, 0x0e, 0x93,
      0x39, 0x63, 0x52, 0xc1, 0x96, 0x8b, 0xba, 0xba,
      0x63, 0x55, 0x5d, 0x94, 0x05, 0xd2, 0x7c, 0xf3,
      0xf6, 0x63, 0x55, 0xa1, 0xc7, 0xe9, 0x43, 0xd0,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_type_hash_t *
airsim_interfaces__srv__Takeoff_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x2b, 0x0e, 0x93, 0x43, 0xec, 0x7b, 0xd6, 0x38,
      0x0e, 0xb5, 0xc0, 0x77, 0x9c, 0xbd, 0x2f, 0x2a,
      0xf2, 0x7f, 0x91, 0x82, 0xf0, 0xd1, 0x15, 0x3d,
      0xf5, 0xa5, 0x5f, 0x78, 0xb3, 0x46, 0x19, 0xbe,
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

static char airsim_interfaces__srv__Takeoff__TYPE_NAME[] = "airsim_interfaces/srv/Takeoff";
static char airsim_interfaces__srv__Takeoff_Event__TYPE_NAME[] = "airsim_interfaces/srv/Takeoff_Event";
static char airsim_interfaces__srv__Takeoff_Request__TYPE_NAME[] = "airsim_interfaces/srv/Takeoff_Request";
static char airsim_interfaces__srv__Takeoff_Response__TYPE_NAME[] = "airsim_interfaces/srv/Takeoff_Response";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char airsim_interfaces__srv__Takeoff__FIELD_NAME__request_message[] = "request_message";
static char airsim_interfaces__srv__Takeoff__FIELD_NAME__response_message[] = "response_message";
static char airsim_interfaces__srv__Takeoff__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field airsim_interfaces__srv__Takeoff__FIELDS[] = {
  {
    {airsim_interfaces__srv__Takeoff__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {airsim_interfaces__srv__Takeoff_Request__TYPE_NAME, 37, 37},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__Takeoff__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {airsim_interfaces__srv__Takeoff_Response__TYPE_NAME, 38, 38},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__Takeoff__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {airsim_interfaces__srv__Takeoff_Event__TYPE_NAME, 35, 35},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription airsim_interfaces__srv__Takeoff__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {airsim_interfaces__srv__Takeoff_Event__TYPE_NAME, 35, 35},
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__Takeoff_Request__TYPE_NAME, 37, 37},
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__Takeoff_Response__TYPE_NAME, 38, 38},
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
airsim_interfaces__srv__Takeoff__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {airsim_interfaces__srv__Takeoff__TYPE_NAME, 29, 29},
      {airsim_interfaces__srv__Takeoff__FIELDS, 3, 3},
    },
    {airsim_interfaces__srv__Takeoff__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    description.referenced_type_descriptions.data[0].fields = airsim_interfaces__srv__Takeoff_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = airsim_interfaces__srv__Takeoff_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = airsim_interfaces__srv__Takeoff_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char airsim_interfaces__srv__Takeoff_Request__FIELD_NAME__wait_on_last_task[] = "wait_on_last_task";

static rosidl_runtime_c__type_description__Field airsim_interfaces__srv__Takeoff_Request__FIELDS[] = {
  {
    {airsim_interfaces__srv__Takeoff_Request__FIELD_NAME__wait_on_last_task, 17, 17},
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
airsim_interfaces__srv__Takeoff_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {airsim_interfaces__srv__Takeoff_Request__TYPE_NAME, 37, 37},
      {airsim_interfaces__srv__Takeoff_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char airsim_interfaces__srv__Takeoff_Response__FIELD_NAME__success[] = "success";

static rosidl_runtime_c__type_description__Field airsim_interfaces__srv__Takeoff_Response__FIELDS[] = {
  {
    {airsim_interfaces__srv__Takeoff_Response__FIELD_NAME__success, 7, 7},
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
airsim_interfaces__srv__Takeoff_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {airsim_interfaces__srv__Takeoff_Response__TYPE_NAME, 38, 38},
      {airsim_interfaces__srv__Takeoff_Response__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char airsim_interfaces__srv__Takeoff_Event__FIELD_NAME__info[] = "info";
static char airsim_interfaces__srv__Takeoff_Event__FIELD_NAME__request[] = "request";
static char airsim_interfaces__srv__Takeoff_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field airsim_interfaces__srv__Takeoff_Event__FIELDS[] = {
  {
    {airsim_interfaces__srv__Takeoff_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__Takeoff_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {airsim_interfaces__srv__Takeoff_Request__TYPE_NAME, 37, 37},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__Takeoff_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {airsim_interfaces__srv__Takeoff_Response__TYPE_NAME, 38, 38},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription airsim_interfaces__srv__Takeoff_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {airsim_interfaces__srv__Takeoff_Request__TYPE_NAME, 37, 37},
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__Takeoff_Response__TYPE_NAME, 38, 38},
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
airsim_interfaces__srv__Takeoff_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {airsim_interfaces__srv__Takeoff_Event__TYPE_NAME, 35, 35},
      {airsim_interfaces__srv__Takeoff_Event__FIELDS, 3, 3},
    },
    {airsim_interfaces__srv__Takeoff_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    description.referenced_type_descriptions.data[0].fields = airsim_interfaces__srv__Takeoff_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = airsim_interfaces__srv__Takeoff_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "bool wait_on_last_task\n"
  "---\n"
  "bool success";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
airsim_interfaces__srv__Takeoff__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {airsim_interfaces__srv__Takeoff__TYPE_NAME, 29, 29},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 40, 40},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
airsim_interfaces__srv__Takeoff_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {airsim_interfaces__srv__Takeoff_Request__TYPE_NAME, 37, 37},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
airsim_interfaces__srv__Takeoff_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {airsim_interfaces__srv__Takeoff_Response__TYPE_NAME, 38, 38},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
airsim_interfaces__srv__Takeoff_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {airsim_interfaces__srv__Takeoff_Event__TYPE_NAME, 35, 35},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
airsim_interfaces__srv__Takeoff__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *airsim_interfaces__srv__Takeoff__get_individual_type_description_source(NULL),
    sources[1] = *airsim_interfaces__srv__Takeoff_Event__get_individual_type_description_source(NULL);
    sources[2] = *airsim_interfaces__srv__Takeoff_Request__get_individual_type_description_source(NULL);
    sources[3] = *airsim_interfaces__srv__Takeoff_Response__get_individual_type_description_source(NULL);
    sources[4] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
airsim_interfaces__srv__Takeoff_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *airsim_interfaces__srv__Takeoff_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
airsim_interfaces__srv__Takeoff_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *airsim_interfaces__srv__Takeoff_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
airsim_interfaces__srv__Takeoff_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *airsim_interfaces__srv__Takeoff_Event__get_individual_type_description_source(NULL),
    sources[1] = *airsim_interfaces__srv__Takeoff_Request__get_individual_type_description_source(NULL);
    sources[2] = *airsim_interfaces__srv__Takeoff_Response__get_individual_type_description_source(NULL);
    sources[3] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from airsim_interfaces:srv/RefreshInstanceSegmentation.idl
// generated code does not contain a copyright notice

#include "airsim_interfaces/srv/detail/refresh_instance_segmentation__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_type_hash_t *
airsim_interfaces__srv__RefreshInstanceSegmentation__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xc3, 0xb5, 0x75, 0x26, 0x84, 0x36, 0x79, 0x4b,
      0x9a, 0xd7, 0xd7, 0x32, 0xd3, 0xa0, 0x5a, 0xf7,
      0x91, 0xbb, 0x44, 0x6b, 0x0b, 0xbd, 0xd3, 0x5c,
      0x70, 0xdc, 0xbc, 0x7e, 0x91, 0x69, 0x0d, 0xeb,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_type_hash_t *
airsim_interfaces__srv__RefreshInstanceSegmentation_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x4e, 0xf7, 0x82, 0x54, 0xc4, 0x8f, 0x43, 0x26,
      0x3f, 0x22, 0x08, 0xdc, 0x6e, 0x59, 0x7c, 0xb4,
      0xbb, 0xd1, 0xea, 0xe1, 0x67, 0x75, 0x5a, 0x10,
      0x41, 0x1b, 0xdf, 0xde, 0x0e, 0x70, 0x0f, 0x7c,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_type_hash_t *
airsim_interfaces__srv__RefreshInstanceSegmentation_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xae, 0x1f, 0x73, 0x5d, 0x47, 0x66, 0xae, 0xca,
      0x5a, 0x1b, 0x9e, 0xdc, 0x6c, 0xee, 0xf3, 0xa0,
      0x53, 0x67, 0x31, 0xdc, 0x0e, 0x91, 0x53, 0x7d,
      0x25, 0x91, 0xa0, 0xce, 0x18, 0xc7, 0x91, 0x69,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_type_hash_t *
airsim_interfaces__srv__RefreshInstanceSegmentation_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x01, 0x68, 0x48, 0x3c, 0x47, 0xbd, 0xf6, 0xf0,
      0x91, 0x11, 0xc7, 0x94, 0x8a, 0x0b, 0x8a, 0x60,
      0xcd, 0x6e, 0xd6, 0x7b, 0x28, 0x9e, 0xf6, 0xed,
      0x78, 0xeb, 0x9a, 0xfb, 0x4a, 0xe8, 0x1c, 0x3e,
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

static char airsim_interfaces__srv__RefreshInstanceSegmentation__TYPE_NAME[] = "airsim_interfaces/srv/RefreshInstanceSegmentation";
static char airsim_interfaces__srv__RefreshInstanceSegmentation_Event__TYPE_NAME[] = "airsim_interfaces/srv/RefreshInstanceSegmentation_Event";
static char airsim_interfaces__srv__RefreshInstanceSegmentation_Request__TYPE_NAME[] = "airsim_interfaces/srv/RefreshInstanceSegmentation_Request";
static char airsim_interfaces__srv__RefreshInstanceSegmentation_Response__TYPE_NAME[] = "airsim_interfaces/srv/RefreshInstanceSegmentation_Response";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char airsim_interfaces__srv__RefreshInstanceSegmentation__FIELD_NAME__request_message[] = "request_message";
static char airsim_interfaces__srv__RefreshInstanceSegmentation__FIELD_NAME__response_message[] = "response_message";
static char airsim_interfaces__srv__RefreshInstanceSegmentation__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field airsim_interfaces__srv__RefreshInstanceSegmentation__FIELDS[] = {
  {
    {airsim_interfaces__srv__RefreshInstanceSegmentation__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {airsim_interfaces__srv__RefreshInstanceSegmentation_Request__TYPE_NAME, 57, 57},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__RefreshInstanceSegmentation__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {airsim_interfaces__srv__RefreshInstanceSegmentation_Response__TYPE_NAME, 58, 58},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__RefreshInstanceSegmentation__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {airsim_interfaces__srv__RefreshInstanceSegmentation_Event__TYPE_NAME, 55, 55},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription airsim_interfaces__srv__RefreshInstanceSegmentation__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {airsim_interfaces__srv__RefreshInstanceSegmentation_Event__TYPE_NAME, 55, 55},
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__RefreshInstanceSegmentation_Request__TYPE_NAME, 57, 57},
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__RefreshInstanceSegmentation_Response__TYPE_NAME, 58, 58},
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
airsim_interfaces__srv__RefreshInstanceSegmentation__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {airsim_interfaces__srv__RefreshInstanceSegmentation__TYPE_NAME, 49, 49},
      {airsim_interfaces__srv__RefreshInstanceSegmentation__FIELDS, 3, 3},
    },
    {airsim_interfaces__srv__RefreshInstanceSegmentation__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    description.referenced_type_descriptions.data[0].fields = airsim_interfaces__srv__RefreshInstanceSegmentation_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = airsim_interfaces__srv__RefreshInstanceSegmentation_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = airsim_interfaces__srv__RefreshInstanceSegmentation_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char airsim_interfaces__srv__RefreshInstanceSegmentation_Request__FIELD_NAME__structure_needs_at_least_one_member[] = "structure_needs_at_least_one_member";

static rosidl_runtime_c__type_description__Field airsim_interfaces__srv__RefreshInstanceSegmentation_Request__FIELDS[] = {
  {
    {airsim_interfaces__srv__RefreshInstanceSegmentation_Request__FIELD_NAME__structure_needs_at_least_one_member, 35, 35},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
airsim_interfaces__srv__RefreshInstanceSegmentation_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {airsim_interfaces__srv__RefreshInstanceSegmentation_Request__TYPE_NAME, 57, 57},
      {airsim_interfaces__srv__RefreshInstanceSegmentation_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char airsim_interfaces__srv__RefreshInstanceSegmentation_Response__FIELD_NAME__success[] = "success";

static rosidl_runtime_c__type_description__Field airsim_interfaces__srv__RefreshInstanceSegmentation_Response__FIELDS[] = {
  {
    {airsim_interfaces__srv__RefreshInstanceSegmentation_Response__FIELD_NAME__success, 7, 7},
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
airsim_interfaces__srv__RefreshInstanceSegmentation_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {airsim_interfaces__srv__RefreshInstanceSegmentation_Response__TYPE_NAME, 58, 58},
      {airsim_interfaces__srv__RefreshInstanceSegmentation_Response__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char airsim_interfaces__srv__RefreshInstanceSegmentation_Event__FIELD_NAME__info[] = "info";
static char airsim_interfaces__srv__RefreshInstanceSegmentation_Event__FIELD_NAME__request[] = "request";
static char airsim_interfaces__srv__RefreshInstanceSegmentation_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field airsim_interfaces__srv__RefreshInstanceSegmentation_Event__FIELDS[] = {
  {
    {airsim_interfaces__srv__RefreshInstanceSegmentation_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__RefreshInstanceSegmentation_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {airsim_interfaces__srv__RefreshInstanceSegmentation_Request__TYPE_NAME, 57, 57},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__RefreshInstanceSegmentation_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {airsim_interfaces__srv__RefreshInstanceSegmentation_Response__TYPE_NAME, 58, 58},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription airsim_interfaces__srv__RefreshInstanceSegmentation_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {airsim_interfaces__srv__RefreshInstanceSegmentation_Request__TYPE_NAME, 57, 57},
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__srv__RefreshInstanceSegmentation_Response__TYPE_NAME, 58, 58},
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
airsim_interfaces__srv__RefreshInstanceSegmentation_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {airsim_interfaces__srv__RefreshInstanceSegmentation_Event__TYPE_NAME, 55, 55},
      {airsim_interfaces__srv__RefreshInstanceSegmentation_Event__FIELDS, 3, 3},
    },
    {airsim_interfaces__srv__RefreshInstanceSegmentation_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    description.referenced_type_descriptions.data[0].fields = airsim_interfaces__srv__RefreshInstanceSegmentation_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = airsim_interfaces__srv__RefreshInstanceSegmentation_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "---\n"
  "bool success";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
airsim_interfaces__srv__RefreshInstanceSegmentation__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {airsim_interfaces__srv__RefreshInstanceSegmentation__TYPE_NAME, 49, 49},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 16, 16},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
airsim_interfaces__srv__RefreshInstanceSegmentation_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {airsim_interfaces__srv__RefreshInstanceSegmentation_Request__TYPE_NAME, 57, 57},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
airsim_interfaces__srv__RefreshInstanceSegmentation_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {airsim_interfaces__srv__RefreshInstanceSegmentation_Response__TYPE_NAME, 58, 58},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
airsim_interfaces__srv__RefreshInstanceSegmentation_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {airsim_interfaces__srv__RefreshInstanceSegmentation_Event__TYPE_NAME, 55, 55},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
airsim_interfaces__srv__RefreshInstanceSegmentation__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *airsim_interfaces__srv__RefreshInstanceSegmentation__get_individual_type_description_source(NULL),
    sources[1] = *airsim_interfaces__srv__RefreshInstanceSegmentation_Event__get_individual_type_description_source(NULL);
    sources[2] = *airsim_interfaces__srv__RefreshInstanceSegmentation_Request__get_individual_type_description_source(NULL);
    sources[3] = *airsim_interfaces__srv__RefreshInstanceSegmentation_Response__get_individual_type_description_source(NULL);
    sources[4] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
airsim_interfaces__srv__RefreshInstanceSegmentation_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *airsim_interfaces__srv__RefreshInstanceSegmentation_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
airsim_interfaces__srv__RefreshInstanceSegmentation_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *airsim_interfaces__srv__RefreshInstanceSegmentation_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
airsim_interfaces__srv__RefreshInstanceSegmentation_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *airsim_interfaces__srv__RefreshInstanceSegmentation_Event__get_individual_type_description_source(NULL),
    sources[1] = *airsim_interfaces__srv__RefreshInstanceSegmentation_Request__get_individual_type_description_source(NULL);
    sources[2] = *airsim_interfaces__srv__RefreshInstanceSegmentation_Response__get_individual_type_description_source(NULL);
    sources[3] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

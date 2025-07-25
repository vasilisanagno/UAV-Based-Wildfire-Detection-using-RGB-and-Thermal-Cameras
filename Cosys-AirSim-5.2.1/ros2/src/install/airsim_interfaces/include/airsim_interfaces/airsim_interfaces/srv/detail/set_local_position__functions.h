// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from airsim_interfaces:srv/SetLocalPosition.idl
// generated code does not contain a copyright notice

#ifndef AIRSIM_INTERFACES__SRV__DETAIL__SET_LOCAL_POSITION__FUNCTIONS_H_
#define AIRSIM_INTERFACES__SRV__DETAIL__SET_LOCAL_POSITION__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "airsim_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "airsim_interfaces/srv/detail/set_local_position__struct.h"

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_type_hash_t *
airsim_interfaces__srv__SetLocalPosition__get_type_hash(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
airsim_interfaces__srv__SetLocalPosition__get_type_description(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_runtime_c__type_description__TypeSource *
airsim_interfaces__srv__SetLocalPosition__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
airsim_interfaces__srv__SetLocalPosition__get_type_description_sources(
  const rosidl_service_type_support_t * type_support);

/// Initialize srv/SetLocalPosition message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * airsim_interfaces__srv__SetLocalPosition_Request
 * )) before or use
 * airsim_interfaces__srv__SetLocalPosition_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
bool
airsim_interfaces__srv__SetLocalPosition_Request__init(airsim_interfaces__srv__SetLocalPosition_Request * msg);

/// Finalize srv/SetLocalPosition message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
void
airsim_interfaces__srv__SetLocalPosition_Request__fini(airsim_interfaces__srv__SetLocalPosition_Request * msg);

/// Create srv/SetLocalPosition message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * airsim_interfaces__srv__SetLocalPosition_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
airsim_interfaces__srv__SetLocalPosition_Request *
airsim_interfaces__srv__SetLocalPosition_Request__create();

/// Destroy srv/SetLocalPosition message.
/**
 * It calls
 * airsim_interfaces__srv__SetLocalPosition_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
void
airsim_interfaces__srv__SetLocalPosition_Request__destroy(airsim_interfaces__srv__SetLocalPosition_Request * msg);

/// Check for srv/SetLocalPosition message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
bool
airsim_interfaces__srv__SetLocalPosition_Request__are_equal(const airsim_interfaces__srv__SetLocalPosition_Request * lhs, const airsim_interfaces__srv__SetLocalPosition_Request * rhs);

/// Copy a srv/SetLocalPosition message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
bool
airsim_interfaces__srv__SetLocalPosition_Request__copy(
  const airsim_interfaces__srv__SetLocalPosition_Request * input,
  airsim_interfaces__srv__SetLocalPosition_Request * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_type_hash_t *
airsim_interfaces__srv__SetLocalPosition_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
airsim_interfaces__srv__SetLocalPosition_Request__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_runtime_c__type_description__TypeSource *
airsim_interfaces__srv__SetLocalPosition_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
airsim_interfaces__srv__SetLocalPosition_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of srv/SetLocalPosition messages.
/**
 * It allocates the memory for the number of elements and calls
 * airsim_interfaces__srv__SetLocalPosition_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
bool
airsim_interfaces__srv__SetLocalPosition_Request__Sequence__init(airsim_interfaces__srv__SetLocalPosition_Request__Sequence * array, size_t size);

/// Finalize array of srv/SetLocalPosition messages.
/**
 * It calls
 * airsim_interfaces__srv__SetLocalPosition_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
void
airsim_interfaces__srv__SetLocalPosition_Request__Sequence__fini(airsim_interfaces__srv__SetLocalPosition_Request__Sequence * array);

/// Create array of srv/SetLocalPosition messages.
/**
 * It allocates the memory for the array and calls
 * airsim_interfaces__srv__SetLocalPosition_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
airsim_interfaces__srv__SetLocalPosition_Request__Sequence *
airsim_interfaces__srv__SetLocalPosition_Request__Sequence__create(size_t size);

/// Destroy array of srv/SetLocalPosition messages.
/**
 * It calls
 * airsim_interfaces__srv__SetLocalPosition_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
void
airsim_interfaces__srv__SetLocalPosition_Request__Sequence__destroy(airsim_interfaces__srv__SetLocalPosition_Request__Sequence * array);

/// Check for srv/SetLocalPosition message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
bool
airsim_interfaces__srv__SetLocalPosition_Request__Sequence__are_equal(const airsim_interfaces__srv__SetLocalPosition_Request__Sequence * lhs, const airsim_interfaces__srv__SetLocalPosition_Request__Sequence * rhs);

/// Copy an array of srv/SetLocalPosition messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
bool
airsim_interfaces__srv__SetLocalPosition_Request__Sequence__copy(
  const airsim_interfaces__srv__SetLocalPosition_Request__Sequence * input,
  airsim_interfaces__srv__SetLocalPosition_Request__Sequence * output);

/// Initialize srv/SetLocalPosition message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * airsim_interfaces__srv__SetLocalPosition_Response
 * )) before or use
 * airsim_interfaces__srv__SetLocalPosition_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
bool
airsim_interfaces__srv__SetLocalPosition_Response__init(airsim_interfaces__srv__SetLocalPosition_Response * msg);

/// Finalize srv/SetLocalPosition message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
void
airsim_interfaces__srv__SetLocalPosition_Response__fini(airsim_interfaces__srv__SetLocalPosition_Response * msg);

/// Create srv/SetLocalPosition message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * airsim_interfaces__srv__SetLocalPosition_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
airsim_interfaces__srv__SetLocalPosition_Response *
airsim_interfaces__srv__SetLocalPosition_Response__create();

/// Destroy srv/SetLocalPosition message.
/**
 * It calls
 * airsim_interfaces__srv__SetLocalPosition_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
void
airsim_interfaces__srv__SetLocalPosition_Response__destroy(airsim_interfaces__srv__SetLocalPosition_Response * msg);

/// Check for srv/SetLocalPosition message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
bool
airsim_interfaces__srv__SetLocalPosition_Response__are_equal(const airsim_interfaces__srv__SetLocalPosition_Response * lhs, const airsim_interfaces__srv__SetLocalPosition_Response * rhs);

/// Copy a srv/SetLocalPosition message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
bool
airsim_interfaces__srv__SetLocalPosition_Response__copy(
  const airsim_interfaces__srv__SetLocalPosition_Response * input,
  airsim_interfaces__srv__SetLocalPosition_Response * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_type_hash_t *
airsim_interfaces__srv__SetLocalPosition_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
airsim_interfaces__srv__SetLocalPosition_Response__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_runtime_c__type_description__TypeSource *
airsim_interfaces__srv__SetLocalPosition_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
airsim_interfaces__srv__SetLocalPosition_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of srv/SetLocalPosition messages.
/**
 * It allocates the memory for the number of elements and calls
 * airsim_interfaces__srv__SetLocalPosition_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
bool
airsim_interfaces__srv__SetLocalPosition_Response__Sequence__init(airsim_interfaces__srv__SetLocalPosition_Response__Sequence * array, size_t size);

/// Finalize array of srv/SetLocalPosition messages.
/**
 * It calls
 * airsim_interfaces__srv__SetLocalPosition_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
void
airsim_interfaces__srv__SetLocalPosition_Response__Sequence__fini(airsim_interfaces__srv__SetLocalPosition_Response__Sequence * array);

/// Create array of srv/SetLocalPosition messages.
/**
 * It allocates the memory for the array and calls
 * airsim_interfaces__srv__SetLocalPosition_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
airsim_interfaces__srv__SetLocalPosition_Response__Sequence *
airsim_interfaces__srv__SetLocalPosition_Response__Sequence__create(size_t size);

/// Destroy array of srv/SetLocalPosition messages.
/**
 * It calls
 * airsim_interfaces__srv__SetLocalPosition_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
void
airsim_interfaces__srv__SetLocalPosition_Response__Sequence__destroy(airsim_interfaces__srv__SetLocalPosition_Response__Sequence * array);

/// Check for srv/SetLocalPosition message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
bool
airsim_interfaces__srv__SetLocalPosition_Response__Sequence__are_equal(const airsim_interfaces__srv__SetLocalPosition_Response__Sequence * lhs, const airsim_interfaces__srv__SetLocalPosition_Response__Sequence * rhs);

/// Copy an array of srv/SetLocalPosition messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
bool
airsim_interfaces__srv__SetLocalPosition_Response__Sequence__copy(
  const airsim_interfaces__srv__SetLocalPosition_Response__Sequence * input,
  airsim_interfaces__srv__SetLocalPosition_Response__Sequence * output);

/// Initialize srv/SetLocalPosition message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * airsim_interfaces__srv__SetLocalPosition_Event
 * )) before or use
 * airsim_interfaces__srv__SetLocalPosition_Event__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
bool
airsim_interfaces__srv__SetLocalPosition_Event__init(airsim_interfaces__srv__SetLocalPosition_Event * msg);

/// Finalize srv/SetLocalPosition message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
void
airsim_interfaces__srv__SetLocalPosition_Event__fini(airsim_interfaces__srv__SetLocalPosition_Event * msg);

/// Create srv/SetLocalPosition message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * airsim_interfaces__srv__SetLocalPosition_Event__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
airsim_interfaces__srv__SetLocalPosition_Event *
airsim_interfaces__srv__SetLocalPosition_Event__create();

/// Destroy srv/SetLocalPosition message.
/**
 * It calls
 * airsim_interfaces__srv__SetLocalPosition_Event__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
void
airsim_interfaces__srv__SetLocalPosition_Event__destroy(airsim_interfaces__srv__SetLocalPosition_Event * msg);

/// Check for srv/SetLocalPosition message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
bool
airsim_interfaces__srv__SetLocalPosition_Event__are_equal(const airsim_interfaces__srv__SetLocalPosition_Event * lhs, const airsim_interfaces__srv__SetLocalPosition_Event * rhs);

/// Copy a srv/SetLocalPosition message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
bool
airsim_interfaces__srv__SetLocalPosition_Event__copy(
  const airsim_interfaces__srv__SetLocalPosition_Event * input,
  airsim_interfaces__srv__SetLocalPosition_Event * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_type_hash_t *
airsim_interfaces__srv__SetLocalPosition_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
airsim_interfaces__srv__SetLocalPosition_Event__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_runtime_c__type_description__TypeSource *
airsim_interfaces__srv__SetLocalPosition_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
airsim_interfaces__srv__SetLocalPosition_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of srv/SetLocalPosition messages.
/**
 * It allocates the memory for the number of elements and calls
 * airsim_interfaces__srv__SetLocalPosition_Event__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
bool
airsim_interfaces__srv__SetLocalPosition_Event__Sequence__init(airsim_interfaces__srv__SetLocalPosition_Event__Sequence * array, size_t size);

/// Finalize array of srv/SetLocalPosition messages.
/**
 * It calls
 * airsim_interfaces__srv__SetLocalPosition_Event__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
void
airsim_interfaces__srv__SetLocalPosition_Event__Sequence__fini(airsim_interfaces__srv__SetLocalPosition_Event__Sequence * array);

/// Create array of srv/SetLocalPosition messages.
/**
 * It allocates the memory for the array and calls
 * airsim_interfaces__srv__SetLocalPosition_Event__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
airsim_interfaces__srv__SetLocalPosition_Event__Sequence *
airsim_interfaces__srv__SetLocalPosition_Event__Sequence__create(size_t size);

/// Destroy array of srv/SetLocalPosition messages.
/**
 * It calls
 * airsim_interfaces__srv__SetLocalPosition_Event__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
void
airsim_interfaces__srv__SetLocalPosition_Event__Sequence__destroy(airsim_interfaces__srv__SetLocalPosition_Event__Sequence * array);

/// Check for srv/SetLocalPosition message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
bool
airsim_interfaces__srv__SetLocalPosition_Event__Sequence__are_equal(const airsim_interfaces__srv__SetLocalPosition_Event__Sequence * lhs, const airsim_interfaces__srv__SetLocalPosition_Event__Sequence * rhs);

/// Copy an array of srv/SetLocalPosition messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
bool
airsim_interfaces__srv__SetLocalPosition_Event__Sequence__copy(
  const airsim_interfaces__srv__SetLocalPosition_Event__Sequence * input,
  airsim_interfaces__srv__SetLocalPosition_Event__Sequence * output);
#ifdef __cplusplus
}
#endif

#endif  // AIRSIM_INTERFACES__SRV__DETAIL__SET_LOCAL_POSITION__FUNCTIONS_H_

// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from airsim_interfaces:msg/ComputerVisionState.idl
// generated code does not contain a copyright notice

#ifndef AIRSIM_INTERFACES__MSG__DETAIL__COMPUTER_VISION_STATE__FUNCTIONS_H_
#define AIRSIM_INTERFACES__MSG__DETAIL__COMPUTER_VISION_STATE__FUNCTIONS_H_

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

#include "airsim_interfaces/msg/detail/computer_vision_state__struct.h"

/// Initialize msg/ComputerVisionState message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * airsim_interfaces__msg__ComputerVisionState
 * )) before or use
 * airsim_interfaces__msg__ComputerVisionState__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
bool
airsim_interfaces__msg__ComputerVisionState__init(airsim_interfaces__msg__ComputerVisionState * msg);

/// Finalize msg/ComputerVisionState message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
void
airsim_interfaces__msg__ComputerVisionState__fini(airsim_interfaces__msg__ComputerVisionState * msg);

/// Create msg/ComputerVisionState message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * airsim_interfaces__msg__ComputerVisionState__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
airsim_interfaces__msg__ComputerVisionState *
airsim_interfaces__msg__ComputerVisionState__create();

/// Destroy msg/ComputerVisionState message.
/**
 * It calls
 * airsim_interfaces__msg__ComputerVisionState__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
void
airsim_interfaces__msg__ComputerVisionState__destroy(airsim_interfaces__msg__ComputerVisionState * msg);

/// Check for msg/ComputerVisionState message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
bool
airsim_interfaces__msg__ComputerVisionState__are_equal(const airsim_interfaces__msg__ComputerVisionState * lhs, const airsim_interfaces__msg__ComputerVisionState * rhs);

/// Copy a msg/ComputerVisionState message.
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
airsim_interfaces__msg__ComputerVisionState__copy(
  const airsim_interfaces__msg__ComputerVisionState * input,
  airsim_interfaces__msg__ComputerVisionState * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_type_hash_t *
airsim_interfaces__msg__ComputerVisionState__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
airsim_interfaces__msg__ComputerVisionState__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_runtime_c__type_description__TypeSource *
airsim_interfaces__msg__ComputerVisionState__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
airsim_interfaces__msg__ComputerVisionState__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of msg/ComputerVisionState messages.
/**
 * It allocates the memory for the number of elements and calls
 * airsim_interfaces__msg__ComputerVisionState__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
bool
airsim_interfaces__msg__ComputerVisionState__Sequence__init(airsim_interfaces__msg__ComputerVisionState__Sequence * array, size_t size);

/// Finalize array of msg/ComputerVisionState messages.
/**
 * It calls
 * airsim_interfaces__msg__ComputerVisionState__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
void
airsim_interfaces__msg__ComputerVisionState__Sequence__fini(airsim_interfaces__msg__ComputerVisionState__Sequence * array);

/// Create array of msg/ComputerVisionState messages.
/**
 * It allocates the memory for the array and calls
 * airsim_interfaces__msg__ComputerVisionState__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
airsim_interfaces__msg__ComputerVisionState__Sequence *
airsim_interfaces__msg__ComputerVisionState__Sequence__create(size_t size);

/// Destroy array of msg/ComputerVisionState messages.
/**
 * It calls
 * airsim_interfaces__msg__ComputerVisionState__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
void
airsim_interfaces__msg__ComputerVisionState__Sequence__destroy(airsim_interfaces__msg__ComputerVisionState__Sequence * array);

/// Check for msg/ComputerVisionState message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
bool
airsim_interfaces__msg__ComputerVisionState__Sequence__are_equal(const airsim_interfaces__msg__ComputerVisionState__Sequence * lhs, const airsim_interfaces__msg__ComputerVisionState__Sequence * rhs);

/// Copy an array of msg/ComputerVisionState messages.
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
airsim_interfaces__msg__ComputerVisionState__Sequence__copy(
  const airsim_interfaces__msg__ComputerVisionState__Sequence * input,
  airsim_interfaces__msg__ComputerVisionState__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // AIRSIM_INTERFACES__MSG__DETAIL__COMPUTER_VISION_STATE__FUNCTIONS_H_

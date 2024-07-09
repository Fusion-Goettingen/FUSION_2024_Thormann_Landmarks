// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from radar_interfaces:msg/Radar.idl
// generated code does not contain a copyright notice

#ifndef RADAR_INTERFACES__MSG__DETAIL__RADAR__STRUCT_H_
#define RADAR_INTERFACES__MSG__DETAIL__RADAR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'data'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/Radar in the package radar_interfaces.
/**
  * Array for storing a radar signal as an array. Provides header with time stamp and ID information.
 */
typedef struct radar_interfaces__msg__Radar
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__double__Sequence data;
} radar_interfaces__msg__Radar;

// Struct for a sequence of radar_interfaces__msg__Radar.
typedef struct radar_interfaces__msg__Radar__Sequence
{
  radar_interfaces__msg__Radar * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} radar_interfaces__msg__Radar__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RADAR_INTERFACES__MSG__DETAIL__RADAR__STRUCT_H_

// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from radar_interfaces:msg/LandmarkEstimate.idl
// generated code does not contain a copyright notice

#ifndef RADAR_INTERFACES__MSG__DETAIL__LANDMARK_ESTIMATE__STRUCT_H_
#define RADAR_INTERFACES__MSG__DETAIL__LANDMARK_ESTIMATE__STRUCT_H_

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
// Member 'range_bin'
// Member 'heatmap'
// Member 'angles_degree'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/LandmarkEstimate in the package radar_interfaces.
/**
  * Array for storing a heatmap as an array. Provides header with time stamp and ID information.
 */
typedef struct radar_interfaces__msg__LandmarkEstimate
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__double__Sequence range_bin;
  rosidl_runtime_c__double__Sequence heatmap;
  rosidl_runtime_c__double__Sequence angles_degree;
} radar_interfaces__msg__LandmarkEstimate;

// Struct for a sequence of radar_interfaces__msg__LandmarkEstimate.
typedef struct radar_interfaces__msg__LandmarkEstimate__Sequence
{
  radar_interfaces__msg__LandmarkEstimate * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} radar_interfaces__msg__LandmarkEstimate__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RADAR_INTERFACES__MSG__DETAIL__LANDMARK_ESTIMATE__STRUCT_H_

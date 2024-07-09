// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from radar_interfaces:msg/GroundTruth.idl
// generated code does not contain a copyright notice

#ifndef RADAR_INTERFACES__MSG__DETAIL__GROUND_TRUTH__TRAITS_HPP_
#define RADAR_INTERFACES__MSG__DETAIL__GROUND_TRUTH__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "radar_interfaces/msg/detail/ground_truth__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace radar_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const GroundTruth & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: relative_landmark_range
  {
    if (msg.relative_landmark_range.size() == 0) {
      out << "relative_landmark_range: []";
    } else {
      out << "relative_landmark_range: [";
      size_t pending_items = msg.relative_landmark_range.size();
      for (auto item : msg.relative_landmark_range) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: relative_landmark_angle
  {
    if (msg.relative_landmark_angle.size() == 0) {
      out << "relative_landmark_angle: []";
    } else {
      out << "relative_landmark_angle: [";
      size_t pending_items = msg.relative_landmark_angle.size();
      for (auto item : msg.relative_landmark_angle) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: is_moving
  {
    out << "is_moving: ";
    rosidl_generator_traits::value_to_yaml(msg.is_moving, out);
    out << ", ";
  }

  // member: relative_position
  {
    if (msg.relative_position.size() == 0) {
      out << "relative_position: []";
    } else {
      out << "relative_position: [";
      size_t pending_items = msg.relative_position.size();
      for (auto item : msg.relative_position) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GroundTruth & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: relative_landmark_range
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.relative_landmark_range.size() == 0) {
      out << "relative_landmark_range: []\n";
    } else {
      out << "relative_landmark_range:\n";
      for (auto item : msg.relative_landmark_range) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: relative_landmark_angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.relative_landmark_angle.size() == 0) {
      out << "relative_landmark_angle: []\n";
    } else {
      out << "relative_landmark_angle:\n";
      for (auto item : msg.relative_landmark_angle) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: is_moving
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_moving: ";
    rosidl_generator_traits::value_to_yaml(msg.is_moving, out);
    out << "\n";
  }

  // member: relative_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.relative_position.size() == 0) {
      out << "relative_position: []\n";
    } else {
      out << "relative_position:\n";
      for (auto item : msg.relative_position) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GroundTruth & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace radar_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use radar_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const radar_interfaces::msg::GroundTruth & msg,
  std::ostream & out, size_t indentation = 0)
{
  radar_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use radar_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const radar_interfaces::msg::GroundTruth & msg)
{
  return radar_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<radar_interfaces::msg::GroundTruth>()
{
  return "radar_interfaces::msg::GroundTruth";
}

template<>
inline const char * name<radar_interfaces::msg::GroundTruth>()
{
  return "radar_interfaces/msg/GroundTruth";
}

template<>
struct has_fixed_size<radar_interfaces::msg::GroundTruth>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<radar_interfaces::msg::GroundTruth>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<radar_interfaces::msg::GroundTruth>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RADAR_INTERFACES__MSG__DETAIL__GROUND_TRUTH__TRAITS_HPP_

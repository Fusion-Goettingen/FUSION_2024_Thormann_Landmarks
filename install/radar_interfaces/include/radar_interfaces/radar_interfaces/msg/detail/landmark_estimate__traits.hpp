// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from radar_interfaces:msg/LandmarkEstimate.idl
// generated code does not contain a copyright notice

#ifndef RADAR_INTERFACES__MSG__DETAIL__LANDMARK_ESTIMATE__TRAITS_HPP_
#define RADAR_INTERFACES__MSG__DETAIL__LANDMARK_ESTIMATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "radar_interfaces/msg/detail/landmark_estimate__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace radar_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const LandmarkEstimate & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: range_bin
  {
    if (msg.range_bin.size() == 0) {
      out << "range_bin: []";
    } else {
      out << "range_bin: [";
      size_t pending_items = msg.range_bin.size();
      for (auto item : msg.range_bin) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: heatmap
  {
    if (msg.heatmap.size() == 0) {
      out << "heatmap: []";
    } else {
      out << "heatmap: [";
      size_t pending_items = msg.heatmap.size();
      for (auto item : msg.heatmap) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: angles_degree
  {
    if (msg.angles_degree.size() == 0) {
      out << "angles_degree: []";
    } else {
      out << "angles_degree: [";
      size_t pending_items = msg.angles_degree.size();
      for (auto item : msg.angles_degree) {
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
  const LandmarkEstimate & msg,
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

  // member: range_bin
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.range_bin.size() == 0) {
      out << "range_bin: []\n";
    } else {
      out << "range_bin:\n";
      for (auto item : msg.range_bin) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: heatmap
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.heatmap.size() == 0) {
      out << "heatmap: []\n";
    } else {
      out << "heatmap:\n";
      for (auto item : msg.heatmap) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: angles_degree
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.angles_degree.size() == 0) {
      out << "angles_degree: []\n";
    } else {
      out << "angles_degree:\n";
      for (auto item : msg.angles_degree) {
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

inline std::string to_yaml(const LandmarkEstimate & msg, bool use_flow_style = false)
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
  const radar_interfaces::msg::LandmarkEstimate & msg,
  std::ostream & out, size_t indentation = 0)
{
  radar_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use radar_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const radar_interfaces::msg::LandmarkEstimate & msg)
{
  return radar_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<radar_interfaces::msg::LandmarkEstimate>()
{
  return "radar_interfaces::msg::LandmarkEstimate";
}

template<>
inline const char * name<radar_interfaces::msg::LandmarkEstimate>()
{
  return "radar_interfaces/msg/LandmarkEstimate";
}

template<>
struct has_fixed_size<radar_interfaces::msg::LandmarkEstimate>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<radar_interfaces::msg::LandmarkEstimate>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<radar_interfaces::msg::LandmarkEstimate>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RADAR_INTERFACES__MSG__DETAIL__LANDMARK_ESTIMATE__TRAITS_HPP_

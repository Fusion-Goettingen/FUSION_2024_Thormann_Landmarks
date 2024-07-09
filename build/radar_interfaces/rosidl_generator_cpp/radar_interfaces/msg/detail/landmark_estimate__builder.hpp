// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from radar_interfaces:msg/LandmarkEstimate.idl
// generated code does not contain a copyright notice

#ifndef RADAR_INTERFACES__MSG__DETAIL__LANDMARK_ESTIMATE__BUILDER_HPP_
#define RADAR_INTERFACES__MSG__DETAIL__LANDMARK_ESTIMATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "radar_interfaces/msg/detail/landmark_estimate__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace radar_interfaces
{

namespace msg
{

namespace builder
{

class Init_LandmarkEstimate_angles_degree
{
public:
  explicit Init_LandmarkEstimate_angles_degree(::radar_interfaces::msg::LandmarkEstimate & msg)
  : msg_(msg)
  {}
  ::radar_interfaces::msg::LandmarkEstimate angles_degree(::radar_interfaces::msg::LandmarkEstimate::_angles_degree_type arg)
  {
    msg_.angles_degree = std::move(arg);
    return std::move(msg_);
  }

private:
  ::radar_interfaces::msg::LandmarkEstimate msg_;
};

class Init_LandmarkEstimate_heatmap
{
public:
  explicit Init_LandmarkEstimate_heatmap(::radar_interfaces::msg::LandmarkEstimate & msg)
  : msg_(msg)
  {}
  Init_LandmarkEstimate_angles_degree heatmap(::radar_interfaces::msg::LandmarkEstimate::_heatmap_type arg)
  {
    msg_.heatmap = std::move(arg);
    return Init_LandmarkEstimate_angles_degree(msg_);
  }

private:
  ::radar_interfaces::msg::LandmarkEstimate msg_;
};

class Init_LandmarkEstimate_range_bin
{
public:
  explicit Init_LandmarkEstimate_range_bin(::radar_interfaces::msg::LandmarkEstimate & msg)
  : msg_(msg)
  {}
  Init_LandmarkEstimate_heatmap range_bin(::radar_interfaces::msg::LandmarkEstimate::_range_bin_type arg)
  {
    msg_.range_bin = std::move(arg);
    return Init_LandmarkEstimate_heatmap(msg_);
  }

private:
  ::radar_interfaces::msg::LandmarkEstimate msg_;
};

class Init_LandmarkEstimate_header
{
public:
  Init_LandmarkEstimate_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LandmarkEstimate_range_bin header(::radar_interfaces::msg::LandmarkEstimate::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_LandmarkEstimate_range_bin(msg_);
  }

private:
  ::radar_interfaces::msg::LandmarkEstimate msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::radar_interfaces::msg::LandmarkEstimate>()
{
  return radar_interfaces::msg::builder::Init_LandmarkEstimate_header();
}

}  // namespace radar_interfaces

#endif  // RADAR_INTERFACES__MSG__DETAIL__LANDMARK_ESTIMATE__BUILDER_HPP_

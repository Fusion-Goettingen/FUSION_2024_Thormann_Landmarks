// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from radar_interfaces:msg/GroundTruth.idl
// generated code does not contain a copyright notice

#ifndef RADAR_INTERFACES__MSG__DETAIL__GROUND_TRUTH__STRUCT_HPP_
#define RADAR_INTERFACES__MSG__DETAIL__GROUND_TRUTH__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__radar_interfaces__msg__GroundTruth __attribute__((deprecated))
#else
# define DEPRECATED__radar_interfaces__msg__GroundTruth __declspec(deprecated)
#endif

namespace radar_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GroundTruth_
{
  using Type = GroundTruth_<ContainerAllocator>;

  explicit GroundTruth_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_moving = false;
    }
  }

  explicit GroundTruth_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_moving = false;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _relative_landmark_range_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _relative_landmark_range_type relative_landmark_range;
  using _relative_landmark_angle_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _relative_landmark_angle_type relative_landmark_angle;
  using _is_moving_type =
    bool;
  _is_moving_type is_moving;
  using _relative_position_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _relative_position_type relative_position;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__relative_landmark_range(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->relative_landmark_range = _arg;
    return *this;
  }
  Type & set__relative_landmark_angle(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->relative_landmark_angle = _arg;
    return *this;
  }
  Type & set__is_moving(
    const bool & _arg)
  {
    this->is_moving = _arg;
    return *this;
  }
  Type & set__relative_position(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->relative_position = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    radar_interfaces::msg::GroundTruth_<ContainerAllocator> *;
  using ConstRawPtr =
    const radar_interfaces::msg::GroundTruth_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<radar_interfaces::msg::GroundTruth_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<radar_interfaces::msg::GroundTruth_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      radar_interfaces::msg::GroundTruth_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<radar_interfaces::msg::GroundTruth_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      radar_interfaces::msg::GroundTruth_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<radar_interfaces::msg::GroundTruth_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<radar_interfaces::msg::GroundTruth_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<radar_interfaces::msg::GroundTruth_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__radar_interfaces__msg__GroundTruth
    std::shared_ptr<radar_interfaces::msg::GroundTruth_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__radar_interfaces__msg__GroundTruth
    std::shared_ptr<radar_interfaces::msg::GroundTruth_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GroundTruth_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->relative_landmark_range != other.relative_landmark_range) {
      return false;
    }
    if (this->relative_landmark_angle != other.relative_landmark_angle) {
      return false;
    }
    if (this->is_moving != other.is_moving) {
      return false;
    }
    if (this->relative_position != other.relative_position) {
      return false;
    }
    return true;
  }
  bool operator!=(const GroundTruth_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GroundTruth_

// alias to use template instance with default allocator
using GroundTruth =
  radar_interfaces::msg::GroundTruth_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace radar_interfaces

#endif  // RADAR_INTERFACES__MSG__DETAIL__GROUND_TRUTH__STRUCT_HPP_

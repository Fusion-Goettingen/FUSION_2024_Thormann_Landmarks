// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from radar_interfaces:msg/LandmarkEstimate.idl
// generated code does not contain a copyright notice

#ifndef RADAR_INTERFACES__MSG__DETAIL__LANDMARK_ESTIMATE__STRUCT_HPP_
#define RADAR_INTERFACES__MSG__DETAIL__LANDMARK_ESTIMATE__STRUCT_HPP_

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
# define DEPRECATED__radar_interfaces__msg__LandmarkEstimate __attribute__((deprecated))
#else
# define DEPRECATED__radar_interfaces__msg__LandmarkEstimate __declspec(deprecated)
#endif

namespace radar_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LandmarkEstimate_
{
  using Type = LandmarkEstimate_<ContainerAllocator>;

  explicit LandmarkEstimate_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit LandmarkEstimate_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _range_bin_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _range_bin_type range_bin;
  using _heatmap_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _heatmap_type heatmap;
  using _angles_degree_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _angles_degree_type angles_degree;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__range_bin(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->range_bin = _arg;
    return *this;
  }
  Type & set__heatmap(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->heatmap = _arg;
    return *this;
  }
  Type & set__angles_degree(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->angles_degree = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    radar_interfaces::msg::LandmarkEstimate_<ContainerAllocator> *;
  using ConstRawPtr =
    const radar_interfaces::msg::LandmarkEstimate_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<radar_interfaces::msg::LandmarkEstimate_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<radar_interfaces::msg::LandmarkEstimate_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      radar_interfaces::msg::LandmarkEstimate_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<radar_interfaces::msg::LandmarkEstimate_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      radar_interfaces::msg::LandmarkEstimate_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<radar_interfaces::msg::LandmarkEstimate_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<radar_interfaces::msg::LandmarkEstimate_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<radar_interfaces::msg::LandmarkEstimate_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__radar_interfaces__msg__LandmarkEstimate
    std::shared_ptr<radar_interfaces::msg::LandmarkEstimate_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__radar_interfaces__msg__LandmarkEstimate
    std::shared_ptr<radar_interfaces::msg::LandmarkEstimate_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LandmarkEstimate_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->range_bin != other.range_bin) {
      return false;
    }
    if (this->heatmap != other.heatmap) {
      return false;
    }
    if (this->angles_degree != other.angles_degree) {
      return false;
    }
    return true;
  }
  bool operator!=(const LandmarkEstimate_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LandmarkEstimate_

// alias to use template instance with default allocator
using LandmarkEstimate =
  radar_interfaces::msg::LandmarkEstimate_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace radar_interfaces

#endif  // RADAR_INTERFACES__MSG__DETAIL__LANDMARK_ESTIMATE__STRUCT_HPP_

// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from msgs:msg/TrackedDetections.idl
// generated code does not contain a copyright notice

#ifndef MSGS__MSG__DETAIL__TRACKED_DETECTIONS__BUILDER_HPP_
#define MSGS__MSG__DETAIL__TRACKED_DETECTIONS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "msgs/msg/detail/tracked_detections__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace msgs
{

namespace msg
{

namespace builder
{

class Init_TrackedDetections_thermal_image
{
public:
  explicit Init_TrackedDetections_thermal_image(::msgs::msg::TrackedDetections & msg)
  : msg_(msg)
  {}
  ::msgs::msg::TrackedDetections thermal_image(::msgs::msg::TrackedDetections::_thermal_image_type arg)
  {
    msg_.thermal_image = std::move(arg);
    return std::move(msg_);
  }

private:
  ::msgs::msg::TrackedDetections msg_;
};

class Init_TrackedDetections_rgb_image
{
public:
  explicit Init_TrackedDetections_rgb_image(::msgs::msg::TrackedDetections & msg)
  : msg_(msg)
  {}
  Init_TrackedDetections_thermal_image rgb_image(::msgs::msg::TrackedDetections::_rgb_image_type arg)
  {
    msg_.rgb_image = std::move(arg);
    return Init_TrackedDetections_thermal_image(msg_);
  }

private:
  ::msgs::msg::TrackedDetections msg_;
};

class Init_TrackedDetections_tracks
{
public:
  explicit Init_TrackedDetections_tracks(::msgs::msg::TrackedDetections & msg)
  : msg_(msg)
  {}
  Init_TrackedDetections_rgb_image tracks(::msgs::msg::TrackedDetections::_tracks_type arg)
  {
    msg_.tracks = std::move(arg);
    return Init_TrackedDetections_rgb_image(msg_);
  }

private:
  ::msgs::msg::TrackedDetections msg_;
};

class Init_TrackedDetections_gps
{
public:
  Init_TrackedDetections_gps()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TrackedDetections_tracks gps(::msgs::msg::TrackedDetections::_gps_type arg)
  {
    msg_.gps = std::move(arg);
    return Init_TrackedDetections_tracks(msg_);
  }

private:
  ::msgs::msg::TrackedDetections msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::msgs::msg::TrackedDetections>()
{
  return msgs::msg::builder::Init_TrackedDetections_gps();
}

}  // namespace msgs

#endif  // MSGS__MSG__DETAIL__TRACKED_DETECTIONS__BUILDER_HPP_

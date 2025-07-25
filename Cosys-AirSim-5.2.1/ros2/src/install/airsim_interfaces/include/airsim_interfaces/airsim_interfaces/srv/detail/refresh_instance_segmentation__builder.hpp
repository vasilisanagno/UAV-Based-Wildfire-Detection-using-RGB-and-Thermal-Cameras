// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from airsim_interfaces:srv/RefreshInstanceSegmentation.idl
// generated code does not contain a copyright notice

#ifndef AIRSIM_INTERFACES__SRV__DETAIL__REFRESH_INSTANCE_SEGMENTATION__BUILDER_HPP_
#define AIRSIM_INTERFACES__SRV__DETAIL__REFRESH_INSTANCE_SEGMENTATION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "airsim_interfaces/srv/detail/refresh_instance_segmentation__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace airsim_interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::airsim_interfaces::srv::RefreshInstanceSegmentation_Request>()
{
  return ::airsim_interfaces::srv::RefreshInstanceSegmentation_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace airsim_interfaces


namespace airsim_interfaces
{

namespace srv
{

namespace builder
{

class Init_RefreshInstanceSegmentation_Response_success
{
public:
  Init_RefreshInstanceSegmentation_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::airsim_interfaces::srv::RefreshInstanceSegmentation_Response success(::airsim_interfaces::srv::RefreshInstanceSegmentation_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::airsim_interfaces::srv::RefreshInstanceSegmentation_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::airsim_interfaces::srv::RefreshInstanceSegmentation_Response>()
{
  return airsim_interfaces::srv::builder::Init_RefreshInstanceSegmentation_Response_success();
}

}  // namespace airsim_interfaces


namespace airsim_interfaces
{

namespace srv
{

namespace builder
{

class Init_RefreshInstanceSegmentation_Event_response
{
public:
  explicit Init_RefreshInstanceSegmentation_Event_response(::airsim_interfaces::srv::RefreshInstanceSegmentation_Event & msg)
  : msg_(msg)
  {}
  ::airsim_interfaces::srv::RefreshInstanceSegmentation_Event response(::airsim_interfaces::srv::RefreshInstanceSegmentation_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::airsim_interfaces::srv::RefreshInstanceSegmentation_Event msg_;
};

class Init_RefreshInstanceSegmentation_Event_request
{
public:
  explicit Init_RefreshInstanceSegmentation_Event_request(::airsim_interfaces::srv::RefreshInstanceSegmentation_Event & msg)
  : msg_(msg)
  {}
  Init_RefreshInstanceSegmentation_Event_response request(::airsim_interfaces::srv::RefreshInstanceSegmentation_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_RefreshInstanceSegmentation_Event_response(msg_);
  }

private:
  ::airsim_interfaces::srv::RefreshInstanceSegmentation_Event msg_;
};

class Init_RefreshInstanceSegmentation_Event_info
{
public:
  Init_RefreshInstanceSegmentation_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RefreshInstanceSegmentation_Event_request info(::airsim_interfaces::srv::RefreshInstanceSegmentation_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_RefreshInstanceSegmentation_Event_request(msg_);
  }

private:
  ::airsim_interfaces::srv::RefreshInstanceSegmentation_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::airsim_interfaces::srv::RefreshInstanceSegmentation_Event>()
{
  return airsim_interfaces::srv::builder::Init_RefreshInstanceSegmentation_Event_info();
}

}  // namespace airsim_interfaces

#endif  // AIRSIM_INTERFACES__SRV__DETAIL__REFRESH_INSTANCE_SEGMENTATION__BUILDER_HPP_

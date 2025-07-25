// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from airsim_interfaces:srv/Reset.idl
// generated code does not contain a copyright notice

#ifndef AIRSIM_INTERFACES__SRV__DETAIL__RESET__BUILDER_HPP_
#define AIRSIM_INTERFACES__SRV__DETAIL__RESET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "airsim_interfaces/srv/detail/reset__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace airsim_interfaces
{

namespace srv
{

namespace builder
{

class Init_Reset_Request_wait_on_last_task
{
public:
  Init_Reset_Request_wait_on_last_task()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::airsim_interfaces::srv::Reset_Request wait_on_last_task(::airsim_interfaces::srv::Reset_Request::_wait_on_last_task_type arg)
  {
    msg_.wait_on_last_task = std::move(arg);
    return std::move(msg_);
  }

private:
  ::airsim_interfaces::srv::Reset_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::airsim_interfaces::srv::Reset_Request>()
{
  return airsim_interfaces::srv::builder::Init_Reset_Request_wait_on_last_task();
}

}  // namespace airsim_interfaces


namespace airsim_interfaces
{

namespace srv
{

namespace builder
{

class Init_Reset_Response_success
{
public:
  Init_Reset_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::airsim_interfaces::srv::Reset_Response success(::airsim_interfaces::srv::Reset_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::airsim_interfaces::srv::Reset_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::airsim_interfaces::srv::Reset_Response>()
{
  return airsim_interfaces::srv::builder::Init_Reset_Response_success();
}

}  // namespace airsim_interfaces


namespace airsim_interfaces
{

namespace srv
{

namespace builder
{

class Init_Reset_Event_response
{
public:
  explicit Init_Reset_Event_response(::airsim_interfaces::srv::Reset_Event & msg)
  : msg_(msg)
  {}
  ::airsim_interfaces::srv::Reset_Event response(::airsim_interfaces::srv::Reset_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::airsim_interfaces::srv::Reset_Event msg_;
};

class Init_Reset_Event_request
{
public:
  explicit Init_Reset_Event_request(::airsim_interfaces::srv::Reset_Event & msg)
  : msg_(msg)
  {}
  Init_Reset_Event_response request(::airsim_interfaces::srv::Reset_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Reset_Event_response(msg_);
  }

private:
  ::airsim_interfaces::srv::Reset_Event msg_;
};

class Init_Reset_Event_info
{
public:
  Init_Reset_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Reset_Event_request info(::airsim_interfaces::srv::Reset_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Reset_Event_request(msg_);
  }

private:
  ::airsim_interfaces::srv::Reset_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::airsim_interfaces::srv::Reset_Event>()
{
  return airsim_interfaces::srv::builder::Init_Reset_Event_info();
}

}  // namespace airsim_interfaces

#endif  // AIRSIM_INTERFACES__SRV__DETAIL__RESET__BUILDER_HPP_

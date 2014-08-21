/* Software License Agreement (BSD License)
 *
 * Copyright (c) 2011, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution.
 *  * Neither the name of Willow Garage, Inc. nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * Auto-generated by genmsg_cpp from file /home/lars/OculusCamViewer_new/src/robotcamera/dynamixel_motor/dynamixel_controllers/srv/TorqueEnable.srv
 *
 */


#ifndef DYNAMIXEL_CONTROLLERS_MESSAGE_TORQUEENABLEREQUEST_H
#define DYNAMIXEL_CONTROLLERS_MESSAGE_TORQUEENABLEREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace dynamixel_controllers
{
template <class ContainerAllocator>
struct TorqueEnableRequest_
{
  typedef TorqueEnableRequest_<ContainerAllocator> Type;

  TorqueEnableRequest_()
    : torque_enable(false)  {
    }
  TorqueEnableRequest_(const ContainerAllocator& _alloc)
    : torque_enable(false)  {
    }



   typedef uint8_t _torque_enable_type;
  _torque_enable_type torque_enable;




  typedef boost::shared_ptr< ::dynamixel_controllers::TorqueEnableRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dynamixel_controllers::TorqueEnableRequest_<ContainerAllocator> const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;

}; // struct TorqueEnableRequest_

typedef ::dynamixel_controllers::TorqueEnableRequest_<std::allocator<void> > TorqueEnableRequest;

typedef boost::shared_ptr< ::dynamixel_controllers::TorqueEnableRequest > TorqueEnableRequestPtr;
typedef boost::shared_ptr< ::dynamixel_controllers::TorqueEnableRequest const> TorqueEnableRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dynamixel_controllers::TorqueEnableRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dynamixel_controllers::TorqueEnableRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace dynamixel_controllers

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::dynamixel_controllers::TorqueEnableRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dynamixel_controllers::TorqueEnableRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dynamixel_controllers::TorqueEnableRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dynamixel_controllers::TorqueEnableRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dynamixel_controllers::TorqueEnableRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dynamixel_controllers::TorqueEnableRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dynamixel_controllers::TorqueEnableRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "e44dc96db32bd58b5a896c2c5bf316d0";
  }

  static const char* value(const ::dynamixel_controllers::TorqueEnableRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xe44dc96db32bd58bULL;
  static const uint64_t static_value2 = 0x5a896c2c5bf316d0ULL;
};

template<class ContainerAllocator>
struct DataType< ::dynamixel_controllers::TorqueEnableRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dynamixel_controllers/TorqueEnableRequest";
  }

  static const char* value(const ::dynamixel_controllers::TorqueEnableRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dynamixel_controllers::TorqueEnableRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool torque_enable\n\
";
  }

  static const char* value(const ::dynamixel_controllers::TorqueEnableRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dynamixel_controllers::TorqueEnableRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.torque_enable);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct TorqueEnableRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dynamixel_controllers::TorqueEnableRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dynamixel_controllers::TorqueEnableRequest_<ContainerAllocator>& v)
  {
    s << indent << "torque_enable: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.torque_enable);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DYNAMIXEL_CONTROLLERS_MESSAGE_TORQUEENABLEREQUEST_H

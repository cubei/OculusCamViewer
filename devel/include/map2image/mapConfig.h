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
 * Auto-generated by genmsg_cpp from file /home/lars/OculusCamViewer_new/src/map2image/msg/mapConfig.msg
 *
 */


#ifndef MAP2IMAGE_MESSAGE_MAPCONFIG_H
#define MAP2IMAGE_MESSAGE_MAPCONFIG_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace map2image
{
template <class ContainerAllocator>
struct mapConfig_
{
  typedef mapConfig_<ContainerAllocator> Type;

  mapConfig_()
    : header()
    , mapSize(0)
    , mapRange(0.0)
    , viewingAngle(0)  {
    }
  mapConfig_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , mapSize(0)
    , mapRange(0.0)
    , viewingAngle(0)  {
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef uint32_t _mapSize_type;
  _mapSize_type mapSize;

   typedef double _mapRange_type;
  _mapRange_type mapRange;

   typedef uint32_t _viewingAngle_type;
  _viewingAngle_type viewingAngle;




  typedef boost::shared_ptr< ::map2image::mapConfig_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::map2image::mapConfig_<ContainerAllocator> const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;

}; // struct mapConfig_

typedef ::map2image::mapConfig_<std::allocator<void> > mapConfig;

typedef boost::shared_ptr< ::map2image::mapConfig > mapConfigPtr;
typedef boost::shared_ptr< ::map2image::mapConfig const> mapConfigConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::map2image::mapConfig_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::map2image::mapConfig_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace map2image

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'map2image': ['/home/lars/OculusCamViewer_new/src/map2image/msg'], 'std_msgs': ['/opt/ros/hydro/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::map2image::mapConfig_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::map2image::mapConfig_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::map2image::mapConfig_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::map2image::mapConfig_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::map2image::mapConfig_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::map2image::mapConfig_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::map2image::mapConfig_<ContainerAllocator> >
{
  static const char* value()
  {
    return "9aa3b0d3ec111dcf83079d026870e7be";
  }

  static const char* value(const ::map2image::mapConfig_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x9aa3b0d3ec111dcfULL;
  static const uint64_t static_value2 = 0x83079d026870e7beULL;
};

template<class ContainerAllocator>
struct DataType< ::map2image::mapConfig_<ContainerAllocator> >
{
  static const char* value()
  {
    return "map2image/mapConfig";
  }

  static const char* value(const ::map2image::mapConfig_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::map2image::mapConfig_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
uint32 mapSize\n\
float64 mapRange\n\
uint32 viewingAngle\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.secs: seconds (stamp_secs) since epoch\n\
# * stamp.nsecs: nanoseconds since stamp_secs\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::map2image::mapConfig_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::map2image::mapConfig_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.mapSize);
      stream.next(m.mapRange);
      stream.next(m.viewingAngle);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct mapConfig_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::map2image::mapConfig_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::map2image::mapConfig_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "mapSize: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.mapSize);
    s << indent << "mapRange: ";
    Printer<double>::stream(s, indent + "  ", v.mapRange);
    s << indent << "viewingAngle: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.viewingAngle);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MAP2IMAGE_MESSAGE_MAPCONFIG_H

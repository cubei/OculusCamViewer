; Auto-generated. Do not edit!


(cl:in-package map2image-msg)


;//! \htmlinclude mapConfig.msg.html

(cl:defclass <mapConfig> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (mapSize
    :reader mapSize
    :initarg :mapSize
    :type cl:integer
    :initform 0)
   (mapRange
    :reader mapRange
    :initarg :mapRange
    :type cl:float
    :initform 0.0)
   (viewingAngle
    :reader viewingAngle
    :initarg :viewingAngle
    :type cl:integer
    :initform 0))
)

(cl:defclass mapConfig (<mapConfig>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <mapConfig>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'mapConfig)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name map2image-msg:<mapConfig> is deprecated: use map2image-msg:mapConfig instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <mapConfig>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader map2image-msg:header-val is deprecated.  Use map2image-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'mapSize-val :lambda-list '(m))
(cl:defmethod mapSize-val ((m <mapConfig>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader map2image-msg:mapSize-val is deprecated.  Use map2image-msg:mapSize instead.")
  (mapSize m))

(cl:ensure-generic-function 'mapRange-val :lambda-list '(m))
(cl:defmethod mapRange-val ((m <mapConfig>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader map2image-msg:mapRange-val is deprecated.  Use map2image-msg:mapRange instead.")
  (mapRange m))

(cl:ensure-generic-function 'viewingAngle-val :lambda-list '(m))
(cl:defmethod viewingAngle-val ((m <mapConfig>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader map2image-msg:viewingAngle-val is deprecated.  Use map2image-msg:viewingAngle instead.")
  (viewingAngle m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <mapConfig>) ostream)
  "Serializes a message object of type '<mapConfig>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'mapSize)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'mapSize)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'mapSize)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'mapSize)) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'mapRange))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'viewingAngle)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'viewingAngle)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'viewingAngle)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'viewingAngle)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <mapConfig>) istream)
  "Deserializes a message object of type '<mapConfig>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'mapSize)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'mapSize)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'mapSize)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'mapSize)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'mapRange) (roslisp-utils:decode-double-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'viewingAngle)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'viewingAngle)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'viewingAngle)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'viewingAngle)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<mapConfig>)))
  "Returns string type for a message object of type '<mapConfig>"
  "map2image/mapConfig")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'mapConfig)))
  "Returns string type for a message object of type 'mapConfig"
  "map2image/mapConfig")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<mapConfig>)))
  "Returns md5sum for a message object of type '<mapConfig>"
  "9aa3b0d3ec111dcf83079d026870e7be")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'mapConfig)))
  "Returns md5sum for a message object of type 'mapConfig"
  "9aa3b0d3ec111dcf83079d026870e7be")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<mapConfig>)))
  "Returns full string definition for message of type '<mapConfig>"
  (cl:format cl:nil "Header header~%uint32 mapSize~%float64 mapRange~%uint32 viewingAngle~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'mapConfig)))
  "Returns full string definition for message of type 'mapConfig"
  (cl:format cl:nil "Header header~%uint32 mapSize~%float64 mapRange~%uint32 viewingAngle~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <mapConfig>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
     8
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <mapConfig>))
  "Converts a ROS message object to a list"
  (cl:list 'mapConfig
    (cl:cons ':header (header msg))
    (cl:cons ':mapSize (mapSize msg))
    (cl:cons ':mapRange (mapRange msg))
    (cl:cons ':viewingAngle (viewingAngle msg))
))

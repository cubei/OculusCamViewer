; Auto-generated. Do not edit!


(cl:in-package oculus_msgs-msg)


;//! \htmlinclude HMDInfo.msg.html

(cl:defclass <HMDInfo> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (display_device_name
    :reader display_device_name
    :initarg :display_device_name
    :type cl:string
    :initform "")
   (product_name
    :reader product_name
    :initarg :product_name
    :type cl:string
    :initform "")
   (manufacturer
    :reader manufacturer
    :initarg :manufacturer
    :type cl:string
    :initform "")
   (version
    :reader version
    :initarg :version
    :type cl:integer
    :initform 0)
   (horizontal_resolution
    :reader horizontal_resolution
    :initarg :horizontal_resolution
    :type cl:integer
    :initform 0)
   (vertical_resolution
    :reader vertical_resolution
    :initarg :vertical_resolution
    :type cl:integer
    :initform 0)
   (horizontal_screen_size
    :reader horizontal_screen_size
    :initarg :horizontal_screen_size
    :type cl:float
    :initform 0.0)
   (vertical_screen_size
    :reader vertical_screen_size
    :initarg :vertical_screen_size
    :type cl:float
    :initform 0.0)
   (vertical_screen_center
    :reader vertical_screen_center
    :initarg :vertical_screen_center
    :type cl:float
    :initform 0.0)
   (eye_to_screen_distance
    :reader eye_to_screen_distance
    :initarg :eye_to_screen_distance
    :type cl:float
    :initform 0.0)
   (lens_separation_distance
    :reader lens_separation_distance
    :initarg :lens_separation_distance
    :type cl:float
    :initform 0.0)
   (interpupillary_distance
    :reader interpupillary_distance
    :initarg :interpupillary_distance
    :type cl:float
    :initform 0.0)
   (desktop_x
    :reader desktop_x
    :initarg :desktop_x
    :type cl:integer
    :initform 0)
   (desktop_y
    :reader desktop_y
    :initarg :desktop_y
    :type cl:integer
    :initform 0)
   (display_id
    :reader display_id
    :initarg :display_id
    :type cl:integer
    :initform 0)
   (distortion_K
    :reader distortion_K
    :initarg :distortion_K
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass HMDInfo (<HMDInfo>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <HMDInfo>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'HMDInfo)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name oculus_msgs-msg:<HMDInfo> is deprecated: use oculus_msgs-msg:HMDInfo instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <HMDInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader oculus_msgs-msg:header-val is deprecated.  Use oculus_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'display_device_name-val :lambda-list '(m))
(cl:defmethod display_device_name-val ((m <HMDInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader oculus_msgs-msg:display_device_name-val is deprecated.  Use oculus_msgs-msg:display_device_name instead.")
  (display_device_name m))

(cl:ensure-generic-function 'product_name-val :lambda-list '(m))
(cl:defmethod product_name-val ((m <HMDInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader oculus_msgs-msg:product_name-val is deprecated.  Use oculus_msgs-msg:product_name instead.")
  (product_name m))

(cl:ensure-generic-function 'manufacturer-val :lambda-list '(m))
(cl:defmethod manufacturer-val ((m <HMDInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader oculus_msgs-msg:manufacturer-val is deprecated.  Use oculus_msgs-msg:manufacturer instead.")
  (manufacturer m))

(cl:ensure-generic-function 'version-val :lambda-list '(m))
(cl:defmethod version-val ((m <HMDInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader oculus_msgs-msg:version-val is deprecated.  Use oculus_msgs-msg:version instead.")
  (version m))

(cl:ensure-generic-function 'horizontal_resolution-val :lambda-list '(m))
(cl:defmethod horizontal_resolution-val ((m <HMDInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader oculus_msgs-msg:horizontal_resolution-val is deprecated.  Use oculus_msgs-msg:horizontal_resolution instead.")
  (horizontal_resolution m))

(cl:ensure-generic-function 'vertical_resolution-val :lambda-list '(m))
(cl:defmethod vertical_resolution-val ((m <HMDInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader oculus_msgs-msg:vertical_resolution-val is deprecated.  Use oculus_msgs-msg:vertical_resolution instead.")
  (vertical_resolution m))

(cl:ensure-generic-function 'horizontal_screen_size-val :lambda-list '(m))
(cl:defmethod horizontal_screen_size-val ((m <HMDInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader oculus_msgs-msg:horizontal_screen_size-val is deprecated.  Use oculus_msgs-msg:horizontal_screen_size instead.")
  (horizontal_screen_size m))

(cl:ensure-generic-function 'vertical_screen_size-val :lambda-list '(m))
(cl:defmethod vertical_screen_size-val ((m <HMDInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader oculus_msgs-msg:vertical_screen_size-val is deprecated.  Use oculus_msgs-msg:vertical_screen_size instead.")
  (vertical_screen_size m))

(cl:ensure-generic-function 'vertical_screen_center-val :lambda-list '(m))
(cl:defmethod vertical_screen_center-val ((m <HMDInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader oculus_msgs-msg:vertical_screen_center-val is deprecated.  Use oculus_msgs-msg:vertical_screen_center instead.")
  (vertical_screen_center m))

(cl:ensure-generic-function 'eye_to_screen_distance-val :lambda-list '(m))
(cl:defmethod eye_to_screen_distance-val ((m <HMDInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader oculus_msgs-msg:eye_to_screen_distance-val is deprecated.  Use oculus_msgs-msg:eye_to_screen_distance instead.")
  (eye_to_screen_distance m))

(cl:ensure-generic-function 'lens_separation_distance-val :lambda-list '(m))
(cl:defmethod lens_separation_distance-val ((m <HMDInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader oculus_msgs-msg:lens_separation_distance-val is deprecated.  Use oculus_msgs-msg:lens_separation_distance instead.")
  (lens_separation_distance m))

(cl:ensure-generic-function 'interpupillary_distance-val :lambda-list '(m))
(cl:defmethod interpupillary_distance-val ((m <HMDInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader oculus_msgs-msg:interpupillary_distance-val is deprecated.  Use oculus_msgs-msg:interpupillary_distance instead.")
  (interpupillary_distance m))

(cl:ensure-generic-function 'desktop_x-val :lambda-list '(m))
(cl:defmethod desktop_x-val ((m <HMDInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader oculus_msgs-msg:desktop_x-val is deprecated.  Use oculus_msgs-msg:desktop_x instead.")
  (desktop_x m))

(cl:ensure-generic-function 'desktop_y-val :lambda-list '(m))
(cl:defmethod desktop_y-val ((m <HMDInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader oculus_msgs-msg:desktop_y-val is deprecated.  Use oculus_msgs-msg:desktop_y instead.")
  (desktop_y m))

(cl:ensure-generic-function 'display_id-val :lambda-list '(m))
(cl:defmethod display_id-val ((m <HMDInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader oculus_msgs-msg:display_id-val is deprecated.  Use oculus_msgs-msg:display_id instead.")
  (display_id m))

(cl:ensure-generic-function 'distortion_K-val :lambda-list '(m))
(cl:defmethod distortion_K-val ((m <HMDInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader oculus_msgs-msg:distortion_K-val is deprecated.  Use oculus_msgs-msg:distortion_K instead.")
  (distortion_K m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <HMDInfo>) ostream)
  "Serializes a message object of type '<HMDInfo>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'display_device_name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'display_device_name))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'product_name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'product_name))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'manufacturer))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'manufacturer))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'version)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'version)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'version)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'version)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'horizontal_resolution)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'horizontal_resolution)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'horizontal_resolution)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'horizontal_resolution)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'vertical_resolution)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'vertical_resolution)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'vertical_resolution)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'vertical_resolution)) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'horizontal_screen_size))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'vertical_screen_size))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'vertical_screen_center))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'eye_to_screen_distance))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'lens_separation_distance))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'interpupillary_distance))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let* ((signed (cl:slot-value msg 'desktop_x)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'desktop_y)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'display_id)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'distortion_K))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'distortion_K))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <HMDInfo>) istream)
  "Deserializes a message object of type '<HMDInfo>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'display_device_name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'display_device_name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'product_name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'product_name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'manufacturer) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'manufacturer) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'version)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'version)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'version)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'version)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'horizontal_resolution)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'horizontal_resolution)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'horizontal_resolution)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'horizontal_resolution)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'vertical_resolution)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'vertical_resolution)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'vertical_resolution)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'vertical_resolution)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'horizontal_screen_size) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'vertical_screen_size) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'vertical_screen_center) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'eye_to_screen_distance) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'lens_separation_distance) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'interpupillary_distance) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'desktop_x) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'desktop_y) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'display_id) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'distortion_K) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'distortion_K)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<HMDInfo>)))
  "Returns string type for a message object of type '<HMDInfo>"
  "oculus_msgs/HMDInfo")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'HMDInfo)))
  "Returns string type for a message object of type 'HMDInfo"
  "oculus_msgs/HMDInfo")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<HMDInfo>)))
  "Returns md5sum for a message object of type '<HMDInfo>"
  "9fd415a6483b21473bf35e7a4b8c2302")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'HMDInfo)))
  "Returns md5sum for a message object of type 'HMDInfo"
  "9fd415a6483b21473bf35e7a4b8c2302")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<HMDInfo>)))
  "Returns full string definition for message of type '<HMDInfo>"
  (cl:format cl:nil "Header header~%string display_device_name~%string product_name~%string manufacturer~%uint32 version~%uint32 horizontal_resolution~%uint32 vertical_resolution~%float32 horizontal_screen_size~%float32 vertical_screen_size~%float32 vertical_screen_center~%float32 eye_to_screen_distance~%float32 lens_separation_distance~%float32 interpupillary_distance~%int32 desktop_x~%int32 desktop_y~%int32 display_id~%float32[] distortion_K~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'HMDInfo)))
  "Returns full string definition for message of type 'HMDInfo"
  (cl:format cl:nil "Header header~%string display_device_name~%string product_name~%string manufacturer~%uint32 version~%uint32 horizontal_resolution~%uint32 vertical_resolution~%float32 horizontal_screen_size~%float32 vertical_screen_size~%float32 vertical_screen_center~%float32 eye_to_screen_distance~%float32 lens_separation_distance~%float32 interpupillary_distance~%int32 desktop_x~%int32 desktop_y~%int32 display_id~%float32[] distortion_K~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <HMDInfo>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4 (cl:length (cl:slot-value msg 'display_device_name))
     4 (cl:length (cl:slot-value msg 'product_name))
     4 (cl:length (cl:slot-value msg 'manufacturer))
     4
     4
     4
     4
     4
     4
     4
     4
     4
     4
     4
     4
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'distortion_K) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <HMDInfo>))
  "Converts a ROS message object to a list"
  (cl:list 'HMDInfo
    (cl:cons ':header (header msg))
    (cl:cons ':display_device_name (display_device_name msg))
    (cl:cons ':product_name (product_name msg))
    (cl:cons ':manufacturer (manufacturer msg))
    (cl:cons ':version (version msg))
    (cl:cons ':horizontal_resolution (horizontal_resolution msg))
    (cl:cons ':vertical_resolution (vertical_resolution msg))
    (cl:cons ':horizontal_screen_size (horizontal_screen_size msg))
    (cl:cons ':vertical_screen_size (vertical_screen_size msg))
    (cl:cons ':vertical_screen_center (vertical_screen_center msg))
    (cl:cons ':eye_to_screen_distance (eye_to_screen_distance msg))
    (cl:cons ':lens_separation_distance (lens_separation_distance msg))
    (cl:cons ':interpupillary_distance (interpupillary_distance msg))
    (cl:cons ':desktop_x (desktop_x msg))
    (cl:cons ':desktop_y (desktop_y msg))
    (cl:cons ':display_id (display_id msg))
    (cl:cons ':distortion_K (distortion_K msg))
))

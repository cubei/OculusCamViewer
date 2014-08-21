
(cl:in-package :asdf)

(defsystem "oculus_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "HMDInfo" :depends-on ("_package_HMDInfo"))
    (:file "_package_HMDInfo" :depends-on ("_package"))
  ))
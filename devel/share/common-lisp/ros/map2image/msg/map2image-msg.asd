
(cl:in-package :asdf)

(defsystem "map2image-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "mapConfig" :depends-on ("_package_mapConfig"))
    (:file "_package_mapConfig" :depends-on ("_package"))
  ))
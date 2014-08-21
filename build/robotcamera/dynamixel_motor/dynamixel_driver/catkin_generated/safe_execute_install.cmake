execute_process(COMMAND "/home/lars/OculusCamViewer_new/build/robotcamera/dynamixel_motor/dynamixel_driver/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/lars/OculusCamViewer_new/build/robotcamera/dynamixel_motor/dynamixel_driver/catkin_generated/python_distutils_install.sh) returned error code ")
endif()

# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lars/OculusCamViewer_new/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lars/OculusCamViewer_new/build

# Include any dependencies generated for this target.
include robotcamera/rosaria/CMakeFiles/RosAria.dir/depend.make

# Include the progress variables for this target.
include robotcamera/rosaria/CMakeFiles/RosAria.dir/progress.make

# Include the compile flags for this target's objects.
include robotcamera/rosaria/CMakeFiles/RosAria.dir/flags.make

robotcamera/rosaria/CMakeFiles/RosAria.dir/RosAria.cpp.o: robotcamera/rosaria/CMakeFiles/RosAria.dir/flags.make
robotcamera/rosaria/CMakeFiles/RosAria.dir/RosAria.cpp.o: /home/lars/OculusCamViewer_new/src/robotcamera/rosaria/RosAria.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/lars/OculusCamViewer_new/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object robotcamera/rosaria/CMakeFiles/RosAria.dir/RosAria.cpp.o"
	cd /home/lars/OculusCamViewer_new/build/robotcamera/rosaria && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -fPIC -o CMakeFiles/RosAria.dir/RosAria.cpp.o -c /home/lars/OculusCamViewer_new/src/robotcamera/rosaria/RosAria.cpp

robotcamera/rosaria/CMakeFiles/RosAria.dir/RosAria.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RosAria.dir/RosAria.cpp.i"
	cd /home/lars/OculusCamViewer_new/build/robotcamera/rosaria && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -fPIC -E /home/lars/OculusCamViewer_new/src/robotcamera/rosaria/RosAria.cpp > CMakeFiles/RosAria.dir/RosAria.cpp.i

robotcamera/rosaria/CMakeFiles/RosAria.dir/RosAria.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RosAria.dir/RosAria.cpp.s"
	cd /home/lars/OculusCamViewer_new/build/robotcamera/rosaria && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -fPIC -S /home/lars/OculusCamViewer_new/src/robotcamera/rosaria/RosAria.cpp -o CMakeFiles/RosAria.dir/RosAria.cpp.s

robotcamera/rosaria/CMakeFiles/RosAria.dir/RosAria.cpp.o.requires:
.PHONY : robotcamera/rosaria/CMakeFiles/RosAria.dir/RosAria.cpp.o.requires

robotcamera/rosaria/CMakeFiles/RosAria.dir/RosAria.cpp.o.provides: robotcamera/rosaria/CMakeFiles/RosAria.dir/RosAria.cpp.o.requires
	$(MAKE) -f robotcamera/rosaria/CMakeFiles/RosAria.dir/build.make robotcamera/rosaria/CMakeFiles/RosAria.dir/RosAria.cpp.o.provides.build
.PHONY : robotcamera/rosaria/CMakeFiles/RosAria.dir/RosAria.cpp.o.provides

robotcamera/rosaria/CMakeFiles/RosAria.dir/RosAria.cpp.o.provides.build: robotcamera/rosaria/CMakeFiles/RosAria.dir/RosAria.cpp.o

# Object files for target RosAria
RosAria_OBJECTS = \
"CMakeFiles/RosAria.dir/RosAria.cpp.o"

# External object files for target RosAria
RosAria_EXTERNAL_OBJECTS =

/home/lars/OculusCamViewer_new/devel/lib/rosaria/RosAria: robotcamera/rosaria/CMakeFiles/RosAria.dir/RosAria.cpp.o
/home/lars/OculusCamViewer_new/devel/lib/rosaria/RosAria: /opt/ros/hydro/lib/libtf.so
/home/lars/OculusCamViewer_new/devel/lib/rosaria/RosAria: /opt/ros/hydro/lib/libtf2_ros.so
/home/lars/OculusCamViewer_new/devel/lib/rosaria/RosAria: /opt/ros/hydro/lib/libactionlib.so
/home/lars/OculusCamViewer_new/devel/lib/rosaria/RosAria: /opt/ros/hydro/lib/libmessage_filters.so
/home/lars/OculusCamViewer_new/devel/lib/rosaria/RosAria: /opt/ros/hydro/lib/libroscpp.so
/home/lars/OculusCamViewer_new/devel/lib/rosaria/RosAria: /usr/lib/libboost_signals-mt.so
/home/lars/OculusCamViewer_new/devel/lib/rosaria/RosAria: /usr/lib/libboost_filesystem-mt.so
/home/lars/OculusCamViewer_new/devel/lib/rosaria/RosAria: /opt/ros/hydro/lib/libxmlrpcpp.so
/home/lars/OculusCamViewer_new/devel/lib/rosaria/RosAria: /opt/ros/hydro/lib/libtf2.so
/home/lars/OculusCamViewer_new/devel/lib/rosaria/RosAria: /opt/ros/hydro/lib/librosconsole.so
/home/lars/OculusCamViewer_new/devel/lib/rosaria/RosAria: /opt/ros/hydro/lib/librosconsole_log4cxx.so
/home/lars/OculusCamViewer_new/devel/lib/rosaria/RosAria: /opt/ros/hydro/lib/librosconsole_backend_interface.so
/home/lars/OculusCamViewer_new/devel/lib/rosaria/RosAria: /usr/lib/liblog4cxx.so
/home/lars/OculusCamViewer_new/devel/lib/rosaria/RosAria: /usr/lib/libboost_regex-mt.so
/home/lars/OculusCamViewer_new/devel/lib/rosaria/RosAria: /opt/ros/hydro/lib/libdynamic_reconfigure_config_init_mutex.so
/home/lars/OculusCamViewer_new/devel/lib/rosaria/RosAria: /opt/ros/hydro/lib/libroscpp_serialization.so
/home/lars/OculusCamViewer_new/devel/lib/rosaria/RosAria: /opt/ros/hydro/lib/librostime.so
/home/lars/OculusCamViewer_new/devel/lib/rosaria/RosAria: /usr/lib/libboost_date_time-mt.so
/home/lars/OculusCamViewer_new/devel/lib/rosaria/RosAria: /usr/lib/libboost_system-mt.so
/home/lars/OculusCamViewer_new/devel/lib/rosaria/RosAria: /usr/lib/libboost_thread-mt.so
/home/lars/OculusCamViewer_new/devel/lib/rosaria/RosAria: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/lars/OculusCamViewer_new/devel/lib/rosaria/RosAria: /opt/ros/hydro/lib/libcpp_common.so
/home/lars/OculusCamViewer_new/devel/lib/rosaria/RosAria: /opt/ros/hydro/lib/libconsole_bridge.so
/home/lars/OculusCamViewer_new/devel/lib/rosaria/RosAria: /usr/lib/libboost_thread-mt.so
/home/lars/OculusCamViewer_new/devel/lib/rosaria/RosAria: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/lars/OculusCamViewer_new/devel/lib/rosaria/RosAria: /opt/ros/hydro/lib/libcpp_common.so
/home/lars/OculusCamViewer_new/devel/lib/rosaria/RosAria: /opt/ros/hydro/lib/libconsole_bridge.so
/home/lars/OculusCamViewer_new/devel/lib/rosaria/RosAria: robotcamera/rosaria/CMakeFiles/RosAria.dir/build.make
/home/lars/OculusCamViewer_new/devel/lib/rosaria/RosAria: robotcamera/rosaria/CMakeFiles/RosAria.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable /home/lars/OculusCamViewer_new/devel/lib/rosaria/RosAria"
	cd /home/lars/OculusCamViewer_new/build/robotcamera/rosaria && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RosAria.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
robotcamera/rosaria/CMakeFiles/RosAria.dir/build: /home/lars/OculusCamViewer_new/devel/lib/rosaria/RosAria
.PHONY : robotcamera/rosaria/CMakeFiles/RosAria.dir/build

robotcamera/rosaria/CMakeFiles/RosAria.dir/requires: robotcamera/rosaria/CMakeFiles/RosAria.dir/RosAria.cpp.o.requires
.PHONY : robotcamera/rosaria/CMakeFiles/RosAria.dir/requires

robotcamera/rosaria/CMakeFiles/RosAria.dir/clean:
	cd /home/lars/OculusCamViewer_new/build/robotcamera/rosaria && $(CMAKE_COMMAND) -P CMakeFiles/RosAria.dir/cmake_clean.cmake
.PHONY : robotcamera/rosaria/CMakeFiles/RosAria.dir/clean

robotcamera/rosaria/CMakeFiles/RosAria.dir/depend:
	cd /home/lars/OculusCamViewer_new/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lars/OculusCamViewer_new/src /home/lars/OculusCamViewer_new/src/robotcamera/rosaria /home/lars/OculusCamViewer_new/build /home/lars/OculusCamViewer_new/build/robotcamera/rosaria /home/lars/OculusCamViewer_new/build/robotcamera/rosaria/CMakeFiles/RosAria.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : robotcamera/rosaria/CMakeFiles/RosAria.dir/depend


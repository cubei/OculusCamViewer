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
include measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/depend.make

# Include the progress variables for this target.
include measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/progress.make

# Include the compile flags for this target's objects.
include measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/flags.make

measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer_node.cpp.o: measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/flags.make
measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer_node.cpp.o: /home/lars/OculusCamViewer_new/src/measurement/measure_image_transfer/src/measure_image_transfer_node.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/lars/OculusCamViewer_new/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer_node.cpp.o"
	cd /home/lars/OculusCamViewer_new/build/measurement/measure_image_transfer && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer_node.cpp.o -c /home/lars/OculusCamViewer_new/src/measurement/measure_image_transfer/src/measure_image_transfer_node.cpp

measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer_node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer_node.cpp.i"
	cd /home/lars/OculusCamViewer_new/build/measurement/measure_image_transfer && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/lars/OculusCamViewer_new/src/measurement/measure_image_transfer/src/measure_image_transfer_node.cpp > CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer_node.cpp.i

measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer_node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer_node.cpp.s"
	cd /home/lars/OculusCamViewer_new/build/measurement/measure_image_transfer && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/lars/OculusCamViewer_new/src/measurement/measure_image_transfer/src/measure_image_transfer_node.cpp -o CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer_node.cpp.s

measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer_node.cpp.o.requires:
.PHONY : measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer_node.cpp.o.requires

measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer_node.cpp.o.provides: measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer_node.cpp.o.requires
	$(MAKE) -f measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/build.make measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer_node.cpp.o.provides.build
.PHONY : measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer_node.cpp.o.provides

measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer_node.cpp.o.provides.build: measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer_node.cpp.o

measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer.cpp.o: measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/flags.make
measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer.cpp.o: /home/lars/OculusCamViewer_new/src/measurement/measure_image_transfer/src/measure_image_transfer.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/lars/OculusCamViewer_new/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer.cpp.o"
	cd /home/lars/OculusCamViewer_new/build/measurement/measure_image_transfer && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer.cpp.o -c /home/lars/OculusCamViewer_new/src/measurement/measure_image_transfer/src/measure_image_transfer.cpp

measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer.cpp.i"
	cd /home/lars/OculusCamViewer_new/build/measurement/measure_image_transfer && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/lars/OculusCamViewer_new/src/measurement/measure_image_transfer/src/measure_image_transfer.cpp > CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer.cpp.i

measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer.cpp.s"
	cd /home/lars/OculusCamViewer_new/build/measurement/measure_image_transfer && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/lars/OculusCamViewer_new/src/measurement/measure_image_transfer/src/measure_image_transfer.cpp -o CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer.cpp.s

measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer.cpp.o.requires:
.PHONY : measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer.cpp.o.requires

measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer.cpp.o.provides: measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer.cpp.o.requires
	$(MAKE) -f measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/build.make measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer.cpp.o.provides.build
.PHONY : measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer.cpp.o.provides

measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer.cpp.o.provides.build: measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer.cpp.o

# Object files for target measure_image_transfer_node
measure_image_transfer_node_OBJECTS = \
"CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer_node.cpp.o" \
"CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer.cpp.o"

# External object files for target measure_image_transfer_node
measure_image_transfer_node_EXTERNAL_OBJECTS =

/home/lars/OculusCamViewer_new/devel/lib/measure_image_transfer/measure_image_transfer_node: measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer_node.cpp.o
/home/lars/OculusCamViewer_new/devel/lib/measure_image_transfer/measure_image_transfer_node: measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer.cpp.o
/home/lars/OculusCamViewer_new/devel/lib/measure_image_transfer/measure_image_transfer_node: /opt/ros/hydro/lib/libimage_transport.so
/home/lars/OculusCamViewer_new/devel/lib/measure_image_transfer/measure_image_transfer_node: /opt/ros/hydro/lib/libmessage_filters.so
/home/lars/OculusCamViewer_new/devel/lib/measure_image_transfer/measure_image_transfer_node: /usr/lib/libtinyxml.so
/home/lars/OculusCamViewer_new/devel/lib/measure_image_transfer/measure_image_transfer_node: /opt/ros/hydro/lib/libclass_loader.so
/home/lars/OculusCamViewer_new/devel/lib/measure_image_transfer/measure_image_transfer_node: /usr/lib/libPocoFoundation.so
/home/lars/OculusCamViewer_new/devel/lib/measure_image_transfer/measure_image_transfer_node: /usr/lib/x86_64-linux-gnu/libdl.so
/home/lars/OculusCamViewer_new/devel/lib/measure_image_transfer/measure_image_transfer_node: /opt/ros/hydro/lib/libroscpp.so
/home/lars/OculusCamViewer_new/devel/lib/measure_image_transfer/measure_image_transfer_node: /usr/lib/libboost_signals-mt.so
/home/lars/OculusCamViewer_new/devel/lib/measure_image_transfer/measure_image_transfer_node: /usr/lib/libboost_filesystem-mt.so
/home/lars/OculusCamViewer_new/devel/lib/measure_image_transfer/measure_image_transfer_node: /opt/ros/hydro/lib/librosconsole.so
/home/lars/OculusCamViewer_new/devel/lib/measure_image_transfer/measure_image_transfer_node: /opt/ros/hydro/lib/librosconsole_log4cxx.so
/home/lars/OculusCamViewer_new/devel/lib/measure_image_transfer/measure_image_transfer_node: /opt/ros/hydro/lib/librosconsole_backend_interface.so
/home/lars/OculusCamViewer_new/devel/lib/measure_image_transfer/measure_image_transfer_node: /usr/lib/liblog4cxx.so
/home/lars/OculusCamViewer_new/devel/lib/measure_image_transfer/measure_image_transfer_node: /usr/lib/libboost_regex-mt.so
/home/lars/OculusCamViewer_new/devel/lib/measure_image_transfer/measure_image_transfer_node: /opt/ros/hydro/lib/libxmlrpcpp.so
/home/lars/OculusCamViewer_new/devel/lib/measure_image_transfer/measure_image_transfer_node: /opt/ros/hydro/lib/libroslib.so
/home/lars/OculusCamViewer_new/devel/lib/measure_image_transfer/measure_image_transfer_node: /opt/ros/hydro/lib/libroscpp_serialization.so
/home/lars/OculusCamViewer_new/devel/lib/measure_image_transfer/measure_image_transfer_node: /opt/ros/hydro/lib/librostime.so
/home/lars/OculusCamViewer_new/devel/lib/measure_image_transfer/measure_image_transfer_node: /usr/lib/libboost_date_time-mt.so
/home/lars/OculusCamViewer_new/devel/lib/measure_image_transfer/measure_image_transfer_node: /usr/lib/libboost_system-mt.so
/home/lars/OculusCamViewer_new/devel/lib/measure_image_transfer/measure_image_transfer_node: /usr/lib/libboost_thread-mt.so
/home/lars/OculusCamViewer_new/devel/lib/measure_image_transfer/measure_image_transfer_node: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/lars/OculusCamViewer_new/devel/lib/measure_image_transfer/measure_image_transfer_node: /opt/ros/hydro/lib/libcpp_common.so
/home/lars/OculusCamViewer_new/devel/lib/measure_image_transfer/measure_image_transfer_node: /opt/ros/hydro/lib/libconsole_bridge.so
/home/lars/OculusCamViewer_new/devel/lib/measure_image_transfer/measure_image_transfer_node: measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/build.make
/home/lars/OculusCamViewer_new/devel/lib/measure_image_transfer/measure_image_transfer_node: measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable /home/lars/OculusCamViewer_new/devel/lib/measure_image_transfer/measure_image_transfer_node"
	cd /home/lars/OculusCamViewer_new/build/measurement/measure_image_transfer && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/measure_image_transfer_node.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/build: /home/lars/OculusCamViewer_new/devel/lib/measure_image_transfer/measure_image_transfer_node
.PHONY : measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/build

measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/requires: measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer_node.cpp.o.requires
measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/requires: measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/src/measure_image_transfer.cpp.o.requires
.PHONY : measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/requires

measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/clean:
	cd /home/lars/OculusCamViewer_new/build/measurement/measure_image_transfer && $(CMAKE_COMMAND) -P CMakeFiles/measure_image_transfer_node.dir/cmake_clean.cmake
.PHONY : measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/clean

measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/depend:
	cd /home/lars/OculusCamViewer_new/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lars/OculusCamViewer_new/src /home/lars/OculusCamViewer_new/src/measurement/measure_image_transfer /home/lars/OculusCamViewer_new/build /home/lars/OculusCamViewer_new/build/measurement/measure_image_transfer /home/lars/OculusCamViewer_new/build/measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : measurement/measure_image_transfer/CMakeFiles/measure_image_transfer_node.dir/depend


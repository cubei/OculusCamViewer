# **Virtual pan-tilt-roll ROS-node** #

This program was used for a telepresencerobot with a stereoscopic mechanical pan-tilt-roll camera system to reduce latency in movement.

For the HMD and the head-tracking-system a Oculus Rift Dev Kit 1 was used.

---

## **Additional credit goes to:** ##
* Hendrik Wiese
* Takashi Ogura (https://github.com/OTL/oculus)

---

## **Licence:** ##
BSD

---

**Problems with Aria.h and ROSARIA**

```
#!bash
sudo apt-get install libudev-dev
cd ws
source devel/setup.bash
rosdep update
rosdep install rosaria
catkin_make
```
(If error remains, use "catkin_make clean" and delete build and devel folder)


**Problems with graphics drivers on opencv compile**
OpenCV without gpu => CMAKE ARG = "-D BUILD_opencv_gpu=OFF"

**Laserscanner:**
```
#!bash
sudo apt-get install ros-hydro-urg-node
```
**Controller:**
```
#!bash
sudo apt-get install ros-hydro-joy
```
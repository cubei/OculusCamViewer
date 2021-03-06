# **Virtual pan-tilt-roll ROS-node** #

This program was used for a telepresence robot with a stereoscopic mechanical pan-tilt-roll camera system to reduce latency in movement.

For the HMD and the head-tracking-system a Oculus Rift Dev Kit 1 was used.

---

### **Additional credit goes to:** ###
* Hendrik Wiese (https://github.com/SeveQ)
* Takashi Ogura (https://github.com/OTL/oculus)

---

### **Licence:** ###
[BSD](http://opensource.org/licenses/BSD-3-Clause), see [license file](/LICENSE.txt)

---

### **Instructions:** ###
* You need ROS and OpenCV
* Add the content of the src folder to your catkin workspace src folder and compile.
* See [msg types](/msg_type.txt) for the msg specifications.

To get the full repo with submodules:
```
git clone https://github.com/cubei/OculusCamViewer.git
cd OculusCamViewer
git submodule init
git submodule update
```
---

### **Images:** ###
![ui](/images/ui.png)
---

**Problems with Aria.h and ROSARIA**

```
sudo apt-get install libudev-dev
cd ws
source devel/setup.bash
rosdep update
rosdep install rosaria
catkin_make
```
(If error remains, use "catkin_make clean" and delete build and devel folder)


**Problems with graphics drivers on opencv compile**

OpenCV without gpu => CMAKE ARG:
```
-D BUILD_opencv_gpu=OFF
```

**Laserscanner:**
```
sudo apt-get install ros-hydro-urg-node
```
**Controller:**
```
sudo apt-get install ros-hydro-joy
```

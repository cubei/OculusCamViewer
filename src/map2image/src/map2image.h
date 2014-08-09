/**
 * @Author Lars Harmsen
 */

#pragma once

#include "ros/ros.h"
#include <sensor_msgs/Image.h>
#include <image_transport/image_transport.h>
#include <sensor_msgs/image_encodings.h>
#include <sensor_msgs/CompressedImage.h>
#include <cv_bridge/cv_bridge.h>

#include <opencv2/core/core.hpp>

#include <nav_msgs/Odometry.h>
#include <nav_msgs/OccupancyGrid.h>
#include <sensor_msgs/Image.h>
#include <map2image/mapConfig.h>

#include "mapAdditionalDrawings.h"

#define TOPIC_MAP_INPUT "/map"
#define TOPIC_MAP_IMAGE "/mapimage"
#define TOPIC_ROBOT_ODOMETRY "/rosaria/pose"
#define TOPIC_MAP_CONFIG "/mapConfig"

// Arguments for ROS Node
#define ARG_DRAW_ARROW "drawArrow"		// Draw an arrow/triangle in the center of the map
#define ARG_DRAW_CIRCLE "drawCircle"	// Draw a circle in the center of the map
#define ARG_DRAW_CONE "drawCone"		// Draw a cone on the map, according to the viewing angle
#define ARG_BIGGER_IMAGE_FOR_ROTATION "biggerImageForRotation"	// Create an image that is 1.5 times bigger than wanted, so after rotation you have a full map
#define ARG_USE_ROTATION "useRotation"	// Rotate according to orientation of robot/HMD, when false, the map is still rotated to 0°
#define ARG_MAP_RANG "mapRange"			// Use this map range instead of the one received over the mapConfig Topic


class Map2Image
{
public:

	Map2Image(void);
	~Map2Image(void);
	
	void init();

	bool ready2publish() { return mapReceived; }
	void publish();

	// --------------- Callbacks ---------------
	void mapCallback(const nav_msgs::OccupancyGrid::ConstPtr &msg);
	void robotOrientationCallback(const nav_msgs::Odometry& msg);
	void mapConfigCallback(const map2image::mapConfig& msg);

private:
	cv::Mat loop2image(const std::vector<signed char> data, int width, int height);
	cv::Mat copy2image(const std::vector<signed char> data, int width, int height);
	cv::Mat createMap();	

	ros::NodeHandle local_node;
	ros::NodeHandle node;
	ros::Subscriber mapSub;
	ros::Subscriber robotPoseSub;
	ros::Subscriber mapConfigSub;
	image_transport::ImageTransport imageTransport;
	image_transport::Publisher mapImagePub;
	cv::Mat rawMapImg;

	float posX;				// x position of the robot (real world coords)
	float posY;				// y position of the robot (real world coords)
	float mapOriginX;			// x = 0 in the map means ? in the real world
	float mapOriginY;			// y = 0 in the map means ? in the real world
	float mapResolution;	// The map resolution [m/cell]
	float mapRotation;		// rotation angle of the map

	float robotRotation;	// rotation angle of the robot

	int mapSize;			// map width/height in pixel
	double mapRange;			// map size in meters
	int viewingangle;		// visable angle for the viewcone.

	float biggerAreaForRotation;

	bool mapReceived;		// Start publishing ?

	bool drawArrowArg;
	bool drawCircleArg;
	bool drawConeArg;
	bool useRotationArg;
	bool useFixedMapRange;
};



/**
 * @Author Lars Harmsen
 */

#include "ros/ros.h"
#include <nav_msgs/OccupancyGrid.h>
#include "nav_msgs/GetMap.h"
#include "tf/transform_datatypes.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#define FREQUENCY 5.0

#define MAP_WIDTH 300
#define MAP_HEIGHT 300
#define MAP_RESOLUTION 0.2f

#define TOPIC_MAP "/map"


char map[MAP_WIDTH*MAP_HEIGHT];
ros::Publisher mapPub;

void init();
void publish();

int main(int argc, char **argv){

	ros::init(argc, argv, "dummyMapPublisher");
	init();

	ros::NodeHandle node;
	mapPub = node.advertise<nav_msgs::OccupancyGrid>(TOPIC_MAP, 1);

	ros::Rate r(FREQUENCY);

	while(ros::ok()) {
		publish();
		r.sleep();
	}

	return 0;
}

void init(){
	//cv::Mat mapImage = cv::imread("/home/lars/oculus_ros_git/src/dummy_map_publisher/src/map.png", CV_LOAD_IMAGE_GRAYSCALE);
	cv::Mat mapImage = cv::imread("/home/lars/oculuscamviewer/src/dummy_map_publisher/src/map.png", CV_LOAD_IMAGE_GRAYSCALE);
	std::copy (&(mapImage.data[0]), &(mapImage.data[0]) + (mapImage.cols * mapImage.rows), map);
}

void publish(){
	nav_msgs::GetMap::Response msg;
	msg.map.header.stamp = ros::Time::now();
	msg.map.info.resolution = MAP_RESOLUTION;
	msg.map.info.width = MAP_WIDTH;
	msg.map.info.height = MAP_HEIGHT;
	geometry_msgs::Point point;
	point.x = -30; point.y = -30; point.z = 0;
	msg.map.info.origin.position = point;

	geometry_msgs::Quaternion quat;
	tf::Quaternion tfQuat;
	tfQuat.setEuler(0.0f, 0.0f, 0.0f);
	tfQuat.normalize();
	tf::quaternionTFToMsg(tfQuat, quat);
	msg.map.info.origin.orientation = quat;

	msg.map.data.resize(msg.map.info.width * msg.map.info.height);
	//msg.map.data = map;
	//std::copy (&(map[0]), &(map[0]) + (MAP_WIDTH * MAP_HEIGHT), msg.map.data);
	for(int i = 0; i < MAP_WIDTH * MAP_HEIGHT; ++i) {
		msg.map.data[i] = map[i];
	}

	mapPub.publish(msg.map);
}	
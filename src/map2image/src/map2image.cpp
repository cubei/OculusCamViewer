/**
 * @Author Lars Harmsen
 */

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "tf/transform_datatypes.h"

#define _USE_MATH_DEFINES
#include <cmath>

#include "map2image.h"


#define CURSOR_SIZE_TO_IMAGE_SIZE 0.06f


Map2Image::Map2Image(void): imageTransport(node) {
	posX = 0.0f;
	posY = 0.0f;
	mapSize = 200;
	mapRotation = 0.0f;
	robotRotation = 45.0f;
	mapResolution = 1.0f;
	viewingangle = 110;

	mapReceived = false;
}

Map2Image::~Map2Image(void) {}

void Map2Image::init() {
	mapSub = node.subscribe(TOPIC_MAP_INPUT, 1, &Map2Image::mapCallback, this);
	robotPoseSub = node.subscribe(TOPIC_ROBOT_ODOMETRY, 1, &Map2Image::robotOrientationCallback, this);
	mapConfigSub = node.subscribe(TOPIC_MAP_CONFIG,1, &Map2Image::mapConfigCallback, this);

	mapImagePub = imageTransport.advertise(TOPIC_MAP_IMAGE, 1);
	
	// args
	local_node = ros::NodeHandle("~");
	if(!local_node.getParam(ARG_DRAW_ARROW, drawArrowArg))
		drawArrowArg = false;
	if(!local_node.getParam(ARG_DRAW_CIRCLE, drawCircleArg))
		drawCircleArg = false;
	if(!local_node.getParam(ARG_DRAW_CONE, drawConeArg))
		drawConeArg = false;
	bool use = false;
	local_node.getParam(ARG_BIGGER_IMAGE_FOR_ROTATION, use);
	if(use) {
		biggerAreaForRotation = 1.5f;
	} else {
		biggerAreaForRotation = 1.0f;
	}
	if(!local_node.getParam(ARG_USE_ROTATION, useRotationArg))
		useRotationArg = false;
	if(!local_node.getParam(ARG_MAP_RANG, mapRange)) {
		useFixedMapRange = true;
		mapRange = 10.0;
	} else {
		useFixedMapRange = false;
	}
	
}

void Map2Image::publish() {
	cv_bridge::CvImage msg;
	msg.header.stamp = ros::Time::now();
	msg.encoding = sensor_msgs::image_encodings::TYPE_8UC1;
	msg.image = createMap();
	mapImagePub.publish(msg.toImageMsg());
}

void Map2Image::mapCallback(const nav_msgs::OccupancyGrid::ConstPtr &msg) {
	double pitch, yaw, roll;
	tf::Quaternion quat;
	tf::quaternionMsgToTF(msg->info.origin.orientation, quat);
	tf::Matrix3x3(quat).getRPY(pitch, yaw, roll);
	mapRotation = yaw * 180/M_PI;

	mapOriginX = msg->info.origin.position.x;
	mapOriginY = msg->info.origin.position.y;

	mapResolution = msg->info.resolution;
 	
	rawMapImg = copy2image(msg->data, msg->info.width, msg->info.height);

	mapReceived = true;
}

void Map2Image::robotOrientationCallback(const nav_msgs::Odometry& msg) {
	double yaw, pitch, roll;
	tf::Quaternion quat;
	tf::quaternionMsgToTF(msg.pose.pose.orientation, quat);
	tf::Matrix3x3(quat).getRPY(pitch, yaw, roll);
	robotRotation = yaw * 180/M_PI;

	posX = msg.pose.pose.position.x;
	posY = msg.pose.pose.position.y;
}

void Map2Image::mapConfigCallback(const map2image::mapConfig& msg) {
	mapSize = msg.mapSize;
	viewingangle = msg.viewingAngle;
	if(!useFixedMapRange) {
		mapRange = msg.mapRange;
	}
}

cv::Mat Map2Image::loop2image(const std::vector<signed char> data, int width, int height) {
	cv::Mat tmp(height, width, CV_8UC1);
	uchar* buf = tmp.data;
	int i = 0;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			*buf = data[i];
			++buf;
			++i;
		}
	}
	return tmp;
}

cv::Mat Map2Image::copy2image(const std::vector<signed char> data, int width, int height) {
	cv::Mat tmp(height, width, CV_8UC1, cv::Scalar(50));
	std::copy (&(data[0]), &(data[0]) + (width * height), tmp.data);
	return tmp;
}

cv::Mat Map2Image::createMap() {
	float scale = mapResolution / (mapRange / mapSize);

	cv::Mat correctResolution;
	cv::resize(rawMapImg, correctResolution, cv::Size(), scale, scale);

	int border = 0;
	int rectX = (int)((posX-mapOriginX)*scale/mapResolution - mapSize/2*biggerAreaForRotation);
	int rectY = (int)((posY-mapOriginY)*scale/mapResolution - mapSize/2*biggerAreaForRotation);
	int rectWidth = (int)(mapSize*biggerAreaForRotation);
	if(rectX < 0 || rectY < 0 || rectX + rectWidth > correctResolution.cols || rectY + rectWidth > correctResolution.rows) {
		border = (int)((mapSize>>1)*biggerAreaForRotation) + 1;
		cv::Mat tmp = cv::Mat(correctResolution.rows + 2*border, correctResolution.cols + 2*border, CV_8UC1, cv::Scalar(20));
		correctResolution.copyTo(tmp(cv::Rect(border, border, correctResolution.cols, correctResolution.rows)));
		correctResolution = tmp;
		rectX += border;
		rectY += border;
	}

	cv::Mat AOI = correctResolution(cv::Rect(rectX, rectY, rectWidth, rectWidth));
	
	if(useRotationArg) {
		cv::Mat rotated;
		cv::warpAffine(AOI, rotated, cv::getRotationMatrix2D(
						cv::Point2f(AOI.cols >> 1, AOI.rows >> 1),
						robotRotation - mapRotation, 1), cv::Size());
		AOI = rotated;
	} else {
		cv::Mat rotated;
		cv::warpAffine(AOI, rotated, cv::getRotationMatrix2D(
						cv::Point2f(AOI.cols >> 1, AOI.rows >> 1),
						-mapRotation, 1.0), rotated.size());
		AOI = rotated;
	}

	if(biggerAreaForRotation != 1){
		cv::Mat tmp = AOI(cv::Rect(	(AOI.cols - mapSize) >> 1,
									(AOI.rows - mapSize) >> 1,
									mapSize, mapSize));
		AOI = tmp;
	}

	if(drawArrowArg){
		drawArrow(&AOI, (int) (AOI.cols * CURSOR_SIZE_TO_IMAGE_SIZE));
	}
	if(drawCircleArg){
		drawCircle(&AOI, (int)(AOI.cols * CURSOR_SIZE_TO_IMAGE_SIZE));
	}
	if(drawConeArg){
		drawViewCone(&AOI, (int)(AOI.cols * CURSOR_SIZE_TO_IMAGE_SIZE)/2);
	}
	return AOI;
}


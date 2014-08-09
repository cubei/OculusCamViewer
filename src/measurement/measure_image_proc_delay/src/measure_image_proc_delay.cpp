/**
 * @Author Lars Harmsen
 */

#include "measure_image_proc_delay.h"

void printTime(long time){
	//ROS_INFO("receive time: rect - untouched = %ld", time);
	std::cout << time << std::endl;
}

MeasureImageProcDelay::MeasureImageProcDelay(void): imageTransport(node) { }

MeasureImageProcDelay::~MeasureImageProcDelay(void) { }

void MeasureImageProcDelay::init() {
	imageSubUntouched = imageTransport.subscribe(TOPIC_IMAGE_CAMERA_UNTOUCHED, 1, &MeasureImageProcDelay::imageCallbackUntouched, this);
	imageSubRect = imageTransport.subscribe(TOPIC_IMAGE_CAMERA_RECT, 1, &MeasureImageProcDelay::imageCallbackRect, this);
}

void MeasureImageProcDelay::imageCallbackRect(const sensor_msgs::ImageConstPtr& msg) {
	ros::Time now = ros::Time::now();
	long sentTime = msg->header.stamp.sec*1000L + msg->header.stamp.nsec/1000L/1000L;
	rectTimes.add(sentTime, now.sec*1000L*1000L + now.nsec/1000L);

	if(untouchedTimes.containsSentTime(sentTime)) {
		printTime(rectTimes.getReceivedTime(sentTime) - untouchedTimes.getReceivedTime(sentTime));
	}
}

void MeasureImageProcDelay::imageCallbackUntouched(const sensor_msgs::ImageConstPtr& msg) {
	ros::Time now = ros::Time::now();
	long sentTime = msg->header.stamp.sec*1000L + msg->header.stamp.nsec/1000L/1000L;
	untouchedTimes.add(sentTime, now.sec*1000L*1000L + now.nsec/1000L);

	if(rectTimes.containsSentTime(sentTime)) {
		printTime(rectTimes.getReceivedTime(sentTime) - untouchedTimes.getReceivedTime(sentTime));
	}
}

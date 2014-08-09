/**
 * @Author Lars Harmsen
 */

#pragma once

#include "ros/ros.h"
#include <sensor_msgs/Image.h>
#include <image_transport/image_transport.h>
#include <sensor_msgs/image_encodings.h>
#include <sensor_msgs/CompressedImage.h>
#include "std_msgs/Int8.h"
#include "sent_received_time_ring_buffer.h"

#define TOPIC_IMAGE_CAMERA_RECT "camera/left/image_rect_color"
#define TOPIC_IMAGE_CAMERA_UNTOUCHED "camera/left/image_raw"

class MeasureImageProcDelay
{
public:

	MeasureImageProcDelay(void);
	~MeasureImageProcDelay(void);
	
	void init();

	// --------------- Callbacks ---------------
	void imageCallbackRect(const sensor_msgs::ImageConstPtr& msg);
	void imageCallbackUntouched(const sensor_msgs::ImageConstPtr& msg);

private:
	ros::NodeHandle node;
	image_transport::ImageTransport imageTransport;
	image_transport::Subscriber imageSubRect;
	image_transport::Subscriber imageSubUntouched;

	sensor_msgs::ImageConstPtr imgMsg;

	SentReceivedTimeRingBuffer rectTimes;
	SentReceivedTimeRingBuffer untouchedTimes;
};



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

#define TOPIC_IMAGE_CAMERA "camera/left/image_rect_color"
#define TOPIC_IMAGE_OUT "image/out"
#define TOPIC_IMAGE_IN "image/in"
#define TOPIC_GO_SIGNAL "measure/go"

class MeasureImageTransfer
{
public:

	MeasureImageTransfer(void);
	~MeasureImageTransfer(void);
	
	void init();

	bool ready2publish() { return imageReceived && goSignalReceived; }
	void publish();

	// --------------- Callbacks ---------------
	void imageInCallback(const sensor_msgs::ImageConstPtr& msg);
	void goSignalCallback(const std_msgs::Int8 msg);

private:
	ros::NodeHandle node;
	ros::Subscriber imageInSub;
	ros::Subscriber goSignalSub;
	image_transport::ImageTransport imageTransport;
	image_transport::Publisher imageOutPub;

	sensor_msgs::ImageConstPtr imgMsg;

	long SentImageTimeMicros;

	bool imageReceived;
	bool goSignalReceived;	// Start publishing ?
};



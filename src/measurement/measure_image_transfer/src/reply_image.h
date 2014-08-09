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

#define TOPIC_IMAGE_IN "image/out"
#define TOPIC_IMAGE_OUT "image/in"
#define TOPIC_GO_SIGNAL "measure/go"

class ReplyImage
{
public:

	ReplyImage(void);
	~ReplyImage(void);
	
	void init();

	void publish(sensor_msgs::ImageConstPtr img);

	void publishGoSignal();

	// --------------- Callbacks ---------------
	void imageCallback(const sensor_msgs::ImageConstPtr& msg);

private:
	ros::NodeHandle node;
	ros::Subscriber imageSub;
	ros::Publisher goSignalPub;
	image_transport::ImageTransport imageTransport;
	image_transport::Publisher imagePub;
};



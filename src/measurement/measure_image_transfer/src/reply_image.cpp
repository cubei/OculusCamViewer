/**
 * @Author Lars Harmsen
 */

#include "reply_image.h"


ReplyImage::ReplyImage(void): imageTransport(node) { }

ReplyImage::~ReplyImage(void) {}


void ReplyImage::init() {
	imageSub = node.subscribe(TOPIC_IMAGE_IN, 1, &ReplyImage::imageCallback, this);
	imagePub = imageTransport.advertise(TOPIC_IMAGE_OUT, 1);
	goSignalPub = node.advertise<std_msgs::Int8>(TOPIC_GO_SIGNAL, 1);
}

void ReplyImage::publish(sensor_msgs::ImageConstPtr img) {
	imagePub.publish(img);
}

void ReplyImage::imageCallback(const sensor_msgs::ImageConstPtr& msg) {
	publish(msg);
	ROS_INFO("reply");
}

void ReplyImage::publishGoSignal() {
	std_msgs::Int8 msg;
	msg.data = 1;
	goSignalPub.publish(msg);
}


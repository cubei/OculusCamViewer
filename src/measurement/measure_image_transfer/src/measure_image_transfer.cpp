/**
 * @Author Lars Harmsen
 */

#include "measure_image_transfer.h"


MeasureImageTransfer::MeasureImageTransfer(void): imageTransport(node) {
	imageReceived = false;
	goSignalReceived = false;
}

MeasureImageTransfer::~MeasureImageTransfer(void) {}


void MeasureImageTransfer::init() {
	imageInSub = node.subscribe(TOPIC_IMAGE_CAMERA, 1, &MeasureImageTransfer::imageInCallback, this);
	imageOutPub = imageTransport.advertise(TOPIC_IMAGE_OUT, 1);
	goSignalSub = node.subscribe(TOPIC_GO_SIGNAL, 1, &MeasureImageTransfer::goSignalCallback, this);
}

void MeasureImageTransfer::publish() {
	imageOutPub.publish(imgMsg);
}

void MeasureImageTransfer::imageInCallback(const sensor_msgs::ImageConstPtr& msg) {
	if(!imageReceived) {
		imgMsg = msg;
		imageReceived = true;
		imageInSub = node.subscribe(TOPIC_IMAGE_IN, 1, &MeasureImageTransfer::imageInCallback, this);
	} else {
		ros::Time now = ros::Time::now();
		long nowMicros = now.sec*1000L*1000L + now.nsec/1000L;
		ROS_INFO("Time between sending and receiving:\n%ld",
					nowMicros - SentImageTimeMicros);
		SentImageTimeMicros = nowMicros;
		publish();
	}
}


void MeasureImageTransfer::goSignalCallback(const std_msgs::Int8 msg) {
	ROS_INFO("GO");
	if(msg.data == 1) {
		goSignalReceived = true;
	}
}
/**
 * @Author Lars Harmsen
 */

#include "measure_orientation_transfer.h"


MeasureOrientationTransfer::MeasureOrientationTransfer(void) {
	goSignalReceived = false;
	orientation;
}

MeasureOrientationTransfer::~MeasureOrientationTransfer(void) { }


void MeasureOrientationTransfer::init() {
	orientationSub = node.subscribe(TOPIC_ORIENTATION_IN, 1, &MeasureOrientationTransfer::orientationCallback, this);
	orientationPub = node.advertise<geometry_msgs::PoseStamped>(TOPIC_ORIENTATION_OUT, 1);
	goSignalSub = node.subscribe(TOPIC_GO_SIGNAL, 1, &MeasureOrientationTransfer::goSignalCallback, this);
}

void MeasureOrientationTransfer::publish() {
	orientationPub.publish(orientation);
}

void MeasureOrientationTransfer::orientationCallback(const geometry_msgs::PoseStamped& msg) {
	ros::Time now = ros::Time::now();
	publish();
	long nowMicros = now.sec*1000L*1000L + now.nsec/1000L;
	ROS_INFO("Time between sending and receiving:\n%ld",
				nowMicros - SentImageTimeMicros, (nowMicros - SentImageTimeMicros)>>1);
	SentImageTimeMicros = nowMicros;
}


void MeasureOrientationTransfer::goSignalCallback(const std_msgs::Int8 msg) {
	ROS_INFO("GO");
	if(msg.data == 1) {
		goSignalReceived = true;
	}
}
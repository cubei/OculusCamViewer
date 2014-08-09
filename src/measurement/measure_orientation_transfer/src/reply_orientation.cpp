/**
 * @Author Lars Harmsen
 */

#include "reply_orientation.h"


ReplyOrientation::ReplyOrientation(void) { }

ReplyOrientation::~ReplyOrientation(void) { }


void ReplyOrientation::init() {
	orientationSub = node.subscribe(TOPIC_ORIENTATION_IN, 1, &ReplyOrientation::orientationCallback, this);
	orientationPub = node.advertise<geometry_msgs::PoseStamped>(TOPIC_ORIENTATION_OUT, 1);
	goSignalPub = node.advertise<std_msgs::Int8>(TOPIC_GO_SIGNAL, 1);
}

void ReplyOrientation::publish(geometry_msgs::PoseStamped msg) {
	orientationPub.publish(msg);
}

void ReplyOrientation::orientationCallback(const geometry_msgs::PoseStamped& msg) {
	publish(msg);
}

void ReplyOrientation::publishGoSignal() {
	std_msgs::Int8 msg;
	msg.data = 1;
	goSignalPub.publish(msg);
}


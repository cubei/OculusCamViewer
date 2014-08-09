/**
 * @Author Lars Harmsen
 */

#include "ros/ros.h"

#include "reply_orientation.h"

int main(int argc, char **argv) {

	ros::init(argc, argv, "reply_image_node");

	ReplyOrientation replyOrientation;

	replyOrientation.init();

	ros::Rate r(1.0);
	r.sleep();
	r.sleep();

	replyOrientation.publishGoSignal();

	while(ros::ok()) {
		ros::spinOnce();
	}

	return 0;
}

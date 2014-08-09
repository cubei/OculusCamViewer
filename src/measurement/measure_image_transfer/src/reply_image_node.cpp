/**
 * @Author Lars Harmsen
 */

#include "ros/ros.h"

#include "reply_image.h"

int main(int argc, char **argv) {

	ros::init(argc, argv, "reply_image_node");

	ReplyImage replyImage;

	replyImage.init();

	ros::Rate r(1.0);
	r.sleep();
	r.sleep();

	replyImage.publishGoSignal();

	while(ros::ok()) {
		ros::spinOnce();
	}

	return 0;
}

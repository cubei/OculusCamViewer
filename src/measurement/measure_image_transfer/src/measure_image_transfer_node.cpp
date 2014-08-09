/**
 * @Author Lars Harmsen
 */

#include "ros/ros.h"

#include "measure_image_transfer.h"

#define FREQUENCY 1.0

int main(int argc, char **argv){

	ros::init(argc, argv, "measurement_image_transfer_node");

	MeasureImageTransfer measureImageTransfer;

	measureImageTransfer.init();

	ros::Rate r(FREQUENCY);

	ROS_INFO("Waiting for signals");

	while(!measureImageTransfer.ready2publish() && ros::ok()) {
		ros::spinOnce();
		r.sleep();
	}

	ROS_INFO("Ready2publish");

	measureImageTransfer.publish();

	while(ros::ok()) {
		ros::spinOnce();
	}

	return 0;
}


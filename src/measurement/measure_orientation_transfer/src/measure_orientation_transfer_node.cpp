/**
 * @Author Lars Harmsen
 */

#include "ros/ros.h"

#include "measure_orientation_transfer.h"

#define FREQUENCY 1.0

int main(int argc, char **argv){

	ros::init(argc, argv, "measurement_image_transfer_node");

	MeasureOrientationTransfer measureOrientationTransfer;

	measureOrientationTransfer.init();

	ros::Rate r(FREQUENCY);

	ROS_INFO("Waiting for signals");

	while(!measureOrientationTransfer.ready2publish() && ros::ok()) {
		ros::spinOnce();
		r.sleep();
	}

	ROS_INFO("Ready2publish");

	measureOrientationTransfer.publish();

	while(ros::ok()) {
		ros::spinOnce();
	}

	return 0;
}


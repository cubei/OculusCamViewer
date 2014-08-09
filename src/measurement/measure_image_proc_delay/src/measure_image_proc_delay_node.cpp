/**
 * @Author Lars Harmsen
 */

#include "ros/ros.h"

#include "measure_image_proc_delay.h"

int main(int argc, char **argv){

	ros::init(argc, argv, "measurement_image_transfer_node");

	MeasureImageProcDelay measureImageProcDelay;

	measureImageProcDelay.init();

	while(ros::ok()) {
		ros::spinOnce();
	}

	return 0;
}


/**
 * @Author Lars Harmsen
 */

#include "ros/ros.h"

#include "map2image.h"

#define FREQUENCY 1.0


int main(int argc, char **argv){

	ros::init(argc, argv, "map2image");

	Map2Image map2image;

	map2image.init();

	ros::Rate r(FREQUENCY);

	while(ros::ok()) {
		ros::spinOnce();
		if(map2image.ready2publish()){
			map2image.publish();
		}
		r.sleep();
	}

	return 0;
}


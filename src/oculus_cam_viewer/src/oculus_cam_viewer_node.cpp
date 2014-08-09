/**
 * @Author Lars Harmsen
 */

#include "ros/ros.h"

#include "ImageViewer.h"

/** Time waited after every ros spin (in ms) */
#define WAIT_TIME 4

int main(int argc, char **argv){

	ros::init(argc, argv, "oculusCamViewer");

	ImageViewer imageViewer = ImageViewer();

	imageViewer.init();

	while(ros::ok()) {
		ros::spinOnce();

		imageViewer.publishMapConfig();
		
		if(imageViewer.areImagesReady()){
			//imageViewer.measureProcessingSteps();	// Test

			imageViewer.imageProcessing();
			imageViewer.showImages();
			cv::waitKey(WAIT_TIME);
		}
	}

	return 0;
}



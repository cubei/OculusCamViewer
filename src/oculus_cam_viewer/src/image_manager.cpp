/**
 * @Author Lars Harmsen
 */

#include "image_manager.h"

long ImageManager::getNewestMatchingImages(cv::Mat *leftImage, cv::Mat *rightImage){
	long time = 0;
	if(leftImages.getNearest(rightImages.getLastTime(), leftImage)
			> rightImages.getNearest(leftImages.getLastTime(), rightImage)){
		leftImage = leftImages.getLastElement();
		time = leftImages.getLastTime();
	} else {
		rightImage = rightImages.getLastElement();
		time = rightImages.getLastTime();
	}
	return time;
}
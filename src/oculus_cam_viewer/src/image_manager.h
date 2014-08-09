/**
 * @Author Lars Harmsen
 */

#pragma once

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
 
#include "timestamp_ring_buffer.h"

class ImageManager {
	public:
		ImageManager() { }
		~ImageManager() { }
	
		void addLeftImage(cv::Mat image, long millis) {
			leftImages.add(image, millis);
		}
		
		void addRightImage(cv::Mat image, long millis) {
			rightImages.add(image, millis);
		}
		
		long getNewestMatchingImages(cv::Mat *leftImage, cv::Mat *rightImage);
		
		bool isEmpty(){
			return leftImages.isEmpty() || rightImages.isEmpty();
		}

		cv::Mat* getLastRightImage() {
			return rightImages.getLastElement();
		}

		cv::Mat* getLastLeftImage() {
			return leftImages.getLastElement();
		}

		long getLastLeftTime() {
			return leftImages.getLastTime();
		}

		long getLastRightTime() {
			return rightImages.getLastTime();
		}
		
	private:
		TimestampRingBuffer<cv::Mat> leftImages;
		TimestampRingBuffer<cv::Mat> rightImages;
};
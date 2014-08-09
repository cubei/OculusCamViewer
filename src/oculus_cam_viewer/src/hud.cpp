/**
 * @Author Lars Harmsen
 */

#define _USE_MATH_DEFINES
#include <cmath>

#include <stdio.h>

#include "hud.h"


int getXPosForRightEye(int lensSeparationDistancePixel, int screenDistancePixel, int screenWidthPixel, int posLeft, float distanceFactor) {
	int leftEyeCenter = (screenWidthPixel - lensSeparationDistancePixel) >> 1;
	int rightEyeCenter = (screenWidthPixel >> 1) - leftEyeCenter;		// on the single right image
	
	float g = (posLeft - leftEyeCenter);	// can be negativ

	float alpha = atan(std::abs(g) / screenDistancePixel);	// in rad
	if(g >= 0) {
		alpha = (90.0f/180.0f*M_PI) - alpha;
	} else {
		alpha = (90.0f/180.0f*M_PI) + alpha;
	}

	float b = screenDistancePixel / sin(alpha) * distanceFactor;

	float a = sqrt	(b*b + lensSeparationDistancePixel*lensSeparationDistancePixel
					- 2 * b * lensSeparationDistancePixel * cos(alpha));

	float beta = acos((b*b - a*a - lensSeparationDistancePixel*lensSeparationDistancePixel) / (-2 * a * lensSeparationDistancePixel));

	float tmp = (90.0f/180.0f*M_PI) - beta;
	if(beta > 90) {
		tmp = beta - (90.0f/180.0f*M_PI);
	}
	float x = screenDistancePixel * tan(tmp);

	float posRight = rightEyeCenter - x;
	if(beta > (90.0f/180.0f*M_PI)) {
		posRight = rightEyeCenter + x;
	}

	return (int) posRight;
}

int getXPosForLeftEye(int lensSeparationDistancePixel, int screenDistancePixel, int screenWidthPixel, int posRight, float distanceFactor) {
	int leftEyeCenter = (screenWidthPixel - lensSeparationDistancePixel) >> 1;
	int rightEyeCenter = (screenWidthPixel >> 1) - leftEyeCenter;		// on the single right image

	float g = rightEyeCenter - posRight;	// can be negativ
	float beta = atan(std::abs(g) / screenDistancePixel);	// in rad
	if(g >= 0) {
		beta = (90.0f/180.0f*M_PI) - beta;
	} else {
		beta = (90.0f/180.0f*M_PI) + beta;
	}

	float a = screenDistancePixel / sin(beta) * distanceFactor;

	float b = sqrt	(a*a + lensSeparationDistancePixel*lensSeparationDistancePixel
					- 2 * a * lensSeparationDistancePixel * cos(beta));

	float alpha = acos((a*a - b*b - lensSeparationDistancePixel*lensSeparationDistancePixel) / (-2 * b * lensSeparationDistancePixel));

	float tmp = (90.0f/180.0f*M_PI) - alpha;
	if(alpha > 90) {
		tmp = alpha - (90.0f/180.0f*M_PI);
	}
	float x = screenDistancePixel * tan(tmp);

	float posLeft = leftEyeCenter + x;
	if(alpha > (90.0f/180.0f*M_PI)) {
		posLeft = leftEyeCenter - x;
	}

	return (int) posLeft;
}

void drawImageOnImage(cv::Mat *src, cv::Mat *dst, int posX, int posY, cv::Mat *mask) {
	if(posX > dst->cols || posY > dst->rows
			|| posX + src->cols < 0
			|| posY + src->rows < 0) {
		// src is outside of dst
		return;
	}

	int leftCrop = std::abs(std::min(0, posX));
	int rightCrop = std::max(posX + src->cols - dst->cols, 0);
	int topCrop = std::abs(std::min(0, posY));
	int bottomCrop = std::max(posY + src->rows - dst->rows, 0);
	
	cv::Rect croppedRect(leftCrop, topCrop, src->cols - leftCrop - rightCrop, src->rows - topCrop - bottomCrop);
	cv::Mat modifiedImage = (*src)(croppedRect);
	cv::Mat modifiedMask;
	if(mask != 0){
		modifiedMask = (*mask)(croppedRect);
	}

	cv::Rect copyRect(	std::max(posX, 0),
						std::max(posY, 0),
						modifiedImage.cols,
						modifiedImage.rows);
	if(mask != 0){
		modifiedImage.copyTo((*dst)(copyRect), modifiedMask);
	}else{
		modifiedImage.copyTo((*dst)(copyRect));
	}
}

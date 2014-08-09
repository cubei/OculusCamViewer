/**
 * @Author Lars Harmsen
 */
 
 // ------------------------ INCLUDES ------------------------

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "geometry_msgs/Vector3.h"
#include "geometry_msgs/Quaternion.h"
#include "tf/transform_datatypes.h"
#include <image_transport/image_transport.h>

#include <oculus_msgs/HMDInfo.h>

#include <opencv2/gpu/gpu.hpp>
#include <pthread.h>

#define _USE_MATH_DEFINES
#include <cmath>

#include "ImageViewer.h"

#include "distort.h"
#include "hud.h"


// ------------------------ FUNCTIONS ------------------------

cv::Mat msg2Mat(const sensor_msgs::ImageConstPtr& msg){
	cv_bridge::CvImagePtr ptr;
	try {
		ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
	} catch (cv_bridge::Exception& e) {
		ROS_ERROR("cv_bridge exception: %s", e.what());
	}
	return cv::Mat(ptr->image);
}

void msgQuat2Degree(const geometry_msgs::Quaternion& msg, double* yaw, double* pitch, double* roll){
	tf::Quaternion quat;
	tf::quaternionMsgToTF(msg, quat);

	tf::Matrix3x3(quat).getRPY(*pitch, *yaw, *roll);
	
	*pitch *= 180/M_PI;
	*yaw *= 180/M_PI;
	*roll *= 180/M_PI;
}


// ------------------------ CLASS FUNCTIONS ------------------------

ImageViewer::ImageViewer(void): imageTransport(node) {
	displaySize = cv::Size(WINDOW_WIDTH_DEFAULT, WINDOW_HEIGHT_DEFAULT);
	
	setHMDOrientation(0.0f, 0.0f, 0.0f);
	setCameraOrientation(0.0f, 0.0f, 0.0f);

	setCameraViewingAngle(CAMERA_ANGLE_HORIZONTAL);
	setHMDViewingAngle(HMD_ANGLE_HORIZONTAL);

	setDistortionCoefficients(DISTORT_K0_DEFAULT, DISTORT_K1_DEFAULT, DISTORT_K2_DEFAULT);

	setEyeLensConfiguration(0.063f, 0.15f, 0.041f);
	
	mapReady = false;

	init();
}


ImageViewer::~ImageViewer(void) {}

void ImageViewer::init() {
	HMDInfoSub = node.subscribe(TOPIC_HMD_INFO, 1, &ImageViewer::HMDInfoCallback, this);

	HMDOrientationSub = node.subscribe(TOPIC_HMD_ORIENTATION, 1, &ImageViewer::HMDOrientationCallback, this);
	cameraOrientationSub = node.subscribe(TOPIC_CAMERA_ORIENTATION, 2, &ImageViewer::cameraOrientationCallback, this);
	robotOdometrySub = node.subscribe(TOPIC_ROBOT_ODOMETRY, 1, &ImageViewer::robotOdometryCallback, this);

	leftImageSub = imageTransport.subscribe(TOPIC_LEFT_IMAGE, 2, &ImageViewer::leftImageCallback, this);
	rightImageSub = imageTransport.subscribe(TOPIC_RIGHT_IMAGE, 2, &ImageViewer::rightImageCallback, this);

	mapImageSub = node.subscribe(TOPIC_MAP_IMAGE, 1, &ImageViewer::mapImageCallback, this);
	mapConfigPub = node.advertise<map2image::mapConfig>(TOPIC_MAP_CONFIG, 1);

	// -------- ARGS --------
	ros::NodeHandle local_node("~");
	if(!local_node.getParam(ARG_USE_VIRTUAL_PAN_TILT, useVirtualPanTiltArg))
		useVirtualPanTiltArg = true;
	if(!local_node.getParam(ARG_MEASURE_TIME, measureTimeArg))
		measureTimeArg = false;
	if(!local_node.getParam(ARG_DRAW_MAP, drawMapArg))
		drawMapArg = true;
	if(!local_node.getParam(ARG_USE_ROBOT_ORIENTATION, useRobotOrientationArg))
		useRobotOrientationArg = false;
	if(!local_node.getParam(ARG_ROTATE_THRESHOLD, rotateThreshold))
		rotateThreshold = MIN_DIFF_FOR_VIRTUAL_ROLL;
		
	if(drawMapArg) {
		createRoundMask();
	}
}

void ImageViewer::createRoundMask() {
	roundMask = cv::Mat(MAP_SIZE(displaySize.height), MAP_SIZE(displaySize.height), CV_8UC1, cv::Scalar(0));
	int center = MAP_SIZE(displaySize.height) >> 1;
	int radius2 = center * center;
	uchar* buf = roundMask.data;
	for(int x = 0; x < MAP_SIZE(displaySize.height); ++x) {
		for(int y = 0; y < MAP_SIZE(displaySize.height); ++y) {
			if((center-x)*(center-x) + (center-y)*(center-y) < radius2) {
				*buf = 1;
			}
			++buf;
		}
	}
}

void ImageViewer::publishMapConfig() {
	map2image::mapConfig msg;
	msg.mapSize = MAP_SIZE(displaySize.height);
	msg.mapRange = MAP_RANGE;
	msg.viewingAngle = (int) hmdViewingAngleHorizontal;
	mapConfigPub.publish(msg);
}

void ImageViewer::leftImageCallback(const sensor_msgs::ImageConstPtr& msg) {
	images.addLeftImage(msg2Mat(msg), msg->header.stamp.sec*1000L + msg->header.stamp.nsec/1000L/1000L);
}

void ImageViewer::rightImageCallback(const sensor_msgs::ImageConstPtr& msg) {
	images.addRightImage(msg2Mat(msg), msg->header.stamp.sec*1000L + msg->header.stamp.nsec/1000L/1000L);
}

void ImageViewer::HMDOrientationCallback(const geometry_msgs::PoseStamped& msg) {
	double yaw, pitch, roll;
	msgQuat2Degree(msg.pose.orientation, &yaw, &pitch, &roll);
	setHMDOrientation(yaw, pitch, -roll);
	if(measureTimeArg){
		HMDOrientationMicrosPrevious = HMDOrientationMicros;
		HMDOrientationMicros = msg.header.stamp.sec*1000L*1000L + msg.header.stamp.nsec/1000L;
	}
}

void ImageViewer::cameraOrientationCallback(const geometry_msgs::PoseStamped& msg) {
	double yaw, pitch, roll;
	msgQuat2Degree(msg.pose.orientation, &yaw, &pitch, &roll);
	struct orientationStruct tmp = {yaw, pitch, -roll};
	cameraOrientations.add(tmp, msg.header.stamp.sec*1000L + msg.header.stamp.nsec/1000L/1000L);
}

void ImageViewer::HMDInfoCallback(const oculus_msgs::HMDInfoPtr& info) {
	if (info->horizontal_screen_size > 0) {
		setEyeLensConfiguration(info->lens_separation_distance, info->horizontal_screen_size, info->eye_to_screen_distance);
		setDistortionCoefficients(info->distortion_K[0], info->distortion_K[1], info->distortion_K[2]);
	}
}

void ImageViewer::mapImageCallback(const sensor_msgs::ImageConstPtr& msg) {
	cv_bridge::CvImagePtr ptr;
	try {
		ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::TYPE_8UC1);
	} catch (cv_bridge::Exception& e) {
		ROS_ERROR("cv_bridge exception: %s", e.what());
	}
	mapImage = cv::Mat(ptr->image);
	if(mapImage.cols == MAP_SIZE(displaySize.height) && mapImage.rows == MAP_SIZE(displaySize.height)) {
		// Check whether the map has the correct size, if not, it would make problems with the masks
		mapReady = true;
	}
}

void ImageViewer::robotOdometryCallback(const nav_msgs::Odometry& msg) {
	double yaw, pitch, roll;
	msgQuat2Degree(msg.pose.pose.orientation, &roll, &pitch, &yaw);
	robotOrientation.yaw = yaw;
	robotOrientation.pitch = pitch;
	robotOrientation.roll = roll;
}

void ImageViewer::scaleImage(cv::Mat *img) {
	cv::Mat scaledImage;
	double scale = (displaySize.width/2.0 / img->cols) * ((cameraViewingAngleHorizontal*1.0) / hmdViewingAngleHorizontal);
	cv::resize(*img, scaledImage, cv::Size(), scale, scale);
	*img = scaledImage;
}

void ImageViewer::virtualRotate(cv::Mat *img) {
	double rollDiff =  HMDOrientation.roll - cameraOrientation.roll;
	if(std::abs(rollDiff) >= rotateThreshold) {
		int diagonal = (int)std::sqrt(img->rows*img->rows + img->cols*img->cols);
		cv::Mat enlargedImage(diagonal, diagonal, img->type(), cv::Scalar(0, 0, 0));
		cv::Rect centerRect = cv::Rect(	(img->cols - img->cols)>>1,
										(img->rows - img->rows)>>1,
										img->cols, img->rows);
		img->copyTo(enlargedImage(centerRect));
		cv::Mat rotatedImage;
		cv::Mat rotationMatrix = cv::getRotationMatrix2D(cv::Point2f(	(float)(enlargedImage.cols>>1),
																		(float)(enlargedImage.rows>>1)
																	), rollDiff, 1.0);
		cv::warpAffine(enlargedImage, *img, rotationMatrix, enlargedImage.size());
		// The image is now rotated
	}
}

void ImageViewer::virtualPanTilt(cv::Mat *img, float eyeOffsetX) {
	int posX = (displaySize.width*eyeOffsetX - img->cols) / 2;
	if(useRobotOrientationArg){
		posX += (int)((HMDOrientation.yaw - cameraOrientation.yaw - robotOrientation.yaw)*((displaySize.width>>1)/hmdViewingAngleHorizontal));
	} else {
		posX += (int)((HMDOrientation.yaw - cameraOrientation.yaw)*((displaySize.width>>1)/hmdViewingAngleHorizontal));
	}

	int posY = (displaySize.height - img->rows) >> 1;
	posY += (int)((HMDOrientation.pitch - cameraOrientation.pitch)*(displaySize.height/hmdViewingAngleVertical));

	cv::Mat dst(displaySize.height, displaySize.width>>1, img->type(), cv::Scalar(0, 0, 0));
	drawImageOnImage(img, &dst, posX, posY);
	*img = dst;
}

void ImageViewer::nonVirtualPositioning(cv::Mat *img, float eyeOffsetX) {
	int posX = (displaySize.width*eyeOffsetX - img->cols) / 2;
	int posY = (displaySize.height - img->rows) >> 1;
	cv::Mat dst(displaySize.height, displaySize.width>>1, img->type(), cv::Scalar(0, 0, 0));
	drawImageOnImage(img, &dst, posX, posY);
	*img = dst;
}

void ImageViewer::drawMap(cv::Mat *img, int posX, int posY) {
	int angle = -HMDOrientation.yaw;
	cv::Mat rotatedMap;
	cv::Mat rotationMatrix = cv::getRotationMatrix2D(cv::Point2f(	(float)(mapImage.cols>>1),
																	(float)(mapImage.rows>>1)
																), angle, 1.0);
	cv::warpAffine(mapImage, rotatedMap, rotationMatrix, rotatedMap.size());
	
	drawViewCone(&rotatedMap, (int) hmdViewingAngleHorizontal);
	drawCircle(&rotatedMap, (int)(CURSOR_SIZE_TO_IMAGE_SIZE*MAP_SIZE(displaySize.height)));
	if(useRobotOrientationArg){
		drawArrow(&rotatedMap, (int)(CURSOR_SIZE_TO_IMAGE_SIZE*MAP_SIZE(displaySize.height)*3), (robotOrientation.yaw+180-HMDOrientation.yaw)/180*M_PI);
	} else {
		drawArrow(&rotatedMap, (int)(CURSOR_SIZE_TO_IMAGE_SIZE*MAP_SIZE(displaySize.height)*3), -(cameraOrientation.yaw+180)/180*M_PI);
	}
	
	cv::Mat mask(MAP_SIZE(displaySize.height), MAP_SIZE(displaySize.height), CV_8UC1, cv::Scalar(0));
	uchar* maskBuf = mask.data;
	uchar* maskRoundBuf = roundMask.data;
	uchar* rawMapBuf = rotatedMap.data;
	for(int i = 0; i < MAP_SIZE(displaySize.height) * MAP_SIZE(displaySize.height); ++i){
		// fuse the round mask and the map mask
		// Is there a function that multiplies the elements of two arrays ?
		*maskBuf = (*maskRoundBuf) * (*rawMapBuf);
		++maskBuf;
		++maskRoundBuf;
		++rawMapBuf;
	}
	
	cv::Mat mapImageC3;
	cv::Mat channel_color(MAP_SIZE(displaySize.height), MAP_SIZE(displaySize.height), CV_8UC1, cv::Scalar(100));
	cv::Mat channel_zero(MAP_SIZE(displaySize.height), MAP_SIZE(displaySize.height), CV_8UC1, cv::Scalar(0));
	cv::Mat arr[3] = {channel_color, rotatedMap, channel_zero};	// blue, green, red
	cv::merge(arr, 3, mapImageC3);

	drawImageOnImage(&mapImageC3, img, posX, posY, &mask);
}

void ImageViewer::drawText(cv::Mat *img, int posX, int posY, std::string txt) {
	
	putText(	*img, txt, cv::Point(posX, posY),
				cv::FONT_HERSHEY_PLAIN, 2, cv::Scalar(20,20,200));
}

void ImageViewer::drawFPSText(cv::Mat *img, int posX, int posY) {
	#define FPS_TEXT_LENGTH_MAX 6
	if(fps > (pow(10, FPS_TEXT_LENGTH_MAX - 3)) || fps < 0) {
		return;
	}
	char tmpText[FPS_TEXT_LENGTH_MAX];
	sprintf(tmpText, "%.1f", fps);
	std::string txt = "FPS: ";
	drawText(img, posX, posY, txt + tmpText);
}


/**
 * This function will be called by a second thread
 * and will process the left image.
 * arg = instance of the ImageViewer
 */
void *threadFunc(void *arg){
    ImageViewer* instance = (ImageViewer*) arg;
    instance->processLeftImage();
}

void ImageViewer::imageProcessing(){
	finalImage = cv::Mat(displaySize, imageLeft.type(), cv::Scalar(0, 0, 0));
	
	//*
	struct orientationStruct tmp = {0,0,0};
	cameraOrientations.getNearest(images.getNewestMatchingImages(&imageLeft, &imageRight), &tmp);
	setCameraOrientation(tmp);
	//*/

	pthread_t thread;
//	pthread_init();

	pthread_create(&thread, 0, &threadFunc, this);		// Left image

	processRightImage();								// Right image

	pthread_join(thread, 0);

	// Both images are now placed side by side in the final image (window sized)
}

void ImageViewer::measureProcessingSteps(){
	images.getNewestMatchingImages(&imageLeft, &imageRight);
	struct orientationStruct tmp = {50,50,50};
	setCameraOrientation(tmp);

	cv::Mat tmpImg(imageLeft);
	ros::Time timeStart = ros::Time::now();

	scaleImage(&tmpImg);
	ros::Time timePostScale = ros::Time::now();

	virtualRotate(&tmpImg);
	ros::Time timePostRotate = ros::Time::now();
	virtualPanTilt(&tmpImg, eyeOffsetXLeft);
	ros::Time timePostVirtual = ros::Time::now();

	int posX = getXPosForLeftEye(lensSeparationDistancePixel, eye2ScreenDistancePixel, displaySize.width, MAP_POS_X_RIGHT((displaySize.width >> 1)), 4.0f);
	if(drawMapArg && mapReady) {
		drawMap(&tmpImg, posX, MAP_POS_Y(displaySize.height));
	}
	drawFPSText(&tmpImg, TEXT_POS_X_LEFT((displaySize.width >> 1)), TEXT_POS_Y(displaySize.height));
	ros::Time timePostHUD = ros::Time::now();

	tmpImg = barrel_dist(&tmpImg, tmpImg.cols * eyeOffsetXLeft, tmpImg.rows/2, distortionK0, distortionK1, distortionK2, 1/eyeScale);
	ros::Time timePostDistortion = ros::Time::now();

	ROS_INFO("\ntotal:%ld\nscale:%ld\nrotate:%ld\nvirtual:%ld\nHUD:%ld\ndistortion:%ld\n",
			timePostDistortion.sec*1000L*1000L + timePostDistortion.nsec/1000L - timeStart.sec*1000L*1000L - timeStart.nsec/1000L,
			timePostScale.sec*1000L*1000L + timePostScale.nsec/1000L - timeStart.sec*1000L*1000L - timeStart.nsec/1000L,
			timePostRotate.sec*1000L*1000L + timePostRotate.nsec/1000L - timePostScale.sec*1000L*1000L - timePostScale.nsec/1000L,
			timePostVirtual.sec*1000L*1000L + timePostVirtual.nsec/1000L - timePostRotate.sec*1000L*1000L - timePostRotate.nsec/1000L,
			timePostHUD.sec*1000L*1000L + timePostHUD.nsec/1000L - timePostVirtual.sec*1000L*1000L - timePostVirtual.nsec/1000L,
			timePostDistortion.sec*1000L*1000L + timePostDistortion.nsec/1000L - timePostHUD.sec*1000L*1000L - timePostHUD.nsec/1000L);
}

void ImageViewer::processLeftImage(){
	cv::Mat leftSide = finalImage(cv::Rect(0, 0, displaySize.width >> 1, displaySize.height));

	scaleImage(&imageLeft);
	
	if(useVirtualPanTiltArg) {
		virtualRotate(&imageLeft);
		virtualPanTilt(&imageLeft, eyeOffsetXLeft);
	} else {
		nonVirtualPositioning(&imageLeft, eyeOffsetXLeft);
	}

	int posX = getXPosForLeftEye(lensSeparationDistancePixel, eye2ScreenDistancePixel, displaySize.width, MAP_POS_X_RIGHT((displaySize.width >> 1)), 4.0f);
	if(drawMapArg && mapReady) {
		drawMap(&imageLeft, posX, MAP_POS_Y(displaySize.height));
	}

	drawFPSText(&imageLeft, TEXT_POS_X_LEFT((displaySize.width >> 1)), TEXT_POS_Y(displaySize.height));
	
	imageLeft = barrel_dist(&imageLeft, imageLeft.cols * eyeOffsetXLeft, imageLeft.rows/2, distortionK0, distortionK1, distortionK2, 1/eyeScale);

	imageLeft.copyTo(leftSide);
}

void ImageViewer::processRightImage(){
	cv::Mat rightSide = finalImage(cv::Rect(displaySize.width >> 1, 0, displaySize.width >> 1, displaySize.height));

	scaleImage(&imageRight);
	
	if(useVirtualPanTiltArg) {
		virtualRotate(&imageRight);
		virtualPanTilt(&imageRight, eyeOffsetXRight);
	} else {
		nonVirtualPositioning(&imageRight, eyeOffsetXRight);
	}

	if(drawMapArg && mapReady) {
		drawMap(&imageRight, MAP_POS_X_RIGHT((displaySize.width >> 1)), MAP_POS_Y(displaySize.height));
	}

	int posX = getXPosForRightEye(lensSeparationDistancePixel, eye2ScreenDistancePixel, displaySize.width, TEXT_POS_X_LEFT((displaySize.width >> 1)), 4.0f);
	drawFPSText(&imageRight, posX, TEXT_POS_Y(displaySize.height));

	imageRight = barrel_dist(&imageRight, imageRight.cols * eyeOffsetXRight, imageRight.rows/2, distortionK0, distortionK1, distortionK2, 1/eyeScale);

	imageRight.copyTo(rightSide);
}

void ImageViewer::showImages(){
	//cv::namedWindow("Display window", cv::WINDOW_NORMAL);
	//cv::namedWindow("Display window", cv::WINDOW_AUTOSIZE);
	cv::imshow("Display window", finalImage);

	ros::Time now = ros::Time::now();
	long nowMicros = now.sec*1000L*1000L + now.nsec/1000L;
	fps = 1000000.0/(nowMicros - imageShowLastMicros);
	if(measureTimeArg){
		ROS_INFO("\nTime from HMDOrientation received to display: %ld\nTime between two received HMDOrientations %ld\nTime between two displayed images: %ld",
				nowMicros - HMDOrientationMicros, HMDOrientationMicros - HMDOrientationMicrosPrevious, nowMicros - imageShowLastMicros);
		ROS_INFO("Frequency/FPS: %f", fps);
	}
	imageShowLastMicros = nowMicros;
}

void ImageViewer::setEyeLensConfiguration(float lensSeparationDistance, float horizontalScreenSize, float eye2ScreenDistance){
	eyeScale = 2 - 2 * lensSeparationDistance / horizontalScreenSize;		// TODO

	lensSeparationDistancePixel = (int) (lensSeparationDistance / horizontalScreenSize * displaySize.width);
	eye2ScreenDistancePixel = (int) (eye2ScreenDistance / lensSeparationDistance * lensSeparationDistancePixel);

	eyeOffsetXRight = lensSeparationDistancePixel >> 1;
	eyeOffsetXLeft = (displaySize.width>>1) - eyeOffsetXRight;

	// relative to the image width
	eyeOffsetXRight /= (displaySize.width>>1);
	eyeOffsetXLeft /= (displaySize.width>>1);
}	


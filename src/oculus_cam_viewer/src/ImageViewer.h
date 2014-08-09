/**
 * @Author Lars Harmsen
 */

#pragma once


// ------------------------ INCLUDES ------------------------

#include "ros/ros.h"
#include <sensor_msgs/Image.h>
#include <sensor_msgs/image_encodings.h>
#include <sensor_msgs/CompressedImage.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/PoseStamped.h>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <string>

#include <oculus_msgs/HMDInfo.h>
#include <map2image/mapConfig.h>

#include "image_manager.h"
#include "mapAdditionalDrawings.h"


// ------------------------ DEFINES ------------------------

#define WINDOW_WIDTH_DEFAULT 1280
#define WINDOW_HEIGHT_DEFAULT 800

#define MAP_SIZE(window_height) (window_height/8)
#define MAP_POS_X_RIGHT(image_width) (image_width>>1)
#define MAP_POS_Y(image_height) (image_height/3)

#define TEXT_POS_X_LEFT(image_width) (image_width/4)
#define TEXT_POS_Y(image_height) (image_height/3)

#define CURSOR_SIZE_TO_IMAGE_SIZE 0.06f

// Oculus Rift Dev Kit 1 has a field of view of 90° horizontal and 110° vertical per eye, this are the default values
#define CAMERA_ANGLE_HORIZONTAL 60.0f
#define HMD_ANGLE_HORIZONTAL 90.0f
#define CAMERA_ANGLE_VERTICAL(x) (x*3/4)
#define HMD_ANGLE_VERTICAL(x) (x*11.0f/9.0f)

#define TOPIC_LEFT_IMAGE "camera/left/image_rect_color"
#define TOPIC_RIGHT_IMAGE "camera/right/image_rect_color"
#define TOPIC_HMD_INFO "/oculus/hmdinfo"
#define TOPIC_HMD_ORIENTATION "/oculus/orientation_stamped"
#define TOPIC_CAMERA_ORIENTATION "/headunit/orientation_stamped"

#define TOPIC_ROBOT_ODOMETRY "/rosaria/pose"
#define TOPIC_MAP_IMAGE "/mapimage"
#define TOPIC_MAP_CONFIG "/mapConfig"

#define ARG_DRAW_MAP "showMap"		// Draw a map in the right upper corner
#define ARG_USE_VIRTUAL_PAN_TILT "useVirtualPanTilt"	// use virtual pan-tilt-roll
#define ARG_MEASURE_TIME "measurement"		// measure time
#define ARG_USE_ROBOT_ORIENTATION "useRobotOrientation"		// uses the odometry of the robot to counter rotate the view (steady head) (must be activated on the mobile side too)
#define ARG_ROTATE_THRESHOLD "rotateThreshold"		// defines minimum rotation angle needed to start image rotation

#define MIN_DIFF_FOR_VIRTUAL_ROLL 3.0f

#define MAP_RANGE 8.0


// ------------------------ STRUCTS ------------------------

struct orientationStruct{
	double yaw;
	double pitch;
	double roll;
};

// ------------------------ FUNCTIONS ------------------------

/** Help function to convert a msg into a Mat*/
cv::Mat msg2Mat(const sensor_msgs::ImageConstPtr& msg);

/** Help function to convert a msg with a quaternion into angles in degree*/
void msgQuat2Degree(const geometry_msgs::Quaternion& msg, double* yaw, double* pitch, double* roll);



// ------------------------ CLASSES ------------------------

class ImageViewer
{
public:

	ImageViewer(void);
	~ImageViewer(void);

	// --------------- PUBLIC FUNCTIONS ---------------

	/**
	 * Initializes ROS subscriptions and publishments.
	 * Reads rosrun parameters or sets the default value.
	 */
	void init();

	/**
	 * Transforms imageLeft and imageRight
	 * and places them side by side in finalImage
	 */
	void imageProcessing();
	void processLeftImage();
	void processRightImage();

	/**
	 * Test function to measure needed time in the different
	 * image processing steps.
	 * Is not used in the final program, just for testing purposes.
	 */
	void measureProcessingSteps();

	/**
	 * Displays finalImage in a window
	 */
	void showImages();

	/**
	 * Returns true, if both, a left and a right image, are available
	 */
	bool areImagesReady(){
		return !images.isEmpty();
	}

	void publishMapConfig();
	
	// --------------- CALLBACKS ---------------

	void leftImageCallback(const sensor_msgs::ImageConstPtr& msg);
	void rightImageCallback(const sensor_msgs::ImageConstPtr& msg);
	
	void mapImageCallback(const sensor_msgs::ImageConstPtr& msg);
	
	void HMDInfoCallback(const oculus_msgs::HMDInfoPtr& info);

	void HMDOrientationCallback(const geometry_msgs::PoseStamped& msg);
	void cameraOrientationCallback(const geometry_msgs::PoseStamped& msg);

	void robotOdometryCallback(const nav_msgs::Odometry& msg);

	// --------------- SETTERS ---------------
	
	void setHMDOrientation(double yaw, double pitch, double roll){
		HMDOrientation.yaw = yaw;
		HMDOrientation.pitch = pitch;
		HMDOrientation.roll = roll;
	}
	void setCameraOrientation(double yaw, double pitch, double roll){
		cameraOrientation.yaw = yaw;
		cameraOrientation.pitch = pitch;
		cameraOrientation.roll = roll;
	}

	void setCameraOrientation(orientationStruct orientation){
		cameraOrientation = orientation;
	}

	void setDistortionCoefficients(float k0, float k1, float k2){
		this->distortionK0 = k0;
		this->distortionK1 = k1;
		this->distortionK2 = k2;
	}

	void setEyeLensConfiguration(float lensSeparationDistance, float horizontalScreenSize, float eye2ScreenDistance);

	void setCameraViewingAngle(float a){
		this->cameraViewingAngleHorizontal = a;
		cameraViewingAngleVertical = CAMERA_ANGLE_VERTICAL(a);
	}

	void setHMDViewingAngle(float a){
		this->hmdViewingAngleHorizontal = a;
		hmdViewingAngleVertical = HMD_ANGLE_VERTICAL(a);
	}

private:

	// --------------- PRIVATE FUNCTIONS ---------------

	void scaleImage(cv::Mat *img);
	
	void virtualRotate(cv::Mat *img);
	void virtualPanTilt(cv::Mat *img, float eyeOffset);

	void nonVirtualPositioning(cv::Mat *img, float eyeOffset);

	void drawMap(cv::Mat *img, int posX, int posY);
	void createRoundMask();

	void drawText(cv::Mat *img, int posX, int posY, std::string txt);
	void drawFPSText(cv::Mat *img, int posX, int posY);


	// --------------- FIELDS ---------------
	
	ImageManager images;
	TimestampRingBuffer<orientationStruct> cameraOrientations;

	// ------ ROS ------
	ros::NodeHandle node;
	// ------ SUBS ------
	ros::Subscriber HMDInfoSub;
	ros::Subscriber HMDOrientationSub;
	ros::Subscriber cameraOrientationSub;
	ros::Subscriber mapImageSub;
	ros::Subscriber robotOdometrySub;
	image_transport::ImageTransport imageTransport;
	image_transport::Subscriber leftImageSub;
	image_transport::Subscriber rightImageSub;
	// ------ PUBS ------
	ros::Publisher mapConfigPub;

	// ------ ARGS ------
	bool useVirtualPanTiltArg;
	bool measureTimeArg;
	bool drawMapArg;
	bool useRobotOrientationArg;
	double rotateThreshold;


	cv::Size displaySize;

	cv::Mat imageLeft;
	cv::Mat imageRight;
	cv::Mat finalImage;
	cv::Mat mapImage;
	cv::Mat roundMask;

	orientationStruct HMDOrientation;
	orientationStruct cameraOrientation;
	orientationStruct robotOrientation;
	
	float cameraViewingAngleHorizontal;
	float cameraViewingAngleVertical;
	float hmdViewingAngleHorizontal;
	float hmdViewingAngleVertical;

	float distortionK0;
	float distortionK1;
	float distortionK2;

	int lensSeparationDistancePixel;
	int eye2ScreenDistancePixel;
	float eyeOffsetXRight;
	float eyeOffsetXLeft;
	float eyeScale;

	bool mapReady;

	long HMDOrientationMicros;
	long HMDOrientationMicrosPrevious;
	long imageShowLastMicros;
	float fps;
};



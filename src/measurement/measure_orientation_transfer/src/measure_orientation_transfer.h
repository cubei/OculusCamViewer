/**
 * @Author Lars Harmsen
 */

#pragma once

#include "ros/ros.h"
#include <geometry_msgs/PoseStamped.h>
#include "std_msgs/Int8.h"

#define TOPIC_ORIENTATION_OUT "orientation/out"
#define TOPIC_ORIENTATION_IN "orientation/in"
#define TOPIC_GO_SIGNAL "measure/go"

class MeasureOrientationTransfer
{
public:

	MeasureOrientationTransfer(void);
	~MeasureOrientationTransfer(void);
	
	void init();

	bool ready2publish() { return goSignalReceived; }
	void publish();

	// --------------- Callbacks ---------------
	void orientationCallback(const geometry_msgs::PoseStamped& msg);
	void goSignalCallback(const std_msgs::Int8 msg);

private:
	ros::NodeHandle node;
	ros::Subscriber orientationSub;
	ros::Subscriber goSignalSub;
	ros::Publisher orientationPub;

	geometry_msgs::PoseStamped orientation;

	long SentImageTimeMicros;

	bool goSignalReceived;	// Start publishing ?
};



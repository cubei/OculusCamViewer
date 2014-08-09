/**
 * @Author Lars Harmsen
 */

#pragma once

#include "ros/ros.h"
#include <geometry_msgs/PoseStamped.h>
#include "std_msgs/Int8.h"

#define TOPIC_ORIENTATION_IN "orientation/out"
#define TOPIC_ORIENTATION_OUT "orientation/in"
#define TOPIC_GO_SIGNAL "measure/go"

class ReplyOrientation
{
public:

	ReplyOrientation(void);
	~ReplyOrientation(void);
	
	void init();

	void publish(geometry_msgs::PoseStamped msg);

	void publishGoSignal();

	// --------------- Callbacks ---------------
	void orientationCallback(const geometry_msgs::PoseStamped& msg);

private:
	ros::NodeHandle node;
	ros::Subscriber orientationSub;
	ros::Publisher goSignalPub;
	ros::Publisher orientationPub;
};



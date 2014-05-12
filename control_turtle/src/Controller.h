#ifndef Controller_h__guard
#define Controller_h__guard

#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Pose2D.h>

class Controller {
public:
	virtual geometry_msgs::Twist computeCommand(const geometry_msgs::Pose2D& pose) = 0;

	virtual ~Controller(){};
};

#endif
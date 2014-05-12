#include "OrganismController.h"

using namespace geometry_msgs;

geometry_msgs::Twist OrganismController::computeCommand(const geometry_msgs::Pose2D& pose) {
	
	
	geometry_msgs::Twist twist;
	
	twist.linear.x = 0.;
	twist.angular.z = 0.;
	
	return twist;
}

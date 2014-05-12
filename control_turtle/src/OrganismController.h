#ifndef OrganismController_h__guard
#define OrganismController_h__guard

#include "Controller.h"

class OrganismController : public Controller {
public:
	geometry_msgs::Twist computeCommand(const geometry_msgs::Pose2D& pose);

};

#endif
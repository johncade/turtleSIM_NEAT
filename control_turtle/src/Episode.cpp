#include "Episode.h"

#include "Controller.h"

#include <std_srvs/Empty.h>

Episode::Episode(const geometry_msgs::Pose2D& goalPose, Controller *controller, ros::Publisher *pub) : 
			controller(controller), 
			velocity_pub(pub),
			initial(ros::Time::now()),
			termination(false),
			done(false),
			goalPose(goalPose),
			finalPose()
			{}

void Episode::run(const geometry_msgs::Pose2D& pose) {

	if(termination) {
		if(false/* TODO the input pose is the initial pose*/)
			done = true;
	}
	else {
		geometry_msgs::Twist command = controller->computeCommand(pose);
		velocity_pub->publish(command);
	}
	
	if((ros::Time::now() - initial).toSec() > 60) {
		 finalPose = pose;
		 termination = true;
		 ros::NodeHandle node;
		 ros::ServiceClient client = node.serviceClient<std_srvs::Empty>("/reset");
		 std_srvs::Empty empty;
		 client.call(empty);
	}
		
}


bool Episode::hasFinished() const {
	return done;
}
	
double Episode::computeFitness() const {
	return 0;
}



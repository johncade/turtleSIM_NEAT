#ifndef Episode_h__guard
#define Episode_h__guard

#include <geometry_msgs/Pose2D.h>
#include <ros/ros.h>

class Controller;

class Episode {
public:

	Episode(const geometry_msgs::Pose2D& goalPose, Controller *controller, ros::Publisher *pub);
	
	void run(const geometry_msgs::Pose2D& pose);
	
	bool hasFinished() const;
	
	double computeFitness() const;
	
	
private:
	
	Controller *controller;
	ros::Publisher *velocity_pub;
	ros::Time initial;
	bool termination;
	bool done;
	geometry_msgs::Pose2D goalPose;
	geometry_msgs::Pose2D finalPose;
};

#endif
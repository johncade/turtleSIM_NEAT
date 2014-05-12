#include <ros/ros.h>
#include <turtlesim/Pose.h>

#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Pose2D.h>
#include <geometry_msgs/Pose.h>

#include "OrganismController.h"
#include "Episode.h"
#include "GeneticAlgorithm.h"

#include <string>

using namespace std;


geometry_msgs::Pose2D currentPose;


void poseCallback(const turtlesim::PoseConstPtr& msg){
  
	/*translating turtlesim's Pose in the more general Pose2D
	so that your control function can be ported to control any 2D system,
	for instance our robots.*/

	currentPose.x = msg->x;
	currentPose.y = msg->y;
	currentPose.theta = msg->theta;
}

int main(int argc, char** argv){
  ros::init(argc, argv, "control_turtle");
  
  string turtle_name = "/turtle1";

  ros::NodeHandle node;
  ros::Subscriber sub = node.subscribe(turtle_name+"/pose", 10, &poseCallback);
  ros::Publisher velocity_pub = node.advertise<geometry_msgs::Twist>(turtle_name+"/cmd_vel", 10);
  
  int episodeCount = 0;
  
  geometry_msgs::Pose2D goal;
  //TODO set you goal
  goal.x = 0.;
  goal.y = 0.;
  goal.theta = 0.;
  
  GeneticAlgorithm algorithm;
  
  OrganismController *controller = algorithm.nextOrganism();
  Episode ep(goal,controller, &velocity_pub);
  
  while(ros::ok() && episodeCount < 100) {
	  
	ros::spinOnce();
	
	ep.run(currentPose);
	
	if(ep.hasFinished()) {
		episodeCount++;
		algorithm.evaluated(controller,ep.computeFitness());
		delete controller;
		ep = Episode(goal,algorithm.nextOrganism(),&velocity_pub);
	}
  }

  return 0;
}

	
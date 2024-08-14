#include "ros/ros.h"
#include "turtlesim/Pose.h"

void chatterCallback(const turtlesim::Pose::ConstPtr& msg)
{
  ROS_INFO("x-axis: %.2f , y-axis: %.2f , theta: %.2f", msg->x,msg->y,msg->theta);
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "pose_node");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("turtle1/pose", 50, chatterCallback);

  ros::spin();

  return 0;
}

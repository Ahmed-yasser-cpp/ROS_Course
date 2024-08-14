#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"
#include "geometry_msgs/Twist.h"

float front   = 0;
float right   = 0;
float left    = 0;

void chatterCallback(const sensor_msgs::LaserScan::ConstPtr& input_msg)
{
    front = input_msg->ranges[0];
    left  = input_msg->ranges[90];
    right = input_msg->ranges[270];
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "project_node");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("scan",50, chatterCallback);
  
  ros::Publisher project_pub ;

  project_pub = n.advertise<geometry_msgs::Twist>("cmd_vel", 50);
    
  ros::Rate loop_rate(50);

  geometry_msgs::Twist output_msg;

  while (ros::ok())
  {
    if ( front>1 && left>1 && right>1){
        output_msg.linear.x  = 0.22;
        output_msg.angular.z = 0;
        ROS_INFO("Moving Forward");
    }
    if ( front<=1 || right<=1){
        output_msg.linear.x  = 0;
        output_msg.angular.z = 1;
        ROS_INFO("Turning Left");
    }
    if (left<=1){
        output_msg.linear.x  = 0;
        output_msg.angular.z = -1;
        ROS_INFO("Turning Right");
    }
    project_pub.publish(output_msg);
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}
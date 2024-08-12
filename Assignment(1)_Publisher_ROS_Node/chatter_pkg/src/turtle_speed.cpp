#include "ros/ros.h"
#include "geometry_msgs/Twist.h"


int main(int argc, char **argv)
{

  ros::init(argc, argv, "turtle_speed");


  ros::NodeHandle n;

  
  ros::Publisher turtle_speed_pub ;

   turtle_speed_pub = n.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 50);

  geometry_msgs::Twist msg;


    
  
  while (ros::ok())
  {

    msg.linear.x= 5.0;

    msg.angular.z= 0.0;

    turtle_speed_pub.publish(msg);

  }


  return 0;
}
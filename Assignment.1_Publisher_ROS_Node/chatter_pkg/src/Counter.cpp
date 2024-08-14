#include "ros/ros.h"
#include "std_msgs/Int32.h"


int main(int argc, char **argv)
{

  ros::init(argc, argv, "Counter_node");


  ros::NodeHandle n;

  
  ros::Publisher counter_pub ;

   counter_pub = n.advertise<std_msgs::Int32>("counter_topic", 50);

  ros::Rate loop_rate(5);

    
  int count = 20;
  while (count <= 100)
  {

    std_msgs::Int32 msg;

 
    msg.data = count;

    counter_pub.publish(msg);

    ROS_INFO("%d", msg);


    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}
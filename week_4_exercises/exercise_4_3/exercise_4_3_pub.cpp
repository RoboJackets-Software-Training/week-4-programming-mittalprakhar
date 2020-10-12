#include <iostream>
#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <nav_msgs/Odometry.h>
#include <week_4_exercises/CustomMessage.h>

int main(int argc, char** argv) {
  ros::init(argc, argv, "custom_message_node_pub");
  ros::NodeHandle nh;

  ros::Publisher custom_pub = nh.advertise<week_4_exercises::CustomMessage>("cosine_sine", 1);

  ros::Rate rate(20);
  while(ros::ok()) {
    ros::Time time = ros::Time::now();

    week_4_exercises::CustomMessage custom_msg;
    custom_msg.cosine.data = cos(time.toSec());
    custom_msg.sine.data = sin(time.toSec());
    
    custom_pub.publish(custom_msg);

    ros::spinOnce();
    rate.sleep();
  }
}

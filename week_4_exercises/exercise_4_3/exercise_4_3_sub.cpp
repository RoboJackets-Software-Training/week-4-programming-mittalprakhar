
#include <iostream>
#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <week_4_exercises/CustomMessage.h>

double cosine = 0;
double sine = 0;
ros::Publisher sum_pub;

void customCallback(week_4_exercises::CustomMessage custom_msg) {
  cosine = custom_msg.cosine.data;
  sine = custom_msg.sine.data;
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "custom_message_node_sub");
  ros::NodeHandle nh;

  sum_pub = nh.advertise<std_msgs::Float64>("output", 1);

  ros::Subscriber custom_sub = nh.subscribe("cosine_sine", 1, customCallback);

  ros::spin();
  ros::Rate rate(20);
  while(ros::ok()) {
    std_msgs::Float64 pub_msg;
    pub_msg.data = std::max(cosine, sine);

    sum_pub.publish(pub_msg);

    ros::spinOnce();
    rate.sleep();
  }
}

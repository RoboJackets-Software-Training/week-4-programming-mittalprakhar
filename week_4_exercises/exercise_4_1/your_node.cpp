#include <ros/ros.h>
#include <std_msgs/String.h>

void callback_function(std_msgs::String string_msg)
{
	ROS_INFO_STREAM(string_msg.data);
}

int main(int argc, char** argv){
    ros::init(argc, argv, "your_node");
    ros::NodeHandle p_nh = ros::NodeHandle("~");

    ros::Subscriber subscriber = p_nh.subscribe("/string_topic", 1, &callback_function);

    ros::spin();
    return 0;
}
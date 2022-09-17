#include <ros/ros.h>
#include <std_msgs/String.h>

void callback(const std_msgs::String& str){
    ROS_INFO("listen: %s", str.data.c_str());
}

int main(int argc, char** argv){
    ros::init(argc,argv, "remote");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::String>("chatter2", 10);
    ros::Subscriber sub = nh.subscribe("chatter1", 10, callback);

    ros::Rate rate(10);

    while(ros::ok()){
        std_msgs::String msg;
        msg.data = "Hello naga";
        pub.publish(msg);

        ros::spinOnce();
        rate.sleep();
    }
}
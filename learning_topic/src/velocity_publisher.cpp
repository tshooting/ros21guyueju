/**
 * 发布的是turtle1/cmd_vel话题，消息类型geometry_msgs::Twist
 * */
 
#include<ros/ros.h>
#include<geometry_msgs/Twist.h>
 

int main(int argc,char ** argv)
{
    // ros node init  the name of publisher node
    ros::init(argc,argv,"velocity_publisher");
    
    // create node handle node master
    ros::NodeHandle n;
    
    // create a publisher && topic name && msg type && queue length
    ros::Publisher turtle_vel_pub = n.advertise<geometry_msgs::Twist> ("/turtle1/cmd_vel",10);

    //set cycle frequency 10times/sec
    ros::Rate loop_rate (10);

    int count = 0;
    while(ros::ok()){
        //init msg 
        geometry_msgs::Twist vel_msg;
        vel_msg.linear.x = 0.5;//now y and z is zero
        vel_msg.angular.z = 0.2;

        //publish msg
        turtle_vel_pub.publish(vel_msg);

        //like cout
        ROS_INFO("Publish turtle velocity command [%0.2f m/s, %0.2f rad/s]",vel_msg.linear.x,vel_msg.angular.z);

        //delay according to cycle frequency  
        loop_rate.sleep();
    }
    return 0;

}
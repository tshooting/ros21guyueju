/**
 * 现在是实现一个订阅者
 * 首先初始化ros节点【这个时候还不知道这个节点的角色，一个节点可以是发布者同时也可以是订阅者】
 * 创建句柄
 * 
 * 创建订阅者 让这个节点去订阅话题
 * 循环等待话题消息，接收到消息后进入回调函数
 * 在回调函数中完成消息的处理
 * 
 * */
#include<ros/ros.h>
#include"turtlesim/Pose.h"
void poseCallback(const turtlesim::Pose::ConstPtr & msg)
{
    ROS_INFO("Turtle Pose : x:%0.6f,y:%0.6f",msg->x,msg->y);
}
int main( int argc,char ** argv){
    //初始化ros节点
    ros::init(argc,argv, "pose_subscriber");
    
    //创建句柄
    ros::NodeHandle n;

    //创建一个订阅者，订阅者的名字和队列长度，注册回调函数
    ros::Subscriber pose_sub = n.subscribe("/turtle1/pose",10,poseCallback);
    
    //循环等待回调函数
    ros::spin();

    return 0;
}
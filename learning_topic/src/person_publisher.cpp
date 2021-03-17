/**
 * 
 * 现在是创建一个话题的发布者
 * 1 初始化ros节点
 * 2 创建句柄
 * 3 创建发布者 话题名字 队列长队
 * 4 设置发布频率
 * 5 创建循环，设置消息，发送消息，按照频率进行延迟
 * 
 * */
#include<ros/ros.h>
#include "learning_topic/Person.h"
int main(int argc,char ** argv)
{
    //初始化ros节点
    ros::init(argc,argv,"person_publisher");
    //创建句柄
    ros::NodeHandle n;
    //创建一个发布者
    ros::Publisher person_info_pub = n.advertise<learning_topic::Person>("/person_info",10);
    //设置循环频率
    ros::Rate loop_rate(1);
    int count = 0;
    while(ros::ok()){
        //初始化learning_topic::Person 类型的消息
        learning_topic::Person person_msg;
        person_msg.name = "Tom";
        person_msg.age = 18;
        person_msg.sex = learning_topic::Person::male;
        //发布消息
        person_info_pub.publish(person_msg);
        ROS_INFO("Publish Person Info : name : %s  age : %d sex : %d",person_msg.name.c_str(),person_msg.age,person_msg.sex);
        //按照循环频率延时
        loop_rate.sleep();

    }
    return 0;
}
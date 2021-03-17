/**
 * 创建一个订阅者，需要导入消息的类
 * 定义回调函数
 * 初始化ros节点
 * 创建句柄
 * 创建订阅者 
 * 循环等待回调函数
 * */
#include<ros/ros.h>
#include"learning_topic/Person.h"
void personInfoCallback(const learning_topic ::Person::ConstPtr & msg){
    ROS_INFO("Subscribe Person Info : name : %s age : %d sex: %d",msg->name.c_str(),msg->age,msg->male);
}
int main(int argv,char ** argc){
    //init node
    ros::init(argv,argc,"person_subscriber");
    
    ros::NodeHandle n;

    ros::Subscriber person_info_sub = n.subscribe("/person_info",10,personInfoCallback);

    ros::spin();
    return 0;
}

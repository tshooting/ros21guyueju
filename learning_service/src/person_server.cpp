/**
 * 创建一个服务端 执行/show_person 服务，参数类型是learning_service::Person
 * 初始化节点
 * 创建服务端，注册回调函数 
 * 循环等待回调函数
 * 
 * */
#include<ros/ros.h>
#include "learning_service/Person.h"
bool personCallback(learning_service::Person::Request & req,
    learning_service::Person::Response & res)
{
    ROS_INFO("Person : name : %s age : %d sex : %d",req.name.c_str(),req.age,req.male);
    //设置反馈数据
    res.result = "OK";

}
int main(int argc,char ** argv)
{
    ros::init(argc,argv,"person_server");
    ros::NodeHandle n;
    ros::ServiceServer person_service = n.advertiseService("/show_person",personCallback);
    //循环等待回调函数
    ROS_INFO("Ready to show person information.");
    ros::spin();
    return 0;
}
/**
 * 现在是客户端代码
 * 初始化节点
 * 发现服务然后创建客户端
 * 初始化数据 发送请求
 * 请求响应的结果
 * 
 * */
#include<ros/ros.h>
#include "learning_service/Person.h"
int main(int argc,char ** argv)
{
    //初始化
    ros::init(argc,argv,"person_client");
    ros::NodeHandle node;
    //等待服务 创建客户端
    ros::service::waitForService("/show_person");
    ros::ServiceClient person_client = node.serviceClient<learning_service::Person>("/show_person");
    //初始化learning_service::Person
    learning_service::Person srv;
    srv.request.name = "Tom";
    srv.request.age = 20;
    srv.request.sex = learning_service::Person::Request::male;
    //请求服务调用
    ROS_INFO("Call service to show person [name :%s,age : %d,sex:%d]",
        srv.request.name.c_str(),srv.request.age,srv.request.sex
    );
    //调用服务
    person_client.call(srv);
    //显示服务调用结果
    ROS_INFO("show person result : %s ",srv.response.result.c_str());


    return 0;
}
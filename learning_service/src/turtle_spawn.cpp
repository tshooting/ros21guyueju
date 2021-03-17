/**
 * 创建一个客户端，请求/spawn，服务的数据类型是 turtlesim::Spawn
 * 初始化ros节点
 * 发现服务创建一个客户端实例
 * 设置请求服务数据，发布请求
 * 等待server处理之后的应答结果
 * */
#include<ros/ros.h>
#include<turtlesim/Spawn.h>
int main(int argc, char ** argv)
{
    //初始化节点 创建句柄
    ros::init(argc,argv,"turtle_spawn");
    ros::NodeHandle node;
    //发现服务 创建客户端
    ros::service::waitForService("/spawn");
    ros::ServiceClient add_turtle = node.serviceClient<turtlesim::Spawn> ("/spawn");
    //初始化turtlesim::Spwn 的请求数据
    turtlesim::Spawn srv;
    srv.request.x = 2.0;
    srv.request.y = 2.0;
    srv.request.name = "turtle2";
    //请求服务调用
    ROS_INFO("Call service to spawn turtle [x : %0.6f,y:%0.6f ,name :%s]",srv.request.x,srv.request.y,srv.request.name);
    add_turtle.call(srv);

    //显示服务调用结果
    ROS_INFO("Spawn turtle successfully [name :%s]",srv.response.name.c_str());

    return 0;
}
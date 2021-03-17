/**
 * 设置海龟历程中的参数
 * */
#include<string>
#include<ros/ros.h>
#include<std_srvs/Empty.h>
int main(int argc,char ** argv)
{
    int red,green , blue;
    //ros 初始化和创建句柄
    ros::init(argc,argv,"parameter_config");
    ros::NodeHandle node;
    //读取背景颜色
    ros::param::get("/background_r",red);
    ros::param::get("/background_g",green);
    ros::param::get("/background_b",blue);
    //输出读取的背景颜色
    ROS_INFO("Get Background Color [%d ,%d,%d]",red,green,blue);
    //设置背景颜色参数
    ros::param::set("/background_r",255);   
    ros::param::set("/background_g",255);   
    ros::param::set("/background_b",255);   
    ROS_INFO("Get Background Color [255,255,255]");
    //因为已经被修改了 再读取背景颜色
    ros::param::get("/background_r",red);
    ros::param::get("/background_g",green);
    ros::param::get("/background_b",blue);
    ROS_INFO("Re-get Background Color [%d ,%d,%d]",red,green,blue);
    //调用服务，刷新背景颜色　等待服务　服务找到之后就设置参数　调用服务
    ros::service::waitForService("/clear");
    ros::ServiceClient clear_background = node.serviceClient<std_srvs::Empty>("/clear");
    std_srvs::Empty srv;
    clear_background.call(srv);
    sleep(1);
    return 0;
}
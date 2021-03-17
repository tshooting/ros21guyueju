/**
 * 现在要实现的就是一个服务器
 * 初始化ros节点
 * 创建服务端
 * 循环等待服务请求，进入回调函数响应请求
 * 在回调函数中完成服务功能的处理并反馈给客户端应答数据
 * 
 * */

#include<ros/ros.h>
#include<geometry_msgs/Twist.h>
#include<std_srvs/Trigger.h>
ros::Publisher turtle_vel_pub;
bool pubCommand = false;
bool commandCallback(std_srvs::TriggerRequest & req, std_srvs::TriggerResponse & res){

    pubCommand =  !pubCommand;
    //显示请求数据
    ROS_INFO ("publish turtle velocity command [%s]", pubCommand == true ? "Yes":"No");
    //设置反馈数据
    res.success = true;
    res.message = "Change turtle command state!";

}
int main(int argc,char ** argv )
{
    //初始化创建句柄
    ros::init(argc,argv,"turtle_command_server");
    ros::NodeHandle n;
    //创建一个服务 注册回调函数
    ros::ServiceServer command_service = n.advertiseService("/turtle_command",commandCallback);
    //创建一个发布者 设置循环发布消息
    turtle_vel_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",10);
    //循环等待回调函数 因为这是一个服务段，要一直等待响应客户端的请求
    ROS_INFO("Ready to receive turtle command.");
    //设置循环频率
    ros::Rate loop_rate(10);
    while(ros::ok()){
        //查看一次回调函数队列
        ros::spinOnce();
        //如果标志为true，则发布速度指令
        if(pubCommand){
            geometry_msgs::Twist vel_msg;
            vel_msg.linear.x = 0.5;
            vel_msg.angular.z = 0.2;
            turtle_vel_pub.publish(vel_msg);
        }
        //按照循环频率延时
        loop_rate.sleep();
    }

    return 0;
}
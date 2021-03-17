/**
 * 现在是实现一个tf广播器
 * 创建坐标变换值
 * 发布坐标变换
 * 
 * */
#include<ros/ros.h>
#include<tf/transform_broadcaster.h>
#include<turtlesim/Pose.h>
std::string turtle_name;
void poseCallback(const turtlesim::PoseConstPtr & msg){
    //创建ｔｆ的广播器
    static tf::TransformBroadcaster br;
    //初始化ｔｆ的数据
    tf::Transform transform;
    //平移
    transform.setOrigin(tf::Vector3(msg->x,msg->y,0));
    //四元数
    tf::Quaternion q;
    q.setRPY(0,0,msg->theta);
    transform.setRotation(q);
    
    //广播ｗｏｒｌｄ与海龟坐标系之间的ｔｆ数据
    br.sendTransform(
        tf::StampedTransform(
            transform,
            ros::Time::now(),
            "world",
            turtle_name
        )
    );

}
int main(int argc,char ** argv){
    ros::init(argc,argv,"my_tf_broadcaster");
    if(argc!=2){
        ROS_ERROR("need turtle name as argument");
        return -1;
    }
    turtle_name = argv[1];
    //订阅海龟的位子话题
    ros::NodeHandle node;
    ros::Subscriber sub = node.subscribe(turtle_name+"/pose",10,&poseCallback);
    //循环等待回调函数
    ros::spin();
    return 0;
}
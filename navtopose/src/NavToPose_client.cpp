#include <NavToPose/NavToPose.hpp>

int main( int argc, char** argv ){

  rclcpp::init(argc, argv);

  std::shared_ptr<nav2pose::nav2pose_client> client = std::make_shared<nav2pose::nav2pose_client>("navigate_to_pose");
  geometry_msgs::msg::PoseStamped pose1;
  pose1.header.frame_id = "map";
  pose1.pose.position.x = 1.62;
  pose1.pose.position.y = -1.84;
  client->call_server( pose1 );
  std::cout << "result is " << client->get_result() << std::endl;
  rclcpp::spin(client);
  rclcpp::shutdown();


  return 0;
}

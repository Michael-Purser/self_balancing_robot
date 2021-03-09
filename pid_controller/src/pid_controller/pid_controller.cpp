#include "pid_controller/helpers.h"
#include "pid_controller/pid_controller.h"

#include <ros/console.h>
#include <ros/node_handle.h>
#include <ros/rate.h>

pid_controller::PIDController::PIDController() :
    current_pitch_ {0.0}
{
  ros::NodeHandle node_handle;

  imu_subscriber_ = node_handle.subscribe("/teeterbot/imu", 1, &PIDController::imuCallback, this);
}

void
pid_controller::PIDController::spin() const
{
  ros::Rate spin_rate(500.0);

  while(ros::ok())
  {
    if (imu_subscriber_.getNumPublishers() > 0)
    {
      ros::spinOnce();
      spin_rate.sleep();
    }
    else
    {
      ROS_WARN_STREAM_THROTTLE(0.3, "No Imu messages published yet!");
    }
  }
}

void
pid_controller::PIDController::imuCallback(const sensor_msgs::ImuConstPtr& imu_msg)
{
  current_pitch_ = getPitchFromImuMessage(imu_msg);
}

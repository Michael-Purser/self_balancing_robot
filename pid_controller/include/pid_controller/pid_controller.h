#ifndef PID_CONTROLLER_PID_CONTROLLER
#define PID_CONTROLLER_PID_CONTROLLER

#include <ros/subscriber.h>

#include <sensor_msgs/Imu.h>

namespace pid_controller
{

class PIDController
{
public:
  PIDController();

  void spin() const;

private:
  void imuCallback(const sensor_msgs::ImuConstPtr& imu_msg);

  double current_pitch_;
  ros::Subscriber imu_subscriber_;
};

}

#endif

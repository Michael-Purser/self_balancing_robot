#ifndef PID_CONTROLLER_PID_CONTROLLER
#define PID_CONTROLLER_PID_CONTROLLER

#include <ros/node_handle.h>
#include <ros/rate.h>
#include <ros/subscriber.h>
#include <ros/publisher.h>

#include <sensor_msgs/Imu.h>

namespace pid_controller
{

class PIDController
{
public:
  PIDController(ros::NodeHandle& node_handle);

  void spin();

private:
  void imuCallback(const sensor_msgs::ImuConstPtr& imu_msg);
  void sendControlSignal();

  double current_pitch_;
  double cutoff_pitch_;
  double pitch_setpoint_;
  double proportional_control_gain_;
  double spin_rate_;

  ros::Subscriber imu_subscriber_;
  ros::Publisher left_wheel_publisher_;
  ros::Publisher right_wheel_publisher_;
};

}

#endif

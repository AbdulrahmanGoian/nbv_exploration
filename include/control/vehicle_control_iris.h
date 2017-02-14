#ifndef VEHICLECONTROLIRIS_H
#define VEHICLECONTROLIRIS_H

#include <ros/ros.h>
#include <geometry_msgs/Pose.h>
#include <nav_msgs/Odometry.h>

#include "control/vehicle_control_base.h"
#include "nbv_exploration/common.h"

class VehicleControlIris : public VehicleControlBase
{
private:
  ros::Subscriber sub_odom;
  double uav_height_min_;
  double uav_height_max_;

public:
  VehicleControlIris();

  void callbackOdometry(const nav_msgs::Odometry& odom_msg);

  bool isNear(double p1, double p2, double threshold_sensitivity = 1);
  bool isNear(const geometry_msgs::Pose p_target, const geometry_msgs::Pose p_current, double threshold_sensitivity = 1);
  bool isReady();
  bool isStationary(double threshold_sensitivity = 1);

  void moveVehicle(double threshold_sensitivity = 1);
  void setSpeed(double speed);
  void setWaypoint(double x, double y, double z, double yaw);
  void setWaypoint(geometry_msgs::Pose p);
  void setWaypointIncrement(double x, double y, double z, double yaw);
  void start();

  geometry_msgs::Pose transformSetpoint2Global (const geometry_msgs::Pose p_set);
  geometry_msgs::Pose transformGlobal2Setpoint (const geometry_msgs::Pose p_global);
};

#endif // VEHICLECONTROLIRIS_H

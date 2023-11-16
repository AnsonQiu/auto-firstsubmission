#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "beyondteslaopenloop";

// For Block beyondteslaopenloop/Subscribe1
SimulinkSubscriber<std_msgs::Float64, SL_Bus_beyondteslaopenloop_std_msgs_Float64> Sub_beyondteslaopenloop_39;

// For Block beyondteslaopenloop/Subscribe2
SimulinkSubscriber<std_msgs::Float64, SL_Bus_beyondteslaopenloop_std_msgs_Float64> Sub_beyondteslaopenloop_70;

// For Block beyondteslaopenloop/Subscribe3
SimulinkSubscriber<std_msgs::Float64, SL_Bus_beyondteslaopenloop_std_msgs_Float64> Sub_beyondteslaopenloop_71;

// For Block beyondteslaopenloop/Publish
SimulinkPublisher<std_msgs::Float64, SL_Bus_beyondteslaopenloop_std_msgs_Float64> Pub_beyondteslaopenloop_35;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}


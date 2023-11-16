#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "beyondteslaopenloop_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block beyondteslaopenloop/Subscribe1
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_beyondteslaopenloop_std_msgs_Float64> Sub_beyondteslaopenloop_39;

// For Block beyondteslaopenloop/Subscribe2
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_beyondteslaopenloop_std_msgs_Float64> Sub_beyondteslaopenloop_70;

// For Block beyondteslaopenloop/Subscribe3
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_beyondteslaopenloop_std_msgs_Float64> Sub_beyondteslaopenloop_71;

// For Block beyondteslaopenloop/Publish
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_beyondteslaopenloop_std_msgs_Float64> Pub_beyondteslaopenloop_35;

void slros_node_init(int argc, char** argv);

#endif

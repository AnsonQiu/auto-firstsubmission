//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: beyondteslaopenloop.h
//
// Code generated for Simulink model 'beyondteslaopenloop'.
//
// Model version                  : 8.0
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Thu Nov 16 12:29:05 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_beyondteslaopenloop_h_
#define RTW_HEADER_beyondteslaopenloop_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "beyondteslaopenloop_types.h"
#include <string.h>
#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

// Block signals (default storage)
struct B_beyondteslaopenloop_T {
  real_T ProportionalGain;             // '<S48>/Proportional Gain'
  real_T DerivativeGain;               // '<S37>/Derivative Gain'
  real_T FilterCoefficient;            // '<S46>/Filter Coefficient'
  real_T IntegralGain;                 // '<S40>/Integral Gain'
  SL_Bus_beyondteslaopenloop_std_msgs_Float64 In1;// '<S9>/In1'
  SL_Bus_beyondteslaopenloop_std_msgs_Float64 In1_f;// '<S8>/In1'
  SL_Bus_beyondteslaopenloop_std_msgs_Float64 In1_c;// '<S7>/In1'
};

// Block states (default storage) for system '<Root>'
struct DW_beyondteslaopenloop_T {
  ros_slroscpp_internal_block_P_T obj; // '<S2>/SinkBlock'
  ros_slroscpp_internal_block_S_T obj_m;// '<S5>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_c;// '<S4>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_k;// '<S3>/SourceBlock'
};

// Continuous states (default storage)
struct X_beyondteslaopenloop_T {
  real_T Integrator_CSTATE;            // '<S43>/Integrator'
  real_T Filter_CSTATE;                // '<S38>/Filter'
};

// State derivatives (default storage)
struct XDot_beyondteslaopenloop_T {
  real_T Integrator_CSTATE;            // '<S43>/Integrator'
  real_T Filter_CSTATE;                // '<S38>/Filter'
};

// State disabled
struct XDis_beyondteslaopenloop_T {
  boolean_T Integrator_CSTATE;         // '<S43>/Integrator'
  boolean_T Filter_CSTATE;             // '<S38>/Filter'
};

#ifndef ODE3_INTG
#define ODE3_INTG

// ODE3 Integration Data
struct ODE3_IntgData {
  real_T *y;                           // output
  real_T *f[3];                        // derivatives
};

#endif

// Parameters (default storage)
struct P_beyondteslaopenloop_T_ {
  real_T PIDController1_D;             // Mask Parameter: PIDController1_D
                                          //  Referenced by: '<S37>/Derivative Gain'

  real_T PIDController1_I;             // Mask Parameter: PIDController1_I
                                          //  Referenced by: '<S40>/Integral Gain'

  real_T PIDController1_InitialCondition;
                              // Mask Parameter: PIDController1_InitialCondition
                                 //  Referenced by: '<S38>/Filter'

  real_T PIDController1_InitialConditi_b;
                              // Mask Parameter: PIDController1_InitialConditi_b
                                 //  Referenced by: '<S43>/Integrator'

  real_T PIDController1_N;             // Mask Parameter: PIDController1_N
                                          //  Referenced by: '<S46>/Filter Coefficient'

  real_T PIDController1_P;             // Mask Parameter: PIDController1_P
                                          //  Referenced by: '<S48>/Proportional Gain'

  SL_Bus_beyondteslaopenloop_std_msgs_Float64 Constant_Value;// Computed Parameter: Constant_Value
                                                                //  Referenced by: '<S1>/Constant'

  SL_Bus_beyondteslaopenloop_std_msgs_Float64 Out1_Y0;// Computed Parameter: Out1_Y0
                                                         //  Referenced by: '<S7>/Out1'

  SL_Bus_beyondteslaopenloop_std_msgs_Float64 Constant_Value_p;// Computed Parameter: Constant_Value_p
                                                                  //  Referenced by: '<S3>/Constant'

  SL_Bus_beyondteslaopenloop_std_msgs_Float64 Out1_Y0_k;// Computed Parameter: Out1_Y0_k
                                                           //  Referenced by: '<S8>/Out1'

  SL_Bus_beyondteslaopenloop_std_msgs_Float64 Constant_Value_c;// Computed Parameter: Constant_Value_c
                                                                  //  Referenced by: '<S4>/Constant'

  SL_Bus_beyondteslaopenloop_std_msgs_Float64 Out1_Y0_i;// Computed Parameter: Out1_Y0_i
                                                           //  Referenced by: '<S9>/Out1'

  SL_Bus_beyondteslaopenloop_std_msgs_Float64 Constant_Value_o;// Computed Parameter: Constant_Value_o
                                                                  //  Referenced by: '<S5>/Constant'

  real_T Saturation_UpperSat;          // Expression: 1.5
                                          //  Referenced by: '<S6>/Saturation'

  real_T Saturation_LowerSat;          // Expression: -3
                                          //  Referenced by: '<S6>/Saturation'

};

// Real-time Model Data Structure
struct tag_RTM_beyondteslaopenloop_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_beyondteslaopenloop_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_beyondteslaopenloop_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[2];
  real_T odeF[3][2];
  ODE3_IntgData intgData;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tStart;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_beyondteslaopenloop_T beyondteslaopenloop_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_beyondteslaopenloop_T beyondteslaopenloop_B;

#ifdef __cplusplus

}

#endif

// Continuous states (default storage)
extern X_beyondteslaopenloop_T beyondteslaopenloop_X;

// Disabled states (default storage)
extern XDis_beyondteslaopenloop_T beyondteslaopenloop_XDis;

// Block states (default storage)
extern struct DW_beyondteslaopenloop_T beyondteslaopenloop_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void beyondteslaopenloop_initialize(void);
  extern void beyondteslaopenloop_step(void);
  extern void beyondteslaopenloop_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_beyondteslaopenloop_T *const beyondteslaopenloop_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Scope' : Unused code path elimination


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'beyondteslaopenloop'
//  '<S1>'   : 'beyondteslaopenloop/Blank Message'
//  '<S2>'   : 'beyondteslaopenloop/Publish'
//  '<S3>'   : 'beyondteslaopenloop/Subscribe1'
//  '<S4>'   : 'beyondteslaopenloop/Subscribe2'
//  '<S5>'   : 'beyondteslaopenloop/Subscribe3'
//  '<S6>'   : 'beyondteslaopenloop/beyondteslacontroller'
//  '<S7>'   : 'beyondteslaopenloop/Subscribe1/Enabled Subsystem'
//  '<S8>'   : 'beyondteslaopenloop/Subscribe2/Enabled Subsystem'
//  '<S9>'   : 'beyondteslaopenloop/Subscribe3/Enabled Subsystem'
//  '<S10>'  : 'beyondteslaopenloop/beyondteslacontroller/MATLAB Function1'
//  '<S11>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1'
//  '<S12>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/Anti-windup'
//  '<S13>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/D Gain'
//  '<S14>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/Filter'
//  '<S15>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/Filter ICs'
//  '<S16>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/I Gain'
//  '<S17>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/Ideal P Gain'
//  '<S18>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/Ideal P Gain Fdbk'
//  '<S19>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/Integrator'
//  '<S20>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/Integrator ICs'
//  '<S21>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/N Copy'
//  '<S22>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/N Gain'
//  '<S23>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/P Copy'
//  '<S24>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/Parallel P Gain'
//  '<S25>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/Reset Signal'
//  '<S26>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/Saturation'
//  '<S27>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/Saturation Fdbk'
//  '<S28>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/Sum'
//  '<S29>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/Sum Fdbk'
//  '<S30>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/Tracking Mode'
//  '<S31>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/Tracking Mode Sum'
//  '<S32>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/Tsamp - Integral'
//  '<S33>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/Tsamp - Ngain'
//  '<S34>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/postSat Signal'
//  '<S35>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/preSat Signal'
//  '<S36>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/Anti-windup/Passthrough'
//  '<S37>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/D Gain/Internal Parameters'
//  '<S38>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/Filter/Cont. Filter'
//  '<S39>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/Filter ICs/Internal IC - Filter'
//  '<S40>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/I Gain/Internal Parameters'
//  '<S41>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/Ideal P Gain/Passthrough'
//  '<S42>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S43>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/Integrator/Continuous'
//  '<S44>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/Integrator ICs/Internal IC'
//  '<S45>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/N Copy/Disabled'
//  '<S46>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/N Gain/Internal Parameters'
//  '<S47>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/P Copy/Disabled'
//  '<S48>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S49>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/Reset Signal/Disabled'
//  '<S50>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/Saturation/Passthrough'
//  '<S51>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/Saturation Fdbk/Disabled'
//  '<S52>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/Sum/Sum_PID'
//  '<S53>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/Sum Fdbk/Disabled'
//  '<S54>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/Tracking Mode/Disabled'
//  '<S55>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S56>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/Tsamp - Integral/TsSignalSpecification'
//  '<S57>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S58>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/postSat Signal/Forward_Path'
//  '<S59>'  : 'beyondteslaopenloop/beyondteslacontroller/PID Controller1/preSat Signal/Forward_Path'

#endif                                 // RTW_HEADER_beyondteslaopenloop_h_

//
// File trailer for generated code.
//
// [EOF]
//

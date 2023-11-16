//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: beyondteslaopenloop.cpp
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
#include "beyondteslaopenloop.h"
#include "rtwtypes.h"
#include "beyondteslaopenloop_types.h"
#include "beyondteslaopenloop_private.h"

// Block signals (default storage)
B_beyondteslaopenloop_T beyondteslaopenloop_B;

// Continuous states
X_beyondteslaopenloop_T beyondteslaopenloop_X;

// Disabled State Vector
XDis_beyondteslaopenloop_T beyondteslaopenloop_XDis;

// Block states (default storage)
DW_beyondteslaopenloop_T beyondteslaopenloop_DW;

// Real-time model
RT_MODEL_beyondteslaopenloop_T beyondteslaopenloop_M_ =
  RT_MODEL_beyondteslaopenloop_T();
RT_MODEL_beyondteslaopenloop_T *const beyondteslaopenloop_M =
  &beyondteslaopenloop_M_;

//
// This function updates continuous states using the ODE3 fixed-step
// solver algorithm
//
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  // Solver Matrices
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = static_cast<ODE3_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) memcpy(y, x,
                static_cast<uint_T>(nXc)*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  beyondteslaopenloop_derivatives();

  // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*));
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  beyondteslaopenloop_step();
  beyondteslaopenloop_derivatives();

  // f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*));
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  beyondteslaopenloop_step();
  beyondteslaopenloop_derivatives();

  // tnew = t + hA(3);
  // ynew = y + f*hB(:,3);
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

// Model step function
void beyondteslaopenloop_step(void)
{
  SL_Bus_beyondteslaopenloop_std_msgs_Float64 b_varargout_2;
  SL_Bus_beyondteslaopenloop_std_msgs_Float64 rtb_BusAssignment;
  real_T rtb_e;
  real_T u0;
  boolean_T b_varargout_1;
  if (rtmIsMajorTimeStep(beyondteslaopenloop_M)) {
    // set solver stop time
    rtsiSetSolverStopTime(&beyondteslaopenloop_M->solverInfo,
                          ((beyondteslaopenloop_M->Timing.clockTick0+1)*
      beyondteslaopenloop_M->Timing.stepSize0));
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep(beyondteslaopenloop_M)) {
    beyondteslaopenloop_M->Timing.t[0] = rtsiGetT
      (&beyondteslaopenloop_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(beyondteslaopenloop_M)) {
    // Outputs for Atomic SubSystem: '<Root>/Subscribe2'
    // MATLABSystem: '<S4>/SourceBlock'
    b_varargout_1 = Sub_beyondteslaopenloop_70.getLatestMessage(&b_varargout_2);

    // Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S8>/Enable'

    // Start for MATLABSystem: '<S4>/SourceBlock'
    if (b_varargout_1) {
      // SignalConversion generated from: '<S8>/In1'
      beyondteslaopenloop_B.In1_f = b_varargout_2;
    }

    // End of Start for MATLABSystem: '<S4>/SourceBlock'
    // End of Outputs for SubSystem: '<S4>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe2'

    // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
    // MATLABSystem: '<S3>/SourceBlock'
    b_varargout_1 = Sub_beyondteslaopenloop_39.getLatestMessage(&b_varargout_2);

    // Outputs for Enabled SubSystem: '<S3>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S7>/Enable'

    // Start for MATLABSystem: '<S3>/SourceBlock'
    if (b_varargout_1) {
      // SignalConversion generated from: '<S7>/In1'
      beyondteslaopenloop_B.In1_c = b_varargout_2;
    }

    // End of Start for MATLABSystem: '<S3>/SourceBlock'
    // End of Outputs for SubSystem: '<S3>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe1'

    // Outputs for Atomic SubSystem: '<Root>/Subscribe3'
    // MATLABSystem: '<S5>/SourceBlock'
    b_varargout_1 = Sub_beyondteslaopenloop_71.getLatestMessage(&b_varargout_2);

    // Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S9>/Enable'

    // Start for MATLABSystem: '<S5>/SourceBlock'
    if (b_varargout_1) {
      // SignalConversion generated from: '<S9>/In1'
      beyondteslaopenloop_B.In1 = b_varargout_2;
    }

    // End of Start for MATLABSystem: '<S5>/SourceBlock'
    // End of Outputs for SubSystem: '<S5>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe3'

    // MATLAB Function: '<S6>/MATLAB Function1'
    rtb_e = beyondteslaopenloop_B.In1_f.Data / beyondteslaopenloop_B.In1.Data;
    if (rtb_e <= 0.5) {
      rtb_e = -30.0;
    } else if (rtb_e <= 1.0) {
      rtb_e = -5.0;
    } else if ((rtb_e > 5.0) && (beyondteslaopenloop_B.In1_c.Data >= 0.0)) {
      rtb_e = 30.0;
    } else if (beyondteslaopenloop_B.In1_c.Data >= 0.0) {
      rtb_e = 20.0;
    } else if (beyondteslaopenloop_B.In1.Data > 40.0) {
      rtb_e = 0.0;
    } else if (-beyondteslaopenloop_B.In1_c.Data > 3.0) {
      rtb_e = (beyondteslaopenloop_B.In1_f.Data /
               -beyondteslaopenloop_B.In1_c.Data - 4.0) * 5.0;
    } else {
      rtb_e = 0.0;
    }

    // End of MATLAB Function: '<S6>/MATLAB Function1'

    // Gain: '<S48>/Proportional Gain'
    beyondteslaopenloop_B.ProportionalGain =
      beyondteslaopenloop_P.PIDController1_P * rtb_e;

    // Gain: '<S37>/Derivative Gain'
    beyondteslaopenloop_B.DerivativeGain =
      beyondteslaopenloop_P.PIDController1_D * rtb_e;
  }

  // Gain: '<S46>/Filter Coefficient' incorporates:
  //   Integrator: '<S38>/Filter'
  //   Sum: '<S38>/SumD'

  beyondteslaopenloop_B.FilterCoefficient =
    (beyondteslaopenloop_B.DerivativeGain - beyondteslaopenloop_X.Filter_CSTATE)
    * beyondteslaopenloop_P.PIDController1_N;

  // Sum: '<S52>/Sum' incorporates:
  //   Integrator: '<S43>/Integrator'

  u0 = (beyondteslaopenloop_B.ProportionalGain +
        beyondteslaopenloop_X.Integrator_CSTATE) +
    beyondteslaopenloop_B.FilterCoefficient;

  // Saturate: '<S6>/Saturation'
  if (u0 > beyondteslaopenloop_P.Saturation_UpperSat) {
    // BusAssignment: '<Root>/Bus Assignment'
    rtb_BusAssignment.Data = beyondteslaopenloop_P.Saturation_UpperSat;
  } else if (u0 < beyondteslaopenloop_P.Saturation_LowerSat) {
    // BusAssignment: '<Root>/Bus Assignment'
    rtb_BusAssignment.Data = beyondteslaopenloop_P.Saturation_LowerSat;
  } else {
    // BusAssignment: '<Root>/Bus Assignment'
    rtb_BusAssignment.Data = u0;
  }

  // End of Saturate: '<S6>/Saturation'

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // MATLABSystem: '<S2>/SinkBlock'
  Pub_beyondteslaopenloop_35.publish(&rtb_BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'
  if (rtmIsMajorTimeStep(beyondteslaopenloop_M)) {
    // Gain: '<S40>/Integral Gain'
    beyondteslaopenloop_B.IntegralGain = beyondteslaopenloop_P.PIDController1_I *
      rtb_e;
  }

  if (rtmIsMajorTimeStep(beyondteslaopenloop_M)) {
    rt_ertODEUpdateContinuousStates(&beyondteslaopenloop_M->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++beyondteslaopenloop_M->Timing.clockTick0;
    beyondteslaopenloop_M->Timing.t[0] = rtsiGetSolverStopTime
      (&beyondteslaopenloop_M->solverInfo);

    {
      // Update absolute timer for sample time: [0.05s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.05, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.

      beyondteslaopenloop_M->Timing.clockTick1++;
    }
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void beyondteslaopenloop_derivatives(void)
{
  XDot_beyondteslaopenloop_T *_rtXdot;
  _rtXdot = ((XDot_beyondteslaopenloop_T *) beyondteslaopenloop_M->derivs);

  // Derivatives for Integrator: '<S43>/Integrator'
  _rtXdot->Integrator_CSTATE = beyondteslaopenloop_B.IntegralGain;

  // Derivatives for Integrator: '<S38>/Filter'
  _rtXdot->Filter_CSTATE = beyondteslaopenloop_B.FilterCoefficient;
}

// Model initialize function
void beyondteslaopenloop_initialize(void)
{
  // Registration code
  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&beyondteslaopenloop_M->solverInfo,
                          &beyondteslaopenloop_M->Timing.simTimeStep);
    rtsiSetTPtr(&beyondteslaopenloop_M->solverInfo, &rtmGetTPtr
                (beyondteslaopenloop_M));
    rtsiSetStepSizePtr(&beyondteslaopenloop_M->solverInfo,
                       &beyondteslaopenloop_M->Timing.stepSize0);
    rtsiSetdXPtr(&beyondteslaopenloop_M->solverInfo,
                 &beyondteslaopenloop_M->derivs);
    rtsiSetContStatesPtr(&beyondteslaopenloop_M->solverInfo, (real_T **)
                         &beyondteslaopenloop_M->contStates);
    rtsiSetNumContStatesPtr(&beyondteslaopenloop_M->solverInfo,
      &beyondteslaopenloop_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&beyondteslaopenloop_M->solverInfo,
      &beyondteslaopenloop_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&beyondteslaopenloop_M->solverInfo,
      &beyondteslaopenloop_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&beyondteslaopenloop_M->solverInfo,
      &beyondteslaopenloop_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&beyondteslaopenloop_M->solverInfo, (boolean_T**)
      &beyondteslaopenloop_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&beyondteslaopenloop_M->solverInfo,
                          (&rtmGetErrorStatus(beyondteslaopenloop_M)));
    rtsiSetRTModelPtr(&beyondteslaopenloop_M->solverInfo, beyondteslaopenloop_M);
  }

  rtsiSetSimTimeStep(&beyondteslaopenloop_M->solverInfo, MAJOR_TIME_STEP);
  beyondteslaopenloop_M->intgData.y = beyondteslaopenloop_M->odeY;
  beyondteslaopenloop_M->intgData.f[0] = beyondteslaopenloop_M->odeF[0];
  beyondteslaopenloop_M->intgData.f[1] = beyondteslaopenloop_M->odeF[1];
  beyondteslaopenloop_M->intgData.f[2] = beyondteslaopenloop_M->odeF[2];
  beyondteslaopenloop_M->contStates = ((X_beyondteslaopenloop_T *)
    &beyondteslaopenloop_X);
  beyondteslaopenloop_M->contStateDisabled = ((XDis_beyondteslaopenloop_T *)
    &beyondteslaopenloop_XDis);
  beyondteslaopenloop_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&beyondteslaopenloop_M->solverInfo, static_cast<void *>
                    (&beyondteslaopenloop_M->intgData));
  rtsiSetIsMinorTimeStepWithModeChange(&beyondteslaopenloop_M->solverInfo, false);
  rtsiSetSolverName(&beyondteslaopenloop_M->solverInfo,"ode3");
  rtmSetTPtr(beyondteslaopenloop_M, &beyondteslaopenloop_M->Timing.tArray[0]);
  beyondteslaopenloop_M->Timing.stepSize0 = 0.05;

  {
    int32_T i;
    char_T b_zeroDelimTopic[10];
    char_T b_zeroDelimTopic_0[8];
    static const char_T b_zeroDelimTopic_1[10] = "lead_dist";
    static const char_T b_zeroDelimTopic_2[8] = "rel_vel";
    static const char_T b_zeroDelimTopic_3[8] = "ego_vel";
    static const char_T b_zeroDelimTopic_4[10] = "cmd_accel";

    // InitializeConditions for Integrator: '<S43>/Integrator'
    beyondteslaopenloop_X.Integrator_CSTATE =
      beyondteslaopenloop_P.PIDController1_InitialConditi_b;

    // InitializeConditions for Integrator: '<S38>/Filter'
    beyondteslaopenloop_X.Filter_CSTATE =
      beyondteslaopenloop_P.PIDController1_InitialCondition;

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe2'
    // SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S8>/In1' incorporates:
    //   Outport: '<S8>/Out1'

    beyondteslaopenloop_B.In1_f = beyondteslaopenloop_P.Out1_Y0_k;

    // End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem'

    // Start for MATLABSystem: '<S4>/SourceBlock'
    beyondteslaopenloop_DW.obj_c.matlabCodegenIsDeleted = false;
    beyondteslaopenloop_DW.obj_c.isInitialized = 1;
    for (i = 0; i < 10; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_1[i];
    }

    Sub_beyondteslaopenloop_70.createSubscriber(&b_zeroDelimTopic[0], 1);
    beyondteslaopenloop_DW.obj_c.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe2'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1'
    // SystemInitialize for Enabled SubSystem: '<S3>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S7>/In1' incorporates:
    //   Outport: '<S7>/Out1'

    beyondteslaopenloop_B.In1_c = beyondteslaopenloop_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S3>/Enabled Subsystem'

    // Start for MATLABSystem: '<S3>/SourceBlock'
    beyondteslaopenloop_DW.obj_k.matlabCodegenIsDeleted = false;
    beyondteslaopenloop_DW.obj_k.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      b_zeroDelimTopic_0[i] = b_zeroDelimTopic_2[i];
    }

    Sub_beyondteslaopenloop_39.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    beyondteslaopenloop_DW.obj_k.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe3'
    // SystemInitialize for Enabled SubSystem: '<S5>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S9>/In1' incorporates:
    //   Outport: '<S9>/Out1'

    beyondteslaopenloop_B.In1 = beyondteslaopenloop_P.Out1_Y0_i;

    // End of SystemInitialize for SubSystem: '<S5>/Enabled Subsystem'

    // Start for MATLABSystem: '<S5>/SourceBlock'
    beyondteslaopenloop_DW.obj_m.matlabCodegenIsDeleted = false;
    beyondteslaopenloop_DW.obj_m.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      b_zeroDelimTopic_0[i] = b_zeroDelimTopic_3[i];
    }

    Sub_beyondteslaopenloop_71.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    beyondteslaopenloop_DW.obj_m.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe3'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S2>/SinkBlock'
    beyondteslaopenloop_DW.obj.matlabCodegenIsDeleted = false;
    beyondteslaopenloop_DW.obj.isInitialized = 1;
    for (i = 0; i < 10; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_4[i];
    }

    Pub_beyondteslaopenloop_35.createPublisher(&b_zeroDelimTopic[0], 1);
    beyondteslaopenloop_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S2>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish'
  }
}

// Model terminate function
void beyondteslaopenloop_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe2'
  // Terminate for MATLABSystem: '<S4>/SourceBlock'
  if (!beyondteslaopenloop_DW.obj_c.matlabCodegenIsDeleted) {
    beyondteslaopenloop_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe2'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Terminate for MATLABSystem: '<S3>/SourceBlock'
  if (!beyondteslaopenloop_DW.obj_k.matlabCodegenIsDeleted) {
    beyondteslaopenloop_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe3'
  // Terminate for MATLABSystem: '<S5>/SourceBlock'
  if (!beyondteslaopenloop_DW.obj_m.matlabCodegenIsDeleted) {
    beyondteslaopenloop_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe3'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S2>/SinkBlock'
  if (!beyondteslaopenloop_DW.obj.matlabCodegenIsDeleted) {
    beyondteslaopenloop_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S2>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish'
}

//
// File trailer for generated code.
//
// [EOF]
//

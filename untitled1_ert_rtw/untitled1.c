/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled1.c
 *
 * Code generated for Simulink model 'untitled1'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Mon May 27 10:40:52 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled1.h"
#include "untitled1_private.h"
#include "untitled1_dt.h"

/* Block states (default storage) */
DW_untitled1_T untitled1_DW;

/* Real-time model */
static RT_MODEL_untitled1_T untitled1_M_;
RT_MODEL_untitled1_T *const untitled1_M = &untitled1_M_;

/* Model step function */
void untitled1_step(void)
{
  /* MATLABSystem: '<Root>/Servo Motor' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rc_servo_send_pulse_normalized(1, (untitled1_P.Constant_Value - 90.0) / 60.0);

  /* MATLABSystem: '<Root>/Servo Motor1' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rc_servo_send_pulse_normalized(2, (untitled1_P.Constant_Value - 90.0) / 60.0);

  /* MATLABSystem: '<Root>/Servo Motor2' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rc_servo_send_pulse_normalized(3, (untitled1_P.Constant_Value - 90.0) / 60.0);

  /* MATLABSystem: '<Root>/Servo Motor3' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rc_servo_send_pulse_normalized(4, (untitled1_P.Constant_Value - 90.0) / 60.0);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.02s, 0.0s] */
    rtExtModeUpload(0, (real_T)untitled1_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.02s, 0.0s] */
    if ((rtmGetTFinal(untitled1_M)!=-1) &&
        !((rtmGetTFinal(untitled1_M)-untitled1_M->Timing.taskTime0) >
          untitled1_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(untitled1_M, "Simulation finished");
    }

    if (rtmGetStopRequested(untitled1_M)) {
      rtmSetErrorStatus(untitled1_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  untitled1_M->Timing.taskTime0 =
    ((time_T)(++untitled1_M->Timing.clockTick0)) * untitled1_M->Timing.stepSize0;
}

/* Model initialize function */
void untitled1_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(untitled1_M, -1);
  untitled1_M->Timing.stepSize0 = 0.02;

  /* External mode info */
  untitled1_M->Sizes.checksums[0] = (3679958982U);
  untitled1_M->Sizes.checksums[1] = (2696088884U);
  untitled1_M->Sizes.checksums[2] = (4042253196U);
  untitled1_M->Sizes.checksums[3] = (2661919664U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    untitled1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled1_M->extModeInfo,
      &untitled1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled1_M->extModeInfo, untitled1_M->Sizes.checksums);
    rteiSetTPtr(untitled1_M->extModeInfo, rtmGetTPtr(untitled1_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    untitled1_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 20;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Start for MATLABSystem: '<Root>/Servo Motor' */
  untitled1_DW.obj_p.matlabCodegenIsDeleted = false;
  untitled1_DW.obj_p.isInitialized = 1;
  untitled1_DW.obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Servo Motor1' */
  untitled1_DW.obj_g.matlabCodegenIsDeleted = false;
  untitled1_DW.obj_g.isInitialized = 1;
  untitled1_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Servo Motor2' */
  untitled1_DW.obj_h.matlabCodegenIsDeleted = false;
  untitled1_DW.obj_h.isInitialized = 1;
  untitled1_DW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Servo Motor3' */
  untitled1_DW.obj.matlabCodegenIsDeleted = false;
  untitled1_DW.obj.isInitialized = 1;
  untitled1_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void untitled1_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Servo Motor' */
  if (!untitled1_DW.obj_p.matlabCodegenIsDeleted) {
    untitled1_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((untitled1_DW.obj_p.isInitialized == 1) &&
        untitled1_DW.obj_p.isSetupComplete) {
      rc_servo_send_pulse_normalized(1, 0.0);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Servo Motor' */

  /* Terminate for MATLABSystem: '<Root>/Servo Motor1' */
  if (!untitled1_DW.obj_g.matlabCodegenIsDeleted) {
    untitled1_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((untitled1_DW.obj_g.isInitialized == 1) &&
        untitled1_DW.obj_g.isSetupComplete) {
      rc_servo_send_pulse_normalized(2, 0.0);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Servo Motor1' */

  /* Terminate for MATLABSystem: '<Root>/Servo Motor2' */
  if (!untitled1_DW.obj_h.matlabCodegenIsDeleted) {
    untitled1_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((untitled1_DW.obj_h.isInitialized == 1) &&
        untitled1_DW.obj_h.isSetupComplete) {
      rc_servo_send_pulse_normalized(3, 0.0);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Servo Motor2' */

  /* Terminate for MATLABSystem: '<Root>/Servo Motor3' */
  if (!untitled1_DW.obj.matlabCodegenIsDeleted) {
    untitled1_DW.obj.matlabCodegenIsDeleted = true;
    if ((untitled1_DW.obj.isInitialized == 1) &&
        untitled1_DW.obj.isSetupComplete) {
      rc_servo_send_pulse_normalized(4, 0.0);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Servo Motor3' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

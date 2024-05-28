/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BeagleBone_Roll_Pitch_R_Kalman_Tuning.c
 *
 * Code generated for Simulink model 'BeagleBone_Roll_Pitch_R_Kalman_Tuning'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Mon May 27 17:43:32 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "BeagleBone_Roll_Pitch_R_Kalman_Tuning.h"
#include "BeagleBone_Roll_Pitch_R_Kalman_Tuning_types.h"
#include <math.h>
#include "rtwtypes.h"
#include "BeagleBone_Roll_Pitch_R_Kalman_Tuning_private.h"
#include "BeagleBone_Roll_Pitch_R_Kalman_Tuning_dt.h"

/* Block signals (default storage) */
B_BeagleBone_Roll_Pitch_R_Kal_T BeagleBone_Roll_Pitch_R_Kalma_B;

/* Block states (default storage) */
DW_BeagleBone_Roll_Pitch_R_Ka_T BeagleBone_Roll_Pitch_R_Kalm_DW;

/* Real-time model */
static RT_MODEL_BeagleBone_Roll_Pitc_T BeagleBone_Roll_Pitch_R_Kalm_M_;
RT_MODEL_BeagleBone_Roll_Pitc_T *const BeagleBone_Roll_Pitch_R_Kalm_M =
  &BeagleBone_Roll_Pitch_R_Kalm_M_;

/* Forward declaration for local functions */
static void BeagleBone_Rol_SystemCore_setup(beagleboneblue_bbblueMPU9250__T *obj);
static void BeagleBone_Rol_SystemCore_setup(beagleboneblue_bbblueMPU9250__T *obj)
{
  /* Start for MATLABSystem: '<Root>/MPU9250' */
  obj->isInitialized = 1;
  MW_IMU_DMP_isAccel_Calibrated();
  MW_IMU_DMP_isGyro_Calibrated();
  MW_IMU_DMP_isMag_Calibrated();

  /* Start for MATLABSystem: '<Root>/MPU9250' */
  obj->i2cObjmpu.MW_I2C_HANDLE = MW_I2C_Open(2, MW_I2C_MASTER);
  obj->i2cObjmpu.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cObjmpu.MW_I2C_HANDLE, obj->i2cObjmpu.BusSpeed);
  obj->i2cObjak8963.MW_I2C_HANDLE = MW_I2C_Open(2, MW_I2C_MASTER);
  obj->i2cObjak8963.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cObjak8963.MW_I2C_HANDLE, obj->i2cObjak8963.BusSpeed);
  MW_Init_IMU_DMP(200);
  obj->TunablePropsChanged = false;
}

/* Model step function */
void BeagleBone_Roll_Pitch_R_Kalman_Tuning_step(void)
{
  real_T mdata[3];
  real_T rtb_MPU9250_o1_0[3];

  /* MATLABSystem: '<Root>/MPU9250' */
  if (BeagleBone_Roll_Pitch_R_Kalm_DW.obj.SampleTime !=
      BeagleBone_Roll_Pitch_R_Kalma_P.MPU9250_SampleTime) {
    BeagleBone_Roll_Pitch_R_Kalm_DW.obj.SampleTime =
      BeagleBone_Roll_Pitch_R_Kalma_P.MPU9250_SampleTime;
  }

  if (BeagleBone_Roll_Pitch_R_Kalm_DW.obj.TunablePropsChanged) {
    BeagleBone_Roll_Pitch_R_Kalm_DW.obj.TunablePropsChanged = false;
  }

  MW_Read_Accel(&rtb_MPU9250_o1_0[0]);
  BeagleBone_Roll_Pitch_R_Kalma_B.Gain1[0] = 0.0;
  BeagleBone_Roll_Pitch_R_Kalma_B.Gain1[1] = 0.0;
  BeagleBone_Roll_Pitch_R_Kalma_B.Gain1[2] = 0.0;
  MW_Read_Gyro(&BeagleBone_Roll_Pitch_R_Kalma_B.Gain1[0]);
  mdata[0] = 0.0;
  mdata[1] = 0.0;
  mdata[2] = 0.0;
  MW_Read_Mag(&mdata[0]);

  /* Gain: '<S1>/Gain1' incorporates:
   *  MATLABSystem: '<Root>/MPU9250'
   */
  BeagleBone_Roll_Pitch_R_Kalma_B.Gain1[0] *=
    BeagleBone_Roll_Pitch_R_Kalma_P.Gain1_Gain;
  BeagleBone_Roll_Pitch_R_Kalma_B.Gain1[1] *=
    BeagleBone_Roll_Pitch_R_Kalma_P.Gain1_Gain;
  BeagleBone_Roll_Pitch_R_Kalma_B.Gain1[2] *=
    BeagleBone_Roll_Pitch_R_Kalma_P.Gain1_Gain;

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  MATLABSystem: '<Root>/MPU9250'
   */
  BeagleBone_Roll_Pitch_R_Kalma_B.pitch = rtb_MPU9250_o1_0[0] /
    rtb_MPU9250_o1_0[2];
  BeagleBone_Roll_Pitch_R_Kalma_B.pitch = atan
    (BeagleBone_Roll_Pitch_R_Kalma_B.pitch);

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  MATLABSystem: '<Root>/MPU9250'
   */
  BeagleBone_Roll_Pitch_R_Kalma_B.roll = rtb_MPU9250_o1_0[1] / rtb_MPU9250_o1_0
    [2];
  BeagleBone_Roll_Pitch_R_Kalma_B.roll = atan
    (BeagleBone_Roll_Pitch_R_Kalma_B.roll);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.1s, 0.0s] */
    rtExtModeUpload(0, (real_T)BeagleBone_Roll_Pitch_R_Kalm_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.1s, 0.0s] */
    if ((rtmGetTFinal(BeagleBone_Roll_Pitch_R_Kalm_M)!=-1) &&
        !((rtmGetTFinal(BeagleBone_Roll_Pitch_R_Kalm_M)-
           BeagleBone_Roll_Pitch_R_Kalm_M->Timing.taskTime0) >
          BeagleBone_Roll_Pitch_R_Kalm_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(BeagleBone_Roll_Pitch_R_Kalm_M, "Simulation finished");
    }

    if (rtmGetStopRequested(BeagleBone_Roll_Pitch_R_Kalm_M)) {
      rtmSetErrorStatus(BeagleBone_Roll_Pitch_R_Kalm_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  BeagleBone_Roll_Pitch_R_Kalm_M->Timing.taskTime0 =
    ((time_T)(++BeagleBone_Roll_Pitch_R_Kalm_M->Timing.clockTick0)) *
    BeagleBone_Roll_Pitch_R_Kalm_M->Timing.stepSize0;
}

/* Model initialize function */
void BeagleBone_Roll_Pitch_R_Kalman_Tuning_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(BeagleBone_Roll_Pitch_R_Kalm_M, -1);
  BeagleBone_Roll_Pitch_R_Kalm_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  BeagleBone_Roll_Pitch_R_Kalm_M->Sizes.checksums[0] = (2582370034U);
  BeagleBone_Roll_Pitch_R_Kalm_M->Sizes.checksums[1] = (2017128304U);
  BeagleBone_Roll_Pitch_R_Kalm_M->Sizes.checksums[2] = (915326109U);
  BeagleBone_Roll_Pitch_R_Kalm_M->Sizes.checksums[3] = (1377458278U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    BeagleBone_Roll_Pitch_R_Kalm_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(BeagleBone_Roll_Pitch_R_Kalm_M->extModeInfo,
      &BeagleBone_Roll_Pitch_R_Kalm_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(BeagleBone_Roll_Pitch_R_Kalm_M->extModeInfo,
                        BeagleBone_Roll_Pitch_R_Kalm_M->Sizes.checksums);
    rteiSetTPtr(BeagleBone_Roll_Pitch_R_Kalm_M->extModeInfo, rtmGetTPtr
                (BeagleBone_Roll_Pitch_R_Kalm_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    BeagleBone_Roll_Pitch_R_Kalm_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 20;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Start for MATLABSystem: '<Root>/MPU9250' */
  BeagleBone_Roll_Pitch_R_Kalm_DW.obj.isInitialized = 0;
  BeagleBone_Roll_Pitch_R_Kalm_DW.obj.i2cObjmpu.DefaultMaximumBusSpeedInHz =
    400000.0;
  BeagleBone_Roll_Pitch_R_Kalm_DW.obj.i2cObjmpu.isInitialized = 0;
  BeagleBone_Roll_Pitch_R_Kalm_DW.obj.i2cObjmpu.matlabCodegenIsDeleted = false;
  BeagleBone_Roll_Pitch_R_Kalm_DW.obj.i2cObjak8963.DefaultMaximumBusSpeedInHz =
    400000.0;
  BeagleBone_Roll_Pitch_R_Kalm_DW.obj.i2cObjak8963.isInitialized = 0;
  BeagleBone_Roll_Pitch_R_Kalm_DW.obj.i2cObjak8963.matlabCodegenIsDeleted =
    false;
  BeagleBone_Roll_Pitch_R_Kalm_DW.obj.matlabCodegenIsDeleted = false;
  BeagleBone_Roll_Pitch_R_Kalm_DW.obj.SampleTime =
    BeagleBone_Roll_Pitch_R_Kalma_P.MPU9250_SampleTime;
  BeagleBone_Rol_SystemCore_setup(&BeagleBone_Roll_Pitch_R_Kalm_DW.obj);
}

/* Model terminate function */
void BeagleBone_Roll_Pitch_R_Kalman_Tuning_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/MPU9250' */
  if (!BeagleBone_Roll_Pitch_R_Kalm_DW.obj.matlabCodegenIsDeleted) {
    BeagleBone_Roll_Pitch_R_Kalm_DW.obj.matlabCodegenIsDeleted = true;
  }

  if (!BeagleBone_Roll_Pitch_R_Kalm_DW.obj.i2cObjak8963.matlabCodegenIsDeleted)
  {
    BeagleBone_Roll_Pitch_R_Kalm_DW.obj.i2cObjak8963.matlabCodegenIsDeleted =
      true;
    if (BeagleBone_Roll_Pitch_R_Kalm_DW.obj.i2cObjak8963.isInitialized == 1) {
      BeagleBone_Roll_Pitch_R_Kalm_DW.obj.i2cObjak8963.isInitialized = 2;
    }
  }

  if (!BeagleBone_Roll_Pitch_R_Kalm_DW.obj.i2cObjmpu.matlabCodegenIsDeleted) {
    BeagleBone_Roll_Pitch_R_Kalm_DW.obj.i2cObjmpu.matlabCodegenIsDeleted = true;
    if (BeagleBone_Roll_Pitch_R_Kalm_DW.obj.i2cObjmpu.isInitialized == 1) {
      BeagleBone_Roll_Pitch_R_Kalm_DW.obj.i2cObjmpu.isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/MPU9250' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

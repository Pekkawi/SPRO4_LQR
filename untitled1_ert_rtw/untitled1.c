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
 * C/C++ source code generated on : Fri May 24 16:27:19 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled1.h"
#include "untitled1_types.h"
#include "rtwtypes.h"
#include "untitled1_private.h"
#include "untitled1_dt.h"

/* Block signals (default storage) */
B_untitled1_T untitled1_B;

/* Block states (default storage) */
DW_untitled1_T untitled1_DW;

/* Real-time model */
static RT_MODEL_untitled1_T untitled1_M_;
RT_MODEL_untitled1_T *const untitled1_M = &untitled1_M_;

/* Forward declaration for local functions */
static void untitled1_SystemCore_setup(beagleboneblue_bbblueMPU9250__T *obj);
static void untitled1_SystemCore_setup(beagleboneblue_bbblueMPU9250__T *obj)
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
void untitled1_step(void)
{
  real_T mdata[3];

  /* MATLABSystem: '<Root>/MPU9250' */
  if (untitled1_DW.obj.SampleTime != untitled1_P.MPU9250_SampleTime) {
    untitled1_DW.obj.SampleTime = untitled1_P.MPU9250_SampleTime;
  }

  if (untitled1_DW.obj.TunablePropsChanged) {
    untitled1_DW.obj.TunablePropsChanged = false;
  }

  MW_Read_Accel(&untitled1_B.MPU9250_o1[0]);
  mdata[0] = 0.0;
  mdata[1] = 0.0;
  mdata[2] = 0.0;
  MW_Read_Gyro(&mdata[0]);
  mdata[0] = 0.0;
  mdata[1] = 0.0;
  mdata[2] = 0.0;
  MW_Read_Mag(&mdata[0]);

  /* End of MATLABSystem: '<Root>/MPU9250' */

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.1s, 0.0s] */
    rtExtModeUpload(0, (real_T)untitled1_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.1s, 0.0s] */
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
  untitled1_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  untitled1_M->Sizes.checksums[0] = (3522886345U);
  untitled1_M->Sizes.checksums[1] = (2927421662U);
  untitled1_M->Sizes.checksums[2] = (3173693851U);
  untitled1_M->Sizes.checksums[3] = (3947557041U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    untitled1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
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

  /* Start for MATLABSystem: '<Root>/MPU9250' */
  untitled1_DW.obj.isInitialized = 0;
  untitled1_DW.obj.i2cObjmpu.DefaultMaximumBusSpeedInHz = 400000.0;
  untitled1_DW.obj.i2cObjmpu.isInitialized = 0;
  untitled1_DW.obj.i2cObjmpu.matlabCodegenIsDeleted = false;
  untitled1_DW.obj.i2cObjak8963.DefaultMaximumBusSpeedInHz = 400000.0;
  untitled1_DW.obj.i2cObjak8963.isInitialized = 0;
  untitled1_DW.obj.i2cObjak8963.matlabCodegenIsDeleted = false;
  untitled1_DW.obj.matlabCodegenIsDeleted = false;
  untitled1_DW.obj.SampleTime = untitled1_P.MPU9250_SampleTime;
  untitled1_SystemCore_setup(&untitled1_DW.obj);
}

/* Model terminate function */
void untitled1_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/MPU9250' */
  if (!untitled1_DW.obj.matlabCodegenIsDeleted) {
    untitled1_DW.obj.matlabCodegenIsDeleted = true;
  }

  if (!untitled1_DW.obj.i2cObjak8963.matlabCodegenIsDeleted) {
    untitled1_DW.obj.i2cObjak8963.matlabCodegenIsDeleted = true;
    if (untitled1_DW.obj.i2cObjak8963.isInitialized == 1) {
      untitled1_DW.obj.i2cObjak8963.isInitialized = 2;
    }
  }

  if (!untitled1_DW.obj.i2cObjmpu.matlabCodegenIsDeleted) {
    untitled1_DW.obj.i2cObjmpu.matlabCodegenIsDeleted = true;
    if (untitled1_DW.obj.i2cObjmpu.isInitialized == 1) {
      untitled1_DW.obj.i2cObjmpu.isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/MPU9250' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BeagleBone_Testing.h
 *
 * Code generated for Simulink model 'BeagleBone_Testing'.
 *
 * Model version                  : 1.42
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue May 28 00:07:35 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef BeagleBone_Testing_h_
#define BeagleBone_Testing_h_
#ifndef BeagleBone_Testing_COMMON_INCLUDES_
#define BeagleBone_Testing_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_bbblue_driver.h"
#include "MW_I2C.h"
#include "MW_MPU9250.h"
#endif                                 /* BeagleBone_Testing_COMMON_INCLUDES_ */

#include "BeagleBone_Testing_types.h"
#include <float.h>
#include <string.h>
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
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
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T A[16];
  real_T Reshapexhat[6];               /* '<S1>/Reshapexhat' */
  real_T dv[6];
  real_T Reshapey[5];                  /* '<S1>/Reshapey' */
  real_T rtb_Reshapey_m[5];
  real_T PWM[4];                       /* '<S2>/MATLAB Function' */
  real_T Product2[6];                  /* '<S57>/Product2' */
  real_T Product3[6];                  /* '<S55>/Product3' */
  real_T dv2[6];
  real_T B[4];
  real_T Gain[4];                      /* '<Root>/Gain' */
  real_T rtb_MPU9250_o1_c[3];
  real_T rtb_MPU9250_o2_k[3];
  real_T dv1[3];
  real_T ang[2];                       /* '<S3>/MATLAB Function' */
} B_BeagleBone_Testing_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  beagleboneblue_bbblueMPU9250__T obj; /* '<S3>/MPU9250' */
  beagleboneblue_bbblueServo_Be_T obj_h;/* '<S2>/Servo Motor3' */
  beagleboneblue_bbblueServo_Be_T obj_j;/* '<S2>/Servo Motor2' */
  beagleboneblue_bbblueServo_Be_T obj_d;/* '<S2>/Servo Motor1' */
  beagleboneblue_bbblueServo_Be_T obj_b;/* '<S2>/Servo Motor' */
  real_T MemoryX_DSTATE[6];            /* '<S1>/MemoryX' */
  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<Root>/Scope3' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S2>/Scope' */

  int8_T EnabledSubsystem_SubsysRanBC; /* '<S31>/Enabled Subsystem' */
  int8_T MeasurementUpdate_SubsysRanBC;/* '<S24>/MeasurementUpdate' */
  boolean_T icLoad;                    /* '<S1>/MemoryX' */
  boolean_T EnabledSubsystem_MODE;     /* '<S31>/Enabled Subsystem' */
  boolean_T MeasurementUpdate_MODE;    /* '<S24>/MeasurementUpdate' */
} DW_BeagleBone_Testing_T;

/* Parameters (default storage) */
struct P_BeagleBone_Testing_T_ {
  real_T K_discrete[24];               /* Variable: K_discrete
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Lykyhatkk1_Y0;                /* Expression: 0
                                        * Referenced by: '<S55>/L*(y[k]-yhat[k|k-1])'
                                        */
  real_T deltax_Y0;                    /* Expression: 0
                                        * Referenced by: '<S57>/deltax'
                                        */
  real_T MPU9250_SampleTime;           /* Expression: 0.02
                                        * Referenced by: '<S3>/MPU9250'
                                        */
  real_T A_Value[36];                  /* Expression: pInitialization.A
                                        * Referenced by: '<S1>/A'
                                        */
  real_T KalmanGainM_Value[30];        /* Expression: pInitialization.M
                                        * Referenced by: '<S4>/KalmanGainM'
                                        */
  real_T C_Value[30];                  /* Expression: pInitialization.C
                                        * Referenced by: '<S1>/C'
                                        */
  real_T KalmanGainL_Value[30];        /* Expression: pInitialization.L
                                        * Referenced by: '<S4>/KalmanGainL'
                                        */
  real_T B_Value[24];                  /* Expression: pInitialization.B
                                        * Referenced by: '<S1>/B'
                                        */
  real_T D_Value[20];                  /* Expression: pInitialization.D
                                        * Referenced by: '<S1>/D'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Gain1_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<S60>/Gain1'
                                        */
  real_T Constant_Value[6];            /* Expression: [0;0;0;0;0;0]
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T X0_Value[6];                  /* Expression: pInitialization.X0
                                        * Referenced by: '<S1>/X0'
                                        */
  real_T Constant_Value_e;             /* Expression: 0
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T CovarianceZ_Value[36];        /* Expression: pInitialization.Z
                                        * Referenced by: '<S4>/CovarianceZ'
                                        */
  boolean_T Enable_Value;              /* Expression: true()
                                        * Referenced by: '<S1>/Enable'
                                        */
  boolean_T isSqrtUsed_Value;          /* Expression: pInitialization.isSqrtUsed
                                        * Referenced by: '<S53>/isSqrtUsed'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_BeagleBone_Testing_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_BeagleBone_Testing_T BeagleBone_Testing_P;

/* Block signals (default storage) */
extern B_BeagleBone_Testing_T BeagleBone_Testing_B;

/* Block states (default storage) */
extern DW_BeagleBone_Testing_T BeagleBone_Testing_DW;

/* Model entry point functions */
extern void BeagleBone_Testing_initialize(void);
extern void BeagleBone_Testing_step(void);
extern void BeagleBone_Testing_terminate(void);

/* Real-time Model object */
extern RT_MODEL_BeagleBone_Testing_T *const BeagleBone_Testing_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S47>/Data Type Duplicate' : Unused code path elimination
 * Block '<S48>/Data Type Duplicate' : Unused code path elimination
 * Block '<S49>/Conversion' : Unused code path elimination
 * Block '<S49>/Data Type Duplicate' : Unused code path elimination
 * Block '<S50>/Data Type Duplicate' : Unused code path elimination
 * Block '<S7>/Data Type Duplicate' : Unused code path elimination
 * Block '<S8>/Data Type Duplicate' : Unused code path elimination
 * Block '<S9>/Data Type Duplicate' : Unused code path elimination
 * Block '<S10>/Data Type Duplicate' : Unused code path elimination
 * Block '<S12>/Data Type Duplicate' : Unused code path elimination
 * Block '<S13>/Data Type Duplicate' : Unused code path elimination
 * Block '<S14>/Data Type Duplicate' : Unused code path elimination
 * Block '<S15>/Conversion' : Unused code path elimination
 * Block '<S15>/Data Type Duplicate' : Unused code path elimination
 * Block '<S16>/Data Type Duplicate' : Unused code path elimination
 * Block '<S17>/Data Type Duplicate' : Unused code path elimination
 * Block '<S18>/Data Type Duplicate' : Unused code path elimination
 * Block '<S20>/Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate' : Unused code path elimination
 * Block '<S1>/G' : Unused code path elimination
 * Block '<S1>/H' : Unused code path elimination
 * Block '<S1>/N' : Unused code path elimination
 * Block '<S1>/P0' : Unused code path elimination
 * Block '<S1>/Q' : Unused code path elimination
 * Block '<S1>/R' : Unused code path elimination
 * Block '<S45>/CheckSignalProperties' : Unused code path elimination
 * Block '<S46>/CheckSignalProperties' : Unused code path elimination
 * Block '<S47>/Conversion' : Eliminate redundant data type conversion
 * Block '<S48>/Conversion' : Eliminate redundant data type conversion
 * Block '<S50>/Conversion' : Eliminate redundant data type conversion
 * Block '<S20>/Conversion' : Eliminate redundant data type conversion
 * Block '<S24>/Reshape' : Reshape block reduction
 * Block '<S1>/ReshapeX0' : Reshape block reduction
 * Block '<S1>/Reshapeu' : Reshape block reduction
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'BeagleBone_Testing'
 * '<S1>'   : 'BeagleBone_Testing/Kalman Filter'
 * '<S2>'   : 'BeagleBone_Testing/Motor Control'
 * '<S3>'   : 'BeagleBone_Testing/Sensors and Filter'
 * '<S4>'   : 'BeagleBone_Testing/Kalman Filter/CalculatePL'
 * '<S5>'   : 'BeagleBone_Testing/Kalman Filter/CalculateYhat'
 * '<S6>'   : 'BeagleBone_Testing/Kalman Filter/CovarianceOutputConfigurator'
 * '<S7>'   : 'BeagleBone_Testing/Kalman Filter/DataTypeConversionA'
 * '<S8>'   : 'BeagleBone_Testing/Kalman Filter/DataTypeConversionB'
 * '<S9>'   : 'BeagleBone_Testing/Kalman Filter/DataTypeConversionC'
 * '<S10>'  : 'BeagleBone_Testing/Kalman Filter/DataTypeConversionD'
 * '<S11>'  : 'BeagleBone_Testing/Kalman Filter/DataTypeConversionEnable'
 * '<S12>'  : 'BeagleBone_Testing/Kalman Filter/DataTypeConversionG'
 * '<S13>'  : 'BeagleBone_Testing/Kalman Filter/DataTypeConversionH'
 * '<S14>'  : 'BeagleBone_Testing/Kalman Filter/DataTypeConversionN'
 * '<S15>'  : 'BeagleBone_Testing/Kalman Filter/DataTypeConversionP'
 * '<S16>'  : 'BeagleBone_Testing/Kalman Filter/DataTypeConversionP0'
 * '<S17>'  : 'BeagleBone_Testing/Kalman Filter/DataTypeConversionQ'
 * '<S18>'  : 'BeagleBone_Testing/Kalman Filter/DataTypeConversionR'
 * '<S19>'  : 'BeagleBone_Testing/Kalman Filter/DataTypeConversionReset'
 * '<S20>'  : 'BeagleBone_Testing/Kalman Filter/DataTypeConversionX'
 * '<S21>'  : 'BeagleBone_Testing/Kalman Filter/DataTypeConversionX0'
 * '<S22>'  : 'BeagleBone_Testing/Kalman Filter/DataTypeConversionu'
 * '<S23>'  : 'BeagleBone_Testing/Kalman Filter/MemoryP'
 * '<S24>'  : 'BeagleBone_Testing/Kalman Filter/Observer'
 * '<S25>'  : 'BeagleBone_Testing/Kalman Filter/ReducedQRN'
 * '<S26>'  : 'BeagleBone_Testing/Kalman Filter/Reset'
 * '<S27>'  : 'BeagleBone_Testing/Kalman Filter/Reshapeyhat'
 * '<S28>'  : 'BeagleBone_Testing/Kalman Filter/ScalarExpansionP0'
 * '<S29>'  : 'BeagleBone_Testing/Kalman Filter/ScalarExpansionQ'
 * '<S30>'  : 'BeagleBone_Testing/Kalman Filter/ScalarExpansionR'
 * '<S31>'  : 'BeagleBone_Testing/Kalman Filter/UseCurrentEstimator'
 * '<S32>'  : 'BeagleBone_Testing/Kalman Filter/checkA'
 * '<S33>'  : 'BeagleBone_Testing/Kalman Filter/checkB'
 * '<S34>'  : 'BeagleBone_Testing/Kalman Filter/checkC'
 * '<S35>'  : 'BeagleBone_Testing/Kalman Filter/checkD'
 * '<S36>'  : 'BeagleBone_Testing/Kalman Filter/checkEnable'
 * '<S37>'  : 'BeagleBone_Testing/Kalman Filter/checkG'
 * '<S38>'  : 'BeagleBone_Testing/Kalman Filter/checkH'
 * '<S39>'  : 'BeagleBone_Testing/Kalman Filter/checkN'
 * '<S40>'  : 'BeagleBone_Testing/Kalman Filter/checkP0'
 * '<S41>'  : 'BeagleBone_Testing/Kalman Filter/checkQ'
 * '<S42>'  : 'BeagleBone_Testing/Kalman Filter/checkR'
 * '<S43>'  : 'BeagleBone_Testing/Kalman Filter/checkReset'
 * '<S44>'  : 'BeagleBone_Testing/Kalman Filter/checkX0'
 * '<S45>'  : 'BeagleBone_Testing/Kalman Filter/checku'
 * '<S46>'  : 'BeagleBone_Testing/Kalman Filter/checky'
 * '<S47>'  : 'BeagleBone_Testing/Kalman Filter/CalculatePL/DataTypeConversionL'
 * '<S48>'  : 'BeagleBone_Testing/Kalman Filter/CalculatePL/DataTypeConversionM'
 * '<S49>'  : 'BeagleBone_Testing/Kalman Filter/CalculatePL/DataTypeConversionP'
 * '<S50>'  : 'BeagleBone_Testing/Kalman Filter/CalculatePL/DataTypeConversionZ'
 * '<S51>'  : 'BeagleBone_Testing/Kalman Filter/CalculatePL/Ground'
 * '<S52>'  : 'BeagleBone_Testing/Kalman Filter/CalculateYhat/Ground'
 * '<S53>'  : 'BeagleBone_Testing/Kalman Filter/CovarianceOutputConfigurator/decideOutput'
 * '<S54>'  : 'BeagleBone_Testing/Kalman Filter/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
 * '<S55>'  : 'BeagleBone_Testing/Kalman Filter/Observer/MeasurementUpdate'
 * '<S56>'  : 'BeagleBone_Testing/Kalman Filter/ReducedQRN/Ground'
 * '<S57>'  : 'BeagleBone_Testing/Kalman Filter/UseCurrentEstimator/Enabled Subsystem'
 * '<S58>'  : 'BeagleBone_Testing/Motor Control/MATLAB Function'
 * '<S59>'  : 'BeagleBone_Testing/Motor Control/input to Force'
 * '<S60>'  : 'BeagleBone_Testing/Sensors and Filter/Degrees to Radians'
 * '<S61>'  : 'BeagleBone_Testing/Sensors and Filter/MATLAB Function'
 */
#endif                                 /* BeagleBone_Testing_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

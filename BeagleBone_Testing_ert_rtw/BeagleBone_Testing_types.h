/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BeagleBone_Testing_types.h
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

#ifndef BeagleBone_Testing_types_h_
#define BeagleBone_Testing_types_h_
#include "rtwtypes.h"
#include "MW_SVD.h"
#ifndef struct_tag_VIgeb4UfEy1UvclkadFbY
#define struct_tag_VIgeb4UfEy1UvclkadFbY

struct tag_VIgeb4UfEy1UvclkadFbY
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                 /* struct_tag_VIgeb4UfEy1UvclkadFbY */

#ifndef typedef_beagleboneblue_bbblueServo_Be_T
#define typedef_beagleboneblue_bbblueServo_Be_T

typedef struct tag_VIgeb4UfEy1UvclkadFbY beagleboneblue_bbblueServo_Be_T;

#endif                             /* typedef_beagleboneblue_bbblueServo_Be_T */

/* Custom Type definition for MATLABSystem: '<S3>/MPU9250' */
#include "MW_SVD.h"
#ifndef struct_tag_oH2PxaXVLCzd6lwdaSR6p
#define struct_tag_oH2PxaXVLCzd6lwdaSR6p

struct tag_oH2PxaXVLCzd6lwdaSR6p
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  uint32_T BusSpeed;
  real_T DefaultMaximumBusSpeedInHz;
  MW_Handle_Type MW_I2C_HANDLE;
};

#endif                                 /* struct_tag_oH2PxaXVLCzd6lwdaSR6p */

#ifndef typedef_i_beagleboneblue_bbblueI2CMas_T
#define typedef_i_beagleboneblue_bbblueI2CMas_T

typedef struct tag_oH2PxaXVLCzd6lwdaSR6p i_beagleboneblue_bbblueI2CMas_T;

#endif                             /* typedef_i_beagleboneblue_bbblueI2CMas_T */

#ifndef struct_tag_s0kXae1yCOw6kF09CPTiMB
#define struct_tag_s0kXae1yCOw6kF09CPTiMB

struct tag_s0kXae1yCOw6kF09CPTiMB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  uint32_T BusSpeed;
  real_T DefaultMaximumBusSpeedInHz;
  MW_Handle_Type MW_I2C_HANDLE;
};

#endif                                 /* struct_tag_s0kXae1yCOw6kF09CPTiMB */

#ifndef typedef_j_beagleboneblue_bbblueI2CMas_T
#define typedef_j_beagleboneblue_bbblueI2CMas_T

typedef struct tag_s0kXae1yCOw6kF09CPTiMB j_beagleboneblue_bbblueI2CMas_T;

#endif                             /* typedef_j_beagleboneblue_bbblueI2CMas_T */

#ifndef struct_tag_A4EdOul8eEsRYmBAaIUDRF
#define struct_tag_A4EdOul8eEsRYmBAaIUDRF

struct tag_A4EdOul8eEsRYmBAaIUDRF
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T TunablePropsChanged;
  real_T SampleTime;
  i_beagleboneblue_bbblueI2CMas_T i2cObjmpu;
  j_beagleboneblue_bbblueI2CMas_T i2cObjak8963;
};

#endif                                 /* struct_tag_A4EdOul8eEsRYmBAaIUDRF */

#ifndef typedef_beagleboneblue_bbblueMPU9250__T
#define typedef_beagleboneblue_bbblueMPU9250__T

typedef struct tag_A4EdOul8eEsRYmBAaIUDRF beagleboneblue_bbblueMPU9250__T;

#endif                             /* typedef_beagleboneblue_bbblueMPU9250__T */

/* Parameters (default storage) */
typedef struct P_BeagleBone_Testing_T_ P_BeagleBone_Testing_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_BeagleBone_Testing_T RT_MODEL_BeagleBone_Testing_T;

#endif                                 /* BeagleBone_Testing_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

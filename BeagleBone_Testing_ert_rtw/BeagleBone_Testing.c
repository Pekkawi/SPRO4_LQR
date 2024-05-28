/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BeagleBone_Testing.c
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

#include "BeagleBone_Testing.h"
#include "BeagleBone_Testing_types.h"
#include <math.h>
#include <string.h>
#include "BeagleBone_Testing_private.h"
#include "rtwtypes.h"
#include "BeagleBone_Testing_dt.h"

/* Block signals (default storage) */
B_BeagleBone_Testing_T BeagleBone_Testing_B;

/* Block states (default storage) */
DW_BeagleBone_Testing_T BeagleBone_Testing_DW;

/* Real-time model */
static RT_MODEL_BeagleBone_Testing_T BeagleBone_Testing_M_;
RT_MODEL_BeagleBone_Testing_T *const BeagleBone_Testing_M =
  &BeagleBone_Testing_M_;

/* Forward declaration for local functions */
static void BeagleBone_Tes_SystemCore_setup(beagleboneblue_bbblueMPU9250__T *obj);
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

static void BeagleBone_Tes_SystemCore_setup(beagleboneblue_bbblueMPU9250__T *obj)
{
  /* Start for MATLABSystem: '<S3>/MPU9250' */
  obj->isInitialized = 1;
  MW_IMU_DMP_isAccel_Calibrated();
  MW_IMU_DMP_isGyro_Calibrated();
  MW_IMU_DMP_isMag_Calibrated();

  /* Start for MATLABSystem: '<S3>/MPU9250' */
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
void BeagleBone_Testing_step(void)
{
  real_T s;
  real_T smax;
  int32_T a;
  int32_T d;
  int32_T i;
  int32_T jA;
  int32_T jj;
  int32_T kAcol;
  int32_T n;
  int8_T ipiv[4];
  int8_T ipiv_0;
  static const real_T f[16] = { 1.0, -0.175, -0.175, 0.015, 1.0, 0.175, -0.175,
    -0.015, 1.0, -0.175, 0.175, -0.015, 1.0, 0.175, 0.175, 0.015 };

  /* Reset subsysRan breadcrumbs */
  srClearBC(BeagleBone_Testing_DW.MeasurementUpdate_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(BeagleBone_Testing_DW.EnabledSubsystem_SubsysRanBC);

  /* MATLABSystem: '<S3>/MPU9250' */
  if (BeagleBone_Testing_DW.obj.SampleTime !=
      BeagleBone_Testing_P.MPU9250_SampleTime) {
    BeagleBone_Testing_DW.obj.SampleTime =
      BeagleBone_Testing_P.MPU9250_SampleTime;
  }

  if (BeagleBone_Testing_DW.obj.TunablePropsChanged) {
    BeagleBone_Testing_DW.obj.TunablePropsChanged = false;
  }

  MW_Read_Accel(&BeagleBone_Testing_B.rtb_MPU9250_o1_c[0]);
  BeagleBone_Testing_B.rtb_MPU9250_o2_k[0] = 0.0;
  BeagleBone_Testing_B.rtb_MPU9250_o2_k[1] = 0.0;
  BeagleBone_Testing_B.rtb_MPU9250_o2_k[2] = 0.0;
  MW_Read_Gyro(&BeagleBone_Testing_B.rtb_MPU9250_o2_k[0]);
  BeagleBone_Testing_B.dv1[0] = 0.0;
  BeagleBone_Testing_B.dv1[1] = 0.0;
  BeagleBone_Testing_B.dv1[2] = 0.0;
  MW_Read_Euler(&BeagleBone_Testing_B.dv1[0]);

  /* MATLAB Function: '<S3>/MATLAB Function' incorporates:
   *  MATLABSystem: '<S3>/MPU9250'
   */
  BeagleBone_Testing_B.ang[0] = atan(BeagleBone_Testing_B.rtb_MPU9250_o1_c[0] /
    BeagleBone_Testing_B.rtb_MPU9250_o1_c[2]);
  BeagleBone_Testing_B.ang[1] = atan(BeagleBone_Testing_B.rtb_MPU9250_o1_c[1] /
    BeagleBone_Testing_B.rtb_MPU9250_o1_c[2]);

  /* Reshape: '<S1>/Reshapey' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Gain: '<S60>/Gain1'
   *  MATLABSystem: '<S3>/MPU9250'
   */
  BeagleBone_Testing_B.Reshapey[2] = BeagleBone_Testing_P.Constant1_Value;
  BeagleBone_Testing_B.Reshapey[0] = BeagleBone_Testing_B.ang[0];
  BeagleBone_Testing_B.Reshapey[3] = BeagleBone_Testing_P.Gain1_Gain *
    BeagleBone_Testing_B.rtb_MPU9250_o2_k[0];
  BeagleBone_Testing_B.Reshapey[1] = BeagleBone_Testing_B.ang[1];
  BeagleBone_Testing_B.Reshapey[4] = BeagleBone_Testing_P.Gain1_Gain *
    BeagleBone_Testing_B.rtb_MPU9250_o2_k[1];

  /* Delay: '<S1>/MemoryX' incorporates:
   *  Constant: '<S1>/X0'
   */
  if (BeagleBone_Testing_DW.icLoad) {
    for (i = 0; i < 6; i++) {
      BeagleBone_Testing_DW.MemoryX_DSTATE[i] = BeagleBone_Testing_P.X0_Value[i];
    }
  }

  /* Outputs for Enabled SubSystem: '<S31>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S57>/Enable'
   */
  /* Constant: '<S1>/Enable' */
  if (BeagleBone_Testing_P.Enable_Value) {
    BeagleBone_Testing_DW.EnabledSubsystem_MODE = true;

    /* Sum: '<S57>/Add1' incorporates:
     *  Constant: '<S1>/C'
     *  Delay: '<S1>/MemoryX'
     *  Product: '<S57>/Product'
     */
    for (i = 0; i < 5; i++) {
      smax = 0.0;
      for (jj = 0; jj < 6; jj++) {
        smax += BeagleBone_Testing_P.C_Value[5 * jj + i] *
          BeagleBone_Testing_DW.MemoryX_DSTATE[jj];
      }

      BeagleBone_Testing_B.rtb_Reshapey_m[i] = BeagleBone_Testing_B.Reshapey[i]
        - smax;
    }

    /* End of Sum: '<S57>/Add1' */
    for (i = 0; i < 6; i++) {
      /* Product: '<S57>/Product2' incorporates:
       *  Constant: '<S4>/KalmanGainM'
       */
      smax = 0.0;
      for (jj = 0; jj < 5; jj++) {
        smax += BeagleBone_Testing_P.KalmanGainM_Value[6 * jj + i] *
          BeagleBone_Testing_B.rtb_Reshapey_m[jj];
      }

      BeagleBone_Testing_B.Product2[i] = smax;

      /* End of Product: '<S57>/Product2' */
    }

    srUpdateBC(BeagleBone_Testing_DW.EnabledSubsystem_SubsysRanBC);
  } else if (BeagleBone_Testing_DW.EnabledSubsystem_MODE) {
    for (i = 0; i < 6; i++) {
      /* Disable for Product: '<S57>/Product2' incorporates:
       *  Outport: '<S57>/deltax'
       */
      BeagleBone_Testing_B.Product2[i] = BeagleBone_Testing_P.deltax_Y0;
    }

    BeagleBone_Testing_DW.EnabledSubsystem_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S31>/Enabled Subsystem' */
  for (i = 0; i < 6; i++) {
    /* Reshape: '<S1>/Reshapexhat' incorporates:
     *  Delay: '<S1>/MemoryX'
     *  Sum: '<S31>/Add'
     */
    smax = BeagleBone_Testing_B.Product2[i] +
      BeagleBone_Testing_DW.MemoryX_DSTATE[i];
    BeagleBone_Testing_B.Reshapexhat[i] = smax;

    /* Sum: '<Root>/Sum' incorporates:
     *  Constant: '<Root>/Constant'
     */
    BeagleBone_Testing_B.dv2[i] = BeagleBone_Testing_P.Constant_Value[i] - smax;
  }

  /* Gain: '<Root>/Gain' */
  for (i = 0; i < 4; i++) {
    smax = 0.0;
    for (jj = 0; jj < 6; jj++) {
      smax += BeagleBone_Testing_P.K_discrete[(jj << 2) + i] *
        BeagleBone_Testing_B.dv2[jj];
    }

    BeagleBone_Testing_B.Gain[i] = smax;
  }

  /* End of Gain: '<Root>/Gain' */

  /* Outputs for Enabled SubSystem: '<S24>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S55>/Enable'
   */
  /* Constant: '<S1>/Enable' */
  if (BeagleBone_Testing_P.Enable_Value) {
    BeagleBone_Testing_DW.MeasurementUpdate_MODE = true;
    for (i = 0; i < 5; i++) {
      /* Product: '<S55>/C[k]*xhat[k|k-1]' incorporates:
       *  Constant: '<S1>/C'
       *  Delay: '<S1>/MemoryX'
       */
      smax = 0.0;
      for (jj = 0; jj < 6; jj++) {
        smax += BeagleBone_Testing_P.C_Value[5 * jj + i] *
          BeagleBone_Testing_DW.MemoryX_DSTATE[jj];
      }

      /* Sum: '<S55>/Sum' incorporates:
       *  Constant: '<S1>/D'
       *  Product: '<S55>/C[k]*xhat[k|k-1]'
       *  Product: '<S55>/D[k]*u[k]'
       *  Sum: '<S55>/Add1'
       */
      BeagleBone_Testing_B.rtb_Reshapey_m[i] = BeagleBone_Testing_B.Reshapey[i]
        - ((((BeagleBone_Testing_P.D_Value[i + 5] * BeagleBone_Testing_B.Gain[1]
              + BeagleBone_Testing_P.D_Value[i] * BeagleBone_Testing_B.Gain[0])
             + BeagleBone_Testing_P.D_Value[i + 10] * BeagleBone_Testing_B.Gain
             [2]) + BeagleBone_Testing_P.D_Value[i + 15] *
            BeagleBone_Testing_B.Gain[3]) + smax);
    }

    for (i = 0; i < 6; i++) {
      /* Product: '<S55>/Product3' incorporates:
       *  Constant: '<S4>/KalmanGainL'
       */
      smax = 0.0;
      for (jj = 0; jj < 5; jj++) {
        smax += BeagleBone_Testing_P.KalmanGainL_Value[6 * jj + i] *
          BeagleBone_Testing_B.rtb_Reshapey_m[jj];
      }

      BeagleBone_Testing_B.Product3[i] = smax;

      /* End of Product: '<S55>/Product3' */
    }

    srUpdateBC(BeagleBone_Testing_DW.MeasurementUpdate_SubsysRanBC);
  } else if (BeagleBone_Testing_DW.MeasurementUpdate_MODE) {
    for (i = 0; i < 6; i++) {
      /* Disable for Product: '<S55>/Product3' incorporates:
       *  Outport: '<S55>/L*(y[k]-yhat[k|k-1])'
       */
      BeagleBone_Testing_B.Product3[i] = BeagleBone_Testing_P.Lykyhatkk1_Y0;
    }

    BeagleBone_Testing_DW.MeasurementUpdate_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S24>/MeasurementUpdate' */
  /* MATLAB Function: '<S2>/input to Force' */
  memcpy(&BeagleBone_Testing_B.A[0], &f[0], sizeof(real_T) << 4U);
  BeagleBone_Testing_B.B[0] = BeagleBone_Testing_B.Gain[0] - -12.46851;
  ipiv[0] = 1;
  BeagleBone_Testing_B.B[1] = BeagleBone_Testing_B.Gain[1];
  ipiv[1] = 2;
  BeagleBone_Testing_B.B[2] = BeagleBone_Testing_B.Gain[2];
  ipiv[2] = 3;
  BeagleBone_Testing_B.B[3] = BeagleBone_Testing_B.Gain[3];
  ipiv[3] = 4;
  for (i = 0; i < 3; i++) {
    jj = i * 5;
    n = 4 - i;
    a = 0;
    smax = fabs(BeagleBone_Testing_B.A[jj]);
    for (kAcol = 2; kAcol <= n; kAcol++) {
      s = fabs(BeagleBone_Testing_B.A[(jj + kAcol) - 1]);
      if (s > smax) {
        a = kAcol - 1;
        smax = s;
      }
    }

    if (BeagleBone_Testing_B.A[jj + a] != 0.0) {
      if (a != 0) {
        kAcol = i + a;
        ipiv[i] = (int8_T)(kAcol + 1);
        smax = BeagleBone_Testing_B.A[i];
        BeagleBone_Testing_B.A[i] = BeagleBone_Testing_B.A[kAcol];
        BeagleBone_Testing_B.A[kAcol] = smax;
        smax = BeagleBone_Testing_B.A[i + 4];
        BeagleBone_Testing_B.A[i + 4] = BeagleBone_Testing_B.A[kAcol + 4];
        BeagleBone_Testing_B.A[kAcol + 4] = smax;
        smax = BeagleBone_Testing_B.A[i + 8];
        BeagleBone_Testing_B.A[i + 8] = BeagleBone_Testing_B.A[kAcol + 8];
        BeagleBone_Testing_B.A[kAcol + 8] = smax;
        smax = BeagleBone_Testing_B.A[i + 12];
        BeagleBone_Testing_B.A[i + 12] = BeagleBone_Testing_B.A[kAcol + 12];
        BeagleBone_Testing_B.A[kAcol + 12] = smax;
      }

      n = (jj - i) + 4;
      for (kAcol = jj + 2; kAcol <= n; kAcol++) {
        BeagleBone_Testing_B.A[kAcol - 1] /= BeagleBone_Testing_B.A[jj];
      }
    }

    a = 2 - i;
    jA = jj + 6;
    for (kAcol = 0; kAcol <= a; kAcol++) {
      smax = BeagleBone_Testing_B.A[((kAcol << 2) + jj) + 4];
      if (smax != 0.0) {
        d = (jA - i) + 2;
        for (n = jA; n <= d; n++) {
          BeagleBone_Testing_B.A[n - 1] += BeagleBone_Testing_B.A[((jj + n) - jA)
            + 1] * -smax;
        }
      }

      jA += 4;
    }

    ipiv_0 = ipiv[i];
    if (i + 1 != ipiv_0) {
      smax = BeagleBone_Testing_B.B[i];
      BeagleBone_Testing_B.B[i] = BeagleBone_Testing_B.B[ipiv_0 - 1];
      BeagleBone_Testing_B.B[ipiv_0 - 1] = smax;
    }
  }

  for (i = 0; i < 4; i++) {
    kAcol = i << 2;
    if (BeagleBone_Testing_B.B[i] != 0.0) {
      for (jj = i + 2; jj < 5; jj++) {
        BeagleBone_Testing_B.B[jj - 1] -= BeagleBone_Testing_B.A[(jj + kAcol) -
          1] * BeagleBone_Testing_B.B[i];
      }
    }
  }

  for (i = 3; i >= 0; i--) {
    kAcol = i << 2;
    smax = BeagleBone_Testing_B.B[i];
    if (smax != 0.0) {
      BeagleBone_Testing_B.B[i] = smax / BeagleBone_Testing_B.A[i + kAcol];
      for (jj = 0; jj < i; jj++) {
        BeagleBone_Testing_B.B[jj] -= BeagleBone_Testing_B.A[jj + kAcol] *
          BeagleBone_Testing_B.B[i];
      }
    }
  }

  /* End of MATLAB Function: '<S2>/input to Force' */

  /* MATLAB Function: '<S2>/MATLAB Function' incorporates:
   *  Constant: '<S2>/Constant'
   */
  BeagleBone_Testing_B.PWM[0] = 0.0;
  BeagleBone_Testing_B.PWM[1] = 0.0;
  BeagleBone_Testing_B.PWM[2] = 0.0;
  BeagleBone_Testing_B.PWM[3] = 0.0;
  if (BeagleBone_Testing_P.Constant_Value_e == 0.0) {
    BeagleBone_Testing_B.PWM[0] = 40.0;
    BeagleBone_Testing_B.PWM[1] = 40.0;
    BeagleBone_Testing_B.PWM[2] = 40.0;
    BeagleBone_Testing_B.PWM[3] = 40.0;
  } else if (BeagleBone_Testing_P.Constant_Value_e == 1.0) {
    smax = rt_roundd_snf((1000.0 * BeagleBone_Testing_B.B[0] /
                          2519.3061000000002 - 0.23548927222460184) * 10.0) /
      10.0 * 10.0 + 60.0;
    BeagleBone_Testing_B.PWM[0] = smax;
    if (smax > 62.0) {
      smax = 62.0;
      BeagleBone_Testing_B.PWM[0] = 62.0;
    }

    if (smax < 45.0) {
      BeagleBone_Testing_B.PWM[0] = 45.0;
    }

    smax = rt_roundd_snf((1000.0 * BeagleBone_Testing_B.B[1] /
                          2519.3061000000002 - 0.23548927222460184) * 10.0) /
      10.0 * 10.0 + 60.0;
    BeagleBone_Testing_B.PWM[1] = smax;
    if (smax > 62.0) {
      smax = 62.0;
      BeagleBone_Testing_B.PWM[1] = 62.0;
    }

    if (smax < 45.0) {
      BeagleBone_Testing_B.PWM[1] = 45.0;
    }

    smax = rt_roundd_snf((1000.0 * BeagleBone_Testing_B.B[2] /
                          2519.3061000000002 - 0.23548927222460184) * 10.0) /
      10.0 * 10.0 + 60.0;
    BeagleBone_Testing_B.PWM[2] = smax;
    if (smax > 62.0) {
      smax = 62.0;
      BeagleBone_Testing_B.PWM[2] = 62.0;
    }

    if (smax < 45.0) {
      BeagleBone_Testing_B.PWM[2] = 45.0;
    }

    smax = rt_roundd_snf((1000.0 * BeagleBone_Testing_B.B[3] /
                          2519.3061000000002 - 0.23548927222460184) * 10.0) /
      10.0 * 10.0 + 60.0;
    BeagleBone_Testing_B.PWM[3] = smax;
    if (smax > 62.0) {
      smax = 62.0;
      BeagleBone_Testing_B.PWM[3] = 62.0;
    }

    if (smax < 45.0) {
      BeagleBone_Testing_B.PWM[3] = 45.0;
    }
  }

  /* End of MATLAB Function: '<S2>/MATLAB Function' */
  /* MATLABSystem: '<S2>/Servo Motor' */
  rc_servo_send_pulse_normalized(1, (BeagleBone_Testing_B.PWM[0] - 90.0) / 60.0);

  /* MATLABSystem: '<S2>/Servo Motor1' */
  rc_servo_send_pulse_normalized(2, (BeagleBone_Testing_B.PWM[1] - 90.0) / 60.0);

  /* MATLABSystem: '<S2>/Servo Motor2' */
  rc_servo_send_pulse_normalized(3, (BeagleBone_Testing_B.PWM[2] - 90.0) / 60.0);

  /* MATLABSystem: '<S2>/Servo Motor3' */
  rc_servo_send_pulse_normalized(4, (BeagleBone_Testing_B.PWM[3] - 90.0) / 60.0);

  /* Update for Delay: '<S1>/MemoryX' */
  BeagleBone_Testing_DW.icLoad = false;
  for (i = 0; i < 6; i++) {
    /* Product: '<S24>/B[k]*u[k]' incorporates:
     *  Constant: '<S1>/B'
     */
    BeagleBone_Testing_B.dv2[i] = ((BeagleBone_Testing_P.B_Value[i + 6] *
      BeagleBone_Testing_B.Gain[1] + BeagleBone_Testing_P.B_Value[i] *
      BeagleBone_Testing_B.Gain[0]) + BeagleBone_Testing_P.B_Value[i + 12] *
      BeagleBone_Testing_B.Gain[2]) + BeagleBone_Testing_P.B_Value[i + 18] *
      BeagleBone_Testing_B.Gain[3];

    /* Product: '<S24>/A[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S1>/A'
     *  Delay: '<S1>/MemoryX'
     */
    smax = 0.0;
    for (jj = 0; jj < 6; jj++) {
      smax += BeagleBone_Testing_P.A_Value[6 * jj + i] *
        BeagleBone_Testing_DW.MemoryX_DSTATE[jj];
    }

    BeagleBone_Testing_B.dv[i] = smax;

    /* End of Product: '<S24>/A[k]*xhat[k|k-1]' */
  }

  /* Update for Delay: '<S1>/MemoryX' incorporates:
   *  Sum: '<S24>/Add'
   */
  for (i = 0; i < 6; i++) {
    BeagleBone_Testing_DW.MemoryX_DSTATE[i] = (BeagleBone_Testing_B.dv2[i] +
      BeagleBone_Testing_B.dv[i]) + BeagleBone_Testing_B.Product3[i];
  }

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.02s, 0.0s] */
    rtExtModeUpload(0, (real_T)BeagleBone_Testing_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.02s, 0.0s] */
    if ((rtmGetTFinal(BeagleBone_Testing_M)!=-1) &&
        !((rtmGetTFinal(BeagleBone_Testing_M)-
           BeagleBone_Testing_M->Timing.taskTime0) >
          BeagleBone_Testing_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(BeagleBone_Testing_M, "Simulation finished");
    }

    if (rtmGetStopRequested(BeagleBone_Testing_M)) {
      rtmSetErrorStatus(BeagleBone_Testing_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  BeagleBone_Testing_M->Timing.taskTime0 =
    ((time_T)(++BeagleBone_Testing_M->Timing.clockTick0)) *
    BeagleBone_Testing_M->Timing.stepSize0;
}

/* Model initialize function */
void BeagleBone_Testing_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(BeagleBone_Testing_M, -1);
  BeagleBone_Testing_M->Timing.stepSize0 = 0.02;

  /* External mode info */
  BeagleBone_Testing_M->Sizes.checksums[0] = (1295071894U);
  BeagleBone_Testing_M->Sizes.checksums[1] = (939863594U);
  BeagleBone_Testing_M->Sizes.checksums[2] = (1642654792U);
  BeagleBone_Testing_M->Sizes.checksums[3] = (2669884193U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[12];
    BeagleBone_Testing_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)
      &BeagleBone_Testing_DW.MeasurementUpdate_SubsysRanBC;
    systemRan[3] = (sysRanDType *)
      &BeagleBone_Testing_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(BeagleBone_Testing_M->extModeInfo,
      &BeagleBone_Testing_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(BeagleBone_Testing_M->extModeInfo,
                        BeagleBone_Testing_M->Sizes.checksums);
    rteiSetTPtr(BeagleBone_Testing_M->extModeInfo, rtmGetTPtr
                (BeagleBone_Testing_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    BeagleBone_Testing_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    int32_T i;

    /* InitializeConditions for Delay: '<S1>/MemoryX' */
    BeagleBone_Testing_DW.icLoad = true;

    /* SystemInitialize for Enabled SubSystem: '<S24>/MeasurementUpdate' */
    /* SystemInitialize for Enabled SubSystem: '<S31>/Enabled Subsystem' */
    for (i = 0; i < 6; i++) {
      /* SystemInitialize for Product: '<S57>/Product2' incorporates:
       *  Outport: '<S57>/deltax'
       */
      BeagleBone_Testing_B.Product2[i] = BeagleBone_Testing_P.deltax_Y0;

      /* SystemInitialize for Product: '<S55>/Product3' incorporates:
       *  Outport: '<S55>/L*(y[k]-yhat[k|k-1])'
       */
      BeagleBone_Testing_B.Product3[i] = BeagleBone_Testing_P.Lykyhatkk1_Y0;
    }

    /* End of SystemInitialize for SubSystem: '<S31>/Enabled Subsystem' */
    /* End of SystemInitialize for SubSystem: '<S24>/MeasurementUpdate' */

    /* Start for MATLABSystem: '<S3>/MPU9250' */
    BeagleBone_Testing_DW.obj.isInitialized = 0;
    BeagleBone_Testing_DW.obj.i2cObjmpu.DefaultMaximumBusSpeedInHz = 400000.0;
    BeagleBone_Testing_DW.obj.i2cObjmpu.isInitialized = 0;
    BeagleBone_Testing_DW.obj.i2cObjmpu.matlabCodegenIsDeleted = false;
    BeagleBone_Testing_DW.obj.i2cObjak8963.DefaultMaximumBusSpeedInHz = 400000.0;
    BeagleBone_Testing_DW.obj.i2cObjak8963.isInitialized = 0;
    BeagleBone_Testing_DW.obj.i2cObjak8963.matlabCodegenIsDeleted = false;
    BeagleBone_Testing_DW.obj.matlabCodegenIsDeleted = false;
    BeagleBone_Testing_DW.obj.SampleTime =
      BeagleBone_Testing_P.MPU9250_SampleTime;
    BeagleBone_Tes_SystemCore_setup(&BeagleBone_Testing_DW.obj);

    /* Start for MATLABSystem: '<S2>/Servo Motor' */
    BeagleBone_Testing_DW.obj_b.matlabCodegenIsDeleted = false;
    BeagleBone_Testing_DW.obj_b.isInitialized = 1;
    BeagleBone_Testing_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Servo Motor1' */
    BeagleBone_Testing_DW.obj_d.matlabCodegenIsDeleted = false;
    BeagleBone_Testing_DW.obj_d.isInitialized = 1;
    BeagleBone_Testing_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Servo Motor2' */
    BeagleBone_Testing_DW.obj_j.matlabCodegenIsDeleted = false;
    BeagleBone_Testing_DW.obj_j.isInitialized = 1;
    BeagleBone_Testing_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Servo Motor3' */
    BeagleBone_Testing_DW.obj_h.matlabCodegenIsDeleted = false;
    BeagleBone_Testing_DW.obj_h.isInitialized = 1;
    BeagleBone_Testing_DW.obj_h.isSetupComplete = true;
  }
}

/* Model terminate function */
void BeagleBone_Testing_terminate(void)
{
  /* Terminate for MATLABSystem: '<S3>/MPU9250' */
  if (!BeagleBone_Testing_DW.obj.matlabCodegenIsDeleted) {
    BeagleBone_Testing_DW.obj.matlabCodegenIsDeleted = true;
  }

  if (!BeagleBone_Testing_DW.obj.i2cObjak8963.matlabCodegenIsDeleted) {
    BeagleBone_Testing_DW.obj.i2cObjak8963.matlabCodegenIsDeleted = true;
    if (BeagleBone_Testing_DW.obj.i2cObjak8963.isInitialized == 1) {
      BeagleBone_Testing_DW.obj.i2cObjak8963.isInitialized = 2;
    }
  }

  if (!BeagleBone_Testing_DW.obj.i2cObjmpu.matlabCodegenIsDeleted) {
    BeagleBone_Testing_DW.obj.i2cObjmpu.matlabCodegenIsDeleted = true;
    if (BeagleBone_Testing_DW.obj.i2cObjmpu.isInitialized == 1) {
      BeagleBone_Testing_DW.obj.i2cObjmpu.isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/MPU9250' */

  /* Terminate for MATLABSystem: '<S2>/Servo Motor' */
  if (!BeagleBone_Testing_DW.obj_b.matlabCodegenIsDeleted) {
    BeagleBone_Testing_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((BeagleBone_Testing_DW.obj_b.isInitialized == 1) &&
        BeagleBone_Testing_DW.obj_b.isSetupComplete) {
      rc_servo_send_pulse_normalized(1, 0.0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Servo Motor' */

  /* Terminate for MATLABSystem: '<S2>/Servo Motor1' */
  if (!BeagleBone_Testing_DW.obj_d.matlabCodegenIsDeleted) {
    BeagleBone_Testing_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((BeagleBone_Testing_DW.obj_d.isInitialized == 1) &&
        BeagleBone_Testing_DW.obj_d.isSetupComplete) {
      rc_servo_send_pulse_normalized(2, 0.0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Servo Motor1' */

  /* Terminate for MATLABSystem: '<S2>/Servo Motor2' */
  if (!BeagleBone_Testing_DW.obj_j.matlabCodegenIsDeleted) {
    BeagleBone_Testing_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((BeagleBone_Testing_DW.obj_j.isInitialized == 1) &&
        BeagleBone_Testing_DW.obj_j.isSetupComplete) {
      rc_servo_send_pulse_normalized(3, 0.0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Servo Motor2' */

  /* Terminate for MATLABSystem: '<S2>/Servo Motor3' */
  if (!BeagleBone_Testing_DW.obj_h.matlabCodegenIsDeleted) {
    BeagleBone_Testing_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((BeagleBone_Testing_DW.obj_h.isInitialized == 1) &&
        BeagleBone_Testing_DW.obj_h.isSetupComplete) {
      rc_servo_send_pulse_normalized(4, 0.0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Servo Motor3' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

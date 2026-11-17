/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: CLAW_data.c
 *
 * Code generated for Simulink model 'CLAW'.
 *
 * Model version                  : 1.138
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Mar 26 18:06:28 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: STMicroelectronics->ST10/Super10
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
/* --- ERR_E Direction 4~5m/s --- */
#include "mode_tdcn_CLAW.h"

P_CLAW_T CLAW_P = {
    /* --- [1] Scaling Factors --- */
    /* Controller_Var.c           Scale                  (            ) */
    /*  ʿ     Rotor_PWM_max           Ͽ        ʿ  */
    0.5,  /* 3.2 BSC_Scale_Thrust */
    0.1,   /* 0.25 BSC_Scale_Roll   */
    0.05,   /* 0.2 BSC_Scale_Pitch  */
    0.01,   /* 0.01 BSC_Scale_Yaw    */

    /* --- [ ߰ ] Outer Loop Gains --- */
    0.4,  /* 0.3 BSC_K_POS_P :   ġ          */
    0.02,  /* 0.01 BSC_K_POS_I :   ġ           */
    0.1,  /* 0.4 BSC_K_VEL_P :  ӵ           */
    0.005,  /* 0.05 BSC_K_VEL_I :  ӵ            */
    /* [ ߰ ] Anti-Windup Limit */
    5.0,   /* 1.0   б          Ѱ  (  : 5.0m/s             ) */

    /* --- [2] BSC Control Gains (From Controller_Var.c) --- */
    /* Omega */
    0.3,   /* BSC_Ome_XX        2026.04.28 0.5 수정*/
    0.3,   /* BSC_Ome_YY        2026.04.28 0.5 수정*/
    2.0,   /* BSC_Ome_ZZ */
    2.0,  /* 9.0 BSC_Ome_PH */
    2.0,  /* 12.0 BSC_Ome_TH */
    1.5,  /* 3.0 BSC_Ome_PS */

    /* Zeta */
    1.015,  /* BSC_Zeta_XX       2026.04.28 0.95 무조건 1근처로 */
    1.015,   /* BSC_Zeta_YY       2026.04.28 0.95 무조건 1근처로 */
    0.8,  /* 0.75 BSC_Zeta_ZZ */
    0.85,  /* 0.98 BSC_Zeta_PH */
    0.85,  /* 0.98 BSC_Zeta_TH */
    0.9,  /* BSC_Zeta_PS */

    /* Time Constants */
    0.164297e+00, /* BSC_Tau_hdot */
    0.150985e+00, /* BSC_Tau_r    */

    /* --- [3] System Matrix B (From Controller_Var.c) --- */
    /* 12x4 Matrix flattened to 1D array (Row-major) */
    /* Row 0: Force X */
    /* Row 1: Force Y */
    /* Row 2: Force Z (Thrust) */
    /* Row 3: Moment L (Roll) */
    /* Row 4: Moment M (Pitch) */
    /* Row 5: Moment N (Yaw) */
    /* 이전의 Hetlas 기반 B 행렬
 	 {
		 0.473E-14, -.500E-16, 0.764E-24, -.660E-23,
		 0.000E+00, 0.000E+00, 0.000E+00, 0.000E+00,
		 -.386E+02, 0.408E+00, -.624E-08, 0.539E-07,
		 -.673E+00, -.637E+02, -.618E-03, -.521E-04,
		 -.654E-05, -.617E-03, -.548E+02, -.580E+00,
		 0.103E-04, 0.974E-03, 0.356E-01, 0.235E+01,
		 0.000E+00, 0.000E+00, 0.000E+00, 0.000E+00,
		 0.000E+00, 0.000E+00, 0.000E+00, 0.000E+00,
		 0.000E+00, 0.000E+00, 0.000E+00, 0.000E+00,
		 0.000E+00, 0.000E+00, 0.000E+00, 0.000E+00,
		 0.000E+00, 0.000E+00, 0.000E+00, 0.000E+00,
		 0.000E+00, 0.000E+00, 0.000E+00, 0.000E+00,
		 } 이전의 Hetals 기반
    */
/* --- [3] System Matrix B : KAT 3Quad (FINAL, 2026-11-17) --- */
/* 12x4, row-major.  Columns: [T R P Y] = CLAW u (Scale = 1 basis)                  */
/* Structure: CLAW -> mode_tdcn -> ArduPilot QUAD-X mixer -> thrust linearization    */
/*   (chain verified against flight #64 RCOU to 0.3 us rms)                          */
/*   B_virtual = B_motor * 0.968 * MIX_AP * diag(0.5, -1, -1, 1)                      */
/*   mass 11.478 kg, Ixx 0.814 / Iyy 0.793 / Izz 1.385 kg m^2, arm 0.379/0.378 m      */
/*   EXPO 0.65, SPIN 0.15~0.95, PWM 1000~2000 (flight #64 PARM)                      */
/* Magnitude: rev.3 chain B (mfr local slope 153.6 N per FC throttle) x 0.794         */
/*   = hover dT/du 122 N per FC throttle (110 N per ESC throttle, flight #64 ESC RPM)  */
/*   cross-check: Gazebo rev.3 plant 119.5 N per FC throttle (x0.778)                  */
/* Row 2: Z, 3: L (Roll), 4: M (Pitch), 5: N (Yaw)                                    */
    {
        0.000E+00, 0.000E+00, 0.000E+00, 0.000E+00,
        0.000E+00, 0.000E+00, 0.000E+00, 0.000E+00,
        -.206E+02, 0.000E+00, 0.000E+00, 0.000E+00,
        0.000E+00, -.110E+03, 0.136E-04, -.127E-01,
        0.000E+00, 0.135E-04, -.113E+03, 0.441E-03,
        0.000E+00, 0.159E+00, -.552E-02, 0.515E+01,
        0.000E+00, 0.000E+00, 0.000E+00, 0.000E+00,
        0.000E+00, 0.000E+00, 0.000E+00, 0.000E+00,
        0.000E+00, 0.000E+00, 0.000E+00, 0.000E+00,
        0.000E+00, 0.000E+00, 0.000E+00, 0.000E+00,
        0.000E+00, 0.000E+00, 0.000E+00, 0.000E+00,
        0.000E+00, 0.000E+00, 0.000E+00, 0.000E+00
    }
  };  

#include "mode_tdcn_rtwtypes.h" // uint8_T 등을 위해 필요_2026.02.04 수정

// /* Block parameters (default storage) */
// P_CLAW_T CLAW_P = {
//   /* Variable: Kd_height   */
//   0.0,
//
//   /* Variable: Kd_pitch   */
//   0.06,
//
//   /* Variable: Kd_roll   */
//   0.06,
//
//   /* Variable: Kd_yaw   */
//   0.0,
//
//   /* Variable: Ki_height   */
//   0.0,
//
//   /* Variable: Ki_pitch   */
//   0.0,
//
//   /* Variable: Ki_roll   */
//   0.0,
//
//   /* Variable: Ki_yaw   */
//   0.0,
//
//   /* Variable: Kp_height   */
//   0.0,
//
//   /* Variable: Kp_pitch   */
//   0.1,
//
//   /* Variable: Kp_roll   */
//   0.1,
//
//   /* Variable: Kp_yaw   */
//   0.0,
//
//   /* Variable: height_scale   */
//   1.0,
//
//   /* Variable: pitch_scale   */
//   1.0,
//
//   /* Variable: roll_scale   */
//   1.0,
//
//   /* Variable: yaw_scale   */
//   1.0
// };

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

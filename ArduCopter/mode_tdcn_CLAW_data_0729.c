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
    3.2,  /* BSC_Scale_Thrust */
    0.25,   /* BSC_Scale_Roll   */
    0.20,   /* BSC_Scale_Pitch  */
    0.13,   /* BSC_Scale_Yaw    */

    /* --- [ ߰ ] Outer Loop Gains --- */
    0.3,  /* BSC_K_POS_P :   ġ          */
    0.01,  /* BSC_K_POS_I :   ġ           */
    0.4,  /* BSC_K_VEL_P :  ӵ           */
    0.05,  /* BSC_K_VEL_I :  ӵ            */
    /* [ ߰ ] Anti-Windup Limit */
    1.0,   /*    б          Ѱ  (  : 5.0m/s             ) */

    /* --- [2] BSC Control Gains (From Controller_Var.c) --- */
    /* Omega */
    0.3,   /* BSC_Ome_XX        2026.04.28 0.5 수정*/
    0.3,   /* BSC_Ome_YY        2026.04.28 0.5 수정*/
    2.0,   /* BSC_Ome_ZZ */
    9.3,  /* BSC_Ome_PH */
    12.0,  /* BSC_Ome_TH */
    3.0,  /* BSC_Ome_PS */

    /* Zeta */
    1.015,  /* BSC_Zeta_XX       2026.04.28 0.95 무조건 1근처로 */
    1.015,   /* BSC_Zeta_YY       2026.04.28 0.95 무조건 1근처로 */
    0.75,  /* BSC_Zeta_ZZ */
    0.98,  /* BSC_Zeta_PH */
    0.98,  /* BSC_Zeta_TH */
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
		 } 
/* --- [3] System Matrix B : KAT 3Quad (rev.2, 2026-11-12) --- */
/* 12x4 Matrix flattened to 1D array (Row-major)                         */
/* HETLAS B (15 kg model) rescaled with re-measured airframe data:       */
/*   mass 15 -> 11.478 kg, Ixx 2.757->0.814, Iyy 2.281->0.793,             */
/* (잠시 무효화) 
    {
        0.000E+00, 0.000E+00, 0.000E+00, 0.000E+00,
        0.000E+00, 0.000E+00, 0.000E+00, 0.000E+00,
        -.513E+02, 0.542E+00, -.830E-08, 0.717E-07,
        -.240E+01, -.227E+03, -.221E-02, -.186E-03,
        -.177E-04, -.167E-02, -.148E+03, -.157E+01,
        0.205E-04, 0.194E-02, 0.710E-01, 0.469E+01,
        0.000E+00, 0.000E+00, 0.000E+00, 0.000E+00,
        0.000E+00, 0.000E+00, 0.000E+00, 0.000E+00,
        0.000E+00, 0.000E+00, 0.000E+00, 0.000E+00,
        0.000E+00, 0.000E+00, 0.000E+00, 0.000E+00,
        0.000E+00, 0.000E+00, 0.000E+00, 0.000E+00,
        0.000E+00, 0.000E+00, 0.000E+00, 0.000E+00
    }  /* 류시양 신규 B 입력*/
  (잠시 무효화) */
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

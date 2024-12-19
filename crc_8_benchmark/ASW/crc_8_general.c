/*
 * File: crc_8_general.c
 *
 * Code generated for Simulink model 'crc_8_general'.
 *
 * Model version                  : 1.30
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Thu Dec 19 18:22:02 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "crc_8_general.h"
#include "crc_8_general_private.h"

/*
 * System initialize for atomic system:
 *    '<S7>/Scalar to Binary'
 *    '<S11>/Scalar to Binary'
 *    '<S15>/Scalar to Binary'
 *    '<S19>/Scalar to Binary'
 */
void crc_8_gener_ScalartoBinary_Init(DW_ScalartoBinary_crc_8_gener_T *localDW)
{
  int32_T k;
  for (k = 0; k < 8; k++) {
    localDW->temp[k] = k;
    localDW->temp[k] = pow(2.0, localDW->temp[k]);
  }
}

/*
 * Output and update for atomic system:
 *    '<S7>/Scalar to Binary'
 *    '<S11>/Scalar to Binary'
 *    '<S15>/Scalar to Binary'
 *    '<S19>/Scalar to Binary'
 */
void crc_8_general_ScalartoBinary(uint8_T rtu_u, boolean_T rty_y[8],
  DW_ScalartoBinary_crc_8_gener_T *localDW)
{
  int32_T k;
  for (k = 0; k < 8; k++) {
    real_T b_r;
    real_T x;
    x = (real_T)rtu_u / localDW->temp[k];
    if (x == 0.0) {
      b_r = 0.0;
    } else {
      b_r = fmod(x, 2.0);
      if (b_r == 0.0) {
        b_r = 0.0;
      } else if (x < 0.0) {
        b_r += 2.0;
      }
    }

    rty_y[k] = (floor(b_r) != 0.0);
  }
}

/* Model step function */
uint8_T crc_8_general_step(RT_MODEL_crc_8_general_T *const crc_8_general_M,
  uint8_T arg_In1, uint8_T arg_In2, uint8_T arg_In3, uint8_T arg_In4)
{
  real_T x[8];
  real_T rtb_y;
  int32_T i;
  uint32_T shReg;
  boolean_T rtb_GeneralCRCGenerator[40];
  boolean_T rtb_TmpSignalConversionAtGenera[32];
  boolean_T rtb_Flip[8];
  boolean_T rtb_Flip_i[8];
  boolean_T rtb_Flip_n[8];
  boolean_T tmp;

  /* specified return value */
  uint8_T arg_Out1;

  /* MATLAB Function: '<S7>/Scalar to Binary' incorporates:
   *  Inport: '<Root>/In1'
   */
  crc_8_general_ScalartoBinary(arg_In1, rtb_Flip_n, &(crc_8_general_M)
    ->dwork.sf_ScalartoBinary);

  /* DSPFlip: '<S10>/Flip' */
  rtb_Flip[0] = rtb_Flip_n[7];
  rtb_Flip[7] = rtb_Flip_n[0];
  rtb_Flip[1] = rtb_Flip_n[6];
  rtb_Flip[6] = rtb_Flip_n[1];
  rtb_Flip[2] = rtb_Flip_n[5];
  rtb_Flip[5] = rtb_Flip_n[2];
  rtb_Flip[3] = rtb_Flip_n[4];
  rtb_Flip[4] = rtb_Flip_n[3];

  /* MATLAB Function: '<S11>/Scalar to Binary' incorporates:
   *  Inport: '<Root>/In2'
   */
  crc_8_general_ScalartoBinary(arg_In2, rtb_Flip_n, &(crc_8_general_M)
    ->dwork.sf_ScalartoBinary_p);

  /* DSPFlip: '<S14>/Flip' */
  rtb_Flip_i[0] = rtb_Flip_n[7];
  rtb_Flip_i[7] = rtb_Flip_n[0];
  rtb_Flip_i[1] = rtb_Flip_n[6];
  rtb_Flip_i[6] = rtb_Flip_n[1];
  rtb_Flip_i[2] = rtb_Flip_n[5];
  rtb_Flip_i[5] = rtb_Flip_n[2];
  rtb_Flip_i[3] = rtb_Flip_n[4];
  rtb_Flip_i[4] = rtb_Flip_n[3];

  /* MATLAB Function: '<S15>/Scalar to Binary' incorporates:
   *  Inport: '<Root>/In3'
   */
  crc_8_general_ScalartoBinary(arg_In3, rtb_Flip_n, &(crc_8_general_M)
    ->dwork.sf_ScalartoBinary_k);

  /* DSPFlip: '<S18>/Flip' */
  tmp = rtb_Flip_n[0];
  rtb_Flip_n[0] = rtb_Flip_n[7];
  rtb_Flip_n[7] = tmp;
  tmp = rtb_Flip_n[1];
  rtb_Flip_n[1] = rtb_Flip_n[6];
  rtb_Flip_n[6] = tmp;
  tmp = rtb_Flip_n[2];
  rtb_Flip_n[2] = rtb_Flip_n[5];
  rtb_Flip_n[5] = tmp;
  tmp = rtb_Flip_n[3];
  rtb_Flip_n[3] = rtb_Flip_n[4];
  rtb_Flip_n[4] = tmp;

  /* MATLAB Function: '<S19>/Scalar to Binary' incorporates:
   *  Inport: '<Root>/In4'
   */
  crc_8_general_ScalartoBinary(arg_In4, &rtb_GeneralCRCGenerator[0],
    &(crc_8_general_M)->dwork.sf_ScalartoBinary_h);

  /* DSPFlip: '<S22>/Flip' */
  tmp = rtb_GeneralCRCGenerator[0];
  rtb_GeneralCRCGenerator[0] = rtb_GeneralCRCGenerator[7];
  rtb_GeneralCRCGenerator[7] = tmp;
  tmp = rtb_GeneralCRCGenerator[1];
  rtb_GeneralCRCGenerator[1] = rtb_GeneralCRCGenerator[6];
  rtb_GeneralCRCGenerator[6] = tmp;
  tmp = rtb_GeneralCRCGenerator[2];
  rtb_GeneralCRCGenerator[2] = rtb_GeneralCRCGenerator[5];
  rtb_GeneralCRCGenerator[5] = tmp;
  tmp = rtb_GeneralCRCGenerator[3];
  rtb_GeneralCRCGenerator[3] = rtb_GeneralCRCGenerator[4];
  rtb_GeneralCRCGenerator[4] = tmp;

  /* SignalConversion generated from: '<S1>/General CRC Generator' */
  for (i = 0; i < 8; i++) {
    rtb_TmpSignalConversionAtGenera[i] = rtb_Flip[i];
    rtb_TmpSignalConversionAtGenera[i + 8] = rtb_Flip_i[i];
    rtb_TmpSignalConversionAtGenera[i + 16] = rtb_Flip_n[i];
    rtb_TmpSignalConversionAtGenera[i + 24] = rtb_GeneralCRCGenerator[i];
  }

  /* End of SignalConversion generated from: '<S1>/General CRC Generator' */

  /* S-Function (scomcrcgen): '<S1>/General CRC Generator' */
  /* Initialize for current sub-frame */
  shReg = 255U;
  for (i = 0; i < 32; i++) {
    int32_T regIn;

    /* Get MSB of register */
    /* XOR with input bit */
    regIn = (int32_T)((shReg >> 7U & 1U) ^ rtb_TmpSignalConversionAtGenera[i]);
    if ((uint32_T)regIn != 0U) {
      /* XOR with generator polynomial if feedback bit is 1 */
      shReg = (shReg ^ 14U) << 1U;
    } else {
      shReg <<= 1U;
    }

    shReg += regIn;
  }

  /* Apply final XOR */
  shReg ^= 255U;

  /* DSPFlip: '<S26>/Flip' incorporates:
   *  S-Function (scomcrcgen): '<S1>/General CRC Generator'
   */
  /* Output the register */
  crc_8_general_M->blockIO.Flip[0] = ((shReg & 1U) != 0U);
  crc_8_general_M->blockIO.Flip[7] = ((shReg >> 7U & 1U) != 0U);
  crc_8_general_M->blockIO.Flip[1] = ((shReg >> 1U & 1U) != 0U);
  crc_8_general_M->blockIO.Flip[6] = ((shReg >> 6U & 1U) != 0U);
  crc_8_general_M->blockIO.Flip[2] = ((shReg >> 2U & 1U) != 0U);
  crc_8_general_M->blockIO.Flip[5] = ((shReg >> 5U & 1U) != 0U);
  crc_8_general_M->blockIO.Flip[3] = ((shReg >> 3U & 1U) != 0U);
  crc_8_general_M->blockIO.Flip[4] = ((shReg >> 4U & 1U) != 0U);

  /* MATLAB Function: '<S23>/Binary to Scalar' */
  for (i = 0; i < 8; i++) {
    x[i] = crc_8_general_M->dwork.pows[i] * (real_T)
      crc_8_general_M->blockIO.Flip[i];
  }

  rtb_y = x[0];
  for (i = 0; i < 7; i++) {
    rtb_y += x[i + 1];
  }

  /* End of MATLAB Function: '<S23>/Binary to Scalar' */

  /* DataTypeConversion: '<S23>/Data Type Conversion' */
  rtb_y = fmod(floor(rtb_y), 256.0);

  /* Outport: '<Root>/Out1' incorporates:
   *  DataTypeConversion: '<S23>/Data Type Conversion'
   */
  arg_Out1 = (uint8_T)(rtb_y < 0.0 ? (int32_T)(uint8_T)-(int8_T)(uint8_T)-rtb_y :
                       (int32_T)(uint8_T)rtb_y);
  return arg_Out1;
}

/* Model initialize function */
void crc_8_general_initialize(RT_MODEL_crc_8_general_T *const crc_8_general_M)
{
  /* Registration code */
  {
    (void) memset((void *) &(crc_8_general_M->dwork), 0,
                  sizeof(DW_crc_8_general_T));
  }

  {
    int32_T k;

    /* SystemInitialize for MATLAB Function: '<S7>/Scalar to Binary' */
    crc_8_gener_ScalartoBinary_Init(&(crc_8_general_M)->dwork.sf_ScalartoBinary);

    /* SystemInitialize for MATLAB Function: '<S11>/Scalar to Binary' */
    crc_8_gener_ScalartoBinary_Init(&(crc_8_general_M)
      ->dwork.sf_ScalartoBinary_p);

    /* SystemInitialize for MATLAB Function: '<S15>/Scalar to Binary' */
    crc_8_gener_ScalartoBinary_Init(&(crc_8_general_M)
      ->dwork.sf_ScalartoBinary_k);

    /* SystemInitialize for MATLAB Function: '<S19>/Scalar to Binary' */
    crc_8_gener_ScalartoBinary_Init(&(crc_8_general_M)
      ->dwork.sf_ScalartoBinary_h);

    /* SystemInitialize for MATLAB Function: '<S23>/Binary to Scalar' */
    for (k = 0; k < 8; k++) {
      crc_8_general_M->dwork.pows[k] = pow(2.0, ((real_T)k + 1.0) - 1.0);
    }

    /* End of SystemInitialize for MATLAB Function: '<S23>/Binary to Scalar' */
  }
}

/* Model terminate function */
void crc_8_general_terminate(RT_MODEL_crc_8_general_T *const crc_8_general_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(crc_8_general_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

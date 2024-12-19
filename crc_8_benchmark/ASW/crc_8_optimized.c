/*
 * File: crc_8_optimized.c
 *
 * Code generated for Simulink model 'crc_8_optimized'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Wed Dec 18 22:15:07 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "crc_8_optimized.h"
#include "crc_8_optimized_private.h"

/* Forward declaration for local functions */
static boolean_T SystemCore_detectInputSizeChang(comm_HDLCRCGenerator_crc_8_op_T
  *obj, boolean_T skipNonDirectFeed);
static void crc_8_optimize_SystemCore_setup(comm_HDLCRCGenerator_crc_8_op_T *obj);
static void crc_8_HDLCRCGenerator_resetImpl(comm_HDLCRCGenerator_crc_8_op_T *obj);
int32_T div_s32_floor(int32_T numerator, int32_T denominator)
{
  int32_T quotient;
  if (denominator == 0) {
    quotient = numerator >= 0 ? MAX_int32_T : MIN_int32_T;

    /* Divide by zero handler */
  } else {
    uint32_T absDenominator;
    uint32_T absNumerator;
    uint32_T tempAbsQuotient;
    boolean_T quotientNeedsNegation;
    absNumerator = numerator < 0 ? ~(uint32_T)numerator + 1U : (uint32_T)
      numerator;
    absDenominator = denominator < 0 ? ~(uint32_T)denominator + 1U : (uint32_T)
      denominator;
    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    tempAbsQuotient = absNumerator / absDenominator;
    if (quotientNeedsNegation) {
      absNumerator %= absDenominator;
      if (absNumerator > 0U) {
        tempAbsQuotient++;
      }
    }

    quotient = quotientNeedsNegation ? -(int32_T)tempAbsQuotient : (int32_T)
      tempAbsQuotient;
  }

  return quotient;
}

static boolean_T SystemCore_detectInputSizeChang(comm_HDLCRCGenerator_crc_8_op_T
  *obj, boolean_T skipNonDirectFeed)
{
  int32_T b_k;
  boolean_T anyInputSizeChanged;
  boolean_T exitg1;
  anyInputSizeChanged = false;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k < 8)) {
    if ((!skipNonDirectFeed) && (obj->inputVarSize[0].f1[b_k] != 1U)) {
      anyInputSizeChanged = true;
      for (b_k = 0; b_k < 8; b_k++) {
        obj->inputVarSize[0].f1[b_k] = 1U;
      }

      exitg1 = true;
    } else {
      b_k++;
    }
  }

  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k < 8)) {
    if ((!skipNonDirectFeed) && (obj->inputVarSize[1].f1[b_k] != 1U)) {
      anyInputSizeChanged = true;
      for (b_k = 0; b_k < 8; b_k++) {
        obj->inputVarSize[1].f1[b_k] = 1U;
      }

      exitg1 = true;
    } else {
      b_k++;
    }
  }

  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k < 8)) {
    if ((!skipNonDirectFeed) && (obj->inputVarSize[2].f1[b_k] != 1U)) {
      anyInputSizeChanged = true;
      for (b_k = 0; b_k < 8; b_k++) {
        obj->inputVarSize[2].f1[b_k] = 1U;
      }

      exitg1 = true;
    } else {
      b_k++;
    }
  }

  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k < 8)) {
    if ((!skipNonDirectFeed) && (obj->inputVarSize[3].f1[b_k] != 1U)) {
      anyInputSizeChanged = true;
      for (b_k = 0; b_k < 8; b_k++) {
        obj->inputVarSize[3].f1[b_k] = 1U;
      }

      exitg1 = true;
    } else {
      b_k++;
    }
  }

  return anyInputSizeChanged;
}

static void crc_8_optimize_SystemCore_setup(comm_HDLCRCGenerator_crc_8_op_T *obj)
{
  int32_T b_i;
  int32_T b_k;
  int32_T i;
  int8_T B[8];
  boolean_T c[64];
  static const int8_T tmp[64] = { 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 };

  static const boolean_T tmp_0[8] = { false, true, true, true, true, true, true,
    false };

  static const int8_T tmp_1[8] = { 0, 0, 0, 1, 1, 1, 0, 1 };

  obj->isInitialized = 1;
  obj->inputVarSize[0].f1[0] = 1U;
  obj->inputVarSize[0].f1[1] = 1U;
  obj->inputVarSize[1].f1[0] = 1U;
  obj->inputVarSize[1].f1[1] = 1U;
  obj->inputVarSize[2].f1[0] = 1U;
  obj->inputVarSize[2].f1[1] = 1U;
  obj->inputVarSize[3].f1[0] = 1U;
  obj->inputVarSize[3].f1[1] = 1U;
  for (b_i = 0; b_i < 6; b_i++) {
    obj->inputVarSize[0].f1[b_i + 2] = 1U;
    obj->inputVarSize[1].f1[b_i + 2] = 1U;
    obj->inputVarSize[2].f1[b_i + 2] = 1U;
    obj->inputVarSize[3].f1[b_i + 2] = 1U;
  }

  obj->startOutbuffer = false;
  obj->validInReg = false;
  for (i = 0; i < 8; i++) {
    obj->mReg[i] = false;
    obj->dm[i] = false;
    obj->yOutReg[i] = false;
    obj->xorValue[i] = true;
    obj->initVector[i] = tmp_0[i];
    obj->reg[i] = obj->initVector[i];
    obj->crcoutreg[i] = false;
  }

  for (b_i = 0; b_i < 64; b_i++) {
    obj->F[b_i] = false;
    obj->F[b_i] = (tmp[b_i] != 0);
  }

  for (i = 0; i < 8; i++) {
    B[i] = tmp_1[i];
  }

  for (i = 0; i < 7; i++) {
    for (b_i = 0; b_i < 8; b_i++) {
      boolean_T t;
      t = false;
      for (b_k = 0; b_k < 8; b_k++) {
        t = ((obj->F[(b_k << 3) + b_i] && (B[b_k] != 0)) != (int32_T)t);
      }

      c[b_i] = t;
    }

    for (b_i = 0; b_i < 7; b_i++) {
      for (b_k = 0; b_k < 8; b_k++) {
        c[b_k + ((b_i + 1) << 3)] = obj->F[(b_i << 3) + b_k];
      }
    }

    memcpy(&obj->F[0], &c[0], sizeof(boolean_T) << 6U);
  }
}

static void crc_8_HDLCRCGenerator_resetImpl(comm_HDLCRCGenerator_crc_8_op_T *obj)
{
  int32_T i;
  static const boolean_T tmp[8] = { false, true, true, true, true, true, true,
    false };

  obj->processMsg = false;
  obj->padZero = false;
  obj->tStartOut = false;
  obj->tEndOut = false;
  obj->startOutReg = false;
  obj->endOutReg = false;
  obj->validOutReg = false;
  for (i = 0; i < 8; i++) {
    obj->yOutReg[i] = false;
    obj->mReg[i] = false;
    obj->dm[i] = false;
    obj->xorValue[i] = true;
    obj->initVector[i] = tmp[i];
    obj->reg[i] = obj->initVector[i];
  }

  obj->validIn_delay = false;
  obj->endIn_delay = false;
  obj->startOutbuffer = false;
  obj->validInReg = false;
  obj->sysenb = false;
  obj->processCRC = false;
  obj->outputCRC = false;
  obj->counter1 = 0.0;
  obj->counter2 = 0.0;
}

/* Model step function */
uint8_T crc_8_optimized_step(RT_MODEL_crc_8_optimized_T *const crc_8_optimized_M,
  uint8_T arg_In1, boolean_T arg_In2, boolean_T arg_In3, boolean_T arg_In4)
{
  real_T yv;
  int32_T b_i;
  int32_T f;
  int32_T idx;
  char_T s[8];
  char_T sfull[8];
  boolean_T a[8];
  boolean_T d[8];

  /* specified return value */
  uint8_T arg_Out1;

  /* Copy value for root inport '<Root>/In1' since it is accessed globally */
  crc_8_optimized_M->inputs.In1 = arg_In1;

  /* Copy value for root inport '<Root>/In2' since it is accessed globally */
  crc_8_optimized_M->inputs.In2 = arg_In2;

  /* Copy value for root inport '<Root>/In3' since it is accessed globally */
  crc_8_optimized_M->inputs.In3 = arg_In3;

  /* Copy value for root inport '<Root>/In4' since it is accessed globally */
  crc_8_optimized_M->inputs.In4 = arg_In4;

  /* MATLABSystem: '<S1>/General CRC Generator HDL Optimized' */
  SystemCore_detectInputSizeChang(&(crc_8_optimized_M)->dwork.obj, true);
  yv = 0.0;
  for (b_i = 0; b_i < 8; b_i++) {
    yv += pow(2.0, 8.0 - ((real_T)b_i + 1.0)) * (real_T)
      crc_8_optimized_M->dwork.obj.yOutReg[b_i];
  }

  if (yv < 256.0) {
    /* Outport: '<Root>/Out1' */
    arg_Out1 = (uint8_T)yv;
  } else {
    /* Outport: '<Root>/Out1' */
    arg_Out1 = MAX_uint8_T;
  }

  /* End of MATLABSystem: '<S1>/General CRC Generator HDL Optimized' */

  /* Update for MATLABSystem: '<S1>/General CRC Generator HDL Optimized' */
  if (crc_8_optimized_M->dwork.obj.isInitialized != 1) {
    crc_8_optimize_SystemCore_setup(&(crc_8_optimized_M)->dwork.obj);
    crc_8_HDLCRCGenerator_resetImpl(&(crc_8_optimized_M)->dwork.obj);
  } else {
    SystemCore_detectInputSizeChang(&(crc_8_optimized_M)->dwork.obj, false);
  }

  crc_8_optimized_M->dwork.obj.startOutReg =
    crc_8_optimized_M->dwork.obj.startOutbuffer;
  if (crc_8_optimized_M->dwork.obj.sysenb) {
    crc_8_optimized_M->dwork.obj.startOutbuffer =
      crc_8_optimized_M->dwork.obj.tStartOut;
  }

  if (crc_8_optimized_M->dwork.obj.tStartOut) {
    crc_8_optimized_M->dwork.obj.tStartOut = false;
  }

  crc_8_optimized_M->dwork.obj.endOutReg = crc_8_optimized_M->dwork.obj.tEndOut;
  if (crc_8_optimized_M->dwork.obj.outputCRC) {
    yv = 8.0 - crc_8_optimized_M->dwork.obj.counter2 * 8.0;
    if (9.0 - (crc_8_optimized_M->dwork.obj.counter2 + 1.0) * 8.0 > yv) {
      idx = 1;
      f = 1;
    } else {
      idx = (int32_T)yv;
      f = -1;
    }

    for (b_i = 0; b_i < 8; b_i++) {
      crc_8_optimized_M->dwork.obj.yOutReg[b_i] =
        crc_8_optimized_M->dwork.obj.crcoutreg[(f * b_i + idx) - 1];
    }

    crc_8_optimized_M->dwork.obj.validOutReg =
      crc_8_optimized_M->dwork.obj.outputCRC;
  } else {
    crc_8_optimized_M->dwork.obj.validOutReg =
      crc_8_optimized_M->dwork.obj.validInReg;
    for (b_i = 0; b_i < 8; b_i++) {
      crc_8_optimized_M->dwork.obj.yOutReg[b_i] =
        (crc_8_optimized_M->dwork.obj.validOutReg &&
         crc_8_optimized_M->dwork.obj.mReg[b_i]);
    }
  }

  if (crc_8_optimized_M->dwork.obj.processCRC) {
    crc_8_optimized_M->dwork.obj.counter1++;
  }

  if (crc_8_optimized_M->dwork.obj.outputCRC) {
    crc_8_optimized_M->dwork.obj.counter2++;
  }

  if (crc_8_optimized_M->dwork.obj.sysenb) {
    boolean_T tv;
    if (crc_8_optimized_M->dwork.obj.processCRC) {
      for (b_i = 0; b_i < 8; b_i++) {
        crc_8_optimized_M->dwork.obj.mReg[b_i] = false;
      }

      tv = false;
    } else {
      for (b_i = 0; b_i < 8; b_i++) {
        crc_8_optimized_M->dwork.obj.mReg[b_i] = crc_8_optimized_M->
          dwork.obj.dm[b_i];
      }

      tv = crc_8_optimized_M->dwork.obj.validIn_delay;
    }

    crc_8_optimized_M->dwork.obj.validInReg = tv;
    for (b_i = 0; b_i < 8; b_i++) {
      d[b_i] = false;
    }

    if ((!crc_8_optimized_M->dwork.obj.padZero) &&
        crc_8_optimized_M->dwork.obj.validIn_delay) {
      for (b_i = 0; b_i < 8; b_i++) {
        d[b_i] = crc_8_optimized_M->dwork.obj.dm[b_i];
      }
    }

    if (crc_8_optimized_M->dwork.obj.validIn_delay ||
        crc_8_optimized_M->dwork.obj.padZero) {
      for (idx = 0; idx < 8; idx++) {
        tv = (crc_8_optimized_M->dwork.obj.F[idx] &&
              crc_8_optimized_M->dwork.obj.reg[7]);
        for (b_i = 0; b_i < 7; b_i++) {
          tv = ((crc_8_optimized_M->dwork.obj.F[((b_i + 1) << 3) + idx] &&
                 crc_8_optimized_M->dwork.obj.reg[6 - b_i]) != (int32_T)tv);
        }

        a[7 - idx] = (tv != d[idx]);
      }

      for (b_i = 0; b_i < 8; b_i++) {
        crc_8_optimized_M->dwork.obj.reg[b_i] = a[b_i];
      }
    }

    if (crc_8_optimized_M->dwork.obj.counter1 == 1.0) {
      for (b_i = 0; b_i < 8; b_i++) {
        crc_8_optimized_M->dwork.obj.reg[b_i] =
          (crc_8_optimized_M->dwork.obj.reg[b_i] !=
           crc_8_optimized_M->dwork.obj.xorValue[b_i]);
      }
    }
  }

  if (crc_8_optimized_M->dwork.obj.endIn_delay &&
      crc_8_optimized_M->dwork.obj.sysenb) {
    crc_8_optimized_M->dwork.obj.processCRC = true;
    crc_8_optimized_M->dwork.obj.padZero = true;
    crc_8_optimized_M->dwork.obj.processMsg = false;
  }

  if (crc_8_optimized_M->inputs.In3 && crc_8_optimized_M->inputs.In4) {
    crc_8_optimized_M->dwork.obj.endIn_delay = true;
  } else {
    crc_8_optimized_M->dwork.obj.endIn_delay = false;
  }

  if (crc_8_optimized_M->dwork.obj.tEndOut) {
    crc_8_optimized_M->dwork.obj.counter2 = 0.0;
    crc_8_optimized_M->dwork.obj.outputCRC = false;
    crc_8_optimized_M->dwork.obj.tEndOut = false;
  }

  if (crc_8_optimized_M->dwork.obj.counter1 == 1.0) {
    crc_8_optimized_M->dwork.obj.padZero = false;
    crc_8_optimized_M->dwork.obj.processCRC = false;
    crc_8_optimized_M->dwork.obj.outputCRC = true;
    crc_8_optimized_M->dwork.obj.sysenb = false;
    crc_8_optimized_M->dwork.obj.counter1 = 0.0;
    for (b_i = 0; b_i < 8; b_i++) {
      crc_8_optimized_M->dwork.obj.crcoutreg[b_i] =
        crc_8_optimized_M->dwork.obj.reg[b_i];
      crc_8_optimized_M->dwork.obj.reg[b_i] =
        crc_8_optimized_M->dwork.obj.initVector[b_i];
    }
  }

  if ((crc_8_optimized_M->dwork.obj.counter2 == 0.0) &&
      crc_8_optimized_M->dwork.obj.outputCRC) {
    crc_8_optimized_M->dwork.obj.tEndOut = true;
  }

  if (crc_8_optimized_M->inputs.In2 && crc_8_optimized_M->inputs.In4 &&
      (!crc_8_optimized_M->dwork.obj.sysenb)) {
    crc_8_optimized_M->dwork.obj.processMsg = true;
    crc_8_optimized_M->dwork.obj.tStartOut = true;
    crc_8_optimized_M->dwork.obj.sysenb = true;
  }

  if (crc_8_optimized_M->dwork.obj.processMsg) {
    int32_T npad;
    boolean_T exitg1;
    for (b_i = 0; b_i < 8; b_i++) {
      sfull[b_i] = '0';
      if ((1 << (7 - b_i) & crc_8_optimized_M->inputs.In1) != 0) {
        sfull[b_i] = '1';
      }
    }

    idx = 0;
    b_i = 1;
    exitg1 = false;
    while ((!exitg1) && (b_i - 1 < 8)) {
      if (sfull[b_i - 1] == '1') {
        idx = b_i;
        exitg1 = true;
      } else {
        b_i++;
      }
    }

    if (idx == 0) {
      idx = 8;
    }

    f = 8 - idx;
    if (9 - idx < 8) {
      npad = idx - 2;
      for (b_i = 0; b_i <= npad; b_i++) {
        s[b_i] = '0';
      }
    } else {
      npad = -1;
    }

    for (b_i = 0; b_i <= f; b_i++) {
      s[(npad + b_i) + 1] = sfull[(b_i + idx) - 1];
    }

    for (b_i = 0; b_i < 8; b_i++) {
      crc_8_optimized_M->dwork.obj.dm[b_i] = (s[b_i] - 48 != 0);
    }

    crc_8_optimized_M->dwork.obj.validIn_delay = crc_8_optimized_M->inputs.In4;
  }

  /* End of Update for MATLABSystem: '<S1>/General CRC Generator HDL Optimized' */
  return arg_Out1;
}

/* Model initialize function */
void crc_8_optimized_initialize(RT_MODEL_crc_8_optimized_T *const
  crc_8_optimized_M)
{
  ExtU_crc_8_optimized_T *crc_8_optimized_U = (ExtU_crc_8_optimized_T *)
    &(crc_8_optimized_M->inputs);

  /* Registration code */
  {
    (void) memset((void *) &(crc_8_optimized_M->dwork), 0,
                  sizeof(DW_crc_8_optimized_T));
  }

  /* Start for MATLABSystem: '<S1>/General CRC Generator HDL Optimized' */
  crc_8_optimized_M->dwork.obj.isInitialized = 0;
  crc_8_optimize_SystemCore_setup(&(crc_8_optimized_M)->dwork.obj);

  /* InitializeConditions for MATLABSystem: '<S1>/General CRC Generator HDL Optimized' */
  crc_8_HDLCRCGenerator_resetImpl(&(crc_8_optimized_M)->dwork.obj);
}

/* Model terminate function */
void crc_8_optimized_terminate(RT_MODEL_crc_8_optimized_T *const
  crc_8_optimized_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(crc_8_optimized_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

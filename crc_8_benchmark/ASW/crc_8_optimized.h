/*
 * File: crc_8_optimized.h
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

#ifndef RTW_HEADER_crc_8_optimized_h_
#define RTW_HEADER_crc_8_optimized_h_
#include <math.h>
#include <string.h>
#ifndef crc_8_optimized_COMMON_INCLUDES_
#define crc_8_optimized_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* crc_8_optimized_COMMON_INCLUDES_ */

#include "crc_8_optimized_types.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  comm_HDLCRCGenerator_crc_8_op_T obj;
                                /* '<S1>/General CRC Generator HDL Optimized' */
} DW_crc_8_optimized_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  uint8_T In1;                         /* '<Root>/In1' */
  boolean_T In2;                       /* '<Root>/In2' */
  boolean_T In3;                       /* '<Root>/In3' */
  boolean_T In4;                       /* '<Root>/In4' */
} ExtU_crc_8_optimized_T;

/* Self model data, for system '<Root>' */
struct tag_RTM_crc_8_optimized_T {
  const char_T * volatile errorStatus;
  DW_crc_8_optimized_T dwork;
  ExtU_crc_8_optimized_T inputs;
};

/* Model entry point functions */
extern void crc_8_optimized_initialize(RT_MODEL_crc_8_optimized_T *const
  crc_8_optimized_M);
extern void crc_8_optimized_terminate(RT_MODEL_crc_8_optimized_T *const
  crc_8_optimized_M);

/* Customized model step function */
extern uint8_T crc_8_optimized_step(RT_MODEL_crc_8_optimized_T *const
  crc_8_optimized_M, uint8_T arg_In1, boolean_T arg_In2, boolean_T arg_In3,
  boolean_T arg_In4);

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
 * '<Root>' : 'crc_8_optimized'
 * '<S1>'   : 'crc_8_optimized/crc_8_optimized'
 */
#endif                                 /* RTW_HEADER_crc_8_optimized_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

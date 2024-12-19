/*
 * File: crc_8_general.h
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

#ifndef RTW_HEADER_crc_8_general_h_
#define RTW_HEADER_crc_8_general_h_
#include <math.h>
#include <string.h>
#ifndef crc_8_general_COMMON_INCLUDES_
#define crc_8_general_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* crc_8_general_COMMON_INCLUDES_ */

#include "crc_8_general_types.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<S7>/Scalar to Binary' */
typedef struct {
  real_T temp[8];                      /* '<S7>/Scalar to Binary' */
} DW_ScalartoBinary_crc_8_gener_T;

/* Block signals (default storage) */
typedef struct {
  boolean_T Flip[8];                   /* '<S26>/Flip' */
} B_crc_8_general_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  DW_ScalartoBinary_crc_8_gener_T sf_ScalartoBinary_h;/* '<S19>/Scalar to Binary' */
  DW_ScalartoBinary_crc_8_gener_T sf_ScalartoBinary_k;/* '<S15>/Scalar to Binary' */
  DW_ScalartoBinary_crc_8_gener_T sf_ScalartoBinary_p;/* '<S11>/Scalar to Binary' */
  DW_ScalartoBinary_crc_8_gener_T sf_ScalartoBinary;/* '<S7>/Scalar to Binary' */
  real_T pows[8];                      /* '<S23>/Binary to Scalar' */
} DW_crc_8_general_T;

/* Self model data, for system '<Root>' */
struct tag_RTM_crc_8_general_T {
  const char_T * volatile errorStatus;
  DW_crc_8_general_T dwork;
  B_crc_8_general_T blockIO;
};

/* Model entry point functions */
extern void crc_8_general_initialize(RT_MODEL_crc_8_general_T *const
  crc_8_general_M);
extern void crc_8_general_terminate(RT_MODEL_crc_8_general_T *const
  crc_8_general_M);

/* Customized model step function */
extern uint8_T crc_8_general_step(RT_MODEL_crc_8_general_T *const
  crc_8_general_M, uint8_T arg_In1, uint8_T arg_In2, uint8_T arg_In3, uint8_T
  arg_In4);

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
 * '<Root>' : 'crc_8_general'
 * '<S1>'   : 'crc_8_general/crc_8_general'
 * '<S2>'   : 'crc_8_general/crc_8_general/Binary Vector Conversion1'
 * '<S3>'   : 'crc_8_general/crc_8_general/Binary Vector Conversion2'
 * '<S4>'   : 'crc_8_general/crc_8_general/Binary Vector Conversion3'
 * '<S5>'   : 'crc_8_general/crc_8_general/Binary Vector Conversion4'
 * '<S6>'   : 'crc_8_general/crc_8_general/Binary Vector Conversion5'
 * '<S7>'   : 'crc_8_general/crc_8_general/Binary Vector Conversion1/To Unipolar'
 * '<S8>'   : 'crc_8_general/crc_8_general/Binary Vector Conversion1/To Unipolar/OutputInvert'
 * '<S9>'   : 'crc_8_general/crc_8_general/Binary Vector Conversion1/To Unipolar/Scalar to Binary'
 * '<S10>'  : 'crc_8_general/crc_8_general/Binary Vector Conversion1/To Unipolar/OutputInvert/on'
 * '<S11>'  : 'crc_8_general/crc_8_general/Binary Vector Conversion2/To Unipolar'
 * '<S12>'  : 'crc_8_general/crc_8_general/Binary Vector Conversion2/To Unipolar/OutputInvert'
 * '<S13>'  : 'crc_8_general/crc_8_general/Binary Vector Conversion2/To Unipolar/Scalar to Binary'
 * '<S14>'  : 'crc_8_general/crc_8_general/Binary Vector Conversion2/To Unipolar/OutputInvert/on'
 * '<S15>'  : 'crc_8_general/crc_8_general/Binary Vector Conversion3/To Unipolar'
 * '<S16>'  : 'crc_8_general/crc_8_general/Binary Vector Conversion3/To Unipolar/OutputInvert'
 * '<S17>'  : 'crc_8_general/crc_8_general/Binary Vector Conversion3/To Unipolar/Scalar to Binary'
 * '<S18>'  : 'crc_8_general/crc_8_general/Binary Vector Conversion3/To Unipolar/OutputInvert/on'
 * '<S19>'  : 'crc_8_general/crc_8_general/Binary Vector Conversion4/To Unipolar'
 * '<S20>'  : 'crc_8_general/crc_8_general/Binary Vector Conversion4/To Unipolar/OutputInvert'
 * '<S21>'  : 'crc_8_general/crc_8_general/Binary Vector Conversion4/To Unipolar/Scalar to Binary'
 * '<S22>'  : 'crc_8_general/crc_8_general/Binary Vector Conversion4/To Unipolar/OutputInvert/on'
 * '<S23>'  : 'crc_8_general/crc_8_general/Binary Vector Conversion5/From Unipolar'
 * '<S24>'  : 'crc_8_general/crc_8_general/Binary Vector Conversion5/From Unipolar/Binary to Scalar'
 * '<S25>'  : 'crc_8_general/crc_8_general/Binary Vector Conversion5/From Unipolar/InputInvert'
 * '<S26>'  : 'crc_8_general/crc_8_general/Binary Vector Conversion5/From Unipolar/InputInvert/on'
 */
#endif                                 /* RTW_HEADER_crc_8_general_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

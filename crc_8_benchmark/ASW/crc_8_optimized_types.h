/*
 * File: crc_8_optimized_types.h
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

#ifndef RTW_HEADER_crc_8_optimized_types_h_
#define RTW_HEADER_crc_8_optimized_types_h_
#include "rtwtypes.h"

/* Model Code Variants */
#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap_crc_8_optimized_T
#define typedef_cell_wrap_crc_8_optimized_T

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap_crc_8_optimized_T;

#endif                                 /* typedef_cell_wrap_crc_8_optimized_T */

#ifndef struct_tag_Skrq9lU91WK9QNAIqKAA6B
#define struct_tag_Skrq9lU91WK9QNAIqKAA6B

struct tag_Skrq9lU91WK9QNAIqKAA6B
{
  int32_T isInitialized;
  cell_wrap_crc_8_optimized_T inputVarSize[4];
  boolean_T processMsg;
  boolean_T padZero;
  boolean_T tStartOut;
  boolean_T tEndOut;
  boolean_T startOutReg;
  boolean_T endOutReg;
  boolean_T validOutReg;
  boolean_T yOutReg[8];
  boolean_T F[64];
  boolean_T reg[8];
  boolean_T crcoutreg[8];
  boolean_T mReg[8];
  boolean_T dm[8];
  boolean_T xorValue[8];
  boolean_T initVector[8];
  boolean_T validIn_delay;
  boolean_T endIn_delay;
  boolean_T startOutbuffer;
  boolean_T validInReg;
  boolean_T sysenb;
  boolean_T processCRC;
  boolean_T outputCRC;
  real_T counter1;
  real_T counter2;
};

#endif                                 /* struct_tag_Skrq9lU91WK9QNAIqKAA6B */

#ifndef typedef_comm_HDLCRCGenerator_crc_8_op_T
#define typedef_comm_HDLCRCGenerator_crc_8_op_T

typedef struct tag_Skrq9lU91WK9QNAIqKAA6B comm_HDLCRCGenerator_crc_8_op_T;

#endif                             /* typedef_comm_HDLCRCGenerator_crc_8_op_T */

/* Forward declaration for rtModel */
typedef struct tag_RTM_crc_8_optimized_T RT_MODEL_crc_8_optimized_T;

#endif                                 /* RTW_HEADER_crc_8_optimized_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

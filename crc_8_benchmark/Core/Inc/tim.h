/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    tim.h
  * @brief   This file contains all the function prototypes for
  *          the tim.c file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TIM_H__
#define __TIM_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern TIM_HandleTypeDef htim3;

/* USER CODE BEGIN Private defines */
extern volatile u8 TIM_Flag_10ms;			//10ms标志位
extern volatile u8 TIM_Flag_1s;				//1s标志位
extern volatile u16 TIM_Cnt;						//TIM_Flag计数，自增xx次后重新置0
extern volatile u8 RT_s;									//运行时间（s）
extern volatile u8 RT_m;									//运行时间（m）
extern volatile u8 RT_h;									//运行时间（h）
/* USER CODE END Private defines */

void MX_TIM3_Init(void);

/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __TIM_H__ */


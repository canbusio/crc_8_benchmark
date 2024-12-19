/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    can.c
  * @brief   This file provides code for the configuration
  *          of the CAN instances.
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
/* Includes ------------------------------------------------------------------*/
#include "can.h"

/* USER CODE BEGIN 0 */
CAN_TxHeaderTypeDef   TxHeader;
CAN_RxHeaderTypeDef   RxHeader;
u8                    TxData[8];
u8                    RxData[8];
u32                   TxMailbox;
/* USER CODE END 0 */

CAN_HandleTypeDef hcan;

/* CAN init function */
void MX_CAN_Init(void)
{

  /* USER CODE BEGIN CAN_Init 0 */

  /* USER CODE END CAN_Init 0 */

  /* USER CODE BEGIN CAN_Init 1 */

  /* USER CODE END CAN_Init 1 */
  hcan.Instance = CAN1;
  hcan.Init.Prescaler = 4;
  hcan.Init.Mode = CAN_MODE_NORMAL;
  hcan.Init.SyncJumpWidth = CAN_SJW_2TQ;
  hcan.Init.TimeSeg1 = CAN_BS1_14TQ;
  hcan.Init.TimeSeg2 = CAN_BS2_3TQ;
  hcan.Init.TimeTriggeredMode = DISABLE;
  hcan.Init.AutoBusOff = ENABLE;
  hcan.Init.AutoWakeUp = DISABLE;
  hcan.Init.AutoRetransmission = DISABLE;
  hcan.Init.ReceiveFifoLocked = DISABLE;
  hcan.Init.TransmitFifoPriority = DISABLE;
  if (HAL_CAN_Init(&hcan) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CAN_Init 2 */
  CAN_FilterTypeDef  fcan;

  fcan.FilterBank = 0;
  fcan.FilterMode = CAN_FILTERMODE_IDMASK;
  fcan.FilterScale = CAN_FILTERSCALE_32BIT;
  fcan.FilterIdHigh = 0x0000;
  fcan.FilterIdLow = 0x0000;
  fcan.FilterMaskIdHigh = 0x0000;
  fcan.FilterMaskIdLow = 0x0002;			//只接收数据帧
  fcan.FilterFIFOAssignment = CAN_RX_FIFO0;
  fcan.FilterActivation = ENABLE;
  //fcan.SlaveStartFilterBank = 14;			//单路CAN此参数无意义

  if (HAL_CAN_ConfigFilter(&hcan, &fcan) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE END CAN_Init 2 */

}

void HAL_CAN_MspInit(CAN_HandleTypeDef* canHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(canHandle->Instance==CAN1)
  {
  /* USER CODE BEGIN CAN1_MspInit 0 */

  /* USER CODE END CAN1_MspInit 0 */
    /* CAN1 clock enable */
    __HAL_RCC_CAN1_CLK_ENABLE();

    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**CAN GPIO Configuration
    PB8     ------> CAN_RX
    PB9     ------> CAN_TX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_8;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_9;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    __HAL_AFIO_REMAP_CAN1_2();

    /* CAN1 interrupt Init */
    HAL_NVIC_SetPriority(USB_LP_CAN1_RX0_IRQn, 1, 0);
    HAL_NVIC_EnableIRQ(USB_LP_CAN1_RX0_IRQn);
  /* USER CODE BEGIN CAN1_MspInit 1 */

  /* USER CODE END CAN1_MspInit 1 */
  }
}

void HAL_CAN_MspDeInit(CAN_HandleTypeDef* canHandle)
{

  if(canHandle->Instance==CAN1)
  {
  /* USER CODE BEGIN CAN1_MspDeInit 0 */

  /* USER CODE END CAN1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_CAN1_CLK_DISABLE();

    /**CAN GPIO Configuration
    PB8     ------> CAN_RX
    PB9     ------> CAN_TX
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_8|GPIO_PIN_9);

    /* CAN1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USB_LP_CAN1_RX0_IRQn);
  /* USER CODE BEGIN CAN1_MspDeInit 1 */

  /* USER CODE END CAN1_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */
HAL_StatusTypeDef CAN1_Send_Msg(u32 can_id, u8 *data, u8 dlc, u8 is_extended)
{
    u8 i = 0;
    u8 addTxStatus = HAL_ERROR;
    u16 addTxRetry = 0;

    TxHeader.StdId = (is_extended == 0) ? can_id : 0;
    TxHeader.ExtId = (is_extended != 0) ? can_id : 0;
    TxHeader.RTR = CAN_RTR_DATA;
    TxHeader.IDE = (is_extended != 0) ? CAN_ID_EXT : CAN_ID_STD;
    TxHeader.DLC = dlc;
    TxHeader.TransmitGlobalTime = DISABLE;

    for(i=0;i<dlc;i++) TxData[i]=data[i];

    do {
    	addTxStatus = HAL_CAN_AddTxMessage(&hcan, &TxHeader, TxData, &TxMailbox);
    	addTxRetry++;
    } while(addTxStatus != HAL_OK && addTxRetry<=0xFFF);

    return addTxStatus;
}

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *p_hcan)
{
  if (HAL_CAN_GetRxMessage(p_hcan, CAN_RX_FIFO0, &RxHeader, RxData) != HAL_OK)
  {
    Error_Handler();
  }

  if ((RxHeader.StdId == 0x01) && (RxHeader.IDE == CAN_ID_STD) && (RxHeader.DLC == 8))
  {
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
  }
  if ((RxHeader.StdId == 0x10) && (RxHeader.IDE == CAN_ID_STD) && (RxHeader.DLC == 8))
  {
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
  }
  if ((RxHeader.StdId == 0x100) && (RxHeader.IDE == CAN_ID_STD) && (RxHeader.DLC == 8))
  {
	  u8 mode = RxData[7];
	  crc_8_benchmark(mode);
  }
}

/*SAE-J1850 CRC-8校验*/
u8 crc8(u8 *raw_crc, u8 length) //SAE-J1850 CRC-8 function
{
  u8 t_crc;
  u8 f, b;
  t_crc = 0xFF;
  for (f = 0; f < length; f++)
  {
    t_crc ^= raw_crc[f];
    for (b = 0; b < 8; b++)
    {
      if ((t_crc & 0x80) != 0) //最高位为1，需要异或
      {
        t_crc <<= 1;
        t_crc ^= 0x1D;
      }
      else
      {
        t_crc <<= 1;
      }
    }
  }
  return ~t_crc; //按位非，相当于异或0xFF
}
/* USER CODE END 1 */

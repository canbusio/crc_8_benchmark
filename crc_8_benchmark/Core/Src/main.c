/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
#include "main.h"
#include "can.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM3_Init();
  MX_CAN_Init();
  /* USER CODE BEGIN 2 */
  if (HAL_CAN_Start(&hcan) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_CAN_ActivateNotification(&hcan, CAN_IT_RX_FIFO0_MSG_PENDING) != HAL_OK)
  {
    Error_Handler();
  }
  HAL_TIM_Base_Start_IT(&htim3);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
  while (1)
  {
	  if (TIM_Flag_10ms == 1)
	  {

		  if (TIM_Flag_1s == 1)
		  {
			  HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);

			  TIM_Flag_1s = 0;
		  }

		  TIM_Flag_10ms = 0;
	  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void crc_8_benchmark(u8 mode)
{
  u8 i=0;
  u8 j=0;
  RT_MODEL_crc_8_general_T crc_8_general_M;
  crc_8_general_initialize(&crc_8_general_M);
  RT_MODEL_crc_8_optimized_T crc_8_optimized_M;
  crc_8_optimized_initialize(&crc_8_optimized_M);
  u8 data[8];

  if(mode == 0)
  {
    data[0] = 0x0F;
    data[1] = 0xAA;
    data[2] = 0x00;
    data[3] = 0x55;
    data[4] = 0xFF;
    data[5] = 0xFF;
    data[6] = 0xFF;
    data[7] = 0xFF;

    //simulink_crc_8_general_checksum
    data[7] = crc_8_general_step(&crc_8_general_M,data[0],data[1],data[2],data[3]);
    CAN1_Send_Msg(0x101,data,8,0);

    //simulink_crc_8_optimized_checksum
    u8 k = 0;
    u8 in1[8]={data[0],data[1],data[2],data[3],data[4],data[5],data[6],data[7]};
    u8 in2[8]={1,0,0,0,0,0,0,0};
    u8 in3[8]={0,0,0,1,0,0,0,0};
    u8 in4[8]={1,1,1,1,0,0,0,0};
    u8 out;
    for(k=0;k<8;k++)
    {
      out = crc_8_optimized_step(&crc_8_optimized_M,in1[k],in2[k],in3[k],in4[k]);
      if(k==7) data[7]=out;
    }
    CAN1_Send_Msg(0x102,data,8,0);

    //manual_crc_8_bitwise_operation
    data[7]=crc8(data,4);
    CAN1_Send_Msg(0x103,data,8,0);
  }
  else if(mode <=3)
  {
		    /* crc_8_benchmark_start */
		    data[0] = RT_h;
		    data[1] = RT_m;
		    data[2] = RT_s;
		    data[3] = 0xFF;
		    data[4] = 0xFF;
		    data[5] = 0xFF;
		    data[6] = (u8)(TIM_Cnt<<8);
		    data[7] = (u8)(TIM_Cnt<<8>>8);
		    CAN1_Send_Msg(0x201,data,8,0);

		    //crc_8_j-1850_result_check

		    //simulink_crc_8_general
		    if(mode == 1)
		    {
		        for(i=0;i<100;i++)
		        {
		          for(j=0;j<100;j++)
		          {
		            data[0] = i;
		            data[1] = j;
		            data[2] = i;
		            data[3] = j;
		            crc_8_general_step(&crc_8_general_M,data[0],data[1],data[2],data[3]);
		          }
		        }
		    }

		    //simulink_crc_8_optimized
		    if(mode == 2)
		    {
		        for(i=0;i<100;i++)
		        {
		          for(j=0;j<100;j++)
		          {
		            data[0] = i;
		            data[1] = j;
		            data[2] = i;
		            data[3] = j;
		            u8 k = 0;
		            u8 in1[8]={data[0],data[1],data[2],data[3],data[4],data[5],data[6],data[7]};
		            u8 in2[8]={1,0,0,0,0,0,0,0};
		            u8 in3[8]={0,0,0,1,0,0,0,0};
		            u8 in4[8]={1,1,1,1,0,0,0,0};
		            u8 out;
		            for(k=0;k<8;k++)
		            {
		              crc_8_optimized_step(&crc_8_optimized_M,in1[k],in2[k],in3[k],in4[k]);
		            }
		          }
		        }
		    }

		    //manual_crc_8_bitwise_operation
		    if(mode == 3)
		    {
		        for(i=0;i<100;i++)
		        {
		          for(j=0;j<100;j++)
		          {
		            data[0] = i;
		            data[1] = j;
		            data[2] = i;
		            data[3] = j;
		            crc8(data,4);
		          }
		        }
		    }

		    data[0] = RT_h;
		    data[1] = RT_m;
		    data[2] = RT_s;
		    data[3] = 0xFF;
		    data[4] = 0xFF;
		    data[5] = 0xFF;
		    data[6] = (u8)(TIM_Cnt<<8);
		    data[7] = (u8)(TIM_Cnt<<8>>8);
		    CAN1_Send_Msg(0x202,data,8,0);
		    /* crc_8_benchmark_end */
  }
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

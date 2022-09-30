/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

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
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void display7SEG1 (int num){
	switch (num){
		case 0:
			HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, RESET);
			HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, RESET);
			HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, RESET);
			HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, RESET);
			HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, RESET);
			HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, RESET);
			HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, SET);
			break;
		case 1:
			HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, SET);
			HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, RESET);
			HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, RESET);
			HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, SET);
			HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, SET);
			HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, SET);
			HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, SET);
			break;
		case 2:
			HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, RESET);
			HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, RESET);
			HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, SET);
			HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, RESET);
			HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, RESET);
			HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, SET);
			HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, RESET);
			HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, RESET);
			HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, RESET);
			HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, RESET);
			HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, SET);
			HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, SET);
			HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, SET);
			HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, RESET);
			HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, RESET);
			HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, SET);
			HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, SET);
			HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, RESET);
			HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, RESET);
			HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, SET);
			HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, RESET);
			HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, RESET);
			HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, SET);
			HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, RESET);
			HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, RESET);
			break;
		default:
			break;
	}
}

void enableRed1 (void){
	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, GPIO_PIN_SET);
}

void enableYellow1 (void){
	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, GPIO_PIN_SET);
}

void enableGreen1 (void){
	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, GPIO_PIN_RESET);
}

void enableRed2 (void){
	HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_SET);
}

void enableYellow2 (void){
	HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_SET);
}

void enableGreen2 (void){
	HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_RESET);
}

static int setCounterRed (void){
	return 5;
}

static int setCounterYellow (void){
	return 2;
}

static int setCounterGreen (void){
	return 3;
}

int enableTerm_Green2 (int value){
	if (value >=3) return 1;
	return 0;
}

int enableTerm_Yellow2 (int value){
	if (value <= 2) return 1;
	return 0;
}
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
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  enum displayState {state0, state1, state2};
  enum displayState status = state0;

  // For West-East Direction:
  // status = 0 -> Red1:on, Yellow1: off, Green1: off
  // status = 1 -> Red1:off, Yellow1: off, Green1: on
  // status = 2 -> Red1:off, Yellow1: on, Green1: off

  // For North-South Direction:
  // status = 0 -> Red2:off, Green2: on(3s) -> Yellow2: on(2s),
  // status = 1 -> Red2:on, Yellow2: off, Green2: off
  // status = 2 -> Red2:on, Yellow2: off, Green2: off

  static int counterRED = 5;
  static int counterYellow = 2;
  static int counterGreen = 3;

  const int threshold = 0;
  while (1)
  {
	  switch (status){
			case state0:
				{
					//West-East Direction
					enableRed1();

					// Countdown number for W-E when red led on is the same as counterRED
					int temp1 = counterRED;
					display7SEG1(temp1);

					if (enableTerm_Green2(counterRED)==1){
						//North-South Direction
						enableGreen2();
					}

					if (enableTerm_Yellow2(counterRED)==1){
						//North-South Direction
						enableYellow2();
					}

					counterRED--;
					if (counterRED == threshold){
						counterRED = setCounterRed();
						status = state1;
					}
				}
				break;

			case state1:
				{
					//West-East Direction
					enableGreen1();

					//Countdown number in W-E when green led on is same as counterGreen
					int temp2 = counterGreen;
					display7SEG1(temp2);

					//North-South Direction
					enableRed2();

					counterGreen--;
					if (counterGreen == threshold){
						counterGreen = setCounterGreen();
						status = state2;
					}
				}
				break;

			case state2:
				{
					//West-East Direction
					enableYellow1();

					//Countdown number for W-E when yellow led on is same as counterYellow
					int temp3 = counterYellow;
					display7SEG1(temp3);

					//North-South Direction
					enableRed2();

					counterYellow--;
					if (counterYellow == threshold){
						counterYellow = setCounterYellow();
						status = state0;
					}
				}
				break;
			default:
				break;
	  }
	  HAL_Delay(1000);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin|LED_YELLOW_1_Pin|LED_GREEN_1_Pin|LED_RED_2_Pin
                          |LED_YELLOW_2_Pin|LED_GREEN_2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, a_Pin|b_Pin|c_Pin|d_Pin
                          |e_Pin|f_Pin|g_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_RED_1_Pin LED_YELLOW_1_Pin LED_GREEN_1_Pin LED_RED_2_Pin
                           LED_YELLOW_2_Pin LED_GREEN_2_Pin */
  GPIO_InitStruct.Pin = LED_RED_1_Pin|LED_YELLOW_1_Pin|LED_GREEN_1_Pin|LED_RED_2_Pin
                          |LED_YELLOW_2_Pin|LED_GREEN_2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : a_Pin b_Pin c_Pin d_Pin
                           e_Pin f_Pin g_Pin */
  GPIO_InitStruct.Pin = a_Pin|b_Pin|c_Pin|d_Pin
                          |e_Pin|f_Pin|g_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f3xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define COMPB_NEG_Pin GPIO_PIN_2
#define COMPB_NEG_GPIO_Port GPIOA
#define COMPB_Pin GPIO_PIN_3
#define COMPB_GPIO_Port GPIOA
#define ADCA_Pin GPIO_PIN_4
#define ADCA_GPIO_Port GPIOA
#define ADCB_Pin GPIO_PIN_5
#define ADCB_GPIO_Port GPIOA
#define ADCC_Pin GPIO_PIN_6
#define ADCC_GPIO_Port GPIOA
#define LOW_A_Pin GPIO_PIN_10
#define LOW_A_GPIO_Port GPIOE
#define LOW_B_Pin GPIO_PIN_11
#define LOW_B_GPIO_Port GPIOE
#define LOW_C_Pin GPIO_PIN_12
#define LOW_C_GPIO_Port GPIOE
#define HIGH_B_Pin GPIO_PIN_10
#define HIGH_B_GPIO_Port GPIOB
#define COMPC_NEG_Pin GPIO_PIN_12
#define COMPC_NEG_GPIO_Port GPIOB
#define COMPC_Pin GPIO_PIN_14
#define COMPC_GPIO_Port GPIOB
#define HIGH_A_Pin GPIO_PIN_15
#define HIGH_A_GPIO_Port GPIOA
#define HIGH_C_Pin GPIO_PIN_4
#define HIGH_C_GPIO_Port GPIOD
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

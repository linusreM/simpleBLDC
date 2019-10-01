/**
  ******************************************************************************
  * File Name          : COMP.c
  * Description        : This file provides code for the configuration
  *                      of the COMP instances.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "comp.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

COMP_HandleTypeDef hcomp2;
COMP_HandleTypeDef hcomp3;
COMP_HandleTypeDef hcomp4;

/* COMP2 init function */
void MX_COMP2_Init(void)
{

  hcomp2.Instance = COMP2;
  hcomp2.Init.InvertingInput = COMP_INVERTINGINPUT_IO1;
  hcomp2.Init.NonInvertingInput = COMP_NONINVERTINGINPUT_IO2;
  hcomp2.Init.Output = COMP_OUTPUT_NONE;
  hcomp2.Init.OutputPol = COMP_OUTPUTPOL_INVERTED;
  hcomp2.Init.Hysteresis = COMP_HYSTERESIS_NONE;
  hcomp2.Init.BlankingSrce = COMP_BLANKINGSRCE_NONE;
  hcomp2.Init.Mode = COMP_MODE_MEDIUMSPEED;
  hcomp2.Init.WindowMode = COMP_WINDOWMODE_DISABLE;
  hcomp2.Init.TriggerMode = COMP_TRIGGERMODE_IT_RISING_FALLING;
  if (HAL_COMP_Init(&hcomp2) != HAL_OK)
  {
    Error_Handler();
  }

}
/* COMP3 init function */
void MX_COMP3_Init(void)
{

  hcomp3.Instance = COMP3;
  hcomp3.Init.InvertingInput = COMP_INVERTINGINPUT_IO2;
  hcomp3.Init.NonInvertingInput = COMP_NONINVERTINGINPUT_IO1;
  hcomp3.Init.Output = COMP_OUTPUT_NONE;
  hcomp3.Init.OutputPol = COMP_OUTPUTPOL_INVERTED;
  hcomp3.Init.Hysteresis = COMP_HYSTERESIS_NONE;
  hcomp3.Init.BlankingSrce = COMP_BLANKINGSRCE_NONE;
  hcomp3.Init.Mode = COMP_MODE_MEDIUMSPEED;
  hcomp3.Init.WindowMode = COMP_WINDOWMODE_DISABLE;
  hcomp3.Init.TriggerMode = COMP_TRIGGERMODE_IT_RISING_FALLING;
  if (HAL_COMP_Init(&hcomp3) != HAL_OK)
  {
    Error_Handler();
  }

}
/* COMP4 init function */
void MX_COMP4_Init(void)
{

  hcomp4.Instance = COMP4;
  hcomp4.Init.InvertingInput = COMP_INVERTINGINPUT_IO2;
  hcomp4.Init.NonInvertingInput = COMP_NONINVERTINGINPUT_IO1;
  hcomp4.Init.Output = COMP_OUTPUT_NONE;
  hcomp4.Init.OutputPol = COMP_OUTPUTPOL_INVERTED;
  hcomp4.Init.Hysteresis = COMP_HYSTERESIS_NONE;
  hcomp4.Init.BlankingSrce = COMP_BLANKINGSRCE_NONE;
  hcomp4.Init.Mode = COMP_MODE_MEDIUMSPEED;
  hcomp4.Init.WindowMode = COMP_WINDOWMODE_DISABLE;
  hcomp4.Init.TriggerMode = COMP_TRIGGERMODE_IT_RISING_FALLING;
  if (HAL_COMP_Init(&hcomp4) != HAL_OK)
  {
    Error_Handler();
  }

}

void HAL_COMP_MspInit(COMP_HandleTypeDef* compHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(compHandle->Instance==COMP2)
  {
  /* USER CODE BEGIN COMP2_MspInit 0 */

  /* USER CODE END COMP2_MspInit 0 */
  
    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**COMP2 GPIO Configuration    
    PA2     ------> COMP2_INM
    PA3     ------> COMP2_INP 
    */
    GPIO_InitStruct.Pin = COMPB_NEG_Pin|COMPB_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* COMP2 interrupt Init */
    HAL_NVIC_SetPriority(COMP1_2_3_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(COMP1_2_3_IRQn);
  /* USER CODE BEGIN COMP2_MspInit 1 */

  /* USER CODE END COMP2_MspInit 1 */
  }
  else if(compHandle->Instance==COMP3)
  {
  /* USER CODE BEGIN COMP3_MspInit 0 */

  /* USER CODE END COMP3_MspInit 0 */
  
    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**COMP3 GPIO Configuration    
    PB12     ------> COMP3_INM
    PB14     ------> COMP3_INP 
    */
    GPIO_InitStruct.Pin = COMPC_NEG_Pin|COMPC_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* COMP3 interrupt Init */
    HAL_NVIC_SetPriority(COMP1_2_3_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(COMP1_2_3_IRQn);
  /* USER CODE BEGIN COMP3_MspInit 1 */

  /* USER CODE END COMP3_MspInit 1 */
  }
  else if(compHandle->Instance==COMP4)
  {
  /* USER CODE BEGIN COMP4_MspInit 0 */

  /* USER CODE END COMP4_MspInit 0 */
  
    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**COMP4 GPIO Configuration    
    PB0     ------> COMP4_INP
    PB2     ------> COMP4_INM 
    */
    GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* COMP4 interrupt Init */
    HAL_NVIC_SetPriority(COMP4_5_6_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(COMP4_5_6_IRQn);
  /* USER CODE BEGIN COMP4_MspInit 1 */

  /* USER CODE END COMP4_MspInit 1 */
  }
}

void HAL_COMP_MspDeInit(COMP_HandleTypeDef* compHandle)
{

  if(compHandle->Instance==COMP2)
  {
  /* USER CODE BEGIN COMP2_MspDeInit 0 */

  /* USER CODE END COMP2_MspDeInit 0 */
  
    /**COMP2 GPIO Configuration    
    PA2     ------> COMP2_INM
    PA3     ------> COMP2_INP 
    */
    HAL_GPIO_DeInit(GPIOA, COMPB_NEG_Pin|COMPB_Pin);

    /* COMP2 interrupt Deinit */
  /* USER CODE BEGIN COMP2:COMP1_2_3_IRQn disable */
    /**
    * Uncomment the line below to disable the "COMP1_2_3_IRQn" interrupt
    * Be aware, disabling shared interrupt may affect other IPs
    */
    /* HAL_NVIC_DisableIRQ(COMP1_2_3_IRQn); */
  /* USER CODE END COMP2:COMP1_2_3_IRQn disable */

  /* USER CODE BEGIN COMP2_MspDeInit 1 */

  /* USER CODE END COMP2_MspDeInit 1 */
  }
  else if(compHandle->Instance==COMP3)
  {
  /* USER CODE BEGIN COMP3_MspDeInit 0 */

  /* USER CODE END COMP3_MspDeInit 0 */
  
    /**COMP3 GPIO Configuration    
    PB12     ------> COMP3_INM
    PB14     ------> COMP3_INP 
    */
    HAL_GPIO_DeInit(GPIOB, COMPC_NEG_Pin|COMPC_Pin);

    /* COMP3 interrupt Deinit */
  /* USER CODE BEGIN COMP3:COMP1_2_3_IRQn disable */
    /**
    * Uncomment the line below to disable the "COMP1_2_3_IRQn" interrupt
    * Be aware, disabling shared interrupt may affect other IPs
    */
    /* HAL_NVIC_DisableIRQ(COMP1_2_3_IRQn); */
  /* USER CODE END COMP3:COMP1_2_3_IRQn disable */

  /* USER CODE BEGIN COMP3_MspDeInit 1 */

  /* USER CODE END COMP3_MspDeInit 1 */
  }
  else if(compHandle->Instance==COMP4)
  {
  /* USER CODE BEGIN COMP4_MspDeInit 0 */

  /* USER CODE END COMP4_MspDeInit 0 */
  
    /**COMP4 GPIO Configuration    
    PB0     ------> COMP4_INP
    PB2     ------> COMP4_INM 
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_0|GPIO_PIN_2);

    /* COMP4 interrupt Deinit */
    HAL_NVIC_DisableIRQ(COMP4_5_6_IRQn);
  /* USER CODE BEGIN COMP4_MspDeInit 1 */

  /* USER CODE END COMP4_MspDeInit 1 */
  }
} 

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

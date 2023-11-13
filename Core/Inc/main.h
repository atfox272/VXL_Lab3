/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

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
#define RED_2_Pin GPIO_PIN_2
#define RED_2_GPIO_Port GPIOA
#define YEL_2_Pin GPIO_PIN_3
#define YEL_2_GPIO_Port GPIOA
#define GRE_2_Pin GPIO_PIN_4
#define GRE_2_GPIO_Port GPIOA
#define RED_1_Pin GPIO_PIN_5
#define RED_1_GPIO_Port GPIOA
#define YEL_1_Pin GPIO_PIN_6
#define YEL_1_GPIO_Port GPIOA
#define GRE_1_Pin GPIO_PIN_7
#define GRE_1_GPIO_Port GPIOA
#define SSEG_0_Pin GPIO_PIN_0
#define SSEG_0_GPIO_Port GPIOB
#define SSEG_1_Pin GPIO_PIN_1
#define SSEG_1_GPIO_Port GPIOB
#define SSEG_2_Pin GPIO_PIN_2
#define SSEG_2_GPIO_Port GPIOB
#define S2_Pin GPIO_PIN_8
#define S2_GPIO_Port GPIOA
#define S3_Pin GPIO_PIN_9
#define S3_GPIO_Port GPIOA
#define S4_Pin GPIO_PIN_10
#define S4_GPIO_Port GPIOA
#define S5_Pin GPIO_PIN_11
#define S5_GPIO_Port GPIOA
#define S6_Pin GPIO_PIN_12
#define S6_GPIO_Port GPIOA
#define S7_Pin GPIO_PIN_13
#define S7_GPIO_Port GPIOA
#define SSEG_3_Pin GPIO_PIN_3
#define SSEG_3_GPIO_Port GPIOB
#define BUTTON_0_Pin GPIO_PIN_4
#define BUTTON_0_GPIO_Port GPIOB
#define BUTTON_1_Pin GPIO_PIN_5
#define BUTTON_1_GPIO_Port GPIOB
#define BUTTON_2_Pin GPIO_PIN_6
#define BUTTON_2_GPIO_Port GPIOB
#define S1_Pin GPIO_PIN_7
#define S1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

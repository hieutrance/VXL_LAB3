/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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
#define MODE_BUTTON_Pin GPIO_PIN_2
#define MODE_BUTTON_GPIO_Port GPIOA
#define MODIFY_BUTTON_Pin GPIO_PIN_3
#define MODIFY_BUTTON_GPIO_Port GPIOA
#define SET_BUTTON_Pin GPIO_PIN_4
#define SET_BUTTON_GPIO_Port GPIOA
#define RED_13_Pin GPIO_PIN_5
#define RED_13_GPIO_Port GPIOA
#define YELLOW_13_Pin GPIO_PIN_6
#define YELLOW_13_GPIO_Port GPIOA
#define GREEN_13_Pin GPIO_PIN_7
#define GREEN_13_GPIO_Port GPIOA
#define a_Pin GPIO_PIN_0
#define a_GPIO_Port GPIOB
#define b_Pin GPIO_PIN_1
#define b_GPIO_Port GPIOB
#define c_Pin GPIO_PIN_2
#define c_GPIO_Port GPIOB
#define en4_Pin GPIO_PIN_10
#define en4_GPIO_Port GPIOB
#define RED_24_Pin GPIO_PIN_8
#define RED_24_GPIO_Port GPIOA
#define YELLOW_24_Pin GPIO_PIN_9
#define YELLOW_24_GPIO_Port GPIOA
#define GREEN_24_Pin GPIO_PIN_10
#define GREEN_24_GPIO_Port GPIOA
#define d_Pin GPIO_PIN_3
#define d_GPIO_Port GPIOB
#define e_Pin GPIO_PIN_4
#define e_GPIO_Port GPIOB
#define f_Pin GPIO_PIN_5
#define f_GPIO_Port GPIOB
#define g_Pin GPIO_PIN_6
#define g_GPIO_Port GPIOB
#define en1_Pin GPIO_PIN_7
#define en1_GPIO_Port GPIOB
#define en2_Pin GPIO_PIN_8
#define en2_GPIO_Port GPIOB
#define en3_Pin GPIO_PIN_9
#define en3_GPIO_Port GPIOB

void turnoff_red();
void turnoff_yellow();
void turnoff_green();

/* USER CODE BEGIN Private defines */



/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

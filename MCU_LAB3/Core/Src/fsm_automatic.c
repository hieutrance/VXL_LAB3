/*
 * fsm_automatic.c
 *
 *  Created on: Nov 16, 2024
 *      Author: trung
 */

#include "fsm_automatic.h"

void fsm_automatic(){
	switch(status){
	case INIT:
		HAL_GPIO_WritePin(RED_13_GPIO_Port , RED_13_Pin , GPIO_PIN_RESET);
		HAL_GPIO_WritePin(YELLOW_13_GPIO_Port , YELLOW_13_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_13_GPIO_Port , GREEN_13_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(RED_24_GPIO_Port , RED_24_Pin , GPIO_PIN_RESET);
		HAL_GPIO_WritePin(YELLOW_24_GPIO_Port , YELLOW_24_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_24_GPIO_Port , GREEN_24_Pin , GPIO_PIN_SET);
		HAL_Delay(100);
		HAL_GPIO_WritePin(RED_13_GPIO_Port , RED_13_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(YELLOW_13_GPIO_Port , YELLOW_13_Pin , GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GREEN_13_GPIO_Port , GREEN_13_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(RED_24_GPIO_Port , RED_24_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(YELLOW_24_GPIO_Port , YELLOW_24_Pin , GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GREEN_24_GPIO_Port , GREEN_24_Pin , GPIO_PIN_SET);
		HAL_Delay(100);
		HAL_GPIO_WritePin(RED_13_GPIO_Port , RED_13_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(YELLOW_13_GPIO_Port , YELLOW_13_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_13_GPIO_Port , GREEN_13_Pin , GPIO_PIN_RESET);
		HAL_GPIO_WritePin(RED_24_GPIO_Port , RED_24_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(YELLOW_24_GPIO_Port , YELLOW_24_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_24_GPIO_Port , GREEN_24_Pin , GPIO_PIN_RESET);
		HAL_Delay(100);
		HAL_GPIO_WritePin(RED_13_GPIO_Port , RED_13_Pin , GPIO_PIN_RESET);
		HAL_GPIO_WritePin(YELLOW_13_GPIO_Port , YELLOW_13_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_13_GPIO_Port , GREEN_13_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(RED_24_GPIO_Port , RED_24_Pin , GPIO_PIN_RESET);
		HAL_GPIO_WritePin(YELLOW_24_GPIO_Port , YELLOW_24_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_24_GPIO_Port , GREEN_24_Pin , GPIO_PIN_SET);
		HAL_Delay(100);
		HAL_GPIO_WritePin(RED_13_GPIO_Port , RED_13_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(YELLOW_13_GPIO_Port , YELLOW_13_Pin , GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GREEN_13_GPIO_Port , GREEN_13_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(RED_24_GPIO_Port , RED_24_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(YELLOW_24_GPIO_Port , YELLOW_24_Pin , GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GREEN_24_GPIO_Port , GREEN_24_Pin , GPIO_PIN_SET);
		HAL_Delay(100);
		HAL_GPIO_WritePin(RED_13_GPIO_Port , RED_13_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(YELLOW_13_GPIO_Port , YELLOW_13_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_13_GPIO_Port , GREEN_13_Pin , GPIO_PIN_RESET);
		HAL_GPIO_WritePin(RED_24_GPIO_Port , RED_24_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(YELLOW_24_GPIO_Port , YELLOW_24_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_24_GPIO_Port , GREEN_24_Pin , GPIO_PIN_RESET);
		HAL_Delay(100);

		status = RED13_GREEN24;
		setTimer(1 , 3000);
		break;
	case RED13_GREEN24:
		//set cho lane 13
		HAL_GPIO_WritePin(RED_13_GPIO_Port , RED_13_Pin , GPIO_PIN_RESET);
		HAL_GPIO_WritePin(YELLOW_13_GPIO_Port , YELLOW_13_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_13_GPIO_Port , GREEN_13_Pin , GPIO_PIN_SET);
		//set cho lane 24
		HAL_GPIO_WritePin(RED_24_GPIO_Port , RED_24_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(YELLOW_24_GPIO_Port , YELLOW_24_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_24_GPIO_Port , GREEN_24_Pin , GPIO_PIN_RESET);

		if(isTimerFlagSet(1) == 1){
			status = RED13_YELLOW24;
			setTimer(1 , 2000);
		}
		if(isButtonPressed(MODE_BUTTON)==1){
			status = MODIFY_RED;
			setTimer(1 , 500);
			turnoff_red();
			turnoff_yellow();
			turnoff_green();
		}
		break;
	case RED13_YELLOW24:
		//set cho lane 13
		HAL_GPIO_WritePin(RED_13_GPIO_Port , RED_13_Pin , GPIO_PIN_RESET);
		HAL_GPIO_WritePin(YELLOW_13_GPIO_Port , YELLOW_13_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_13_GPIO_Port , GREEN_13_Pin , GPIO_PIN_SET);
		//set cho lane 24
		HAL_GPIO_WritePin(RED_24_GPIO_Port , RED_24_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(YELLOW_24_GPIO_Port , YELLOW_24_Pin , GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GREEN_24_GPIO_Port , GREEN_24_Pin , GPIO_PIN_SET);

		if(isTimerFlagSet(1) == 1){
			status = GREEN13_RED24;
			setTimer(1 , 3000);
		}
		if(isButtonPressed(MODE_BUTTON)==1){
			status = MODIFY_RED;
			setTimer(1 , 500);
			turnoff_red();
			turnoff_yellow();
			turnoff_green();
		}
		break;
	case GREEN13_RED24:
		//set cho lane 13
		HAL_GPIO_WritePin(RED_13_GPIO_Port , RED_13_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(YELLOW_13_GPIO_Port , YELLOW_13_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_13_GPIO_Port , GREEN_13_Pin , GPIO_PIN_RESET);
		//set cho lane 24
		HAL_GPIO_WritePin(RED_24_GPIO_Port , RED_24_Pin , GPIO_PIN_RESET);
		HAL_GPIO_WritePin(YELLOW_24_GPIO_Port , YELLOW_24_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_24_GPIO_Port , GREEN_24_Pin , GPIO_PIN_SET);

		if(isTimerFlagSet(1) == 1){
			status = YELLOW13_RED24;
			setTimer(1 , 2000);
		}
		if(isButtonPressed(MODE_BUTTON)==1){
			status = MODIFY_RED;
			setTimer(1 , 500);
			turnoff_red();
			turnoff_yellow();
			turnoff_green();
		}
		break;
	case YELLOW13_RED24:
		//set cho lane 13
		HAL_GPIO_WritePin(RED_13_GPIO_Port , RED_13_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(YELLOW_13_GPIO_Port , YELLOW_13_Pin , GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GREEN_13_GPIO_Port , GREEN_13_Pin , GPIO_PIN_SET);
		//set cho lane 24
		HAL_GPIO_WritePin(RED_24_GPIO_Port , RED_24_Pin , GPIO_PIN_RESET);
		HAL_GPIO_WritePin(YELLOW_24_GPIO_Port , YELLOW_24_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_24_GPIO_Port , GREEN_24_Pin , GPIO_PIN_SET);

		if(isTimerFlagSet(1) == 1){
			status = RED13_GREEN24;
			setTimer(1 , 3000);
		}
		if(isButtonPressed(MODE_BUTTON)==1){
			status = MODIFY_RED;
			setTimer(1 , 500);
			turnoff_red();
			turnoff_yellow();
			turnoff_green();
		}
		break;
	default:
		break;
	}
}

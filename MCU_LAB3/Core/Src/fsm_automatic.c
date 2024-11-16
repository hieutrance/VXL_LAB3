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
		//TODO

		//CHANGE STATUS
		status = AUTO_RED;
		setTimer(1 , 5000);
		break;
	case AUTO_RED:
		HAL_GPIO_WritePin(RED_13_GPIO_Port , RED_13_Pin , GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GREEN_13_GPIO_Port , GREEN_13_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(YELLOW_13_GPIO_Port , YELLOW_13_Pin , GPIO_PIN_SET);

		if(isTimerFlagSet(1) == 1){
			status = AUTO_GREEN;
			setTimer(1 , 3000);
		}
		break;
	case AUTO_GREEN:
		HAL_GPIO_WritePin(RED_13_GPIO_Port , RED_13_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_13_GPIO_Port , GREEN_13_Pin , GPIO_PIN_RESET);
		HAL_GPIO_WritePin(YELLOW_13_GPIO_Port , YELLOW_13_Pin , GPIO_PIN_SET);

		if(isTimerFlagSet(1) == 1){
			status = AUTO_YELLOW;
			setTimer(1 , 2000);
		}
		break;
	case AUTO_YELLOW:
		HAL_GPIO_WritePin(RED_13_GPIO_Port , RED_13_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_13_GPIO_Port , GREEN_13_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(YELLOW_13_GPIO_Port , YELLOW_13_Pin , GPIO_PIN_RESET);

		if(isTimerFlagSet(1) == 1){
			status = AUTO_RED;
			setTimer(1 , 5000);
		}
		break;
	default:
		break;
	}

}

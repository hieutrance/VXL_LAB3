/*
 * fsm_automatic.c
 *
 *  Created on: Nov 16, 2024
 *      Author: trung
 */

#include "fsm_automatic.h"
#include "software_timer.h"
int led_index;

void fsm_automatic(){
	switch(status){
	case INIT:
		status = RED13_GREEN24;
		led_index = 0;
		setTimer(1 , timeGreen*1000);
		timer_flag[2] = 1;
		timer_flag[3] = 1;
		updateBufer();
		break;
////////////////////////////////////////////////
	case RED13_GREEN24:
		updateTimeForState(status);
		//set cho lane 13
		HAL_GPIO_WritePin(RED_13_GPIO_Port , RED_13_Pin , GPIO_PIN_RESET);
		HAL_GPIO_WritePin(YELLOW_13_GPIO_Port , YELLOW_13_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_13_GPIO_Port , GREEN_13_Pin , GPIO_PIN_SET);
		//set cho lane 24
		HAL_GPIO_WritePin(RED_24_GPIO_Port , RED_24_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(YELLOW_24_GPIO_Port , YELLOW_24_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_24_GPIO_Port , GREEN_24_Pin , GPIO_PIN_RESET);

		if(isTimerFlagSet(1)){
			time13remain = time13;
			status = RED13_YELLOW24;
			setTimer(1 , timeYellow*1000);
		}
		if(isTimerFlagSet(2)){
			update7SegLed(led_index);
			setTimer(2 , 250);
			led_index++;
			if(led_index >= 4){
				led_index = 0;
			}
		}
		if(isTimerFlagSet(3)){
			time13--;
			time24--;
			updateBufer();
			updateTimeForState(status);
			setTimer(3 , 1000);
		}

		if(isButtonPressed(MODE_BUTTON)==1){
			status = MODIFY_RED;
			setTimer(1 , 500);
			led_index = 0;
			timer_flag[2] = 1;

			turnOffAll7Seg();
			turnoff_red();
			turnoff_yellow();
			turnoff_green();
		}
		break;
//////////////////////////////////////////////
	case RED13_YELLOW24:
		updateTimeForState(status);
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
			setTimer(1 , timeGreen*1000);
		}
		if(isTimerFlagSet(2)){
			update7SegLed(led_index);
			setTimer(2 , 250);
			led_index++;
			if(led_index >= 4){
				led_index = 0;
			}
		}
		if(isTimerFlagSet(3)){
			time13--;
			time24--;
			updateBufer();
			updateTimeForState(status);
			setTimer(3 , 1000);
		}
		if(isButtonPressed(MODE_BUTTON)==1){
			status = MODIFY_RED;
			setTimer(1 , 500);

			turnOffAll7Seg();
			turnoff_red();
			turnoff_yellow();
			turnoff_green();
		}
		break;
/////////////////////////////////////////////////
	case GREEN13_RED24:
		updateTimeForState(status);
		//set cho lane 13
		HAL_GPIO_WritePin(RED_13_GPIO_Port , RED_13_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(YELLOW_13_GPIO_Port , YELLOW_13_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_13_GPIO_Port , GREEN_13_Pin , GPIO_PIN_RESET);
		//set cho lane 24
		HAL_GPIO_WritePin(RED_24_GPIO_Port , RED_24_Pin , GPIO_PIN_RESET);
		HAL_GPIO_WritePin(YELLOW_24_GPIO_Port , YELLOW_24_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_24_GPIO_Port , GREEN_24_Pin , GPIO_PIN_SET);

		if(isTimerFlagSet(1) == 1){
			time24remain = time24;
			status = YELLOW13_RED24;
			setTimer(1 , timeYellow*1000);
		}
		if(isTimerFlagSet(2)){
			update7SegLed(led_index);
			setTimer(2 , 250);
			led_index++;
			if(led_index >= 4){
				led_index = 0;
			}
		}
		if(isTimerFlagSet(3)){
			time13--;
			time24--;
			updateBufer();
			updateTimeForState(status);
			setTimer(3 , 1000);
		}
		if(isButtonPressed(MODE_BUTTON)==1){
			status = MODIFY_RED;
			setTimer(1 , 500);
			turnOffAll7Seg();
			turnoff_red();
			turnoff_yellow();
			turnoff_green();
		}
		break;
///////////////////////////////////////////////////
	case YELLOW13_RED24:
		updateTimeForState(status);
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
			setTimer(1 , timeGreen*1000);
		}
		if(isTimerFlagSet(2)){
			update7SegLed(led_index);
			setTimer(2 , 250);
			led_index++;
			if(led_index >= 4){
				led_index = 0;
			}
		}
		if(isTimerFlagSet(3)){
			time13--;
			time24--;
			updateBufer();
			updateTimeForState(status);
			setTimer(3 , 1000);
		}
		if(isButtonPressed(MODE_BUTTON)==1){
			status = MODIFY_RED;
			setTimer(1 , 500);
			turnOffAll7Seg();
			turnoff_red();
			turnoff_yellow();
			turnoff_green();
		}
		break;
	default:
		break;
	}
}

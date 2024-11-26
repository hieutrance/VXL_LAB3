/*
 * fsm_manual.c
 *
 *  Created on: Nov 17, 2024
 *      Author: trung
 */
#include "fsm_manual.h"
#include "fsm_automatic.h"

int led_index = 0;
void fsm_manual(){
	switch(status){
/////////////////////////////////////////////////////////////
	case MODIFY_RED:
		if(isTimerFlagSet(1)==1){
			HAL_GPIO_TogglePin(RED_13_GPIO_Port , RED_13_Pin);
			HAL_GPIO_TogglePin(RED_24_GPIO_Port , RED_24_Pin);
			setTimer(1 , 500);
		}

		if(isTimerFlagSet(2)){
			setTimer(2 , 250);
			update7SegLed(led_index);
			led_index++;
			if(led_index >= 4){
				led_index = 0;
			}
		}

		if(isButtonPressed(MODE_BUTTON)==1){
			turnoff_red();
			status = MODIFY_YELLOW;
			setTimer(1 , 500);
		}

		break;
/////////////////////////////////////////////////////////////
	case MODIFY_YELLOW:
		if(isTimerFlagSet(1)==1){
			HAL_GPIO_TogglePin(YELLOW_13_GPIO_Port , YELLOW_13_Pin);
			HAL_GPIO_TogglePin(YELLOW_24_GPIO_Port , YELLOW_24_Pin);
			setTimer(1 , 500);
		}

		if(isTimerFlagSet(2)){
			setTimer(2 , 250);
			update7SegLed(led_index);
			led_index++;
			if(led_index >= 4){
				led_index = 0;
			}
		}

		if(isButtonPressed(MODE_BUTTON)==1){
			turnoff_yellow();
			status = MODIFY_GREEN;
			setTimer(1 , 500);
		}


		break;
/////////////////////////////////////////////////////////////
	case MODIFY_GREEN:
		if(isTimerFlagSet(1)==1){
			HAL_GPIO_TogglePin(GREEN_13_GPIO_Port , GREEN_13_Pin);
			HAL_GPIO_TogglePin(GREEN_24_GPIO_Port , GREEN_24_Pin);
			setTimer(1 , 500);
		}

		if(isTimerFlagSet(2)){
			setTimer(2 , 250);
			update7SegLed(led_index);
			led_index++;
			if(led_index >= 4){
				led_index = 0;
			}
		}

		if(isButtonPressed(MODE_BUTTON)==1){
			turnoff_green();
			status = RED13_GREEN24;
			setTimer(1 , 3000);
		}
		break;
	default:
		break;
	}
}

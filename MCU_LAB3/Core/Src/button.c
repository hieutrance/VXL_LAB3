/*
 * button.c
 *
 *  Created on: Nov 13, 2024
 *      Author: trung
 */

#include "button.h"

#define NUM_OF_BUTTONS 3

#define MODE_BUTTON     0
#define MODIFY_BUTTON   1
#define SET_BUTTON      2

int KeyReg0[NUM_OF_BUTTONS] = {NORMAL_STATE};
int KeyReg1[NUM_OF_BUTTONS] = {NORMAL_STATE};
int KeyReg2[NUM_OF_BUTTONS] = {NORMAL_STATE};
int KeyReg3[NUM_OF_BUTTONS] = {NORMAL_STATE};


int TimerForKeyPress[NUM_OF_BUTTONS] = {200, 200, 200};

int Pressed_flag[NUM_OF_BUTTONS] = {0};
int LongPressed_flag[NUM_OF_BUTTONS] = {0};

int isButtonPressed(int num){
	if(Pressed_flag[num] == 1){
		Pressed_flag[num] = 0;
		return 1;
	}
	return 0;
}

int isButtonLongPressed(int num){
	if(LongPressed_flag[num] == 1){
		LongPressed_flag[num] = 0;
		return 1;
	}
	return 0;
}

void getKeyInput() {
    for (int i = 0; i < NUM_OF_BUTTONS; i++) {
        KeyReg0[i] = KeyReg1[i];
        KeyReg1[i] = KeyReg2[i];

        if (i == MODE_BUTTON) {
            KeyReg2[i] = HAL_GPIO_ReadPin(MODE_BUTTON_GPIO_Port, MODE_BUTTON_Pin);
        } else if (i == MODIFY_BUTTON) {
            KeyReg2[i] = HAL_GPIO_ReadPin(MODIFY_BUTTON_GPIO_Port, MODIFY_BUTTON_Pin);
        } else if (i == SET_BUTTON) {
            KeyReg2[i] = HAL_GPIO_ReadPin(SET_BUTTON_GPIO_Port, SET_BUTTON_Pin);
        }

        if ((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i])) {
            if (KeyReg2[i] == PRESSED_STATE) {
                if (KeyReg3[i] != PRESSED_STATE) { // Phát hiện nhấn ngắn
                    Pressed_flag[i] = 1;
                    KeyReg3[i] = PRESSED_STATE;
                    TimerForKeyPress[i] = 200;
                } else { // Xử lý nhấn giữ
                    TimerForKeyPress[i]--;
                    if (TimerForKeyPress[i] == 0) {
                        LongPressed_flag[i] = 1;
                        TimerForKeyPress[i] = 200;
                    }
                }
            } else { // Nút không được nhấn
                KeyReg3[i] = NORMAL_STATE;
                TimerForKeyPress[i] = 200; // Reset bộ đếm
            }
        }
    }
}


//void getKeyInput() {
//	for (int i = 0; i < NUM_OF_BUTTONS; i++) {
//
//		KeyReg0[i] = KeyReg1[i];
//		KeyReg1[i] = KeyReg2[i];
//
//		if (i == MODE_BUTTON) {
//			KeyReg2[i] = HAL_GPIO_ReadPin(MODE_BUTTON_GPIO_Port, MODE_BUTTON_Pin);
//		} else if (i == MODIFY_BUTTON) {
//			KeyReg2[i] = HAL_GPIO_ReadPin(MODIFY_BUTTON_GPIO_Port, MODIFY_BUTTON_Pin);
//		} else if (i == SET_BUTTON) {
//			KeyReg2[i] = HAL_GPIO_ReadPin(SET_BUTTON_GPIO_Port, SET_BUTTON_Pin);
//		}
//
//		if ((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i])) {
//			if (KeyReg3[i] != KeyReg2[i]) {
//				KeyReg3[i] = KeyReg2[i];
//				if (KeyReg2[i] == PRESSED_STATE){
//					Pressed_flag[i] = 1; /////
//					TimerForKeyPress[i] = 200;
//				}
//			} else if (KeyReg2[i] == PRESSED_STATE){
//				TimerForKeyPress[i]--;
//				if (TimerForKeyPress[i] == 0) {
//					LongPressed_flag[i] = 1;
//					TimerForKeyPress[i] = 200; // Reset lại bộ đếm để xử lý nhấn giữ
//				}
//			}
//		}
//	}
//}



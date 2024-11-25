/*
 * button.h
 *
 *  Created on: Nov 13, 2024
 *      Author: trung
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

#define NUM_OF_BUTTONS 3

#define MODE_BUTTON     0
#define MODIFY_BUTTON   1
#define SET_BUTTON      2


void getKeyInput();
int isButtonPressed(int num);
int isButtonLongPressed(int num);

#endif /* INC_BUTTON_H_ */

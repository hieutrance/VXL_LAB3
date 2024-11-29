/*
 * display7SegLed.h
 *
 *  Created on: Nov 17, 2024
 *      Author: trung
 */

#ifndef INC_DISPLAY7SEGLED_H_
#define INC_DISPLAY7SEGLED_H_

#include "main.h"
#include "global.h"


void display7SegLed(int num);
void updateBufer();
void update7SegLed(int num);
void updateTimeForState(int status);
void turnOffAll7Seg();

#endif /* INC_DISPLAY7SEGLED_H_ */

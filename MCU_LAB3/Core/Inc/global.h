/*
 * global.h
 *
 *  Created on: Nov 16, 2024
 *      Author: trung
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "main.h"
#include "display7SegLed.h"

#define INIT 			1
#define RED13_GREEN24 	2
#define RED13_YELLOW24 	3
#define GREEN13_RED24	4
#define YELLOW13_RED24	5

#define MODIFY_RED 		11
#define MODIFY_YELLOW	12
#define MODIFY_GREEN	13
extern int status;
extern int time13;
extern int time24;
extern int time13remain;
extern int time24remain;
extern int timeRed;
extern int timeGreen;
extern int timeYellow;
#endif /* INC_GLOBAL_H_ */

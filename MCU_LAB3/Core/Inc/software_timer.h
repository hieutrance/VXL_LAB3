/*
 * software_timer.h
 *
 *  Created on: Nov 13, 2024
 *      Author: trung
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "main.h"

#define NUM_OF_TIMERS 5
#define TIMER_CYCLE 10

extern int timer_counter[NUM_OF_TIMERS];
extern int timer_flag[NUM_OF_TIMERS];


void setTimer(int index, int duration);
int isTimerFlagSet(int index);
void timerRun();



#endif /* INC_SOFTWARE_TIMER_H_ */

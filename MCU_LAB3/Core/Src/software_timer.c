/*
 * software_timer.c
 *
 *  Created on: Nov 13, 2024
 *      Author: trung
 */

#include "software_timer.h"


int timer_counter[NUM_OF_TIMERS] = {0};
int timer_flag[NUM_OF_TIMERS] = {0};


void setTimer(int index, int duration) {
	if (index >= 0 && index < NUM_OF_TIMERS) {
		timer_counter[index] = duration / TIMER_CYCLE;
		timer_flag[index] = 0;
	}
}


int isTimerFlagSet(int index){
	if (index >= 0 && index < NUM_OF_TIMERS) {
		if (timer_flag[index] == 1) {
			timer_flag[index] = 0;
			return 1;
		}
	}
	return 0;
}


void timerRun() {
	for (int i = 0; i < NUM_OF_TIMERS; i++) {
		if (timer_counter[i] > 0) {
			timer_counter[i]--;
			if (timer_counter[i] <= 0) {
				timer_flag[i] = 1;
			}
		}
	}
}

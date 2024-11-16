/*
 * software_timer.h
 *
 *  Created on: Nov 13, 2024
 *      Author: trung
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer1_flag;
extern int timer2_flag;
extern int timer0_flag;

void setTimer1(int duration);
void setTimer2(int duration);
void setTimer0(int duration);
void timerRun();



#endif /* INC_SOFTWARE_TIMER_H_ */

/*
 * display7SegLed.c
 *
 *  Created on: Nov 17, 2024
 *      Author: trung
 */

#include "display7SegLed.h"

int led_buffer[4];

void display7SegLed(int num){
	switch(num){
	case 0:
		HAL_GPIO_WritePin(a_GPIO_Port , a_Pin , RESET);
		HAL_GPIO_WritePin(b_GPIO_Port , b_Pin , RESET);
		HAL_GPIO_WritePin(c_GPIO_Port , c_Pin , RESET);
		HAL_GPIO_WritePin(d_GPIO_Port , d_Pin , RESET);
		HAL_GPIO_WritePin(e_GPIO_Port , e_Pin , RESET);
		HAL_GPIO_WritePin(f_GPIO_Port , f_Pin , RESET);
		HAL_GPIO_WritePin(g_GPIO_Port , g_Pin , SET);
		break;
	case 1:
		HAL_GPIO_WritePin(a_GPIO_Port , a_Pin , SET);
		HAL_GPIO_WritePin(b_GPIO_Port , b_Pin , RESET);
		HAL_GPIO_WritePin(c_GPIO_Port , c_Pin , RESET);
		HAL_GPIO_WritePin(d_GPIO_Port , d_Pin , SET);
		HAL_GPIO_WritePin(e_GPIO_Port , e_Pin , SET);
		HAL_GPIO_WritePin(f_GPIO_Port , f_Pin , SET);
		HAL_GPIO_WritePin(g_GPIO_Port , g_Pin , SET);
		break;
	case 2:
		HAL_GPIO_WritePin(a_GPIO_Port , a_Pin , RESET);
		HAL_GPIO_WritePin(b_GPIO_Port , b_Pin , RESET);
		HAL_GPIO_WritePin(c_GPIO_Port , c_Pin , SET);
		HAL_GPIO_WritePin(d_GPIO_Port , d_Pin , RESET);
		HAL_GPIO_WritePin(e_GPIO_Port , e_Pin , RESET);
		HAL_GPIO_WritePin(f_GPIO_Port , f_Pin , SET);
		HAL_GPIO_WritePin(g_GPIO_Port , g_Pin , RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(a_GPIO_Port , a_Pin , RESET);
		HAL_GPIO_WritePin(b_GPIO_Port , b_Pin , RESET);
		HAL_GPIO_WritePin(c_GPIO_Port , c_Pin , RESET);
		HAL_GPIO_WritePin(d_GPIO_Port , d_Pin , RESET);
		HAL_GPIO_WritePin(e_GPIO_Port , e_Pin , SET);
		HAL_GPIO_WritePin(f_GPIO_Port , f_Pin , SET);
		HAL_GPIO_WritePin(g_GPIO_Port , g_Pin , RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(a_GPIO_Port , a_Pin , SET);
		HAL_GPIO_WritePin(b_GPIO_Port , b_Pin , RESET);
		HAL_GPIO_WritePin(c_GPIO_Port , c_Pin , RESET);
		HAL_GPIO_WritePin(d_GPIO_Port , d_Pin , SET);
		HAL_GPIO_WritePin(e_GPIO_Port , e_Pin , SET);
		HAL_GPIO_WritePin(f_GPIO_Port , f_Pin , RESET);
		HAL_GPIO_WritePin(g_GPIO_Port , g_Pin , RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(a_GPIO_Port , a_Pin , RESET);
		HAL_GPIO_WritePin(b_GPIO_Port , b_Pin , SET);
		HAL_GPIO_WritePin(c_GPIO_Port , c_Pin , RESET);
		HAL_GPIO_WritePin(d_GPIO_Port , d_Pin , RESET);
		HAL_GPIO_WritePin(e_GPIO_Port , e_Pin , SET);
		HAL_GPIO_WritePin(f_GPIO_Port , f_Pin , RESET);
		HAL_GPIO_WritePin(g_GPIO_Port , g_Pin , RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(a_GPIO_Port , a_Pin , RESET);
		HAL_GPIO_WritePin(b_GPIO_Port , b_Pin , SET);
		HAL_GPIO_WritePin(c_GPIO_Port , c_Pin , RESET);
		HAL_GPIO_WritePin(d_GPIO_Port , d_Pin , RESET);
		HAL_GPIO_WritePin(e_GPIO_Port , e_Pin , RESET);
		HAL_GPIO_WritePin(f_GPIO_Port , f_Pin , RESET);
		HAL_GPIO_WritePin(g_GPIO_Port , g_Pin , RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(a_GPIO_Port , a_Pin , RESET);
		HAL_GPIO_WritePin(b_GPIO_Port , b_Pin , RESET);
		HAL_GPIO_WritePin(c_GPIO_Port , c_Pin , RESET);
		HAL_GPIO_WritePin(d_GPIO_Port , d_Pin , SET);
		HAL_GPIO_WritePin(e_GPIO_Port , e_Pin , SET);
		HAL_GPIO_WritePin(f_GPIO_Port , f_Pin , SET);
		HAL_GPIO_WritePin(g_GPIO_Port , g_Pin , SET);
		break;
	case 8:
		HAL_GPIO_WritePin(a_GPIO_Port , a_Pin , RESET);
		HAL_GPIO_WritePin(b_GPIO_Port , b_Pin , RESET);
		HAL_GPIO_WritePin(c_GPIO_Port , c_Pin , RESET);
		HAL_GPIO_WritePin(d_GPIO_Port , d_Pin , RESET);
		HAL_GPIO_WritePin(e_GPIO_Port , e_Pin , RESET);
		HAL_GPIO_WritePin(f_GPIO_Port , f_Pin , RESET);
		HAL_GPIO_WritePin(g_GPIO_Port , g_Pin , RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(a_GPIO_Port , a_Pin , RESET);
		HAL_GPIO_WritePin(b_GPIO_Port , b_Pin , RESET);
		HAL_GPIO_WritePin(c_GPIO_Port , c_Pin , RESET);
		HAL_GPIO_WritePin(d_GPIO_Port , d_Pin , RESET);
		HAL_GPIO_WritePin(e_GPIO_Port , e_Pin , SET);
		HAL_GPIO_WritePin(f_GPIO_Port , f_Pin , RESET);
		HAL_GPIO_WritePin(g_GPIO_Port , g_Pin , RESET);
		break;
	default:
		break;
	}
}

void updateBuffer(){
	led_buffer[0] = value13/10000;
	led_buffer[1] = value13/1000;
	led_buffer[2] = value24/10000;
	led_buffer[3] = value24/1000;
}

void update7SegLed(int num){
	switch(num){
	case 1:
		HAL_GPIO_WritePin(en1_GPIO_Port , en1_Pin , RESET);
		HAL_GPIO_WritePin(en2_GPIO_Port , en2_Pin , SET);
		HAL_GPIO_WritePin(en3_GPIO_Port , en3_Pin , SET);
		HAL_GPIO_WritePin(en4_GPIO_Port , en4_Pin , SET);
		display7SegLed(led_buffer[0]);
		break;
	case 2:
		HAL_GPIO_WritePin(en1_GPIO_Port , en1_Pin , SET);
		HAL_GPIO_WritePin(en2_GPIO_Port , en2_Pin , RESET);
		HAL_GPIO_WritePin(en3_GPIO_Port , en3_Pin , SET);
		HAL_GPIO_WritePin(en4_GPIO_Port , en4_Pin , SET);
		display7SegLed(led_buffer[1]);
		break;
	case 3:
		HAL_GPIO_WritePin(en1_GPIO_Port , en1_Pin , SET);
		HAL_GPIO_WritePin(en2_GPIO_Port , en2_Pin , SET);
		HAL_GPIO_WritePin(en3_GPIO_Port , en3_Pin , RESET);
		HAL_GPIO_WritePin(en4_GPIO_Port , en4_Pin , SET);
		display7SegLed(led_buffer[2]);
		break;
	case 4:
		HAL_GPIO_WritePin(en1_GPIO_Port , en1_Pin , SET);
		HAL_GPIO_WritePin(en2_GPIO_Port , en2_Pin , SET);
		HAL_GPIO_WritePin(en3_GPIO_Port , en3_Pin , SET);
		HAL_GPIO_WritePin(en4_GPIO_Port , en4_Pin , RESET);
		display7SegLed(led_buffer[3]);
		break;
	default:
		break;
	}
}


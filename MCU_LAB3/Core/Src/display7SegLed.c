/*
 * display7SegLed.c
 *
 *  Created on: Nov 17, 2024
 *      Author: trung
 */

#include "display7SegLed.h"

int led_buffer[4] = {0};
int led_extra_buffer[4]={0};

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

//void updateExtraBufer(){
//    led_extra_buffer[0] = (time13 > 99) ? 9 : (time13 / 10);
//    led_extra_buffer[1] = (time13 > 99) ? 9 : (time13 % 10);
//
//    led_extra_buffer[2] = (time24 > 99) ? 9 : (time24 / 10);
//    led_extra_buffer[3] = (time24 > 99) ? 9 : (time24 % 10);
//}

//void updateBufer(){
//    led_buffer[0] = led_extra_buffer[0];
//    led_buffer[1] = led_extra_buffer[1];
//
//    led_buffer[2] = led_extra_buffer[3];
//    led_buffer[3] = led_extra_buffer[4];
//}

void updateBufer(){
    led_buffer[0] = (time13 > 99) ? 9 : (time13 / 10);
    led_buffer[1] = (time13 > 99) ? 9 : (time13 % 10);

    led_buffer[2] = (time24 > 99) ? 9 : (time24 / 10);
    led_buffer[3] = (time24 > 99) ? 9 : (time24 % 10);
}




void update7SegLed(int index){
    HAL_GPIO_WritePin(en1_GPIO_Port, en1_Pin, SET);
    HAL_GPIO_WritePin(en2_GPIO_Port, en2_Pin, SET);
    HAL_GPIO_WritePin(en3_GPIO_Port, en3_Pin, SET);
    HAL_GPIO_WritePin(en4_GPIO_Port, en4_Pin, SET);

    switch(index){
    case 0:
    	HAL_GPIO_WritePin(en1_GPIO_Port , en1_Pin , RESET);
    	display7SegLed(led_buffer[0]);
    	break;
    case 1:
    	HAL_GPIO_WritePin(en2_GPIO_Port , en2_Pin , RESET);
    	display7SegLed(led_buffer[1]);
    	break;
    case 2:
    	HAL_GPIO_WritePin(en3_GPIO_Port , en3_Pin , RESET);
    	display7SegLed(led_buffer[2]);
    	break;
    case 3:
    	HAL_GPIO_WritePin(en4_GPIO_Port , en4_Pin , RESET);
    	display7SegLed(led_buffer[3]);
    	break;
    default:
    	break;
    }
}

void updateTimeForState(int status){
	switch(status){
	case RED13_GREEN24:
		time13 = timeRed;
		time24 = timeGreen;
		break;
	case RED13_YELLOW24:
		time24 = timeYellow;
		break;
	case GREEN13_RED24:
		time13 = timeGreen;
		time24 = timeRed;
		break;
	case YELLOW13_RED24:
		time13 = timeYellow;
		break;
	default:
		break;
	}
}

void turnOffAll7Seg(){
    HAL_GPIO_WritePin(en1_GPIO_Port, en1_Pin, SET);
    HAL_GPIO_WritePin(en2_GPIO_Port, en2_Pin, SET);
    HAL_GPIO_WritePin(en3_GPIO_Port, en3_Pin, SET);
    HAL_GPIO_WritePin(en4_GPIO_Port, en4_Pin, SET);
}





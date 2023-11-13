/*
 * display.c
 *
 *  Created on: Nov 13, 2023
 *      Author: atfox
 */

#include "main.h"
#include "display.h"
#include "timer.h"
#include "defination.h"

int sseg_buffer[SSEG_AMOUNT];
int sseg_index = 0;
void trafficLightOn(enum LightDecode light) {
  	  switch(light) {
  	  case RED1:
  		  HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, 1);
  		  HAL_GPIO_WritePin(YEL_1_GPIO_Port, YEL_1_Pin, 0);
  		  HAL_GPIO_WritePin(GRE_1_GPIO_Port, GRE_1_Pin, 0);
  		  break;
  	  case GREEN1:
  		  HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, 0);
  		  HAL_GPIO_WritePin(YEL_1_GPIO_Port, YEL_1_Pin, 0);
  		  HAL_GPIO_WritePin(GRE_1_GPIO_Port, GRE_1_Pin, 1);
  		  break;
  	  case YELLOW1:
  		  HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, 0);
  		  HAL_GPIO_WritePin(YEL_1_GPIO_Port, YEL_1_Pin, 1);
  		  HAL_GPIO_WritePin(GRE_1_GPIO_Port, GRE_1_Pin, 0);
  		  break;
  	  case RED2:
  		  HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, 1);
  		  HAL_GPIO_WritePin(YEL_2_GPIO_Port, YEL_2_Pin, 0);
  		  HAL_GPIO_WritePin(GRE_2_GPIO_Port, GRE_2_Pin, 0);
  		  break;
  	  case GREEN2:
  		  HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, 0);
  		  HAL_GPIO_WritePin(YEL_2_GPIO_Port, YEL_2_Pin, 0);
  		  HAL_GPIO_WritePin(GRE_2_GPIO_Port, GRE_2_Pin, 1);
  		  break;
  	  case YELLOW2:
  		  HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, 0);
  		  HAL_GPIO_WritePin(YEL_2_GPIO_Port, YEL_2_Pin, 1);
  		  HAL_GPIO_WritePin(GRE_2_GPIO_Port, GRE_2_Pin, 0);
  		  break;
  	  }
}
void setUpBlinkLed(enum ColorDecode colorDecode) {
	switch(colorDecode) {
	case RED_LED:
		trafficLightOn(RED1);
		trafficLightOn(RED2);
		break;
	case GREEN_LED:
		trafficLightOn(GREEN1);
		trafficLightOn(GREEN2);
		break;
	case YELLOW_LED:
		trafficLightOn(YELLOW1);
		trafficLightOn(YELLOW2);
		break;
	}
}
void blinkLed(enum ColorDecode colorDecode) {
	switch(colorDecode) {
	case RED_LED:
		HAL_GPIO_TogglePin(RED_1_GPIO_Port, RED_1_Pin);
		HAL_GPIO_TogglePin(RED_2_GPIO_Port, RED_2_Pin);
		break;
	case GREEN_LED:
		HAL_GPIO_TogglePin(GRE_1_GPIO_Port, GRE_1_Pin);
		HAL_GPIO_TogglePin(GRE_2_GPIO_Port, GRE_2_Pin);
		break;
	case YELLOW_LED:
		HAL_GPIO_TogglePin(YEL_1_GPIO_Port, YEL_1_Pin);
		HAL_GPIO_TogglePin(YEL_2_GPIO_Port, YEL_2_Pin);
		break;
	}
}
void display7SEG(int num) {
	switch(num) {
		case 0:
			HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, 0);
			HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, 0);
			HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, 0);
			HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, 0);
			HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, 0);
			HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, 0);
			HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, 1);
			break;
		case 1:
			HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, 1);
			HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, 0);
			HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, 0);
			HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, 1);
			HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, 1);
			HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, 1);
			HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, 1);
			break;
		case 2:
			HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, 0);
			HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, 0);
			HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, 1);
			HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, 0);
			HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, 0);
			HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, 1);
			HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, 0);
			break;
		case 3:
			HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, 0);
			HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, 0);
			HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, 0);
			HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, 0);
			HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, 1);
			HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, 1);
			HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, 0);
			break;
		case 4:
			HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, 1);
			HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, 0);
			HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, 0);
			HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, 1);
			HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, 1);
			HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, 0);
			HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, 0);
			break;
		case 5:
			HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, 0);
			HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, 1);
			HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, 0);
			HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, 0);
			HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, 1);
			HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, 0);
			HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, 0);
			break;
		case 6:
			HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, 0);
			HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, 1);
			HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, 0);
			HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, 0);
			HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, 0);
			HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, 0);
			HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, 0);
			break;
		case 7:
			HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, 0);
			HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, 0);
			HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, 0);
			HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, 1);
			HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, 1);
			HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, 1);
			HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, 1);
			break;
		case 8:
			HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, 0);
			HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, 0);
			HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, 0);
			HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, 0);
			HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, 0);
			HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, 0);
			HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, 0);
			break;
		case 9:
			HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, 0);
			HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, 0);
			HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, 0);
			HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, 0);
			HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, 1);
			HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, 0);
			HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, 0);
			break;
		default:
			HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, 0);
			HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, 0);
			HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, 0);
			HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, 0);
			HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, 0);
			HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, 0);
			HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, 0);
			break;

	}
}
void update7SEG(int index){
    switch (index){
		  case 0:
			  HAL_GPIO_WritePin(SSEG_3_GPIO_Port, SSEG_3_Pin, 1);
			  display7SEG(sseg_buffer[0]);
			  HAL_GPIO_WritePin(SSEG_0_GPIO_Port, SSEG_0_Pin, 0);
			  HAL_GPIO_WritePin(SSEG_1_GPIO_Port, SSEG_1_Pin, 1);
			  HAL_GPIO_WritePin(SSEG_2_GPIO_Port, SSEG_2_Pin, 1);
			  break;
		  case 1:
			  HAL_GPIO_WritePin(SSEG_0_GPIO_Port, SSEG_0_Pin, 1);
			  display7SEG(sseg_buffer[1]);
			  HAL_GPIO_WritePin(SSEG_1_GPIO_Port, SSEG_1_Pin, 0);
			  HAL_GPIO_WritePin(SSEG_2_GPIO_Port, SSEG_2_Pin, 1);
			  HAL_GPIO_WritePin(SSEG_3_GPIO_Port, SSEG_3_Pin, 1);
	  		  break;
	  	  case 2:
			  HAL_GPIO_WritePin(SSEG_0_GPIO_Port, SSEG_0_Pin, 1);
			  HAL_GPIO_WritePin(SSEG_1_GPIO_Port, SSEG_1_Pin, 1);
			  display7SEG(sseg_buffer[2]);
			  HAL_GPIO_WritePin(SSEG_2_GPIO_Port, SSEG_2_Pin, 0);
			  HAL_GPIO_WritePin(SSEG_3_GPIO_Port, SSEG_3_Pin, 1);
	  		  break;
	  	  case 3:
			  HAL_GPIO_WritePin(SSEG_0_GPIO_Port, SSEG_0_Pin, 1);
			  HAL_GPIO_WritePin(SSEG_1_GPIO_Port, SSEG_1_Pin, 1);
			  HAL_GPIO_WritePin(SSEG_2_GPIO_Port, SSEG_2_Pin, 1);
			  display7SEG(sseg_buffer[3]);
			  HAL_GPIO_WritePin(SSEG_3_GPIO_Port, SSEG_3_Pin, 0);
	  		  break;
        default:
            break;
    }
}
void set7Seg4BCD(int first_num, int second_num) {
	sseg_buffer[0] = first_num / 10;
	sseg_buffer[1] = first_num % 10;
	sseg_buffer[2] = second_num / 10;
	sseg_buffer[3] = second_num % 10;
}
void ledScanningRun(void) {
	if(timer_flag_scanning_7seg) {
		setTimerScanning7Seg(SCANNING_DURATION);
		sseg_index = (sseg_index + 1) % SSEG_AMOUNT;
		update7SEG(sseg_index);
	}
}

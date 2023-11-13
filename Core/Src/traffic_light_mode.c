/*
 * traffic_light_mode.c
 *
 *  Created on: Nov 13, 2023
 *      Author: atfox
 */
#include "main.h"
#include "timer.h"
#include "traffic_light_mode.h"
#include "defination.h"
#include "input_reading.h"
#include "input_processing.h"
#include "display.h"
#include "stm32f1xx_hal_tim.h"


enum NormalModeState {
	RED_GREEN,
	RED_YELLOW,
	GREEN_RED,
	YELLOW_RED
 };
enum NormalModeState normalModeState = RED_GREEN;
int firstWayCounter;
int secondWayCounter;
int redCountDown = RED_LIGHT_LIMIT * SECOND_UNIT;
int yelCountDown = YELLOW_LIGHT_LIMIT * SECOND_UNIT;
int greCountDown = GREEN_LIGHT_LIMIT * SECOND_UNIT;

void init_fsm_traffic_mode(void) {
	trafficLightMode = INIT_MODE;
}
void reset_fsm_normal_mode(void) {
	normalModeState = RED_GREEN;
	setTimerNormalMode(SECOND_UNIT);
	firstWayCounter = redCountDown;
	secondWayCounter = greCountDown;
}
int traffic_is_modify_mode(void) {
	return (trafficLightMode == MODIFY_RED_MODE && trafficLightMode == MODIFY_YELLOW_MODE && trafficLightMode == MODIFY_GREEN_MODE);
}
int traffic_is_normal_mode(void) {
	return (trafficLightMode == NORMAL_MODE);
}

void fsm_normal_mode(void) {
	if(timer_flag_normal_mode) {
		setTimerNormalMode(SECOND_UNIT);
		firstWayCounter--;
		secondWayCounter--;
	}
	switch(normalModeState) {
	case RED_GREEN:
		if(secondWayCounter == -1) {
			normalModeState = RED_YELLOW;
			trafficLightOn(RED1);
			trafficLightOn(YELLOW2);
			secondWayCounter = yelCountDown;
		}
		break;
	case RED_YELLOW:
		if(secondWayCounter == -1) {
			normalModeState = GREEN_RED;
			trafficLightOn(GREEN1);
			trafficLightOn(RED2);
			firstWayCounter = greCountDown;
			secondWayCounter = redCountDown;
		}
		break;
	case GREEN_RED:
		if(firstWayCounter == -1) {
			normalModeState = YELLOW_RED;
			trafficLightOn(YELLOW1);
			trafficLightOn(RED2);
			firstWayCounter = yelCountDown;
		}
		break;
	case YELLOW_RED:
		if(firstWayCounter == -1) {
			normalModeState = RED_GREEN;
			trafficLightOn(RED1);
			trafficLightOn(GREEN2);
			firstWayCounter = redCountDown;
			secondWayCounter = greCountDown;
		}
		break;
	}
	set7Seg4BCD(firstWayCounter, secondWayCounter);
}
void fsm_modify_mode(enum ColorDecode colorDecode) {
	if(colorDecode == RED_LED) {
		if(is_button_pressed(SET_BUTTON_ENCODE)) {
			redCountDown = get_buffer();
		}
	}
	else if (colorDecode == YELLOW_LED) {
		if(is_button_pressed(SET_BUTTON_ENCODE)) {
			yelCountDown = get_buffer();
		}
	}
	else if (colorDecode == GREEN_LED) {
		if(is_button_pressed(SET_BUTTON_ENCODE)) {
			greCountDown = get_buffer();
		}
	}

	if(timer_flag_blink_led) {
		setTimerBlinkLed(BLINK_LED_COUNTER);
		blinkLed(colorDecode);
	}
	set7Seg4BCD(trafficLightMode, get_buffer());
}
void reset_fsm_modify_mode(void) {
	setTimerBlinkLed(BLINK_LED_COUNTER);
	reset_buffer();
}
// Return: Limitation of light number is valid
int is_light_num_valid(void) {
	return (redCountDown + 1 == yelCountDown + greCountDown + 2);
}
void fsm_traffic_light_mode(void) {
	switch(trafficLightMode) {
	case INIT_MODE:
		trafficLightMode = NORMAL_MODE;
		init_timer();
		redCountDown = RED_LIGHT_LIMIT * SECOND_UNIT;
		yelCountDown = YELLOW_LIGHT_LIMIT * SECOND_UNIT;
		greCountDown = GREEN_LIGHT_LIMIT * SECOND_UNIT;
		trafficLightOn(RED1);
		trafficLightOn(GREEN2);
		reset_fsm_normal_mode();
		set7Seg4BCD(firstWayCounter, secondWayCounter);
		break;
	case NORMAL_MODE:
		fsm_normal_mode();
		if(is_button_pressed(MODE_BUTTON_ENCODE)) {
			trafficLightMode = MODIFY_RED_MODE;
			reset_fsm_normal_mode();
			setUpBlinkLed(RED_LED);
			reset_buffer();
			set7Seg4BCD(trafficLightMode, get_buffer());
		}
		break;
	case MODIFY_RED_MODE:
		fsm_modify_mode(RED_LED);
		if(is_button_pressed(MODE_BUTTON_ENCODE)) {
			trafficLightMode = MODIFY_YELLOW_MODE;
			reset_fsm_modify_mode();
			setUpBlinkLed(YELLOW_LED);
			reset_buffer();
			set7Seg4BCD(trafficLightMode, get_buffer());
		}
		break;
	case MODIFY_YELLOW_MODE:
		fsm_modify_mode(YELLOW_LED);
		if(is_button_pressed(MODE_BUTTON_ENCODE)) {
			trafficLightMode = MODIFY_GREEN_MODE;
			reset_fsm_modify_mode();
			setUpBlinkLed(GREEN_LED);
			reset_buffer();
			set7Seg4BCD(trafficLightMode, get_buffer());
		}
		break;
	case MODIFY_GREEN_MODE:
		fsm_modify_mode(GREEN_LED);
		if(is_button_pressed(MODE_BUTTON_ENCODE)) {
			if(is_light_num_valid()) {
				trafficLightMode = NORMAL_MODE;
				trafficLightOn(RED1);
				trafficLightOn(GREEN2);
				reset_fsm_normal_mode();
				set7Seg4BCD(firstWayCounter, secondWayCounter);
			}
			else {
				trafficLightMode = ERROR_MODE;
				set7Seg4BCD(ERROR_7SEG_DISPLAY_1, ERROR_7SEG_DISPLAY_0);
			}

		}
		break;
	case ERROR_MODE:
		if(is_button_pressed(MODE_BUTTON_ENCODE)) {
			trafficLightMode = INIT_MODE;
		}
		break;
	}
}



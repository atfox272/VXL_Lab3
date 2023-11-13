/*
 * timer.c
 *
 *  Created on: Nov 13, 2023
 *      Author: atfox
 */

#include "main.h"
#include "timer.h"
#include "input_processing.h"
#include "traffic_light_mode.h"
#include "input_reading.h"
#include "defination.h"
#include "stm32f1xx_hal_tim.h"

void setTimerNormalMode(int num) {		/* Always SECOND_UNIT*/
	timer_counter_normal_mode = num / TIMER_CYCLE;
	timer_flag_normal_mode = 0;
}
void setTimerIncHoldButton(int num) {	/* Always INC_HOLD_DURATION*/
	timer_counter_inc_hold = num / TIMER_CYCLE;
	timer_flag_inc_hold = 0;
}
void setTimerBlinkLed(int num) {		/* Always BLINK_LED_COUNTER*/
	timer_counter_blink_led = num / TIMER_CYCLE;
	timer_flag_blink_led = 0;
}
void setTimerScanning7Seg(int num) {	/* Always SCANNING_DURATION*/
	timer_counter_scanning_7seg = num / TIMER_CYCLE;
	timer_flag_scanning_7seg = 0;
}
void init_timer(void) {
	setTimerNormalMode(SECOND_UNIT);
	setTimerIncHoldButton(INC_HOLD_DURATION);
	setTimerBlinkLed(BLINK_LED_COUNTER);
	setTimerScanning7Seg(SCANNING_DURATION);
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if(htim->Instance == TIM2){
		button_reading();
	}
	if(traffic_is_normal_mode()) {
		timer_counter_normal_mode--;
		if(timer_counter_normal_mode == 0) {
			timer_flag_normal_mode = 1;
		}
	}
	else if(traffic_is_modify_mode()) {
		/* Blinking led */
		timer_counter_blink_led--;
		if(timer_counter_blink_led == 0) {
			timer_flag_blink_led = 1;
		}
		/* Button */
		if(is_button_hold(MODIFY_BUTTON_ENCODE)) {
			timer_counter_inc_hold--;
			if(timer_counter_inc_hold == 0) {
				timer_flag_inc_hold = 1;
			}
		}
	}
	timer_counter_scanning_7seg--;
	if(timer_counter_scanning_7seg == 0) {
		timer_flag_scanning_7seg = 1;
	}

}


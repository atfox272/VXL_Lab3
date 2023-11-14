/*
 * input_processing.c
 *
 *  Created on: Nov 13, 2023
 *      Author: atfox
 */


#include "main.h"
#include "defination.h"
#include "traffic_light_mode.h"
#include "timer.h"
#include "input_processing.h"
#include "input_reading.h"

enum ButtonState{BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND} ;
enum ButtonState buttonState[N0_OF_BUTTONS];

int buffer_value;
int button_pressed_flag[N0_OF_BUTTONS];

void reset_buffer(void) {
	buffer_value = 0;
	for(int index = 0; index < N0_OF_BUTTONS; index++) {
		button_pressed_flag[index] = 0;
	}
}
int get_buffer(void) {
	return buffer_value;
}
void incr_buffer(void) {
	buffer_value = (traffic_is_modify_mode()) ? (buffer_value + 1) % BUFFER_LIMIT : 0;
}
void init_fsm_for_input_processing(void) {
	for(int button_index = 0; button_index < N0_OF_BUTTONS; button_index++) {
		buttonState[button_index] = BUTTON_RELEASED;
	}
	reset_buffer();
}
void fsm_for_input_processing(unsigned char index){
	switch(buttonState[index]){
	case BUTTON_RELEASED:
		if(is_button_pressed(index)){
			buttonState[index] = BUTTON_PRESSED;
			//INCREASE VALUE OF PORT A BY ONE UNIT
			if(index == MODIFY_BUTTON_ENCODE) {
				incr_buffer();
			}
			button_pressed_flag[index] = 1;
		}
		break;
	case BUTTON_PRESSED:
		if(!is_button_pressed(index)){
			buttonState[index] = BUTTON_RELEASED;
		} else {
			if(is_button_pressed_1s(index)){
				buttonState[index] = BUTTON_PRESSED_MORE_THAN_1_SECOND;
				if(index == MODIFY_BUTTON_ENCODE) setTimerIncHoldButton(INC_HOLD_DURATION);
				else if(index == MODIFY_BUTTON_ENCODE) {
				// Not process
				}
			}
		}
		break;
	case BUTTON_PRESSED_MORE_THAN_1_SECOND:
		if(!is_button_pressed(index)){
			buttonState[index] = BUTTON_RELEASED;
		}
		if(index == MODIFY_BUTTON_ENCODE) {
			if(timer_flag_inc_hold) {
				setTimerIncHoldButton(INC_HOLD_DURATION);
				incr_buffer();
			}
		}
		else if(index == MODIFY_BUTTON_ENCODE) {
		// Not process
		}
		break;
	}
}
int is_button_hold(unsigned char index) {
	return (buttonState[index] == BUTTON_PRESSED_MORE_THAN_1_SECOND);
}
// To: Clear flag when button is pressed
char is_button_state_press(unsigned char index) {
	int temp = button_pressed_flag[index];
	button_pressed_flag[index] = 0;
	return temp;
}

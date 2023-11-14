/*
 * input_processing.h
 *
 *  Created on: Nov 13, 2023
 *      Author: atfox
 */

#ifndef INC_INPUT_PROCESSING_H_
#define INC_INPUT_PROCESSING_H_

void init_fsm_for_input_processing(void);
void fsm_for_input_processing(unsigned char index);
void reset_buffer(void);
int  get_buffer(void);
void incr_buffer(void);
int is_button_hold(unsigned char index);

char is_button_state_press(unsigned char index);

#endif /* INC_INPUT_PROCESSING_H_ */

/*
 * timer.h
 *
 *  Created on: Nov 13, 2023
 *      Author: atfox
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_


int timer_counter_normal_mode;
int timer_flag_normal_mode;
int timer_counter_second;
int timer_flag_second;
int timer_counter_inc_hold;
int timer_flag_inc_hold;
int timer_counter_blink_led;
int timer_flag_blink_led;
int timer_counter_scanning_7seg;
int timer_flag_scanning_7seg;
void setTimerNormalMode(int num);
void setTimerSecond(int num);
void setTimerIncHoldButton(int num);
void setTimerBlinkLed(int num);
void setTimerScanning7Seg(int num);
void init_timer(void);

#endif /* INC_TIMER_H_ */

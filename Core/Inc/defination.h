/*
 * defination.h
 *
 *  Created on: Nov 13, 2023
 *      Author: atfox
 */

#ifndef INC_DEFINATION_H_
#define INC_DEFINATION_H_

#define MODE_BUTTON_ENCODE		0		// Mode button
#define MODIFY_BUTTON_ENCODE	1		// Increase button
#define SET_BUTTON_ENCODE		2		// Set button

#define TIMER_CYCLE 			10		// 10ms
#define SECOND_UNIT 			1000	// Second Unit <=> 1000 unit
#define BLINK_LED_COUNTER 		500		// 0.5s

#define N0_OF_BUTTONS 	3

#define RED_LIGHT_LIMIT 		4		// Counting 5s
#define YELLOW_LIGHT_LIMIT 		2		// Counting 3s
#define GREEN_LIGHT_LIMIT 		1		// Counting 2s

#define BUFFER_LIMIT			100		// 7Seg limitation

/* Timer */
#define INC_HOLD_DURATION		400		// 0.4s
#define SCANNING_DURATION		50		// 0.05s
/* Display */
enum LightDecode {
	RED1,
	GREEN1,
	YELLOW1,
	RED2,
	GREEN2,
	YELLOW2
};
enum ColorDecode {
	RED_LED,
	GREEN_LED,
	YELLOW_LED
};
#define ERROR_7SEG_DISPLAY_1	99
#define ERROR_7SEG_DISPLAY_0	99
#endif /* INC_DEFINATION_H_ */

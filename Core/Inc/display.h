/*
 * display.h
 *
 *  Created on: Nov 13, 2023
 *      Author: atfox
 */

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_

#define SSEG_AMOUNT				4

enum LightDecode;
enum ColorDecode;
void trafficLightOn(enum LightDecode light);
void blinkLed(enum ColorDecode colorDecode);
void setUpBlinkLed(enum ColorDecode colorDecode);
void display7SEG_1(int num);
void set7Seg4BCD(int first_num, int second_num);
void ledScanningRun(void);

#endif /* INC_DISPLAY_H_ */

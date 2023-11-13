/*
 * traffic_light_mode.h
 *
 *  Created on: Nov 13, 2023
 *      Author: atfox
 */

#ifndef INC_TRAFFIC_LIGHT_MODE_H_
#define INC_TRAFFIC_LIGHT_MODE_H_

enum TrafficLightMode {INIT_MODE = 5, NORMAL_MODE = 1, MODIFY_RED_MODE = 2, MODIFY_YELLOW_MODE = 3, MODIFY_GREEN_MODE = 4, ERROR_MODE = 6};
enum TrafficLightMode trafficLightMode;

int traffic_is_modify_mode(void);
int traffic_is_normal_mode(void);

#endif /* INC_TRAFFIC_LIGHT_MODE_H_ */

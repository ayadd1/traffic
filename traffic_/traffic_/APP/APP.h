/*
 * APP.h
 *
 * Created: 2/12/2023 3:56:20 PM
 *  Author: union
 */ 


#ifndef APP_H_
#define APP_H_

//All the includes of the lower levels
#define F_CPU 1000000U
#include "../HAL/BUTTON/BUTTON.h"
#include "../HAL/LED/led.h"



//** Application function prototypes **//
void APP_init();
void APP_start();





#endif /* APP_H_ */
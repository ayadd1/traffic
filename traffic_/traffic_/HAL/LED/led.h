/*
 * led.h
 *
 * Created: 2/12/2023 3:58:20 PM
 *  Author: union
 */ 


#ifndef LED_H_
#define LED_H_

typedef enum EN_LEDError_t
{
	LED_OK, LED_ERROR
}EN_LEDError_t;


#include "../../MCAL/DIO/dio.h"

EN_LEDError_t LED_init(uint8_t portname, uint8_t pinnum);
EN_LEDError_t LED_on(uint8_t portname, uint8_t pinnum);
EN_LEDError_t LED_off(uint8_t portname, uint8_t pinnum);
EN_LEDError_t LED_toggle(uint8_t portname, uint8_t pinnum);




#endif /* LED_H_ */
/*
 * led.c
 *
 * Created: 2/12/2023 3:58:38 PM
 *  Author: union
 */ 
#include "LED.h"

EN_LEDError_t LED_init(uint8_t portname, uint8_t pinnum){
	EN_LEDError_t LED_init_error = LED_OK;
	DIO_init(portname, pinnum, OUT);
	if(TRUE)
	{
		LED_init_error = LED_OK;
	}

	return LED_init_error;
}


EN_LEDError_t LED_on(uint8_t portname, uint8_t pinnum){
	EN_LEDError_t LED_init_error = LED_OK;
	DIO_write(portname, pinnum, HIGH);
	if(TRUE)
	{
		LED_init_error = LED_OK;
	}

	return LED_init_error;
}


EN_LEDError_t LED_off(uint8_t portname, uint8_t pinnum){
	EN_LEDError_t LED_init_error = LED_OK;
	DIO_write(portname, pinnum, LOW);
	if(TRUE)
	{
		LED_init_error = LED_OK;
	}

	return LED_init_error;
}

EN_LEDError_t LED_toggle(uint8_t portname, uint8_t pinnum){
	EN_LEDError_t LED_init_error = LED_OK;
	DIO_toggle(portname, pinnum);
	if(TRUE)
	{
		LED_init_error = LED_OK;
	}

	return LED_init_error;
}
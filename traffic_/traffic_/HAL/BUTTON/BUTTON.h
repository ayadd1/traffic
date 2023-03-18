/*
 * BUTTON.h
 *
 * Created: 2/12/2023 3:57:48 PM
 *  Author: union
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../LED/led.h"
#include "../../MCAL/TIMERS/timer.h"
#include "../../MCAL/INTERRUPTS/interrupt.h"
typedef enum EN_BUTTONError_t
{
	BUTTON_OK, BUTTON_ERROR
}EN_BUTTONError_t;


// Function prototypes
EN_BUTTONError_t BUTTON_init(uint8_t portname, uint8_t pinnum);
EN_BUTTONError_t BUTTON_read(uint8_t portname, uint8_t pinnum, uint8_t* result);




#endif /* BUTTON_H_ */
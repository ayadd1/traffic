/*
 * timer.h
 *
 * Created: 2/12/2023 4:01:02 PM
 *  Author: union
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../UTILITY/macros.h"
#include "../../UTILITY/reg.h"
#include "../../UTILITY/std_types.h"

#include "../INTERRUPTS/interrupt.h"



#define init_value 11

typedef enum EN_TIMERSError_t
{
	TIMERS_OK, TIMERS_ERROR
}EN_TIMERSError_t;


// TIMER0 function prototypes
EN_TIMERSError_t TIMER_0_init();
EN_TIMERSError_t TIMER_0_set_init_value(uint8_t val);
EN_TIMERSError_t TIMER_0_start();
EN_TIMERSError_t TIMER_0_stop();
EN_TIMERSError_t TIMER_0_reset();

EN_TIMERSError_t TIMER_0_delay();


// Callback function to access LED_toggle function from upper layer (HAL)
void setcallback(void (*cbvar)(uint8_t portname, uint8_t pinnum));





#endif /* TIMER_H_ */
/*
 * timer.c
 *
 * Created: 2/12/2023 4:01:15 PM
 *  Author: union
 */ 
#include "timer.h"

/** After performing timer calculations to make a 5 seconds delay, prescaler 1024 is used, number of overflows is 20, and initial value is 11 **/


// Declaring extern variables to be accessed by timer driver
extern uint8_t count;
extern uint8_t first_click;

// Overflow counter for timer_0
uint8_t ovf;

// Pointer to function to save address of the function passed to callback function
void static (*callbackvar)(uint8_t portname, uint8_t pinnum);

// Callback function that takes the address of toggle function from upper layers and execute it in timer_0 overflow to blink yellow lights
void setcallback(void (*cbvar)(uint8_t portname, uint8_t pinnum)){
	callbackvar = cbvar;
}


EN_TIMERSError_t TIMER_0_init(){
	EN_TIMERSError_t TIMER0_init_error = TIMERS_OK;
	//selecting normal mode
	TCCR0 |= ((0<<3) | (0<<6));
	
	TIMER_0_set_init_value(init_value);
	if(TRUE)
	{
		TIMER0_init_error = TIMERS_OK;
	}

	return TIMER0_init_error;
}

EN_TIMERSError_t TIMER_0_set_init_value(uint8_t val){
	EN_TIMERSError_t TIMER0_init_error = TIMERS_OK;
	//assigning initial value after calculation
	TCNT0 = val;
	if(TRUE)
	{
		TIMER0_init_error = TIMERS_OK;
	}

	return TIMER0_init_error;
}

EN_TIMERSError_t TIMER_0_start(){
	EN_TIMERSError_t TIMER0_init_error = TIMERS_OK;
	// Selecting 1024 prescaler
	TCCR0 |= ((1<<0) | (1<<2));
	
	// Waiting for the overflow counter to reach a value of 20
	while(ovf <20);
	if(TRUE)
	{
		TIMER0_init_error = TIMERS_OK;
	}

	return TIMER0_init_error;
}


EN_TIMERSError_t TIMER_0_stop(){
	EN_TIMERSError_t TIMER0_init_error = TIMERS_OK;
	// Setting control register TCCR to 0  to stop the timer
	TCCR0 = 0;
	
	// Resetting overflow counter TO zero
	ovf = 0;
	if(TRUE)
	{
		TIMER0_init_error = TIMERS_OK;
	}

	return TIMER0_init_error;
}

// Delay function that perform a 5 sec delay
EN_TIMERSError_t TIMER_0_delay(){
	EN_TIMERSError_t TIMER0_init_error = TIMERS_OK;
	TIMER_0_start();
	TIMER_0_stop();
	if(TRUE)
	{
		TIMER0_init_error = TIMERS_OK;
	}

	return TIMER0_init_error;
}

// This function resets timer vale without needing to stop it
EN_TIMERSError_t TIMER_reset(){
	EN_TIMERSError_t TIMER0_init_error = TIMERS_OK;
	TIMER_0_set_init_value(init_value);
	ovf = 0; // Resetting overflow counter TO zero
	if(TRUE)
	{
		TIMER0_init_error = TIMERS_OK;
	}

	return TIMER0_init_error;
}

//  overflow interrupt
ISR(TIMER_0_OVF){
	// Resetting initial value for the next timer cycle
	TIMER_0_set_init_value(init_value);
	
	// Incrementing overflow variable
	ovf++;
	
	// Blinking yellow lights only in phase_2 and phase_4
	if(count== phase_2 || count == phase_4){
		// Only blink cars yellow light in normal mode
		if(!first_click){
			callbackvar(CAR_light, LED_yellow);
		}
		// Blink both yellow lights in pedestrian mode
		else if(first_click){
			callbackvar(CAR_light, LED_yellow);
			callbackvar(PED_light, LED_yellow);
		}
	}
}
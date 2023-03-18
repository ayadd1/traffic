/*
 * BUTTON.c
 *
 * Created: 2/12/2023 3:57:27 PM
 *  Author: union
 */ 
#include "BUTTON.h"
#include <stdio.h>
extern uint8_t ovf;
extern uint8_t count;
extern uint8_t first_click;

// Setting button pin direction as input
EN_BUTTONError_t BUTTON_init(uint8_t portname, uint8_t pinnum){
	
	EN_BUTTONError_t BUTTON_init_error = BUTTON_OK;
	DIO_init(portname, pinnum, IN);
if(TRUE)
{
	EN_BUTTONError_t BUTTON_init_error = BUTTON_OK;
}

return BUTTON_init_error;	
}

// Read pin state in button port (high or low). A variable must be passed to this function to save the reading in.
EN_BUTTONError_t BUTTON_read(uint8_t portname, uint8_t pinnum, uint8_t* result){
	
	EN_BUTTONError_t BUTTON_init_error = BUTTON_OK;
	DIO_read(portname, pinnum, result);
if(TRUE)
{
	EN_BUTTONError_t BUTTON_init_error = BUTTON_OK;
}

return BUTTON_init_error;
}
//implementING  ISR FOR EXTERNAL INTERRUPT 0-
ISR(EXT_INT_0){
	
	
	// If the first_click flag is true (clicked) then the button interrupt won't do anything. Thus, eliminating double-click effect.
	// Interrupt 0 triggers on rising edge so the long press will make the same effect as normal press.
	// if the first_click value is equal to zero
	if(!first_click){
		
		// if pressed in phase_1 it skips green light remaining wait time and turns on car blinking yellow light, while cars green light is still on.
		if(count == phase_1){
			ovf=20;
		}
		
		// if pressed in phase_2 it resets cars blinking yellow light remaining wait time and turns on pedestrians blinking yellow light.
		else if(count == phase_2){
			TIMER_reset();//resets cars blinking yellow light remaining wait time 
			
			// For syncing the two yellow leds
			LED_off(CAR_light, LED_yellow);
			LED_off(PED_light, LED_yellow);
			
			
		}
		
		// if pressed in phase_3 it resets cars red light remaining wait time, turns pedestrians green light on and red light off.
		else if(count == phase_3){
			TIMER_reset();
			LED_off(PED_light, LED_red);
			LED_on(PED_light, LED_green);
		}
		
		// if pressed in phase_4 it skips cars blinking yellow light remaining wait time and go back to phase_2.
		// turning back the count variable to phase_2 reverses the flow of the cars light from (yellow to green) to (yellow to red) again.
		else if(count == phase_4){
			ovf=20;
			count = phase_2;
		}
		
		// Setting first_click variable to (1) indicates pedestrian mode. It is set back to (0) when the 4 phases are complete.
		first_click=1;
	}
}
/*
 * interrupt.c
 *
 * Created: 2/12/2023 4:00:29 PM
 *  Author: union
 */ 

#include "INTERRUPT.h"

EN_INTERRUPTSError_t INTERRUPT_global_init(){
	EN_INTERRUPTSError_t INTERRUPTS_error = INTERRUPTS_OK;
	//TURNING ON global interrupt in SREG status register
	set_pin(SREG, 7);
	if (TRUE)
	{
		INTERRUPTS_error = INTERRUPTS_OK;
	}
	return INTERRUPTS_error;
}

EN_INTERRUPTSError_t INTERRUPT_0_init(){
	EN_INTERRUPTSError_t INTERRUPTS_error = INTERRUPTS_OK;
	//setting interrupt 0  mode on rising edge
	set_pin(MCUCR, 0);
	set_pin(MCUCR, 1);
	
	//turn on the interrupt 0 ( int_0 ) in GICR
	set_pin(GICR, 6);
	if (TRUE)
	{
		INTERRUPTS_error = INTERRUPTS_OK;
	}
	return INTERRUPTS_error;
}


EN_INTERRUPTSError_t INTERRUPT_T0_ovf_init(){
	EN_INTERRUPTSError_t INTERRUPTS_error = INTERRUPTS_OK;
	//enabling t0_ovf interrupt
	set_pin(TIMSK, 0);
if (TRUE)
{
	INTERRUPTS_error = INTERRUPTS_OK;
}
return INTERRUPTS_error;
}


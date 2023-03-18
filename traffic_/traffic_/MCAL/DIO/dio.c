/*
 * dio.c
 *
 * Created: 2/12/2023 3:59:51 PM
 *  Author: union
 */ 
#include "DIO.h"

// Set pin direction in a specific port (input or output)
EN_DIOError_t DIO_init(uint8_t portname, uint8_t pinnum, uint8_t direction){
	EN_DIOError_t DIO_init_error = DIO_OK;
	switch(portname){
		case PORT_A:
		if(direction==OUT){
			set_pin(DDRA, pinnum);
			}else if(direction==IN){
			clr_pin(DDRA, pinnum);
		}
		
		
		if (TRUE)
		{
			DIO_init_error = DIO_OK;
		}
		break;
		case PORT_B:
		if(direction==OUT){
			set_pin(DDRB, pinnum);
			}else if(direction==IN){
			clr_pin(DDRB, pinnum);
		}
		
		if (TRUE)
		{
			DIO_init_error = DIO_OK;
		}
		break;
		
		case PORT_C:
		if(direction==OUT){
			set_pin(DDRC, pinnum);
			}else if(direction==IN){
			clr_pin(DDRC, pinnum);
		}
		
		if (TRUE)
		{
			DIO_init_error = DIO_OK;
		}
		break;
		
		case PORT_D:
		if(direction==OUT){
			set_pin(DDRD, pinnum);
			}else if(direction==IN){
			clr_pin(DDRD, pinnum);
		}
		
		if (TRUE)
		{
			DIO_init_error = DIO_OK;
		}
		break;
	}
return DIO_init_error;	
}

// Set pin state in a specific port (high or low)
EN_DIOError_t DIO_write(uint8_t portname, uint8_t pinnum, uint8_t state){
	EN_DIOError_t DIO_write_error = DIO_OK;
	switch(portname){
		case PORT_A:
		if(state==HIGH){
			set_pin(PORTA, pinnum);
			}else if(state==LOW){
			clr_pin(PORTA, pinnum);
		}
		if (TRUE)
		{
			DIO_write_error = DIO_OK;
		}
		break;
		
		case PORT_B:
		if(state==HIGH){
			set_pin(PORTB, pinnum);
			}else if(state==LOW){
			clr_pin(PORTB, pinnum);
		}
		if (TRUE)
		{
			DIO_write_error = DIO_OK;
		}
		break;
		
		case PORT_C:
		if(state==HIGH){
			set_pin(PORTC, pinnum);
			}else if(state==LOW){
			clr_pin(PORTC, pinnum);
		}
		if (TRUE)
		{
			DIO_write_error = DIO_OK;
		}
		break;
		
		case PORT_D:
		if(state==HIGH){
			set_pin(PORTD, pinnum);
			}else if(state==LOW){
			clr_pin(PORTD, pinnum);
		}
		if (TRUE)
		{
			DIO_write_error = DIO_OK;
		}
		break;
	}
return DIO_write_error;
}

// Toggle pin state in a specific port
EN_DIOError_t DIO_toggle(uint8_t portname, uint8_t pinnum){
	EN_DIOError_t DIO_toggle_error = DIO_OK;
	switch(portname){
		case PORT_A:
		tgl_pin(PORTA, pinnum);
		if (TRUE)
		{
			DIO_toggle_error = DIO_OK;
		}
		break;
		
		case PORT_B:
		tgl_pin(PORTB, pinnum);
		if (TRUE)
		{
			DIO_toggle_error = DIO_OK;
		}
		break;
		
		case PORT_C:
		tgl_pin(PORTC, pinnum);
		if (TRUE)
		{
			DIO_toggle_error = DIO_OK;
		}
		break;
		
		case PORT_D:
		tgl_pin(PORTD, pinnum);
		if (TRUE)
		{
			DIO_toggle_error = DIO_OK;
		}
		break;
	}
	return DIO_toggle_error;
}

// Read pin state in specific port (high or low). A variable must be passed to this function to save the reading in.
EN_DIOError_t DIO_read(uint8_t portname, uint8_t pinnum, uint8_t* result){
	EN_DIOError_t DIO_read_error = DIO_OK;
	switch(portname){
		case PORT_A:
		*result = get_pin(PINA, pinnum);
		if (TRUE)
		{
			DIO_read_error = DIO_OK;
		}

		break;
		
		
		case PORT_B:
		*result = get_pin(PINB, pinnum);
		if (TRUE)
		{
			DIO_read_error = DIO_OK;
		}
		break;
		
		case PORT_C:
		*result = get_pin(PINC, pinnum);
		if (TRUE)
		{
			DIO_read_error = DIO_OK;
		}
		break;
		
		case PORT_D:
		*result = get_pin(PIND, pinnum);
		if (TRUE)
		{
			DIO_read_error = DIO_OK;
		}
		break;
	}
return DIO_read_error;
}



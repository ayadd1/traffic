/*
 * dio.h
 *
 * Created: 2/12/2023 4:00:04 PM
 *  Author: union
 */ 


#ifndef DIO_H_
#define DIO_H_


#include "../../UTILITY/macros.h"
#include "../../UTILITY/reg.h"
#include "../../UTILITY/std_types.h"
/* Typedefs */
typedef enum EN_DIOError_t
{
    DIO_OK, DIO_ERROR
}EN_DIOError_t;


//** FUNCTION prototypes **//
EN_DIOError_t DIO_init(uint8_t portname, uint8_t pinnum, uint8_t direction);
EN_DIOError_t DIO_write(uint8_t portname, uint8_t pinnum, uint8_t state);
EN_DIOError_t DIO_toggle(uint8_t portname, uint8_t pinnum);
EN_DIOError_t DIO_read(uint8_t portname, uint8_t pinnum, uint8_t* result);


//** PORT names **//
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'
	/* direction defines*/
#define IN (0u)
#define OUT (1u)




#endif /* DIO_H_ */
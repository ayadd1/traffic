/*
 * interrupt.h
 *
 * Created: 2/12/2023 4:00:46 PM
 *  Author: union
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_


#include "../../UTILITY/macros.h"
#include "../../UTILITY/reg.h"
#include "../../UTILITY/std_types.h"
/* typedefs */
typedef enum EN_INTERRUPTSError_t
{
	INTERRUPTS_OK, INTERRUPTS_ERROR
}EN_INTERRUPTSError_t;


// Interrupts vectors from interrupt vector table
// external interrupt request 0 
#define EXT_INT_0	__vector_1
// external interrupt request 1
#define EXT_INT_1	__vector_2
// external interrupt request 2
#define EXT_INT_2	__vector_3
//TIMER overflow vector
#define TIMER_0_OVF __vector_11

// macro defining ISR
#define ISR(INT_VECT) void INT_VECT(void) __attribute__((signal,used));\
void INT_VECT(void)


// Function prototypes
 EN_INTERRUPTSError_t INTERRUPT_global_init();
EN_INTERRUPTSError_t INTERRUPT_0_init();
EN_INTERRUPTSError_t INTERRUPT_T0_ovf_init();





#endif /* INTERRUPT_H_ */
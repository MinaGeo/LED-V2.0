/*
 * interrupts.h
 *
 * Created: 8/27/2023 2:09:12 PM
 *  Author: HP
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include "../Utitlities/registers.h"

//defining external interrupts vectors
//external interrupt request 0
#define EXT_INT_0 __vector_1
//external interrupt request 1
#define EXT_INT_1 __vector_2
//external interrupt request 2
#define EXT_INT_2 __vector_3


// Setting global interrupts - setting bit 7 in the status register 1
#define sei() __asm__ __volatile__ ("sei" ::: "memory")

// clear global interrupts, set the I-bit in status register 0
#define cli() __asm__ __volatile__ ("cli" ::: "memory")

//ISR FUNCTION
#define ISR(INT_VECT)void INT_VECT(void) __attribute__((signal,used));\
void INT_VECT(void)

/*enable external interrupt 0- INT0 */
void enable_external_interrupt0 (void);
// Enable global interrupts
void enable_Global_interrupt(void);
// Disable global interrupts
void disable_Global_interrupt(void);
  /* Choose the external interrupt sense - sense on rising edge */
void extInt_rising(void);
	


#endif /* INTERRUPTS_H_ */
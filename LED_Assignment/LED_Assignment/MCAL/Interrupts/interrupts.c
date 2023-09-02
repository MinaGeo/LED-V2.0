/*
 * interrupts.c
 *
 * Created: 8/30/2023 2:38:13 PM
 *  Author: HP
 */ 
#include "interrupts.h"
void enable_external_interrupt0 (void)
{
  GICR |= (1<<6);
}


void extInt_rising(void)
{

  MCUCR |= (1<<0) | (1<<1);
		
}

// Enable global interrupts
void enable_Global_interrupt(void)
{
	sei();
	
}
// Disable global interrupts
void disable_Global_interrupt(void)
{
	
	cli();
}
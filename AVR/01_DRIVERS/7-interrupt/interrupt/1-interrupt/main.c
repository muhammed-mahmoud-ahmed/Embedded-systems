/*
 * interrupt.c
 *
 * Created: 3/18/2023 9:13:44 AM
 * Author : muhammed mahmoud
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "Common_Macros.h"
int main(void)
{
    /* Replace with your application code */
	DDRD |= (1<<7);
	DDRD |= (0<<2);
	sei();//global interrupt enable I_bit
	
	GICR |= (1<<INT0);//enable interrupt of int0
	MCUCR |= ((1<<ISC01)|(1<<ISC00));//select rising edge mode
	//MCUCR |=(1<<ISC00);
	//MCUCR |=(1<<ISC01);
	//SET_BIT(MCUCR,ISC00);
	//SET_BIT(MCUCR,ISC01);
	
	DDRD |= (1<<6);//set D6 output
	DDRD |= (1<<5);
	GICR |=(1<<INT1);
	MCUCR |=((1<<ISC10)|(1<<ISC11));
	
	//unsigned char counter=0;//prevent starting of interrupt
    while (1) 
    {
		/*
		//Read pin: (((1<<2)&PIND)>>2)
		if((((1<<2)&PIND)>>2)==1)
		{
			PORTD |= (1<<7);
		}
		else
			PORTD &= ~(1<<7);
		*/
		
		PORTD &= ~(1<<7);//clear bit 7 
		if(READ_BIT(GIFR,7)==1)
		PORTD |= (1<<6);
		
		else
		PORTD &= ~(1<<6);		
		
	}
}

ISR(INT0_vect)
{
	PORTD|= (1<<7);//set bit 7
	
	_delay_ms(2000);//hold until i send int 1 signal
	
	if(READ_BIT(GIFR,7)==1)
	PORTD |= (1<<6);
	
	else
	PORTD &= ~(1<<6);
	
	_delay_ms(5000);//delay 100 msec
	
	
	//read flag : ((GIFR&(1<<6))>>6)
	
}

ISR(INT1_vect)
{
	
	
}
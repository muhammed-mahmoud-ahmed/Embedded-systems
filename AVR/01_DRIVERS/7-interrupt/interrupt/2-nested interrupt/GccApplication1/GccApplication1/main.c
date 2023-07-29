/*
 * nested_Interrupts.c
 *
 * Created: 3/18/2023 11:16:03 AM
 *  Author: muhammed mahmoud
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include <util/delay.h>

/*
GIFR &= (~(1<<5));//clear flag int 2
GIFR &= (~(1<<6));//clear flag int 0
GIFR &= (~(1<<7));//clear flag int 1
*/
int main(void)
{
	sei();//enable interrupts
	 
	GICR |=(1<<INT0);//enable interrupt 0
	
	GICR |=(1<<INT1);//enable interrupt 1
	
	GICR |=(1<<INT2);//enable interrupt 2
	
	MCUCR |=((1<<ISC00)|(1<<ISC01));//rising edge mode for int 0
	
	MCUCR |=((1<<ISC10)|(1<<ISC11));//rising edge mode for int 1
	
	MCUCSR |=(1<<ISC2);//rising edge mode for int 2
	
	DDRA |= (1<<0);//set A0 as output
	
	DDRA |= (1<<1);//set A1 as output
	
	DDRA |= (1<<2);//set A2 as output
	
	
	
	
	while(1)
	{
		
		PORTA &=~(1<<0);//reset A0
		PORTA &=~(1<<1);//reset A1
		PORTA &=~(1<<2);//reset A2
		
	}
}

ISR(INT0_vect)
{
	PORTA |= (1<<0);//set A0
	_delay_ms(2000);
}


ISR(INT1_vect)
{
	
	/*
	PORTA |= (1<<1);//set A1
	_delay_ms(2000);
	*/
	//enabling nested interrupt
	
	sei();//enable I bit (global interrupt enable)
	GICR &=~(1<<INT2);//disable int 2
	PORTA |= (1<<1);//set A1
	_delay_ms(2000);
	GICR |=(1<<INT2);//enable int 2
	
}

ISR(INT2_vect)
{
	/*
	PORTA |= (1<<2);//set A2
	_delay_ms(2000);
	*/
	
	
	//enabling nested interrupt
	
	sei();//enable I bit (global interrupt enable)
	PORTA |= (1<<2);//set A2
	_delay_ms(2000);
	
}
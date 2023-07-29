/*
 * GccApplication1.c
 *
 * Created: 3/22/2023 1:06:27 AM
 * Author : muhammed mahmoud
 */ 

#include <avr/io.h>
#include "Common_Macros.h"
#include "ADC.h"

int main(void)
{
	DDRD=0xFF;
	DDRC |= (1<<0);
	DDRC |= (1<<1);
	unsigned short value=0;	
	ADC_vIntialize();
    /* Replace with your application code */
    while (1) 
    {
		value=ADC_u16Read();
		PORTD=value;
		PORTC =(value>>8);//read Most Significant 2 bits
		
		
		
    }
}


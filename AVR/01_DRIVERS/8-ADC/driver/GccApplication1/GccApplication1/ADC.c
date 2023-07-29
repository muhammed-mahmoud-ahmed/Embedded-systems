/*
 * ADC.c
 *
 * Created: 3/22/2023 1:06:51 AM
 *  Author: muhammed mahmoud
 */

#include <avr/io.h>
#include "Common_Macros.h"

// initialize ADC
void ADC_vIntialize(void)
{
	SET_BIT(ADMUX, REFS0); // configure vref as avcc
	SET_BIT(ADCSRA, ADEN); // enable adc

	/*by default we are getting volt on adc0*/
	/*adjust adc clock*/
	SET_BIT(ADCSRA, ADPS2);
	SET_BIT(ADCSRA, ADPS1);
}

// Read ADC value
unsigned short ADC_u16Read(void)
{
	unsigned short value;

	SET_BIT(ADCSRA, ADSC); // start conversion
	while (READ_BIT(ADCSRA, ADIF) == 0); // check flag
	// while(READ_BIT(ADCSRA,ADSC)==1);another way to hold operation
	SET_BIT(ADCSRA, ADIF); // clear flag

	/*store value*/
	/*we are working right adjust*/
	value = (ADCL);
	value |= (ADCH << 8);

	return value;
}
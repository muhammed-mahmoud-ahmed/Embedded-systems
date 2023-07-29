/*
 * GccApplication1.c
 *
 * Created: 7/15/2023 6:36:42 PM
 * Author : muhammed mahmoud
 */ 

#include <avr/io.h>
#include "I2C.h"
#define F_CPU 8000000UL
#include <util/delay.h>
unsigned char x[]="test";

int main(void)
{
	I2C_vMASTER_INT(50000);
	I2C_vSET_ADDRESS(0x08);
	unsigned char counter=0;
	_delay_ms(1000);
	
	while(counter<6)
	{
		_delay_ms(100);
		I2C_vSTART();
		I2C_vSEND_ADDRESS(0x04,I2C_WRITE);
		I2C_vWRITE_DATA(x[counter]);
		I2C_vSTOP();
		counter++;
	}
}
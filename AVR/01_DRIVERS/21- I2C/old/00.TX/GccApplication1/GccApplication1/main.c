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
unsigned char x;

int main(void)
{
	unsigned char counter=0;
	I2C_vMASTER_INT(50000);
	
	
	/*
	_delay_ms(500);
	I2C_vSTART();
	I2C_vSEND_ADDRESS(0x04,I2C_WRITE);
	I2C_vWRITE_DATA(counter+48);
	I2C_vSTOP();
	*/
	
	
	_delay_ms(500);
	 I2C_vSTART();
	
	while(counter<10)
	{
		I2C_vSEND_ADDRESS(0x04,I2C_WRITE);
		I2C_vWRITE_DATA(counter+48);
		_delay_ms(500);
		I2C_vSTART_REPEAT();
		counter++;
	}
	
	/*
	I2C_vSEND_ADDRESS(0x04,I2C_READ);
	x=I2C_vread_no_ack();
	
	I2C_vSTART_REPEAT();
	I2C_vSEND_ADDRESS(0x04,I2C_WRITE);
	I2C_vWRITE_DATA(x+48);
	I2C_vSTOP();
	*/
	
	
	
	
	
	
	
}
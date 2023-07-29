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

int main(void)
{
	I2C_vMASTER_INT(50000);
	I2C_vSET_ADDRESS(0x02);
	unsigned char counter=0;
	_delay_ms(500);
    /* Replace with your application code */
    
	unsigned  char x[]="shadoo";
	unsigned char i=0;
	
	I2C_vSTART();
	while ( x[i] != 0) 
    {	
		I2C_vSEND_ADDRESS(0x04,I2C_WRITE);
		I2C_vWRITE_DATA(x[i]);
		_delay_ms(200);
		I2C_vSTART_REPEAT();
		i++;
    }
	I2C_vSTOP();
}


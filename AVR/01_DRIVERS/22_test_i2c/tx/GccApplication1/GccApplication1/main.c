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
#include "EEPROM_I2C.h"

unsigned char x;
int main(void)
{
	I2C_vMASTER_INT(50000);
	unsigned counter =0;

	/*	
	_delay_ms(500);
	while(counter<10)
	{
		_delay_ms(100);
		I2C_vSTART();
		I2C_vSEND_ADDRESS(0x04,I2C_WRITE);
		I2C_vWRITE_DATA(counter+48);
		I2C_vSTOP();
		counter++;
	}
	_delay_ms(100);

	EEPROM_I2C_vWRITE_DATA(0b10100000,0x01,'a');
	_delay_ms(100);
	counter=EEPROM_I2C_u8READ_DATA(0b10100000,0x01);
	I2C_vSTOP();
	_delay_ms(100);
	*/
	
	I2C_vMASTER_INT(50000);
	_delay_ms(1000);
	
	I2C_vSTART();
	I2C_vSEND_ADDRESS(0x04,I2C_READ);
	x=I2C_read_with_NO_ACK();
	I2C_vSTOP();
	
	_delay_ms(500);
	
	I2C_vSTART();
	I2C_vSEND_ADDRESS(0x04,I2C_WRITE);
	I2C_vWRITE_DATA(x);
	I2C_vSTOP();
	
}
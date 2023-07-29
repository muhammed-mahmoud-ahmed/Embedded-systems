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
	LCD_vInitialize();
	unsigned char x;
	unsigned char  counter = 0;
	I2C_vMASTER_INT(50000);
	I2C_vSTART();
	I2C_vSEND_ADDRESS(0b10100000,I2C_WRITE);
	I2C_vWRITE_DATA(0x00);
	I2C_vWRITE_DATA(0x37);
	I2C_vSTOP();
	
	_delay_ms(200);
	I2C_vSTART();
	I2C_vSEND_ADDRESS(0b10100000,I2C_WRITE);
	I2C_vWRITE_DATA(0x00);
	I2C_vSTART_REPEAT();
	I2C_vSEND_ADDRESS(0b10100000,I2C_READ);
	x=I2C_read_with_NACK();
	I2C_vSTOP();
	 
	LCD_vSendChar(x);
}
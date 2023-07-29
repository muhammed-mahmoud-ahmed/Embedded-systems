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

int main(void)
{
	LCD_vInitialize();
	unsigned char x;
	I2C_vMASTER_INT(50000);
	
		EEPROM_I2C_vWRITE_DATA(0b10100000,0x00,0x39);
		
		_delay_ms(500);
	
		x=EEPROM_I2C_u8READ_DATA(0b10100000,0x00);
		I2C_vSTOP();
	 
		LCD_vSendChar(x);
}
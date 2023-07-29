/*
 * GccApplication1.c
 *
 * Created: 7/15/2023 6:36:42 PM
 * Author : muhammed mahmoud
 */ 

#include <avr/io.h>
#include "I2C.h"
#include "LCD.h"
#include "EEPROM_I2C.h"
#define F_CPU 8000000UL
#include <util/delay.h>

unsigned char x=0;

int main(void)
{
	LCD_vInitialize();
	I2C_vMASTER_INT(50000);
	
	I2C_vSET_ADDRESS(0x04);
	EEPROM_I2C_vWRITE_DATA(0b10100000,0x04,0x32);
	_delay_ms(1000);
	TWDR=1;
	_delay_ms(1000);	
	_delay_ms(1000);
	x=EEPROM_I2C_u8READ_DATA(0b10100000,0x04);
	I2C_vSTOP();
	LCD_vSendChar(x);
}


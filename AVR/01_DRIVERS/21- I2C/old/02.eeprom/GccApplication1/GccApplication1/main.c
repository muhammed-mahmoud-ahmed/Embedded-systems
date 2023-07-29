/*
 * GccApplication1.c
 *
 * Created: 7/15/2023 6:36:42 PM
 * Author : muhammed mahmoud
 */ 

#include <avr/io.h>
#include "I2C.h"
#include "LCD.h"
#define  F_CPU 8000000UL

#include <util/delay.h>

unsigned char x;

int main(void)
{
	LCD_vInitialize();
	I2C_vMASTER_INT(50000);
	
	EEPROM_I2C_vWRITE_DATA(0b10100000,0x00,0x32);
	_delay_ms(600);
	x=EEPROM_I2C_u8READ_DATA(0b10100000,0x00);
	LCD_vSendChar(x);
	
    /* Replace with your application code */
    while (1) 
    {
		
    }
}


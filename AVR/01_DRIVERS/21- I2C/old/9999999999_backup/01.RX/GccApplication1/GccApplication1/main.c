/*
 * GccApplication1.c
 *
 * Created: 7/15/2023 6:36:42 PM
 * Author : muhammed mahmoud
 */ 

#include <avr/io.h>
#include "I2C.h"
#include "LCD.h"
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
	LCD_vInitialize();
	I2C_vMASTER_INT(50000);
	I2C_vSET_ADDRESS(0x04);
    /* Replace with your application code */
    while (1) 
    {
		LCD_vSendChar(I2C_u8SLAVE_READ());
    }
}


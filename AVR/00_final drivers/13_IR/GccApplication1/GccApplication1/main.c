/*
 * GccApplication1.c
 *
 * Created: 7/15/2023 5:20:12 AM
 * Author : muhammed mahmoud
 */ 

#include <avr/io.h>
#include "Common_Macros.h"
#include "DIO.h"
#include "LCD.h"

#include <util/delay.h>

unsigned char obstacle;

int main(void)
{
	
	DIO_vSetPinDir('b',2,0);
	LCD_vInitialize();
	LCD_vSendString("Hello :)");
	_delay_ms(1000);
	LCD_vClearScreen();
	LCD_vSendString("IR SENSOR proj");
	_delay_ms(1000);
    /* Replace with your application code */
    while (1) 
    {
		
		LCD_vClearScreen();
		if(READ_BIT(PINB,0)==0)
		{
			LCD_vSendString("obstacle found");
			_delay_ms(1000);
		}
		else if(READ_BIT(PINB,0)==1)
		{
			LCD_vSendString("no obstacle");
			_delay_ms(1000);
		}
		
    }
}


#include <avr/io.h>
#include "LCD.h"
#include "DIO.h"
#include "ultra_sonic.h"
#define  F_CPU 8000000UL
#include <util/delay.h>

unsigned char distance;

int main(void)
{
	LCD_vInitialize();
	DIO_vSetPinDir('a',0,1);
	LCD_vSendString("Distance=--");
	while(1)
	{
		
		distance=ultra_sonic_distance();
		if (distance>=80)
		{
			LCD_vClearScreen();
			LCD_vSendString("no object");
			LCD_vNewLine();
			LCD_vSendString("out of Range");
			_delay_ms(1000);
			LCD_vClearScreen();
			LCD_vSendString("Distance=--");
		}
		else
		{
			LCD_vMoveCursor(1,10);
			LCD_vSendChar((distance/10)+48);
			LCD_vSendChar((distance%10)+48);
			LCD_vSendString("cm");
			_delay_ms(500);
		}
	}
}


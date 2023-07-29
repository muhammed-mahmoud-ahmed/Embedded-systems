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
	DIO_vSetPinDir('c',2,0);
	I2C_vSET_ADDRESS(0x08);
	
	while(1)
	{
		LCD_vClearScreen();
		if(button_ucRead('c',2)==0)
		{
			distance=ultra_sonic_distance();
			if (distance>=80)
			{
				LCD_vClearScreen();
				LCD_vSendString("CAR IS NOT");
				LCD_vNewLine();
				LCD_vSendString("FOUND");
				_delay_ms(1000);
				LCD_vClearScreen();
			}
			else if((distance>10)&&(distance<80))
			{
				LCD_vSendString("Near Enough");
				LCD_vNewLine();
				LCD_vSendString("Distance=--");
				LCD_vMoveCursor(2,10);
				LCD_vSendChar((distance/10)+48);
				LCD_vSendChar((distance%10)+48);
				LCD_vSendString("cm");
				_delay_ms(500);
				LCD_vClearScreen();
			}
			else if(distance<=10)
			{
				LCD_vSendString("TOO NEAR!!!");
				LCD_vNewLine();
				LCD_vSendString("Distance=--");
				LCD_vMoveCursor(2,10);
				LCD_vSendChar((distance/10)+48);
				LCD_vSendChar((distance%10)+48);
				LCD_vSendString("cm");
				_delay_ms(500);
				LCD_vClearScreen();
			}

		}
		
		else 
		{
			LCD_vClearScreen();
			LCD_vSendString("COMMUNICATING..");
			I2C_vSLAVE_WRITE(distance);
			_delay_ms(1000);
		}
	}
}


/*
 * GccApplication1.c
 *
 * Created: 6/27/2023 12:00:52 PM
 * Author : muhammed mahmoud
 */ 

#include <avr/io.h>
#include"lcd.h"
#include"adc.h"
#include "LM_35.h"
#define F_CPU 8000000UL
#include <util/delay.h>
int main(void)
{
	//unsigned short adc_output;//this is the output of adc 
	LCD_vInitialize();
	//ADC_vIntialize();
	temp_vinitialize();
	
	unsigned char temperature;//this is the temperature
	LCD_vSendString("Hello :)");
	_delay_ms(2000);
	LCD_vClearScreen();
	LCD_vSendString("Temperature=");
	DIO_vSetPinDir('b',0,1);

    /* Replace with your application code */
    while (1) 
    {
		DIO_vTogglePin('b',0);
		temperature=temp_u8value();//conversion of temp from adc.o/p
		if(temperature<10)
		{
			LCD_vMoveCursor(1,13);
			LCD_vSendChar(temperature+48);//send the ascii of temp.;
			LCD_vSendChar(0xDF);//to display temp mark 
			LCD_vSendChar('C');//to display Celisius 
			/*if you returned form 2 digit temp to one digit temp so the c will remaining so we want to remove it*/
			LCD_vMoveCursor(1,16);//postion of C if temp. is more than 100
			LCD_vSendChar(0x20);//to display no thing
		}		 
		else if(temperature<100)
		{
			DIO_vTogglePin('d',0);
			LCD_vMoveCursor(1,13);
			LCD_vSendChar( (temperature/10) + 48 );//to display tenth value
			LCD_vSendChar( (temperature%10) + 48 );//send the ascii of temp.
			LCD_vSendChar(0xDF);//to display temp mark
			LCD_vSendChar('C');//to display Celisius
		}
		_delay_ms(1000);//to make it read temp. every 5 seconds
    }
}


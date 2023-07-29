/*
 * GccApplication1.c
 *
 * Created: 6/29/2023 8:02:33 PM
 * Author : muhammed mahmoud
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "DIO.h"
#include "LCD.h"
#include "timer.h"
#define F_CPU 8000000UL
#include <util/delay.h>

unsigned char counter_green=10;
unsigned char counter_yellow=7;
unsigned char counter_red=5;

volatile unsigned char counter_time=0;




int main(void)
{
	DIO_vSetPinDir('d',0,1);
	DIO_vSetPinDir('d',1,1);
	DIO_vSetPinDir('d',2,1);
	LCD_vInitialize();
	timer_vSelect_mode(0,TIMER_MODE_CTC);
	
	

    /* Replace with your application code */
    while (1) 
    {
		counter_green=10;
		counter_yellow=7;
		counter_red=5;
		
		LCD_vClearScreen();
		LCD_vSendString("remaining 10 sec");
		
		counter_time=0;//to start counting time from now
		
		DIO_vWritePinValue('d',2,1);
		while(counter_green>0)
		{
			if(counter_time>=100)
			{
				counter_time=0;
				counter_green--;
				LCD_vMoveCursor(1,11);
				LCD_vSendChar(0x20);
				LCD_vSendChar(counter_green+48);				
			}
		}
		DIO_vWritePinValue('d',2,0);
		
		LCD_vMoveCursor(1,11);
		LCD_vSendChar(0x20);
		LCD_vSendChar('7');
		counter_time=0;//to start counting time from now
		DIO_vWritePinValue('d',1,1);
		while(counter_yellow>0)
		{
			if(counter_time>=100)
			{
				counter_time=0;
				counter_yellow--;
				LCD_vMoveCursor(1,11);
				LCD_vSendChar(0x20);
				LCD_vSendChar(counter_yellow+48);
			}
		}
		DIO_vWritePinValue('d',1,0);
		
		
		LCD_vMoveCursor(1,12);
		LCD_vSendChar('5');
		counter_time=0;//to start counting time from now
		DIO_vWritePinValue('d',0,1);
		while(counter_red>0)
		{
			if(counter_time>=100)
			{
				counter_time=0;
				counter_red--;
				LCD_vMoveCursor(1,11);
				LCD_vSendChar(0x20);
				LCD_vSendChar(counter_red+48);
			}
		}
		DIO_vWritePinValue('d',0,0);
	
    }
}

ISR(TIMER0_COMP_vect)
{
	counter_time++;
}
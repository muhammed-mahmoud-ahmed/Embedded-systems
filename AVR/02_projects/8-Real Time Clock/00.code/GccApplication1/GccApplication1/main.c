#include <avr/io.h>
#include <avr/interrupt.h>
#include "DIO.h"
#include "7_seg.h"
#include "LCD.h"
#include "key_pad.h"
#include "timer.h"
#define F_CPU 8000000ul
#include <util/delay.h>

volatile unsigned char seconds_counter=0;
unsigned char minutes_counter=0;
unsigned char hours_counter=0;
unsigned char pressed_value;
int main(void)
{
	LCD_vInitialize();
	key_pad_initialize();
	DIO_vSetPortDir('a',0xff);
	DIO_vSetPortDir('b',0xff);
	LCD_vSendString("to adjust");
	LCD_vNewLine();
	LCD_vSendString("press 1");
	timer_vSelect_mode(2,TIMER_OVERFLOW_EXT_OSC,TIMER_OCR0_DEFAULT_VALUE);
	
	
    while (1) 
    {
		pressed_value=key_pad_read_u8Read();
		if(pressed_value!=KEY_PAD_NOT_PRESSED)
		{
			LCD_vClearScreen();
			if(pressed_value=='1')
			{
				LCD_vSendString("Set Hours:--");
				LCD_vMoveCursor(1,11);
				do 
				{
					pressed_value=key_pad_read_u8Read();
				} while (pressed_value==KEY_PAD_NOT_PRESSED);
				LCD_vSendChar(pressed_value);
				_delay_ms(250);
				hours_counter=(pressed_value-48)*10;
				do 
				{
					pressed_value=key_pad_read_u8Read();
				} while (pressed_value==KEY_PAD_NOT_PRESSED);
				LCD_vSendChar(pressed_value);
				_delay_ms(500);
				hours_counter=hours_counter+(pressed_value-48);
				
				LCD_vClearScreen();
				LCD_vSendString("Set Minutes:--");
				LCD_vMoveCursor(1,13);
				do
				{
					pressed_value=key_pad_read_u8Read();
				} while (pressed_value==KEY_PAD_NOT_PRESSED);
				LCD_vSendChar(pressed_value);
				_delay_ms(500);
				minutes_counter=(pressed_value-48)*10;
				do
				{
					pressed_value=key_pad_read_u8Read();
				} while (pressed_value==KEY_PAD_NOT_PRESSED);
				LCD_vSendChar(pressed_value);
				minutes_counter=minutes_counter+(pressed_value-48);
				_delay_ms(500);
				
				LCD_vClearScreen();
				LCD_vSendString("Set Seconds:--");
				LCD_vMoveCursor(1,13);
				do
				{
					pressed_value=key_pad_read_u8Read();
				} while (pressed_value==KEY_PAD_NOT_PRESSED);
				LCD_vSendChar(pressed_value);
				_delay_ms(500);
				seconds_counter=(pressed_value-48)*10;
				do
				{
					pressed_value=key_pad_read_u8Read();
				} while (pressed_value==KEY_PAD_NOT_PRESSED);
				LCD_vSendChar(pressed_value);
				seconds_counter=seconds_counter+(pressed_value-48);
				_delay_ms(500);
				LCD_vClearScreen();
				LCD_vSendString("to adjust");
				LCD_vNewLine();
				LCD_vSendString("press 1");
			}
			else 
			{
				LCD_vSendString("wrong choice");
			}
		 }
		 
		 
		 
		 /*segment multiplexing*/
		 
		 
         DIO_vWritePinValue('b',5,0);
		 DIO_vWritePinValue('b',0,1);
		 DIO_vWritePinValue('b',1,1);
		 DIO_vWritePinValue('b',2,1);
		 DIO_vWritePinValue('b',3,1);
		 DIO_vWritePinValue('b',4,1);
		
		 seven_segment_vWrite('a',seconds_counter%10);
		 _delay_ms(5);
		 
		 DIO_vWritePinValue('b',5,1);
		 DIO_vWritePinValue('b',0,0);
		 DIO_vWritePinValue('b',1,1);
		 DIO_vWritePinValue('b',2,1);
		 DIO_vWritePinValue('b',3,1);
		 DIO_vWritePinValue('b',4,1);
		 
		 seven_segment_vWrite('a',seconds_counter/10);
		 _delay_ms(5);
		
		 
		 DIO_vWritePinValue('b',5,1);
		 DIO_vWritePinValue('b',0,1);
		 DIO_vWritePinValue('b',1,0);
		 DIO_vWritePinValue('b',2,1);
		 DIO_vWritePinValue('b',3,1);
		 DIO_vWritePinValue('b',4,1);
		 
		 seven_segment_vWrite('a',minutes_counter%10);
		 _delay_ms(5);
		 
		 DIO_vWritePinValue('b',5,1);
		 DIO_vWritePinValue('b',0,1);
		 DIO_vWritePinValue('b',1,1);
		 DIO_vWritePinValue('b',2,0);
		 DIO_vWritePinValue('b',3,1);
		 DIO_vWritePinValue('b',4,1);
		 
		 seven_segment_vWrite('a',minutes_counter/10);
		 _delay_ms(5);
		 
		 DIO_vWritePinValue('b',5,1);
		 DIO_vWritePinValue('b',0,1);
		 DIO_vWritePinValue('b',1,1);
		 DIO_vWritePinValue('b',2,1);
		 DIO_vWritePinValue('b',3,0);
		 DIO_vWritePinValue('b',4,1);
		 
		 seven_segment_vWrite('a',hours_counter%10);
		 _delay_ms(5);
		 
		 DIO_vWritePinValue('b',5,1);
		 DIO_vWritePinValue('b',0,1);
		 DIO_vWritePinValue('b',1,1);
		 DIO_vWritePinValue('b',2,1);
		 DIO_vWritePinValue('b',3,1);
		 DIO_vWritePinValue('b',4,0);
		 seven_segment_vWrite('a',hours_counter/10);
		 _delay_ms(5);
		 
		 if(seconds_counter>=60)
		 {
			 seconds_counter=0;
			 minutes_counter++;
		 }
		 if(minutes_counter>=60)
		 {
			 minutes_counter=0;
			 hours_counter++;
		 }
		 if(hours_counter>=24)
		 {
			 hours_counter=0;
		 }
		 
    }
}

ISR(TIMER2_OVF_vect)
{
	seconds_counter++;
}

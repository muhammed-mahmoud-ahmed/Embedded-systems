/*
 * GccApplication1.c
 *
 * Created: 5/5/2023 11:36:22 AM
 * Author : muhammed mahmoud
 */ 

#include <avr/io.h>
#include  "LCD.h"
#define F_CPU 8000000UL
#include <util/delay.h>


int main(void)
{
	LCD_vInitialize();
	LCD_vSendString("Muhammed Mahmoud");
	LCD_vSendCommand(LCD_CGRAM);
	
	//location 0
	LCD_vSendChar(0b00000000);//?
	LCD_vSendChar(0b00000000);
	LCD_vSendChar(0b00000100);
	LCD_vSendChar(0b00001010);
	LCD_vSendChar(0b00010001);
	LCD_vSendChar(0b00001001);
	LCD_vSendChar(0b00000110);
	LCD_vSendChar(0b00000000);
	
	//location 1
	LCD_vSendChar(0b00010000);//? 
	LCD_vSendChar(0b00001000);
	LCD_vSendChar(0b00000100);
	LCD_vSendChar(0b00000010);
	LCD_vSendChar(0b00011111);
	LCD_vSendChar(0b00000000);
	LCD_vSendChar(0b00000000);
	LCD_vSendChar(0b00000000);
	
	//location 2
	LCD_vSendChar(0b00000000);//?
	LCD_vSendChar(0b00000000);
	LCD_vSendChar(0b00000001);
	LCD_vSendChar(0b00000001);
	LCD_vSendChar(0b00011111);
	LCD_vSendChar(0b00000000);
	LCD_vSendChar(0b00000000);
	LCD_vSendChar(0b00000000);
	
	//location 3
	LCD_vSendChar(0b00000000);//?
	LCD_vSendChar(0b00000000);
	LCD_vSendChar(0b00000111);
	LCD_vSendChar(0b00000111);
	LCD_vSendChar(0b00000111);
	LCD_vSendChar(0b00000010);
	LCD_vSendChar(0b00000100);
	LCD_vSendChar(0b00001000);
	
	LCD_vMoveCursor(2,16);
	LCD_vSendChar(0);
	_delay_ms(100);
	LCD_vMoveCursor(2,15);
	LCD_vSendChar(1);
	_delay_ms(100);
	LCD_vMoveCursor(2,14);
	LCD_vSendChar(0);
	_delay_ms(100);
	LCD_vMoveCursor(2,13);
	LCD_vSendChar(2);
	_delay_ms(100);
	LCD_vMoveCursor(2,12);
	LCD_vSendChar(' ');
	_delay_ms(100);
	LCD_vMoveCursor(2,11);
	LCD_vSendChar(0);
	_delay_ms(100);	
	LCD_vMoveCursor(2,10);
	LCD_vSendChar(1);
	_delay_ms(100);
	LCD_vMoveCursor(2,9);
	LCD_vSendChar(0);
	_delay_ms(100);
	LCD_vMoveCursor(2,8);
	LCD_vSendChar(3);
	_delay_ms(100);
	LCD_vMoveCursor(2,7);
	LCD_vSendChar(2);
	
	
	
	
    /* Replace with your application code */
    while (1) 
    {
    }
}


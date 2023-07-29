/*
 * GccApplication1.c
 *
 * Created: 3/24/2023 2:58:29 PM
 * Author : muhammed mahmoud
 */ 

#include <avr/io.h>
#include "LCD.h"
#define F_CPU 8000000UL
#include <util/delay.h>
int main(void)
{
	LCD_vInitialize();
	LCD_vSendString("shadoo");
	_delay_ms(1000);
	
    /* Replace with your application code */
    while (1) 
    {
		/*
		LCD_vSendString("shadoo_loves");
		_delay_ms(500);
		LCD_vMoveCursor(2,1);
		LCD_vSendString("MAMA&RERE");
		_delay_ms(1000);
		LCD_vClearScreen();
		*/
		
		/*
		LCD_vSendString("test_ya");
		_delay_ms(200);
		LCD_vNewLine();
		LCD_vSendString("shadoo");
		_delay_ms(3000);
		LCD_vClearScreen();
		*/
		
		/*
		LCD_vSendChar('a');
		_delay_ms(2000);
		LCD_vNewLine();
		LCD_vSendString("arz3");
		_delay_ms(2000);
		LCD_vSendCommand(LCD_RETURN_HOME);
		LCD_vSendChar('d');
		_delay_ms(2000);
		*/
		

/*		
		LCD_vMoveCursor(2,3);
		_delay_ms(500);
		LCD_vMoveCursor(1,3);
		_delay_ms(500);
	*/
	
	/*
	LCD_vSendString("shaaaaaaaadoo is");
	LCD_vNewLine();
	//LCD_vSendCommand(LCD_ENTRY_MODE_DISP_ON_CURSOR_OFF);
	LCD_vSendString("trying to test");
	_delay_ms(1000);
	LCD_vClearScreen();
	*/
	
	/*
	
	LCD_vMoveCursor(1,5);
	LCD_vSendString("1234");
	_delay_ms(1000);
	LCD_vSendCommand(LCD_ENTRY_MODE_SHIFT_DISPLAY);
    LCD_vSendString("1234");
	_delay_ms(1000);
	*/
	
	
	LCD_vClearScreen();
	_delay_ms(1000);
	LCD_vSendString("test :)");
	_delay_ms(2000);
	
	}
}


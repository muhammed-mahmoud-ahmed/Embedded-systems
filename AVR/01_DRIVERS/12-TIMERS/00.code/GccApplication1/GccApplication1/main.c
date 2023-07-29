/*
 * GccApplication1.c
 *
 * Created: 6/28/2023 8:04:02 PM
 * Author : muhammed mahmoud
 */ 

#include <avr/io.h>
#include "Common_Macros.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "LCD.h"
#include "timer.h"
unsigned short frequency;
unsigned char duty_cycle;


int main(void)
{

	LCD_vInitialize();
	LCD_vSendString("Hello :)");
	_delay_ms(1000);
	LCD_vClearScreen();
	frequency=TIMER_ICU_measureFreq_lowFerq();
	LCD_vClearScreen();
	LCD_vSendString("Frequency:");
	LCD_vSendChar((frequency/1000)+48);
	LCD_vSendChar(((frequency/100)%10)+48);
	LCD_vSendChar(((frequency/10)%10)+48);
	LCD_vSendChar((frequency%10)+48);
	LCD_vSendString("HZ");			
	
	duty_cycle=TIMER_ICU_dutyCycle_lowFerq();
	LCD_vNewLine();
	LCD_vSendString("Duty_cycle:");
	LCD_vSendChar((duty_cycle/10)+48);
	LCD_vSendChar((duty_cycle%10)+48);
	LCD_vSendChar('%');
   /* Replace with your application code */
    while (1) 
    {
		
    }
}


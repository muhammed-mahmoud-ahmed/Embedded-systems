/*
 * GccApplication1.c
 *
 * Created: 7/25/2023 3:28:15 PM
 * Author : muhammed mahmoud
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "usart.h"

int main(void)
{
	UART_vINT(9600);
	LCD_vInitialize();
	LCD_vSendString("HI YA :");
	LCD_vNewLine();
	unsigned char x;
    /* Replace with your application code */
    while (1) 
    {
		x=UART_u8Receive_Data();
		LCD_vSendChar(x);
		_delay_ms(10);
    }
}


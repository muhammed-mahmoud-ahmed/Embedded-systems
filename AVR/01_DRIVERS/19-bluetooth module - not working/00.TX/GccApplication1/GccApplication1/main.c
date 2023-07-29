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
	_delay_ms(300);
	UART_vSend_string("shadoo");
	
    /* Replace with your application code */
    while (1) 
    {
		
    }
}


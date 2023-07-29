/*
 * 3-Button.c
 *
 * Created: 2/23/2023 8:49:38 PM
 * Author : muhammed mahmoud
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "button.h"
#include "LED.h"

int main(void)
{
	button_vInitialize('a',0);
	LED_vInitialize('a',1);
    /* Replace with your application code */
    while (1) 
    {
		if(button_ucRead('a',0)==1)
		{
			LED_vOn('a',1);
		}
		else
		{
			LED_vOff('a',1);
		}
    }
}


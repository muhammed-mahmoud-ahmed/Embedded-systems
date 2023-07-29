/*
 * LED.c
 *
 * Created: 2/7/2023 5:31:23 PM
 * Author : muhammed mahmoud
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "LED.h"

int main(void)
{
	LED_vInitialize('a',0);
	LED_vInitialize('b',1);
    /* Replace with your application code */
    while (1) 
    {
		LED_vOn('a',0);
		_delay_ms(50);
		LED_vOff('a',0);
		_delay_ms(50);
		LED_vToggle('b',1);
    }
}


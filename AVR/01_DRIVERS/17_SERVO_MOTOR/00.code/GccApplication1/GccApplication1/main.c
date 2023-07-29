/*
 * GccApplication1.c
 *
 * Created: 7/15/2023 6:36:42 PM
 * Author : muhammed mahmoud
 */ 

#include <avr/io.h>
#include "timer.h"
#define F_CPU 8000000UL
#include <util/delay.h>


int main(void)
{
	
    /* Replace with your application code */
    while (1) 
    {
		SERVO_MOTOR_180();
		_delay_ms(2000);
		
		SERVO_MOTOR_0();
		_delay_ms(2000);
		
		SERVO_MOTOR_90();
		_delay_ms(2000);
		
    }
}


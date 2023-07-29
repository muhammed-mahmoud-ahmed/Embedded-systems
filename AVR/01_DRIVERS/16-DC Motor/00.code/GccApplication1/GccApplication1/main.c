/*
 * GccApplication1.c
 *
 * Created: 7/15/2023 6:36:42 PM
 * Author : muhammed mahmoud
 */ 

#include <avr/io.h>
#include "timer.h"
#include "DC_MOTOR.h"

unsigned char duty_cycle=100;
int main(void)
{
	DC_MOTOR_DUTY_CYCLE(duty_cycle);
    /* Replace with your application code */
    while (1) 
    {
    }
}


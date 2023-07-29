/*
 * GccApplication1.c
 *
 * Created: 7/1/2023 1:10:14 AM
 * Author : muhammed mahmoud
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "Common_Macros.h"
#include "DIO.h"
#include "timer.h"

int main(void)
{

	timer_vSelect_mode(0,TIMER_MODE_NON_PWM);
    /* Replace with your application code */
    while (1) 
    {
    }
}


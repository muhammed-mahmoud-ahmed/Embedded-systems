/*
 * GccApplication1.c
 *
 * Created: 6/30/2023 2:40:10 PM
 * Author : muhammed mahmoud
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "7_seg_autosar.h"
#include "DIO.h"
#include "timer.h"
#define F_CPU 8000000UL
#include <util/delay.h>

volatile unsigned char timer_counter=0;
unsigned char seven_segment_counter =0;
volatile unsigned char flag =0;

int main(void)
{
	timer_vSelect_mode(0,TIMER_MODE_CTC);
	seven_segment_vIinitialize('c');
	DIO_vSetPinDir('d',0,1);
	DIO_vSetPinDir('d',1,1);
	DIO_vWritePinValue('d',0,0);
	DIO_vWritePinValue('d',1,0);
	seven_segment_vWrite('c',0);
	timer_counter=0;
    /* Replace with your application code */
    while (1) 
    {
		
		DIO_vWritePinValue('d',0,1);
		DIO_vWritePinValue('d',1,0);
		seven_segment_vWrite('c',seven_segment_counter%10);
		while(flag==0);
		flag=0;
		DIO_vWritePinValue('d',0,0);
		DIO_vWritePinValue('d',1,1);
		seven_segment_vWrite('c',seven_segment_counter/10);
		while(flag==0);
		flag=0; 
		if(timer_counter>=100)
		{
			timer_counter=0;
			seven_segment_counter++;
			if(seven_segment_counter==21)
			{
				seven_segment_counter=0;
			}
		}				
    }
}


ISR(TIMER0_COMP_vect)
{
	timer_counter++;
	flag=1;
}



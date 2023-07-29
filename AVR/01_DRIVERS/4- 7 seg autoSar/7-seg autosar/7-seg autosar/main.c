/*
 * 7-seg autosar.c
 *
 * Created: 2/25/2023 10:11:15 AM
 * Author : muhammed mahmoud
 */ 

#include <avr/io.h>
#define F_CPU 8000000Ul
#include <util/delay.h>
#include "7_seg_autosar.h"

int main(void)
{
	seven_segment_vIinitialize('c');
    /* Replace with your application code */
    while (1) 
    {
		for(int i=0;i<16;i++)
		{
			seven_segment_vWrite('c',i);
			_delay_ms(500);
		}
    }
}


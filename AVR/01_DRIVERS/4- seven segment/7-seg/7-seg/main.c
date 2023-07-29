/*
 * 7-seg.c
 *
 * Created: 2/25/2023 9:59:59 AM
 * Author : muhammed mahmoud
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "7_seg.h"

int main(void)
{
	seven_segment_vinitialize('d');
    /* Replace with your application code */
    while (1) 
    {
		for(int i=0;i<16;i++)
		{
			seven_segment_vWrite('d',i);
			_delay_ms(500);
		}
    }
}


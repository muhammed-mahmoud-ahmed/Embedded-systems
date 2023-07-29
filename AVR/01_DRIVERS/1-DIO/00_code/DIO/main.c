/*
 * DIO.c
 *
 * Created: 2/6/2023 6:26:39 PM
 * Author : muhammed mahmoud
 */

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "DIO.h"

int main(void)
{
    /* Replace with your application code */
    //DIO_vSetPinDir('A', 0, 1);
    //DIO_vSetPinDir('A', 1, 1);
    DIO_vSetPortDir('A',0xff);
	while (1)
    {
		/*
        DIO_vWritePinValue('A', 0, 1);
        DIO_vTogglePin('A', 1);
        _delay_ms(1000);
        DIO_vWritePinValue('A', 0, 0);
        DIO_vTogglePin('A', 1);
        _delay_ms(1000);
		*/
		
		/*
		DIO_vWritePortValue('a',0x0f);
		_delay_ms(1000);
		DIO_vWritePortValue('a',0xf0);
		_delay_ms(1000);	
		*/
		
		/*
		for(int i=0;i<4;i++)
		{
			DIO_vWritePinValue('a',i,1);
			DIO_vWritePinValue('a',(7-i),1);
			_delay_ms(1000);
			DIO_vWritePinValue('a',i,0);
			DIO_vWritePinValue('a',(7-i),0);
		}
		
		for (int i=2;i>0;i--)
		{
			DIO_vWritePinValue('a',i,1);
			DIO_vWritePinValue('a',(7-i),1);
			_delay_ms(1000);
			DIO_vWritePinValue('a',i,0);
			DIO_vWritePinValue('a',(6-i),0);
		}
		*/
		
		DIO_vTogglePort('a');
		_delay_ms(500);
		DIO_vTogglePort('a');
		_delay_ms(500);
    }
}

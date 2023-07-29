#include <avr/io.h>
#include <avr/interrupt.h>
#include "DIO.h"
#include "7_seg.h"
#include "LCD.h"
#include "key_pad.h"
#include "timer.h"
#include "I2C.h"
#define F_CPU 8000000ul
#include <util/delay.h>

volatile unsigned char seconds_counter=0;
unsigned char minutes_counter=0;
unsigned char hours_counter=0;
unsigned char pressed_value;
unsigned char mode;
int main(void)
{
	
	I2C_vSET_ADDRESS(0x06);
	DIO_vSetPinDir('c',2,0);//input for configuration from master
	
	
	DIO_vSetPortDir('a',0xff);
	DIO_vSetPortDir('b',0xff);
	timer_vSelect_mode(2,TIMER_OVERFLOW_EXT_OSC,TIMER_OCR0_DEFAULT_VALUE);
	
	
	while (1)
	{
		mode=button_ucRead('c',2);		
		
		/*segment multiplexing*/
		
		if(mode==0)
		{
			DIO_vWritePinValue('b',5,0);
			DIO_vWritePinValue('b',0,1);
			DIO_vWritePinValue('b',1,1);
			DIO_vWritePinValue('b',2,1);
			DIO_vWritePinValue('b',3,1);
			DIO_vWritePinValue('b',4,1);
			
			seven_segment_vWrite('a',seconds_counter%10);
			_delay_ms(5);
			
			DIO_vWritePinValue('b',5,1);
			DIO_vWritePinValue('b',0,0);
			DIO_vWritePinValue('b',1,1);
			DIO_vWritePinValue('b',2,1);
			DIO_vWritePinValue('b',3,1);
			DIO_vWritePinValue('b',4,1);
			
			seven_segment_vWrite('a',seconds_counter/10);
			_delay_ms(5);
			
			
			DIO_vWritePinValue('b',5,1);
			DIO_vWritePinValue('b',0,1);
			DIO_vWritePinValue('b',1,0);
			DIO_vWritePinValue('b',2,1);
			DIO_vWritePinValue('b',3,1);
			DIO_vWritePinValue('b',4,1);
			
			seven_segment_vWrite('a',minutes_counter%10);
			_delay_ms(5);
			
			DIO_vWritePinValue('b',5,1);
			DIO_vWritePinValue('b',0,1);
			DIO_vWritePinValue('b',1,1);
			DIO_vWritePinValue('b',2,0);
			DIO_vWritePinValue('b',3,1);
			DIO_vWritePinValue('b',4,1);
			
			seven_segment_vWrite('a',minutes_counter/10);
			_delay_ms(5);
			
			DIO_vWritePinValue('b',5,1);
			DIO_vWritePinValue('b',0,1);
			DIO_vWritePinValue('b',1,1);
			DIO_vWritePinValue('b',2,1);
			DIO_vWritePinValue('b',3,0);
			DIO_vWritePinValue('b',4,1);
			
			seven_segment_vWrite('a',hours_counter%10);
			_delay_ms(5);
			
			DIO_vWritePinValue('b',5,1);
			DIO_vWritePinValue('b',0,1);
			DIO_vWritePinValue('b',1,1);
			DIO_vWritePinValue('b',2,1);
			DIO_vWritePinValue('b',3,1);
			DIO_vWritePinValue('b',4,0);
			seven_segment_vWrite('a',hours_counter/10);
			_delay_ms(5);
			
			if(seconds_counter>=60)
			{
				seconds_counter=0;
				minutes_counter++;
			}
			if(minutes_counter>=60)
			{
				minutes_counter=0;
				hours_counter++;
			}
			if(hours_counter>=24)
			{
				hours_counter=0;
			}
		}
		
		else if(mode == 1)//select configuration mode
		{
			RESET_BIT(TIMSK, TOIE2);
			hours_counter=I2C_u8SLAVE_READ();
			_delay_ms(200);//mandatory
			
			minutes_counter=I2C_u8SLAVE_READ();
			_delay_ms(200);//mandatory
			
			seconds_counter=I2C_u8SLAVE_READ();
			_delay_ms(200);//mandatory
			
			
			SET_BIT(TIMSK, TOIE2);
		}
		
		
	}
}


ISR(TIMER2_OVF_vect)
{
	seconds_counter++;
}

/*
 * ultraSonic.c
 *
 * Created: 7/15/2023 12:26:01 AM
 *  Author: muhammed mahmoud
 */ 

#include <avr/io.h>
#include "ultra_sonic.h"
#include "DIO.h"
#define F_CPU 8000000UL
#include <util/delay.h>


unsigned char ultra_sonic_distance(void)
{
	/*set ultra sonic trigger pin as o/p */
	// DIO_vSetPinDir(ULTRA_SONIC_PORT,ULTRA_SONIC_TRIGGER_PIN,1);
	
	
	unsigned short a;
	unsigned short b;
	unsigned short period;
	unsigned char distance;
	

	TCCR1A=0;// i am working in normal mode with | i am not generating signal i am capturing
	TIFR = (1<<ICF1);//clear flag --> don't remove
	
	/*trigger pulse*/
	DIO_vWritePinValue(ULTRA_SONIC_PORT,ULTRA_SONIC_TRIGGER_PIN,1);
	_delay_us(50);
	DIO_vWritePinValue(ULTRA_SONIC_PORT,ULTRA_SONIC_TRIGGER_PIN,0);

	/*first rising edge*/
	SET_BIT(TCCR1B,0);//select no prescaller 
	SET_BIT(TCCR1B,6);//trigger on rising edge
	while(READ_BIT(TIFR,ICF1)==0);//pooling on flag until it's got triggerd
	a=ICR1;//load value from start to first rising edge
	SET_BIT(TIFR,ICF1);//clear flag by writing one on it
	
	/*first falling edge*/
	RESET_BIT(TCCR1B,6);//trigger on falling edge
	while(READ_BIT(TIFR,ICF1)==0);//pooling on flag until it's got triggerd
	b=ICR1;//load value from start to first falling
	SET_BIT(TIFR,ICF1);//clear flag by writing one on it

	TCNT1=0;//too important to reset counter
	TCCR1B = 0;  		/* Stop the timer */

	period = (b-a);
	distance=((period*34600)/(F_CPU*2));//we divided over 2 because the period is that taken to go and return
	
	return distance;
	
	

} 
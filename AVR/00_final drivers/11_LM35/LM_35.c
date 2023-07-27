/*
 * LM_35.c
 *
 * Created: 7/8/2023 7:55:02 PM
 *  Author: muhammed mahmoud
 */ 
#include "ADC.h"

void temp_vinitialize(void)
{
	//we are using adc0
	ADC_vIntialize();	
}

unsigned char temp_u8value(void)
{
	return (ADC_u16Read()*0.25); 
}
/*
 * GccApplication1.c
 *
 * Created: 7/15/2023 6:36:42 PM
 * Author : muhammed mahmoud
 */ 

#include <avr/io.h>
#include "SPI.h"
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
	SPI_vINT_MASTER();
	_delay_ms(500);
	SPI_vMASTER_SEND_STRING("shadoo");
}


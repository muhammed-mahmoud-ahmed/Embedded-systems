/*
 * GccApplication1.c
 *
 * Created: 7/15/2023 6:36:42 PM
 * Author : muhammed mahmoud
 */ 

#include <avr/io.h>
#include "SPI.h"
#include "LCD.h"

int main(void)
{
	SPI_vINT_SLAVE();
	LCD_vInitialize();
	unsigned char x=0x30;
	unsigned char z=0;
    
	while (1)
	{
		x=SPI_u8SLAVE_TRANSMITE_RECEIVE(0xff);
		LCD_vSendChar(x);
	}
}


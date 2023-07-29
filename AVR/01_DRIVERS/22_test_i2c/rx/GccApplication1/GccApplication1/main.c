/*
 * GccApplication1.c
 *
 * Created: 7/15/2023 6:36:42 PM
 * Author : muhammed mahmoud
 */ 

#include <avr/io.h>
#include "I2C.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "EEPROM_I2C.h"

int main(void)
{
	LCD_vInitialize();
	I2C_vSET_ADDRESS(0x04);
	
	while(1)
	{
		I2C_vSLAVE_WRITE(0x38);
		LCD_vSendChar('a');
		LCD_vSendChar(I2C_u8SLAVE_READ());
		_delay_ms(5000);	
	}
}
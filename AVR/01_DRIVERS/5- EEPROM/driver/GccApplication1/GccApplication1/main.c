/*
 * GccApplication1.c
 *
 * Created: 3/10/2023 4:18:57 PM
 * Author : muhammed mahmoud
 */ 

#include <avr/io.h>
#include "EEPROM.h"

int main(void)
{
	EEPROM_vWrite(0x0063,0x10);
    /* Replace with your application code */
    while (1) 
    {
		
    }
}


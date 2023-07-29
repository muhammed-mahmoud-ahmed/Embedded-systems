/**
@file    EEPROM_I2C.c
@version 1.0.0
@brief
@author  Muhammed Mahmoud (muhammed76mahmoud.ahmed@gmail.com)
@date    2023-07-27
*/

#include "I2C.h"
#include "LCD.h"

void EEPROM_I2C_vWRITE_DATA(unsigned char eeprom_address, unsigned char data_address, unsigned char data)
{
    I2C_vSTART();
    I2C_vSEND_ADDRESS(eeprom_address, I2C_WRITE);
    I2C_vWRITE_DATA(data_address);
    I2C_vWRITE_DATA(data);
    I2C_vSTOP();
}

unsigned char EEPROM_I2C_u8READ_DATA(unsigned char eeprom_address, unsigned char data_address)
{
	
    I2C_vSTART();
	
    I2C_vSEND_ADDRESS(eeprom_address, I2C_WRITE);
	
    I2C_vWRITE_DATA(data_address);
	
    I2C_vSTART_REPEAT();
	
    I2C_vSEND_ADDRESS(0b10100000, I2C_READ);
    return I2C_vread_no_ack;
}

/* --------------------- Revision Log ---------------------

    Date                  By                  Description
    ------------          ------------        ------------
    23/12/2002            Muhammed Mahmoud    hello world

----------------------------------------------------------*/
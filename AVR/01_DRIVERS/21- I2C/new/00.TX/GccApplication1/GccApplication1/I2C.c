/*
 * I2C.c
 *
 * Created: 7/26/2023 2:07:06 PM
 *  Author: muhammed mahmoud
 */ 
#include <avr/io.h>
#define F_CPU 8000000UL
#define prescalar 1
#include "Common_Macros.h"
#include "I2C.h"

void I2C_vMASTER_INT(unsigned long SCL_CLK)
{
	/* setting the desired clk*/
	/* using prescalar as one */
	/*twps0 & twps1 =0 so prescalar is one*/
	TWBR = (unsigned char)  (((F_CPU/SCL_CLK)-16)/(2*prescalar));

	/*next if is for setting status reg. depending on desired prescalar and clk*/
	if(prescalar == 1)
	{
		TWSR = 0;
	}
	
	else if(prescalar == 4)
	{
		TWSR = 1;
	}
	
	else if(prescalar == 16)
	{
		TWSR = 2;
	}
	
	else if(prescalar == 64)
	{
		TWSR = 3;
	}
	
}

void I2C_vSTART(void)
{
	
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
	while(READ_BIT(TWCR,TWINT)==0); //wait to finish
	while ((TWSR & 0XF8) != 0x08); // start condition has been transmitted
}

void I2C_vSTOP(void)
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}


void I2C_vSET_ADDRESS(unsigned char address)
{
	TWAR = address;
}


void I2C_vSEND_ADDRESS(unsigned char address , unsigned char R_W)
{
	TWDR=address;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while(READ_BIT(TWCR,TWINT)==0); //wait to finish
	if(R_W == I2C_WRITE)
	{
	while ((TWSR & 0XF8) != 0x18); // SLA+write has been transmitted and ACK has been received		
	}
}

void I2C_vWRITE_DATA(unsigned char data)
{
	TWDR=data;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while(READ_BIT(TWCR,TWINT)==0); //wait to finish
	while ((TWSR & 0XF8) != 0x28); // data has been transmitted and ACK has been received
}

unsigned char I2C_u8SLAVE_READ(void)
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while(READ_BIT(TWCR,TWINT)==0);
	while ((TWSR & 0XF8) != 0x60); // own SLA+W has been received and ACK has been returned
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while(READ_BIT(TWCR,TWINT)==0);
	while ((TWSR & 0XF8) != 0x80); // previously addressed with own SLA+W : data has been received : ACK has been returned
	return TWDR ;
	
}











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
	/* 
	 * Clear the TWINT flag before sending the start bit TWINT=1
	 * send the start bit by TWSTA=1
	 * Enable TWI Module TWEN=1 
	 */
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    
    /* Wait for TWINT flag set in TWCR Register (start bit is send successfully) */
    while(READ_BIT(TWCR,TWINT)==0);
	while((TWSR & 0xf8) != 0x08);//to make sure that start condition is transmitted (not mandatory but more ack.)	
}

void I2C_vSTART_REPEAT(void)
{
	/* 
	 * Clear the TWINT flag before sending the start bit TWINT=1
	 * send the start bit by TWSTA=1
	 * Enable TWI Module TWEN=1 
	 */
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    
    /* Wait for TWINT flag set in TWCR Register (start bit is send successfully) */
    while(READ_BIT(TWCR,TWINT)==0);
	while((TWSR & 0xf8) != 0x10);//to make sure that repeated start condition is transmitted (not mandatory but more ack.)	
}

void I2C_vSTOP(void)
{
	/*
	* reset flag
	* enable TWI(I2C)
	* send stop bit 
	*/
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
}

void I2C_vSET_ADDRESS(unsigned char address)
{
	TWAR = address; 
}

void I2C_vMASTER_WRITE_ADDRESS(unsigned char address)
{
	// be aware that you want to read so you should clear bit 0 in address
	TWDR = address;//load address to data reg;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while (READ_BIT(TWCR,TWINT) == 0 );// wait until data is transmitted
	while((TWSR & 0xF8) != 0x18);//to make sure that address is transmitted and ack. is received 
}

void I2C_vMASTER_READ_ADDRESS(unsigned char address)
{
	// be aware that you want to read so you should set bit 0 in address
	TWDR = address;//load address to data reg;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while (READ_BIT(TWCR,TWINT) == 0 );// wait until data is received
	while((TWSR & 0xF8) != 0x40);//to make sure that data is received and ack. is sent
}

void I2C_vMASTER_WRITE_DATA(unsigned char data)
{
	TWDR = data;//load address to data reg;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while (READ_BIT(TWCR,TWINT) == 0 );// wait until data is transmitted
	while((TWSR & 0xF8) != 0x28);//to make sure that data is transmitted and ack. is received
}

unsigned char I2C_u8SLAVE_READ(void)
{
	 /*
	 * TWI ENABLE
	 * CLEAR INTERUPT  FLAG
	 * ENABLE ACK.
	 */
	 
	 /*Read address then return ack. */
	 TWCR = (1<<TWEN) | (1<<TWINT) | (1<<TWEA);
	 while( READ_BIT(TWCR,TWINT) == 0);//pooling on flag until it become 1
	 while((TWSR & 0xf8) != 0x60);
	 
	 /*Read data  and return ack */
	 TWCR = (1<<TWEN) | (1<<TWINT) | (1<<TWEA);
	 while( READ_BIT(TWCR,TWINT) == 0);//pooling on flag until it become 1
	 while((TWSR & 0xf8) != 0x80);
	 
	 return TWDR;	 
}



unsigned char I2C_u8MASTER_READ_DATA_No_ACK(void)
{
	/*
	 * TWI ENABLE
	 * CLEAR INTERUPT  FLAG
	 * ENABLE ACK.
	 */
		 
	 /*Read data  and return ack */
	 TWCR = (1<<TWEN) | (1<<TWINT);
	 while( READ_BIT(TWCR,TWINT) == 0);//pooling on flag until it become 1
	 while((TWSR & 0xf8) != 0x58);
	 
	 return TWDR;	 
}


 







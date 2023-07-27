/*
 * SPI.c
 *
 * Created: 7/26/2023 10:45:16 AM
 *  Author: muhammed mahmoud
 */ 
#include <avr/io.h>
#include "Common_Macros.h"
#include "DIO.h"
#define F_CPU 8000000UL
#include <util/delay.h>


void SPI_vINT_MASTER(void)
{
	/*Set MOSI & SCK & SS as o/p pins */
    DIO_vSetPinDir('b',4,1);//set ss 
	DIO_vSetPinDir('b',5,1);//set MOSI 
	DIO_vSetPinDir('b',7,1);//set SCK
	
	/*set mcu as master*/
	SET_BIT(SPCR,MSTR);
	
	/*set clk at F_CPU / 16*/
	/*SPR0  --> 1*/
	/*SPR1  --> 0*/
	/*SPI2X --> 0*/	
	SET_BIT(SPCR,SPR0);
	
	/*Enable spi*/
	SET_BIT(SPCR,SPE);
	
	/*Set slave select(SS) as high as i am the master */
	DIO_vWritePinValue('b',4,1);
	
}

  
void SPI_vINT_SLAVE(void)
{
	/*Enable spi*/
	SET_BIT(SPCR,SPE);
	
	/*Set MISO as o/p */
	DIO_vSetPinDir('b',6,1);
}

unsigned char  SPI_u8MASTER_TRANSMITE_RECEIVE(unsigned char data)
{
	/*Reset SS to select slave*/
	DIO_vWritePinValue('b',4,0);
	
	/*load data to SPDR*/
	SPDR = data; 
	
	/*wait to make sure that data is transmitted */
	while(READ_BIT(SPSR,SPIF)==0);// Interrupt flag 
	
	/*Read data from slave*/
	return SPDR;
}

unsigned char SPI_u8SLAVE_TRANSMITE_RECEIVE(unsigned char data)
{
	/*load data to spdr*/
	SPDR=data;
	
	/*wait to make sure that data is received*/
	while(READ_BIT(SPSR,SPIF)==0);
	
	/*read received data*/
	return SPDR;
	
}


void SPI_vMASTER_SEND_STRING(unsigned char *ptr)
{
	while( (*ptr) != 0)
	{
		SPI_vMASTER_TRANSMITE_RECEIVE(*ptr);
		*ptr++;
		_delay_ms(100);		
	}
}
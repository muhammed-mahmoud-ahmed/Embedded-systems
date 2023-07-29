/**
@file    usart.c
@version 1.0.0
@brief
@author  Muhammed Mahmoud (muhammed76mahmoud.ahmed@gmail.com)
@date    2023-07-25
*/

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "Common_Macros.h"

void UART_vINT(unsigned long baud_rate)
{
    /*setting UBRR to select desired baud rate*/
    /*mcu is working as normal speed */
    unsigned short UBRR;
    UBRR = ((F_CPU / (16 * baud_rate)) - 1);

    /* note that you have to write UBRRH first as mcu
       calculating baud rate after updating UBRRL    */
    UBRRH = (unsigned char)(UBRR >> 8);
    UBRRL = (unsigned char)UBRR;

    /*Enabling TX & RX*/
    SET_BIT(UCSRB, TXEN);
    SET_BIT(UCSRB, RXEN);

    /*configuration of UART frame*/
    /*we are working with no parity so bit 4,5 =0*/
    /*we are working with one stop bit --> bit 3 =0*/

    /*you have to write UCSRC 8-bit as it's sharing address with UBRRH*/
    /*bit 7 --> 1 : as i want to write in UCSRC*/

    /*we with char size as 8Bit*/
    /*bit 2 --> 1 : as i want to write in UCSRC*/
    /*bit 1 --> 1 : as i want to write in UCSRC*/

    UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
}

void UART_vSendData(unsigned char data)
{
    /*make sure that TX buffer (usart data register) is empty */
	while(READ_BIT(UCSRA,UDRE)==0);
	
	/*load data into TX buffer */
	UDR = data;
}

unsigned char UART_u8Receive_Data(void)
{
	/* pooling RXComplete to make sure that all received data stored in RX buffer (UDR)*/
	while(READ_BIT(UCSRA,RXC)==0);
	
	/* Read received data from RX buffer (UDR) */
	return UDR;
}

void UART_vSend_string(unsigned char *ptr)
{
	while((*ptr)!=0)
	{
		UART_vSendData(*ptr);
		ptr++;
		_delay_ms(100);
	}
}

/* --------------------- Revision Log ---------------------

    Date                  By                  Description
    ------------          ------------        ------------
    23/12/2002            Muhammed Mahmoud    hello world

----------------------------------------------------------*/

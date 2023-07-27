/**
@file    usart.h
@version 1.0.0
@brief
@author  Muhammed Mahmoud (muhammed76mahmoud.ahmed@gmail.com)
@date    2023-07-25
*/

#ifndef USART_H
#define USART_H

/*UART initialize */
void UART_vINT(unsigned long baud_rate);

/*UART send data*/
void UART_vSendData(unsigned char data);

/*UART receive data*/
unsigned char UART_u8Receive_Data(void);

/*UART sends string*/
void UART_vSend_string(unsigned char *ptr);
#endif

/* --------------------- Revision Log ---------------------

    Date                  By                  Description
    ------------          ------------        ------------
    23/12/2002            Muhammed Mahmoud    hello world

----------------------------------------------------------*/

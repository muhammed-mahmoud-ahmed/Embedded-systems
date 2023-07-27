/**
@file    LCD.c
@version 1.1.0
@brief
@author  Muhammed Mahmoud (muhammed76mahmoud.ahmed@gmail.com)
@date    2023-03-24
*/

/* -------------------- Linking section -------------------- */
#include <avr/io.h>
#include "DIO.h"
#include "LCD.h"

/*-----------------------------------------------------------*/

/* ------------------ Definition section ------------------ */
#define F_CPU 8000000UL
#include <util/delay.h>
/*----------------------------------------------------------*/

/* -------------- Global Declaration section -------------- */
/*----------------------------------------------------------*/

/* --------------------- Main section --------------------- */
/*----------------------------------------------------------*/

/* ---------------- Implementation section ---------------- */

// enable function
static void LCD_Enable_pulse(void)
{
	/*enable pulse with pulse duration 2ms*/
	DIO_vWritePinValue(LCD_ENABLE_PORT, LCD_ENABLE_PIN, 1);
	_delay_ms(2);
	DIO_vWritePinValue(LCD_ENABLE_PORT, LCD_ENABLE_PIN, 0);
	_delay_ms(2);
}

// Clear screen
void LCD_vClearScreen()
{
	LCD_vSendCommand(LCD_CLR_SCREEN); // call send command function
}

// LCD move cursor
void LCD_vMoveCursor(unsigned char row_num, unsigned char column_number)
{
	if ((row_num > 2) || (row_num < 1) || (column_number > 16) || (column_number < 1))
	{
		LCD_vSendCommand((LCD_FIRST_ROW + (column_number - 1))); // set address counter to this location
	}
	else if (row_num == 1)
	{
		LCD_vSendCommand((LCD_FIRST_ROW + (column_number - 1))); // set address counter to this location
	}
	else if (row_num == 2)
	{
		LCD_vSendCommand((LCD_SECOND_ROW + (column_number - 1))); // set address counter to this location
	}
	_delay_ms(1); // delay to check that the command has been executed
}

// new line
void LCD_vNewLine()
{
	LCD_vSendCommand(LCD_SECOND_ROW); // go to second row first column
}

// send string function
void LCD_vSendString(const unsigned char *string_ptr)
{
	while ((*string_ptr) != 0) // checks null
	{
		LCD_vSendChar(*string_ptr); // send char to LCD data lines
		_delay_ms(100);				// to see the writing operation
		string_ptr++;				// pointer ++
	}
}

/*
******************8_bit_MODE******************
*/
#if defined EIGHT_BIT_MODE
// send char function
void LCD_vSendChar(unsigned char data)
{
	DIO_vWritePortValue(LCD_PORT, data);			// send data to lcd data lines
	DIO_vWritePinValue(LCD_RS_PORT, LCD_RS_PIN, 1); // RS data select
	LCD_Enable_pulse();								// send enable pulse
}

// send command function
void LCD_vSendCommand(unsigned char command)
{
	DIO_vWritePortValue(LCD_PORT, command);			// send command to lcd data lines
	DIO_vWritePinValue(LCD_RS_PORT, LCD_RS_PIN, 0); // set RS mode as command mode
	LCD_Enable_pulse();								// send enable pulse
	_delay_ms(1);									// delay to make sure that command is executed
}

// LCD initialize
void LCD_vInitialize()
{

	DIO_vSetPortDir(LCD_PORT, 0xff);					// set port connected to lcd as output
	DIO_vSetPinDir(LCD_ENABLE_PORT, LCD_ENABLE_PIN, 1); // set pin connected to enable pin as output
	DIO_vSetPinDir(LCD_RS_PORT, LCD_RS_PIN, 1);			// set pin connected to RS pin as output
	_delay_ms(50);										// delay to make sure that vdd reached 4.5v
	LCD_vSendCommand(LCD_EIGHT_BIT_MODE);				// set lcd at 8-bit mode
	_delay_ms(1);										// to make sure that command is executed
	LCD_vSendCommand(LCD_CURSOR_ON_DISPLAY_ON);			// make cursor and display on
	_delay_ms(1);										// to make sure that command is executed
	LCD_vSendCommand(LCD_CLR_SCREEN);					// clear screen
	_delay_ms(1);										// to make sure that command is executed
	LCD_vSendCommand(LCD_ENTRY_MODE_RIGHT);				// set lcd in entry mode
	_delay_ms(1);										// to make sure that command is executed
	LCD_vSendCommand(LCD_RETURN_HOME);					// Return address counter to first column first row
}

/*
******************4_bit_MODE******************
*/
#elif defined FOUR_BIT_MODE

// LCD 4bit send command on low nibble of port
void LCD_vSendCommand(unsigned char command)
{
	DIO_vWritePinValue(LCD_RS_PORT, LCD_RS_PIN, 0);	   // RS command select
	DIO_vWritePortLowNibble(LCD_PORT, (command >> 4)); // write on port low nibble and write 4 most bits of data on data reg on lcd
	LCD_Enable_pulse();								   // send enable pulse
	DIO_vWritePortLowNibble(LCD_PORT, command);		   // write on port low nibble and write 4 least bits of data on data reg on lcd
	LCD_Enable_pulse();								   // send enable pulse
	_delay_ms(1);									   // delay to make sure that command is executed
}

void LCD_vSendChar(unsigned char data)
{
	DIO_vWritePinValue(LCD_RS_PORT, LCD_RS_PIN, 1); // RS data select
	DIO_vWritePortLowNibble(LCD_PORT, (data >> 4)); // write on port low nibble and write 4 most bits of data on data reg on lcd
	LCD_Enable_pulse();								// send enable pulse
	DIO_vWritePortLowNibble(LCD_PORT, data);		// write on port low nibble and write  4 least bits of data on data reg on lcd
	LCD_Enable_pulse();								// send enable pulse
}

void LCD_vInitialize()
{
	DIO_vSetPortLowNibble(LCD_PORT, 0xff);				// set port connected to lcd as output
	DIO_vSetPinDir(LCD_ENABLE_PORT, LCD_ENABLE_PIN, 1); // set pin connected to enable pin as output
	DIO_vSetPinDir(LCD_RS_PORT, LCD_RS_PIN, 1);			// set pin connected to RS pin as output
	_delay_ms(50);										// delay to make sure that vdd reached 4.5v
	LCD_vSendCommand(LCD_RETURN_HOME);					// mandatory command
	_delay_ms(10);										// to make sure that command is executed
	LCD_vSendCommand(LCD_FOUR_BIT_MODE);				// set lcd at 4-bit mode
	_delay_ms(1);										// to make sure that command is executed
	LCD_vSendCommand(LCD_CLR_SCREEN);					// clear screen
	_delay_ms(1);										// to make sure that command is executed
	LCD_vSendCommand(LCD_ENTRY_MODE_DISP_ON_CURSOR_ON); // make cursor and display on
	_delay_ms(1);										// to make sure that command is executed
	LCD_vSendCommand(LCD_ENTRY_MODE_CURSOR_RIGHT);				// make cursor move right
	_delay_ms(1);										// to make sure that command is executed
	LCD_vSendCommand(LCD_RETURN_HOME);					// set lcd in entry mode
	_delay_ms(1);										// to make sure that command is executed
}

#endif

/* not working
// LCD move cursor
void LCD_vMoveCursor(unsigned char row_num, unsigned char column_number)
{
	#if ((row_num > 2) || (row_num < 1) || (column_number > 16) || (column_number < 1))
	{
	#error Invalid operation --> check column & row
	}
	#elif (row_num == 0)
	{
		LCD_vSendCommand((FIRST_ROW + (column_number - 1))); // set address counter to this location
	}
	#elif (row_num == 1)
	{
		LCD_vSendCommand((SECOND_ROW + (column_number - 1))); // set address counter to this location
	}
	_delay_ms(1); // delay to check that the command has been executed
	#endif
}
*/

/*------------------------4-bit---------------------------*/
/*
// LCD 4bit send char on low nibble of port
void LCD_vSendChar_4bit_portLowNibble(unsigned char data)
{
	DIO_vWritePortLowNibble(LCD_PORT, (data >> 4)); // write on port low nibble and write 4 most bits of data on data reg on lcd
	DIO_vWritePinValue(LCD_RS_PORT, LCD_RS_PIN, 1); // RS data select
	LCD_Enable_pulse();								// send enable pulse
	DIO_vWritePortLowNibble(LCD_PORT, data);		// write on port low nibble and write  4 least bits of data on data reg on lcd
	LCD_Enable_pulse;								// send enable pulse
}
*/

/*
// LCD 4bit send char on high nibble of port
void LCD_vSendChar_4bit_portHighNibble(unsigned char data)
{
	DIO_vWritePortLowNibble(LCD_PORT, data);		// write on port high nibble and write 4 most bits of data on data reg on lcd
	DIO_vWritePinValue(LCD_RS_PORT, LCD_RS_PIN, 1); // RS data select
	LCD_Enable_pulse();								// send enable pulse
	DIO_vWritePortLowNibble(LCD_PORT, (data << 4)); // write on port low nibble and write 4 least bits of data on data reg on lcd
	LCD_Enable_pulse;								// send enable pulse
}
*/

/*
// LCD 4bit send command on low nibble of port
void LCD_vSendCommand_4bit_portLowNibble(unsigned char command)
{
	DIO_vWritePortLowNibble(LCD_PORT, (command >> 4)); // write on port low nibble and write 4 most bits of data on data reg on lcd
	DIO_vWritePinValue(LCD_RS_PORT, LCD_RS_PIN, 0);	   // RS command select
	LCD_Enable_pulse();								   // send enable pulse
	DIO_vWritePortLowNibble(LCD_PORT, command);		   // write on port low nibble and write 4 least bits of data on data reg on lcd
	LCD_Enable_pulse();								   // send enable pulse
	_delay_ms(1);									   // delay to make sure that command is executed
}
*/

/*
// LCD 4bit send command on high nibble of port
void LCD_vSendCommand_4bit_portHighNibble(unsigned char command)
{
	DIO_vWritePortLowNibble(LCD_PORT, (command));	   // write on port low nibble and write 4 most bits of data on data reg on lcd
	DIO_vWritePinValue(LCD_RS_PORT, LCD_RS_PIN, 0);	   // RS command select
	LCD_Enable_pulse();								   // send enable pulse
	DIO_vWritePortLowNibble(LCD_PORT, (command << 4)); // write on port low nibble and write 4 least bits of data on data reg on lcd
	LCD_Enable_pulse();								   // send enable pulse
	_delay_ms(1);									   // delay to make sure that command is executed
}
*/

/*----------------------------------------------------------*/

/* --------------------- Revision Log ---------------------

	Date                  By                  Description
	------------          ------------        ------------
	24/3/2023            Muhammed Mahmoud    LCD_DRIVER
	3/5/2023			 Muhammed Mahmoud    LCD_4_BIT_MODE

----------------------------------------------------------*/

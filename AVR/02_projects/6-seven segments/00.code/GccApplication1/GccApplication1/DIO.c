/*
 * DIO.c
 *
 * Created: 2/6/2023 6:28:02 PM
 *  Author: muhammed mahmoud
 */
#include <avr/io.h>
#include "Common_Macros.h"

// Bin Direction
void DIO_vSetPinDir(unsigned char port_name, unsigned char pin_num, unsigned char pin_direction)
{
	switch (port_name)
	{

	case 'A':
	case 'a':
		if (pin_direction == 1)
		{
			SET_BIT(DDRA, pin_num);
		}
		else
		{
			RESET_BIT(DDRA, pin_num);
		}
		break;

	case 'b':
	case 'B':

		if (pin_direction == 1)
		{
			SET_BIT(DDRB, pin_num);
		}
		else
		{
			RESET_BIT(DDRB, pin_num);
		}
		break;
	case 'c':
	case 'C':

		if (pin_direction == 1)
		{
			SET_BIT(DDRC, pin_num);
		}
		else
		{
			RESET_BIT(DDRC, pin_num);
		}
		break;
	case 'd':
	case 'D':

		if (pin_direction == 1)
		{
			SET_BIT(DDRD, pin_num);
		}
		else
		{
			RESET_BIT(DDRD, pin_num);
		}
		break;
	}
}

// write pin value
void DIO_vWritePinValue(unsigned char port_name, unsigned char pin_num, unsigned char pin_value)
{
	switch (port_name)
	{
	case 'A':
	case 'a':

		if (pin_value == 1)
		{
			SET_BIT(PORTA, pin_num);
		}
		else
		{
			RESET_BIT(PORTA, pin_num);
		}
		break;

	case 'b':
	case 'B':

		if (pin_value == 1)
		{
			SET_BIT(PORTB, pin_num);
		}
		else
		{
			RESET_BIT(PORTB, pin_num);
		}
		break;

	case 'c':
	case 'C':

		if (pin_value == 1)
		{
			SET_BIT(PORTC, pin_num);
		}
		else
		{
			RESET_BIT(PORTC, pin_num);
		}
		break;

	case 'd':
	case 'D':

		if (pin_value == 1)
		{
			SET_BIT(PORTD, pin_num);
		}
		else
		{
			RESET_BIT(PORTD, pin_num);
		}

		break;
	}
}

// Toggle pin
void DIO_vTogglePin(unsigned char port_name, unsigned char pin_num)
{
	switch (port_name)
	{
	case 'a':
	case 'A':
		TOGGLE_BIT(PORTA, pin_num);
		break;
	case 'b':
	case 'B':
		TOGGLE_BIT(PORTB, pin_num);
		break;

	case 'c':
	case 'C':
		TOGGLE_BIT(PORTC, pin_num);
		break;

	case 'd':
	case 'D':
		TOGGLE_BIT(PORTD, pin_num);
		break;
	}
}

// Read pin
unsigned char DIO_u8ReadPin(unsigned char port_name, unsigned char pin_number)
{
	unsigned char value;
	switch (port_name)
	{

	case 'a':
	case 'A':
		value = READ_BIT(PINA, pin_number);
		break;

	case 'b':
	case 'B':
		value = READ_BIT(PINB, pin_number);
		break;

	case 'c':
	case 'C':
		value = READ_BIT(PINC, pin_number);
		break;

	case 'd':
	case 'D':
		value = READ_BIT(PIND, pin_number);
		break;
	}
	return value;
}

// Pin pull-up
void DIO_vPinPullUp(unsigned char port_name, unsigned char pin_number, unsigned char enable)
{

	if (enable == 1)
	{
		DIO_vWritePinValue(port_name, pin_number, 1);
	}
	else
	{
		DIO_vWritePinValue(port_name, pin_number, 1);
	}

	// switch (port_name)
	// {
	// case 'a':
	// case 'A':
	// 	if (enable == 1)
	// 		SET_BIT(PORTA, pin_number);
	// 	else
	// 		RESET_BIT(PORTA, pin_number);
	// 	break;

	// case 'b':
	// case 'B':
	// 	if (enable == 1)
	// 		SET_BIT(PORTB, pin_number);
	// 	else
	// 		RESET_BIT(PORTB, pin_number);
	// 	break;

	// case 'c':
	// case 'C':
	// 	if (enable == 1)
	// 		SET_BIT(port_name, pin_number);
	// 	else
	// 		RESET_BIT(port_name, pin_number);
	// 	break;

	// case 'd':
	// case 'D':
	// 	if (enable == 1)
	// 		SET_BIT(port_name, pin_number);
	// 	else
	// 		RESET_BIT(port_name, pin_number);
	// 	break;
	// }
}

// Port Direction
void DIO_vSetPortDir(unsigned char port_name, unsigned char port_direction)
{
	switch (port_name)
	{
	case 'a':
	case 'A':
		DDRA = port_direction;
		break;

	case 'b':
	case 'B':
		DDRB = port_direction;
		break;

	case 'c':
	case 'C':
		DDRC = port_direction;
		break;

	case 'd':
	case 'D':
		DDRD = port_direction;
		break;
	}
}

// Write Port
void DIO_vWritePortValue(unsigned char port_name, unsigned char port_value)
{
	switch (port_name)
	{
	case 'a':
	case 'A':
		PORTA = port_value;
		break;

	case 'b':
	case 'B':
		PORTB = port_value;
		break;

	case 'c':
	case 'C':
		PORTC = port_value;
		break;

	case 'd':
	case 'D':
		PORTD = port_value;
		break;
	}
}

// Toggle Port

void DIO_vTogglePort(unsigned char port_name)
{
	switch (port_name)
	{
	case 'a':
	case 'A':
		PORTA = ~PORTA;
		break;

	case 'b':
	case 'B':
		PORTB = ~PORTB;
		break;

	case 'c':
	case 'C':
		PORTC = ~PORTC;
		break;

	case 'd':
	case 'D':
		PORTD = ~PORTD;
		break;
	}
}

// Read Port
unsigned char DIO_u8ReadPort(unsigned char port_name)
{
	unsigned char value;
	switch (port_name)
	{
	case 'a':
	case 'A':
		value = PINA;
		break;

	case 'b':
	case 'B':
		value = PINB;
		break;

	case 'c':
	case 'C':
		value = PINC;
		break;

	case 'd':
	case 'D':
		value = PIND;
		break;
	}
	return value;
}

// Port pull-up
void DIO_vPortPullUp(unsigned char port_name, unsigned char enable)
{

	if (enable == 1)
	{
		DIO_vWritePortValue(port_name, 255);
	}
	else
	{
		DIO_vWritePortValue(port_name, 0);
	}
}
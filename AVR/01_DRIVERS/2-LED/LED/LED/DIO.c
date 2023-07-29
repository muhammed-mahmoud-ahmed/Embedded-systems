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
	default:
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
	default:
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
	default:
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
	default:
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
		if ((DDRA) & (1 << pin_num)) // protection if the pin is input
		{
			if (pin_value == 1)
			{
				SET_BIT(PORTA, pin_num);
			}
			else
			{
				RESET_BIT(PORTA, pin_num);
			}
			break;
		}
		else
			break;

	case 'b':
	case 'B':
		if ((DDRB) & (1 << pin_num)) // protection if the pin is input
		{
			if (pin_value == 1)
			{
				SET_BIT(PORTB, pin_num);
			}
			else
			{
				RESET_BIT(PORTB, pin_num);
			}
			break;
		}
		else
			break;
	case 'c':
	case 'C':
		if ((DDRC) & (1 << pin_num)) // protection if the pin is input

		{
			if (pin_value == 1)
			{
				SET_BIT(PORTC, pin_num);
			}
			else
			{
				RESET_BIT(PORTC, pin_num);
			}
			break;
		}
		else
			break;
	case 'd':
	case 'D':
		if ((DDRD) & (1 << pin_num)) // protection if the pin is input
		{
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
		else
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
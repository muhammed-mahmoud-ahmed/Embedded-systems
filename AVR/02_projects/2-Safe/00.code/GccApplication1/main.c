/*
 * GccApplication1.c
 *
 * Created: 6/26/2023 1:22:24 PM
 * Author : muhammed mahmoud
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include "key_pad.h"
#include "EEPROM.h"
#include "LCD.h"
#include "DIO.h"
#include <util/delay.h >

#define new_user 0xff

/* define location of password */
/* 4 digit password */
#define EEPROM_STATUS_LOCATION 0x20    //location of password status (is set or not)
#define EEPROM_PASSWORD_LOCATION1 0x21 //location of first char of password
#define EEPROM_PASSWORD_LOCATION2 0x22 //location of second char of password
#define EEPROM_PASSWORD_LOCATION3 0x23 //location of third char of password
#define EEPROM_PASSWORD_LOCATION4 0x24 //location of fourth char of password 

#define MAX_TRIALS 3 //maximum trials for entering password

int main(void)
{
	unsigned char flag =0;//to detect if there is setted pass or not 
	signed char trials = MAX_TRIALS;//trials counter
	key_pad_initialize();//intializing key pad
	LCD_vInitialize();//intializing lcd
	unsigned char value;//value of keypad at setting
	unsigned char arr[4];//array to store password
	//LCD_vSendString("test");
	if(EEPROM_vRead(EEPROM_STATUS_LOCATION)==new_user)//check if it's first time or not
	{
		LCD_vSendString("Set pass:");
		for(unsigned char i =0;i<=3;i++)
		{
			do 
			{
				value=key_pad_read_u8Read();
			} while (value==KEY_PAD_NOT_PRESSED);
			EEPROM_vWrite(EEPROM_PASSWORD_LOCATION1+i,value);
			LCD_vSendChar(value);
			_delay_ms(500);
			LCD_vMoveCursor(1,10+i);
			LCD_vSendChar('*');
		}
		EEPROM_vWrite(EEPROM_STATUS_LOCATION,0x00);
		flag =0;
	}
		/* Replace with your application code */
		while (flag == 0) 
		{
			LCD_vClearScreen();
			arr[0]=arr[1]=arr[2]=arr[3]=0xff;
			LCD_vSendString("Enter pass:");
			for(signed char i =0;i<=3;i++)
			{
				do
				{
					arr[i]=key_pad_read_u8Read();
				} while (arr[i]==KEY_PAD_NOT_PRESSED);
				LCD_vSendChar(arr[i]);
				_delay_ms(500);
				LCD_vMoveCursor(1,12+i);
				LCD_vSendChar('*');
			}
			LCD_vClearScreen();	
			if( (arr[0]==EEPROM_vRead(EEPROM_PASSWORD_LOCATION1)) && (arr[1]==EEPROM_vRead(EEPROM_PASSWORD_LOCATION2)) && (arr[2]==EEPROM_vRead(EEPROM_PASSWORD_LOCATION3)) && (arr[3]==EEPROM_vRead(EEPROM_PASSWORD_LOCATION4)) )
			{
				LCD_vSendString("right pass");
				flag=1;
			}
			else
			{
				trials--;
				if (trials>0)
				{
					LCD_vSendString("wrong pass");
					_delay_ms(2000);
					LCD_vClearScreen();
					LCD_vSendString("left trials:");
					LCD_vSendChar(trials+48);
					_delay_ms(1000);
				}
				else
				{
					LCD_vSendString("wrong pass");
					_delay_ms(1000);
					LCD_vClearScreen();
					LCD_vSendString("no more.");
					flag =1;
					
				}
			}
		
		}
}


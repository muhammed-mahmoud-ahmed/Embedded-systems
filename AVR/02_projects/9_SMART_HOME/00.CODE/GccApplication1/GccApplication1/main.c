/*
 * GccApplication1.c
 *
 * Created: 7/27/2023 2:29:37 PM
 * Author : muhammed mahmoud
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "LCD.h"
#include "EEPROM.h"
#include "key_pad.h"
#include "ADC.h"
#include "LM_35.h"
#include "timer.h"
#include "DC_MOTOR.h"
#include "I2C.h"
#include "SERVO_MOTOR.h"


#define EEPROM_PASSWORD_LOCATION 0x21
#define EEPROM_NEW_USER_CHECK 0x30;

unsigned char enter_flag=0;//flag to detect if user is entered or not
unsigned char password[4];//array to store entered password and compare it
unsigned char password_tries=3;//to know how times users entered wrong password
unsigned char temperature;
unsigned char I2C_data;
unsigned char pressed_value;
unsigned char hours=0;
unsigned char minutes=0;
unsigned char seconds=0;
unsigned char car_distance;
unsigned char page_select='0';
unsigned char new_user_flag=1;

int main(void)
{
	
	DC_MOTOR_DUTY_CYCLE(0);
	SERVO_MOTOR_0();
	DIO_vWritePinValue('c',2,0);
	/************************************************************************/
	/*                   Initialization section                             */
	/************************************************************************/
	LCD_vInitialize();
	I2C_vMASTER_INT(50000);
	temp_vinitialize();
	key_pad_initialize();
	DIO_vSetPinDir('c',2,1);
	DIO_vSetPinDir('c',3,1);
	/************************************************************************/
	/*                    setting password for home                         */
	/************************************************************************/
	EEPROM_vWrite(0x21,'1');//store ascii of 1 as first digit of password
	EEPROM_vWrite(0x22,'2');//store ascii of 2 as second digit of password
	EEPROM_vWrite(0x23,'3');//store ascii of 3 as third digit of password
	EEPROM_vWrite(0x24,'4');//store ascii of 4 as fourth digit of password
	
	/************************************************************************/
	/*               NEW USER CHECKER                                       */
	/************************************************************************/
	if(EEPROM_vRead(0x30)==0xff)
	{
		LCD_vSendString("New User");
		_delay_ms(1000);
		LCD_vClearScreen();
		LCD_vSendString("SET PASSWORD");
		LCD_vNewLine();
		
		for(unsigned char i=0;i<4;i++)
		{
			do
			{
				pressed_value=key_pad_read_u8Read();
			} while (pressed_value==KEY_PAD_NOT_PRESSED);
			EEPROM_vWrite(0x21+i,pressed_value);
			LCD_vSendChar(pressed_value);
			_delay_ms(250);
			LCD_vMoveCursor(2,i+1);
			LCD_vSendChar('*');
		}
		_delay_ms(250);//delay for last digit
		new_user_flag=0;
		EEPROM_vWrite(0x30,0x00);
	}
	
	// important 
	if(EEPROM_vRead(0x30)==0x00)
	{
		new_user_flag=0;
	}
	
	
	/************************************************************************/
	/*                    IDENTITY CHECKING                                 */
	/************************************************************************/
	
	while( (enter_flag == 0) && (password_tries >0 ) && (new_user_flag==0) )//when flag is one that means that pass is correct , when tries reaches zero that means that user entered wrong pass 3 times
	{
		LCD_vClearScreen();
		LCD_vSendString("Welcome :)");
		_delay_ms(1000);
		LCD_vClearScreen();
		
		LCD_vSendString("Enter PassWord:");
		LCD_vNewLine();
		password[0]=password[1]=password[2]=password[3]=0xff;// give it any default value (this default value for eeprom)
		
		for(unsigned char i=0;i<4;i++)
		{
			do 
			{
				password[i]=key_pad_read_u8Read();
			} while (password[i]==KEY_PAD_NOT_PRESSED);
			LCD_vSendChar(password[i]);
			_delay_ms(250);
			LCD_vMoveCursor(2,i+1);
			LCD_vSendChar('*');
		}
		_delay_ms(250);//delay for last digit in password
		
		LCD_vClearScreen();
		if((password[0]==EEPROM_vRead(0x21)) && (password[1]==EEPROM_vRead(0x22)) && (password[2]==EEPROM_vRead(0x23)) && (password[3]==EEPROM_vRead(0x24)))
		{
			
			LCD_vSendString("Right P@ssW0rd:)");
			_delay_ms(1000);
			enter_flag =1 ;
			LCD_vClearScreen();
			LCD_vSendString("LOCK Opening");
			SERVO_MOTOR_180();
			_delay_ms(2000);
			SERVO_MOTOR_0();
			
		}
		
		else 
		{
			password_tries--;
			LCD_vSendString("wrong P@ssW0rd");
			_delay_ms(1000);
			LCD_vClearScreen();
			LCD_vSendString("left tries=");
			LCD_vSendChar(password_tries+48);
			_delay_ms(500);
			LCD_vClearScreen();	
		}
		
		if(password_tries==0)
		{
			LCD_vSendString("no more");
			LCD_vNewLine();
			LCD_vSendString("shut down system");
		}
	}
	
	
	
	/************************************************************************/
	/*                AFTER ACTIVATION SECTION                              */
	/************************************************************************/
	
   
    while (enter_flag==1) 
    {
		
		/************************************************************************/
		/*               MAIN PAGE SECTION                                      */
		/************************************************************************/
		if(page_select=='0')
		{
			LCD_vClearScreen();
			LCD_vSendString("1-AIR COND.");
			LCD_vNewLine();
			LCD_vSendString("2-RTC");
			LCD_vMoveCursor(2,8);
			LCD_vSendString("3-GARAGE");
			
			do 
			{
				page_select=key_pad_read_u8Read();
			} while (page_select==KEY_PAD_NOT_PRESSED);
			_delay_ms(250);
			LCD_vNewLine();//remember to remove
			LCD_vSendChar(page_select);//remember to remove
		}
		
		
		/************************************************************************/
		/*                AIR CONDINTIONER SECTION                              */
		/************************************************************************/
		else if (page_select == '1')
		{
			LCD_vClearScreen();
			LCD_vSendString("AIR CONDITIONER");
			_delay_ms(1000);
			
			LCD_vClearScreen();
			temperature=temp_u8value();
			if(temperature<=50)
			{
				/*iam dealing as 50 temp is the max temp.*/
				LCD_vSendString("Temperature=");
				LCD_vSendChar((temperature/10)+48);
				LCD_vSendChar((temperature%10)+48);
				LCD_vSendChar(0xDF);//to display temp mark
				LCD_vSendChar('C');//to display Celisius
				
				LCD_vNewLine();
				LCD_vSendString("Duty_cycle=");
				LCD_vSendChar((((int)((temperature/50.0)*100))/10)+48);
				LCD_vSendChar((((int)((temperature/50.0)*100))%10)+48);
				LCD_vSendChar('%');
				DC_MOTOR_DUTY_CYCLE((temperature/50.0)*100);
				_delay_ms(2000);
								
			}
			else
			{
				LCD_vSendString("over heat");
				DC_MOTOR_DUTY_CYCLE(0);
				_delay_ms(2000);
			}
			page_select='0';
			
		}
		
		/************************************************************************/
		/*               REAL TIME CLK SECTION                                  */
		/************************************************************************/
		
		else if (page_select == '2')
		{
			LCD_vClearScreen();
			LCD_vSendString("REAL TIME CLK");
			_delay_ms(1000);
			
			LCD_vClearScreen();
			LCD_vSendString("press 1");
			LCD_vNewLine();
			LCD_vSendString("to adjust:");
			
			do 
			{
				I2C_data=key_pad_read_u8Read();
			} while (I2C_data==KEY_PAD_NOT_PRESSED);
			
			if(I2C_data == '1')
			{
				LCD_vClearScreen();
				
				LCD_vSendString("Set Hours:--");
				LCD_vMoveCursor(1,11);
				do
				{
					pressed_value=key_pad_read_u8Read();
				} while (pressed_value==KEY_PAD_NOT_PRESSED);
				LCD_vSendChar(pressed_value);
				_delay_ms(250);
				hours=(pressed_value-48)*10;
				
				do
				{
					pressed_value=key_pad_read_u8Read();
				} while (pressed_value==KEY_PAD_NOT_PRESSED);
				LCD_vSendChar(pressed_value);
				_delay_ms(500);
				hours=hours+(pressed_value-48);
				
				
				DIO_vWritePinValue('c',2,1);//enable config. mode in RTC
				_delay_ms(100);
				I2C_vSTART();
				I2C_vSEND_ADDRESS(0x06,I2C_WRITE);
				I2C_vWRITE_DATA(hours);
				I2C_vSTOP();
				DIO_vWritePinValue('c',2,0);
				LCD_vClearScreen();
				
				
				
				LCD_vSendString("Set Minutes:--");
				LCD_vMoveCursor(1,13);
				do
				{
					pressed_value=key_pad_read_u8Read();
				} while (pressed_value==KEY_PAD_NOT_PRESSED);
				LCD_vSendChar(pressed_value);
				_delay_ms(250);
				minutes=(pressed_value-48)*10;
				
				do
				{
					pressed_value=key_pad_read_u8Read();
				} while (pressed_value==KEY_PAD_NOT_PRESSED);
				LCD_vSendChar(pressed_value);
				_delay_ms(500);
				minutes=minutes+(pressed_value-48);
				
				
				DIO_vWritePinValue('c',2,1);//enable config. mode in RTC
				_delay_ms(100);
				I2C_vSTART();
				I2C_vSEND_ADDRESS(0x06,I2C_WRITE);
				I2C_vWRITE_DATA(minutes);
				I2C_vSTOP();
				DIO_vWritePinValue('c',2,0);
				LCD_vClearScreen();
				
				
				LCD_vSendString("Set Seconds:--");
				LCD_vMoveCursor(1,13);
				do
				{
					pressed_value=key_pad_read_u8Read();
				} while (pressed_value==KEY_PAD_NOT_PRESSED);
				LCD_vSendChar(pressed_value);
				_delay_ms(250);
				seconds=(pressed_value-48)*10;
				
				do
				{
					pressed_value=key_pad_read_u8Read();
				} while (pressed_value==KEY_PAD_NOT_PRESSED);
				LCD_vSendChar(pressed_value);
				_delay_ms(500);
				seconds=seconds+(pressed_value-48);
				
				
				DIO_vWritePinValue('c',2,1);//enable config. mode in RTC
				_delay_ms(100);
				I2C_vSTART();
				I2C_vSEND_ADDRESS(0x06,I2C_WRITE);
				I2C_vWRITE_DATA(seconds);
				I2C_vSTOP();
				DIO_vWritePinValue('c',2,0);
				LCD_vClearScreen();
				
				
				
			}
			else
			{
				LCD_vClearScreen();
				LCD_vSendString("not an option");
				_delay_ms(1000);
			}
			page_select='0';
			
		}
		
		/************************************************************************/
		/*                     ACCESS GARAGE                                    */
		/************************************************************************/
		else if(page_select == '3')
		{
			
			LCD_vClearScreen();
			LCD_vSendString("GARAGE");
			DIO_vWritePinValue('c',3,1);
			_delay_ms(3000);
			I2C_vSTART();
			I2C_vSEND_ADDRESS(0x08,I2C_READ);
			car_distance=I2C_read_with_NO_ACK();
			I2C_vSTOP();
			_delay_ms(50);
			DIO_vWritePinValue('c',3,0);
			
			if(car_distance>80)
			{
				LCD_vClearScreen();
				LCD_vSendString("CAR IS NOT");
				LCD_vNewLine();
				LCD_vSendString("FOUND o_O ");
				_delay_ms(1000);
			}
			else 
			{
				LCD_vClearScreen();
				LCD_vSendString("CAR IS FOUND :D");
				LCD_vNewLine();
				LCD_vSendString("DISTANCE=--");
				LCD_vMoveCursor(2,10);
				LCD_vSendChar((car_distance/10)+48);
				LCD_vSendChar((car_distance%10)+48);
				LCD_vSendString("cm");
				_delay_ms(1000);
			}
			
			page_select='0';
		}
		
		else
		{
			LCD_vClearScreen();
			LCD_vSendString("NOT OPTION!!");
			_delay_ms(1000);
			page_select = '0';
		}
    }
}


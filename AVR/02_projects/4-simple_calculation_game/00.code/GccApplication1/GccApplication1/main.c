/*
 * GccApplication1.c
 *
 * Created: 6/29/2023 11:46:37 AM
 * Author : muhammed mahmoud
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "LCD.h"
#include "key_pad.h"
#include "timer.h"
#define F_CPU 8000000UL
#include <util/delay.h>

volatile unsigned short game_timer = 0;
volatile unsigned short game_timer_flag = 0;

int main(void)
{
	LCD_vInitialize();
	unsigned char num1;
	unsigned char num2;
	unsigned char press_1=KEY_PAD_NOT_PRESSED;	  // take the value of first press
	unsigned char press_2=KEY_PAD_NOT_PRESSED;	  // take the value of second press
	unsigned char press_flag; // to check if the user moved away his finger from button (mksl a3mlo)
	unsigned char summation;  // the summation of num1&2(press) entered by user
	key_pad_initialize();
	timer_vSelect_mode(0, TIMER_MODE_CTC);
	/* Replace with your application code */
	while (1)
	{
		
		LCD_vClearScreen();
		num1 = rand() % 100; // generate random num less than 100
		num2 = rand() % 100; // generate random num less than 100

		if ((num1 + num2) < 100)
		{
			/*dispaly num 1*/
			LCD_vSendChar((num1 / 10) + 48);
			_delay_ms(100);
			LCD_vSendChar((num1 % 10) + 48);
			_delay_ms(100);

			/*dispaly + sign*/
			LCD_vSendChar('+');
			_delay_ms(100);

			/*dispaly num 2*/
			LCD_vSendChar((num2 / 10) + 48);
			_delay_ms(100);
			LCD_vSendChar((num2 % 10) + 48);
			_delay_ms(100);

			/*dispaly =? sign*/
			LCD_vSendString("=?");
			
			/*
			LCD_vMoveCursor(2,1);
			LCD_vSendString("Left Time:");
			LCD_vMoveCursor(2,15);
			LCD_vSendString("10");
			*/
			
			game_timer=0;//after printing the data on lcd let's start timer
			game_timer_flag=0;//to restart state of timer
				
			/*read value of pressed button*/
			do
			{
				press_1 = key_pad_read_u8Read();
			} while ((press_1 == KEY_PAD_NOT_PRESSED) && (game_timer_flag == 0));
			if (press_1 != KEY_PAD_NOT_PRESSED)
			{
				LCD_vMoveCursor(1, 7);
				LCD_vSendChar(press_1);
				/*read value of pressed button*/
				_delay_ms(250); // to prevent press1&2 taking the same value because of the mcu clk is faster than your finger movement from button to another .
			}
			
			
			do
			{
				press_2 = key_pad_read_u8Read();
			} while ((press_2 == KEY_PAD_NOT_PRESSED) && (game_timer_flag == 0));
			if (press_1 != KEY_PAD_NOT_PRESSED)
			{	
				LCD_vSendChar(press_2);
				game_timer_flag = 1;
				_delay_ms(250);
			}
			

			summation = ((press_1 - 48) * 10) + (press_2 - 48); // i should return to a number because keypad returns char value

			if (summation == (num1 + num2))
			{
				LCD_vClearScreen();
				game_timer = 1100;
				LCD_vSendString("Right Answer :D");
			}
			else if( (summation!=(num1+num2)) && ( press_2!=0xff))
			{
				LCD_vClearScreen();
				game_timer = 1100;
				LCD_vSendString("Wrong Answer :(");
			}
			else if((game_timer_flag==1))
			{
					LCD_vClearScreen();
					LCD_vSendString("Time Out >_<");
					LCD_vMoveCursor(1, 17);
			}	
			
			
			_delay_ms(2000);
			
			LCD_vClearScreen();
			LCD_vSendString("Play Again?");
			_delay_ms(2000);
			LCD_vNewLine();
			LCD_vSendString("Let's GO!");
			_delay_ms(2000);
			
			

			/* //this code is if you don't take answer of summation process from user
			if ((num1 + num2) < 10)
			{
				LCD_vSendChar(num1 + num2 + 48);
				LCD_vSendChar(0x20);
			}

			else if ((num1 + num2) >= 10)
			{
				LCD_vSendChar(((num1 + num2) / 10) + 48);
				LCD_vSendChar(((num1 + num2) % 10) + 48);
			}
			_delay_ms(2000);
			LCD_vClearScreen();
			*/
		}
	}
}
ISR(TIMER0_COMP_vect)
{
	
	game_timer++;
	/*
	if(((game_timer%100)==0)&&(game_timer<10))
	{
		LCD_vMoveCursor(2,15);
		LCD_vSendChar((10-(game_timer%100))+48);
		LCD_vSendChar(0x20);
	}
	*/
	
	if ((game_timer == 1000) && (game_timer_flag == 0)) // 10 seconds
	{
		game_timer = 0;
		game_timer_flag = 1;
		//LCD_vClearScreen();
		//LCD_vSendString("Time Out >_<");
		//LCD_vMoveCursor(1, 17);
	}
	
}

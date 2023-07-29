/*
 * GccApplication1.c
 *
 * Created: 5/10/2023 8:02:06 PM
 * Author : muhammed mahmoud
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "LCD.h"
#include "DIO.h"
#include "button.h"


int main(void)
{
	unsigned char counter_a = 0;//initialize counter a
	unsigned char counter_b = 0;//initialize counter b
	unsigned char counter_c = 0;//initialize counter c
	unsigned char counter_d = 0;//initialize counter d
	
	LCD_vInitialize();//initialize lcd
	
	LCD_vSendString("A=000");
	LCD_vMoveCursor(1,12);
	LCD_vSendString("B=000");
	LCD_vMoveCursor(2,1);
	LCD_vSendString("C=000");
	LCD_vMoveCursor(2,12);
	LCD_vSendString("D=000");
	
	button_vInitialize('b',0);
	button_vInitialize('b',1);
	button_vInitialize('b',2);
	button_vInitialize('b',3);
	button_vInitialize('b',4); 
	unsigned char flag=0;
    /* Replace with your application code */
    while (1) 
    {

		
		if((button_ucRead('b',0)==1) && (flag ==0))
		{
			counter_a++;
			LCD_vMoveCursor(1,3);//go to position a
			LCD_vSendChar(counter_a/100 + 48);//to display hundred numbers;
			LCD_vSendChar((counter_a%100)/10 + 48);//to display tenth number ;
			LCD_vSendChar((counter_a%10)+48);//to display lsb number;
			flag =1;
		}
		
		else if((button_ucRead('b',1)==1) && (flag ==0))
		{
			counter_b++;
			LCD_vMoveCursor(1,14);
			LCD_vSendChar(counter_b/100 + 48);//to display hundred numbers;
			LCD_vSendChar((counter_b%100)/10 + 48);//to display tenth number ;
			LCD_vSendChar((counter_b%10)+48);//to display lsb number;
			flag =1;
		}
		
		else if((button_ucRead('b',2)==1) && (flag ==0))
		{
			counter_c++;
			LCD_vMoveCursor(2,3);
			LCD_vSendChar(counter_c/100 + 48);//to display hundred numbers;
			LCD_vSendChar((counter_c%100)/10 + 48);//to display tenth number ;
			LCD_vSendChar((counter_c%10)+48);//to display lsb number;
			flag =1;
		}
		
		else if((button_ucRead('b',3)==1) && (flag ==0))
		{
			counter_d++;
			LCD_vMoveCursor(2,14);
			LCD_vSendChar(counter_d/100 + 48);//to display hundred numbers;
			LCD_vSendChar((counter_d%100)/10 + 48);//to display tenth number ;
			LCD_vSendChar((counter_d%10)+48);//to display lsb number;
			flag =1;
		}
		
		else if(button_ucRead('b',4)==1)
		{
			LCD_vMoveCursor(1,1);
			LCD_vSendString("A=000");
			LCD_vMoveCursor(1,12);
			LCD_vSendString("B=000");
			LCD_vMoveCursor(2,1);
			LCD_vSendString("C=000");
			LCD_vMoveCursor(2,12);
			LCD_vSendString("D=000");
			counter_a=0;
			counter_b=0;
			counter_c=0;
			counter_d=0;
		}
		_delay_ms(50);
		
		/************************************************************************/
		/*enable control to ensure that button clicked one time                 */
		/************************************************************************/
		if( (button_ucRead('b',0)==0) && (button_ucRead('b',1)==0) && (button_ucRead('b',2)==0) && (button_ucRead('b',3)==0) )
		{
			flag=0;
		}
    
	}
}


/**
@file    lcd.c
@version 1.0.0
@brief
@author  Muhammed Mahmoud (muhammed76mahmoud.ahmed@gmail.com)
@date    2023-05-02
*/

/* -------------------- Linking section -------------------- */
#include "DIO.h"
#include"LCD.h"
#include "Common_Macros.h"
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

void commands(unsigned char command)
{
    DIO_vWritePortLowNibble('d',(command>>4));
    DIO_vWritePinValue(LCD_RS_PORT,LCD_RS_PIN,0);
    LCD_Enable_pulse();
    DIO_vWritePortLowNibble('d',command);
    DIO_vWritePinValue(LCD_RS_PORT,LCD_RS_PIN,0);
    LCD_Enable_pulse();
}

void initialize(void)
{
    DIO_vSetPinDir('d', 0, 1);
    DIO_vSetPinDir('d', 1, 1);
    DIO_vSetPinDir('d', 2, 1);
    DIO_vSetPinDir('d', 3, 1);
    DIO_vSetPinDir(LCD_ENABLE_PORT, LCD_ENABLE_PIN, 1); // set pin connected to enable pin as output
    DIO_vSetPinDir(LCD_RS_PORT, LCD_RS_PIN, 1);         // set pin connected to RS pin as output
    _delay_ms(50);

}

/*----------------------------------------------------------*/

/* --------------------- Revision Log ---------------------

    Date                  By                  Description
    ------------          ------------        ------------
    23/12/2002            Muhammed Mahmoud    hello world

----------------------------------------------------------*/
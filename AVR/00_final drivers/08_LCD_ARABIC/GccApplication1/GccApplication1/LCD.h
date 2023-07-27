/**
@file    LCD.h
@version 1.0.0
@brief
@author  Muhammed Mahmoud (muhammed76mahmoud.ahmed@gmail.com)
@date    2023-03-24
*/

/* -------------------- Linking section -------------------- */
/*-----------------------------------------------------------*/

/* ------------------ Definition section ------------------ */

#ifndef LCD_H_
#define LCD_H_

#include "LCD_CONFIG.h"
#define LCD_EIGHT_BIT_MODE 0x38                // set lcd at 8-bit mode
#define LCD_FOUR_BIT_MODE 0x28                 // set lcd at 8-bit mode
#define LCD_CLR_SCREEN 0x01                    // clear screen
#define LCD_RETURN_HOME 0x02                   // return address counter to home with address 0x00
#define LCD_ENTRY_MODE_CURSOR_RIGHT 0x06       // set lcd in entry mode cursor on move to right
#define LCD_ENTRY_MODE_CURSOR_LEFT 0x04        // set lcd in entry mode cursor on move to left
#define LCD_ENTRY_MODE_CURSOR_BLINK 0x0F       // set lcd in entry mode cursor blink
#define LCD_ENTRY_MODE_SHIFT_DISPLAY 0x07      // set lcd in entry mode cursor on shift display to right
#define LCD_ENTRY_MODE_DISP_ON_CURSOR_ON 0x0E  // set lcd in entry mode lcd on cursor on
#define LCD_ENTRY_MODE_DISP_ON_CURSOR_OFF 0x0C // set lcd in entry mode lcd on cursor off
#define LCD_ENTRY_MODE_DISP_OFF_CURSOR_ON 0x0A // set lcd in entry mode lcd off cursor on
#define LCD_ENTRY_MODE_SHIFT_DISP_RIGHT 0x1C   // shift disp content to right
#define LCD_ENTRY_MODE_SHIFT_DISP_LEFT 0x18    // shift disp content to left
#define LCD_RST_ADD_COUNTER 0x80               // reset address counter to address 0x00
#define LCD_FIRST_ROW 0X80                     // set address counter at first row column 0
#define LCD_SECOND_ROW 0xc0                    // set address counter at second row column 0
#define LCD_CGRAM 64                           // to write in cgram first addres

/*----------------------------------------------------------*/

/* -------------- Global Declaration section -------------- */
// enable function
static void LCD_Enable_pulse(void);

// send char function
void LCD_vSendChar(unsigned char data);

// send command function
void LCD_vSendCommand(unsigned char command);

// Clear screen
void LCD_vClearScreen();

// LCD initialize
void LCD_vInitialize();

// LCD move cursor
void LCD_vMoveCursor(unsigned char row_num, unsigned char column_number);

// new line
void LCD_vNewLine();

// send string function
void LCD_vSendString(const unsigned char *string_ptr);
#endif /* LCD_H_ */
/*----------------------------------------------------------*/

/* --------------------- Main section --------------------- */
/*----------------------------------------------------------*/

/* ---------------- Implementation section ---------------- */
/*----------------------------------------------------------*/

/* --------------------- Revision Log ---------------------

    Date                  By                  Description
    ------------          ------------        ------------
    24/3/2023            Muhammed Mahmoud    LCD_DRIVER

----------------------------------------------------------*/

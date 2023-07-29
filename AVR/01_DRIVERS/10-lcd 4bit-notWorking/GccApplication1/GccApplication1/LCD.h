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

#define LCD_PORT 'd'                  // lcd (data & command)port
#define LCD_ENABLE_PORT 'c'           // Enable port
#define LCD_ENABLE_PIN 1              // Enable pin
#define LCD_RS_PORT 'c'               // Register Select port
#define LCD_RS_PIN 0                  // Register Select pin
#define LCD_EIGHT_BIT_MODE 0x38       // set lcd at 8-bit mode
#define LCD_FOUR_BIT_MODE 0x28        // set lcd at 8-bit mode
#define LCD_CLR_SCREEN 0x01           // clear screen
#define LCD_CURSOR_ON_DISPLAY_ON 0x0e // set Display and Cursor on
#define LCD_RETURN_HOME 0x02          // return address counter to home with address 0x00
#define LCD_ENTRY_MODE 0x06           // set lcd in entry mode
#define LCD_RST_ADD_COUNTER 0x80      // reset address counter to address 0x00
#define LCD_FIRST_ROW 0X80            // set address counter at first row column 0
#define LCD_SECOND_ROW 0xc0           // set address counter at second row column 0

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

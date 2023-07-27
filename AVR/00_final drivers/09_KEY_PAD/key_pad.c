/**
@file    key_pad.c
@version 1.0.0
@brief
@author  Muhammed Mahmoud (muhammed76mahmoud.ahmed@gmail.com)
@date    2023-05-08
*/

/* -------------------- Linking section -------------------- */
#include "key_pad.h"
/*-----------------------------------------------------------*/

/* ------------------ Definition section ------------------ */
/*----------------------------------------------------------*/

/* -------------- Global Declaration section -------------- */
/*----------------------------------------------------------*/

/* --------------------- Main section --------------------- */
/*----------------------------------------------------------*/

/* ---------------- Implementation section ---------------- */

/* Key_pad initialization function */
void key_pad_initialize(void)
{
    DIO_vSetPortLowNibble(KEY_PAD_PORT, 0x0F);  /* set low nipple bits of port as output*/
    DIO_vSetPortHighNibble(KEY_PAD_PORT, 0x0F); /* set high nipple bits of port as input*/
    DIO_vPinPullUp(KEY_PAD_PORT, 4, 1);         /* enable internal pull up on pin 4*/
    DIO_vPinPullUp(KEY_PAD_PORT, 5, 1);         /* enable internal pull up on pin 5*/
    DIO_vPinPullUp(KEY_PAD_PORT, 6, 1);         /* enable internal pull up on pin 6*/
    DIO_vPinPullUp(KEY_PAD_PORT, 7, 1);         /* enable internal pull up on pin 7*/
}

/* Key_pad read function */
unsigned char key_pad_read_u8Read(void)
{
    /* values of buttons to send it lcd as chars */
    unsigned char value[4][4] = {{'1', '2', '3', '+'}, {'4', '5', '6', '-'}, {'7', '8', '9', '*'}, {'%', '0', '=', '/'}};
    unsigned char row_counter;                          /* rows counter */
    unsigned char column_counter;                       /* column counter */
    unsigned char pin_value;                            /* pin value */
    unsigned char returned_value = KEY_PAD_NOT_PRESSED; /*any value not included in array is acceptable*/
    unsigned char x;
    for (row_counter = 0; row_counter < 4; row_counter++)
    {
        DIO_vWritePortLowNibble(KEY_PAD_PORT, 0x0F);      /* output high on low nibble of port */
        DIO_vWritePinValue(KEY_PAD_PORT, row_counter, 0); /* output low on specific row */
        for (column_counter = 0; column_counter < 4; column_counter++)
        {
            x=button_ucRead(KEY_PAD_PORT, column_counter + 4);
            if ( x == 0) /* to read pin value & +4 because we are writing on high nipple */
            {
                returned_value = value[row_counter][column_counter]; /* return saved value of button */
                break;
            }
            else
            {
                returned_value = KEY_PAD_NOT_PRESSED; /* if no button is pressed return the default value */
            }
        }

        if (x == 0) /* if any button is pressed break the loop*/
        {
            break;
        }
    }
    return returned_value;
}

/*----------------------------------------------------------*/

/* --------------------- Revision Log ---------------------

    Date                  By                  Description
    ------------          ------------        ------------
    23/12/2002            Muhammed Mahmoud    hello world

----------------------------------------------------------*/
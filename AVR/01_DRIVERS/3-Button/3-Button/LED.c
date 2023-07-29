/*
 * LED.c
 *
 * Created: 2/7/2023 5:34:10 PM
 *  Author: muhammed mahmoud
 */ 

#include "DIO.h"
//led initialize :
void LED_vInitialize(unsigned char port_name,unsigned char pin_num)
{
    DIO_vSetPinDir(port_name,pin_num,1);
}


//led on :
void LED_vOn(unsigned char port_name,unsigned char pin_num)
{
    DIO_vWritePinValue(port_name,pin_num,1);
}

//led off :
void LED_vOff(unsigned char port_name,unsigned char pin_num)
{
    DIO_vWritePinValue(port_name,pin_num,0);
}

//led toggle :
void LED_vToggle(unsigned char port_name,unsigned char pin_num)
{
    DIO_vTogglePin(port_name,pin_num);
}
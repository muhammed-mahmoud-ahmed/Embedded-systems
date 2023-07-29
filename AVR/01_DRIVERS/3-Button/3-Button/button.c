#include<avr/io.h>
#include "Common_Macros.h"
#include "DIO.h"

//button initialize
void button_vInitialize (unsigned char port_name,unsigned char pin_num)
{
    DIO_vSetPinDir(port_name,pin_num,0);
}

//button read
unsigned char button_ucRead(unsigned char port_name,unsigned char pin_num)
{
    return DIO_u8ReadPin(port_name,pin_num);
}

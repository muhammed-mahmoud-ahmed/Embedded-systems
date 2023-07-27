#include <avr/io.h>
#include "Common_Macros.h"
#include "DIO.h"

//7-seg initialize
void seven_segment_vIinitialize(unsigned char port_name)
{
    DIO_vSetPortDir(port_name,0xff);
} 

//7-seg write
void seven_segment_vWrite(unsigned char port_name,unsigned char value)
{
    unsigned char seven_segment[16] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};
    #if defined cc
    DIO_vWritePortValue(port_name,seven_segment[value]);
    #elif defined ca
    DIO_vWritePortValue(port_name,~seven_segment[value]);
    #endif
}

//7-seg initialize bcd decoder
void seven_segment_bcd_vIniialize(unsigned char port_name ,unsigned char start_pin)
{
    for(unsigned char i=0;i<4;i++)
    {
        DIO_vSetPinDir(port_name,start_pin,1);
        start_pin++;
    }
}

//7-seg write bcd decoder
void seven_segment_bcd_vWrite(unsigned char port_name,unsigned char start_pin,unsigned char value)
{
    for(unsigned i=0;i<4;i++)
    {
        DIO_vWritePinValue(port_name,start_pin,((value>>i)&1));
        start_pin++;
    }
}

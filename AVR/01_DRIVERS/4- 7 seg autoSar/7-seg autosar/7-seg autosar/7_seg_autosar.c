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
    unsigned char seven_segment[16] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7c, 0x07, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};
    DIO_vWritePortValue(port_name,seven_segment[value]);
}
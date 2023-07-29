#include <avr/io.h>
#include "Common_Macros.h"
#define ca

// initialize 7 seg
void seven_segment_vinitialize(unsigned char port_name)
{
    switch (port_name)
    {
    case 'a':
    case 'A':
        DDRA = 0xff;
        break;

    case 'b':
    case 'B':
        DDRB = 0xff;
        break;

    case 'c':
    case 'C':
        DDRC = 0xff;
        break;

    case 'd':
    case 'D':
        DDRD = 0xff;
        break;

    default:
        break;
    }
}

// 7-seg write
void seven_segment_vWrite(unsigned char port_name, unsigned char value)
{
    #if defined  cc
    unsigned char seven_segment[16] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};
    #elif defined ca
    unsigned char seven_segment[16] = {~0x3f, ~0x06, ~0x5b, ~0x4f, ~0x66, ~0x6d,~0x7d, ~0x07, ~0x7f, ~0x6f, ~0x77, ~0x7c, ~0x39, ~0x5e, ~0x79, ~0x71};
    #endif
    switch (port_name)
    {
    case 'a':
    case 'A':
        PORTA = seven_segment[value];
        break;

    case 'b':
    case 'B':
        PORTB = seven_segment[value];
        break;

    case 'c':
    case 'C':
        PORTC = seven_segment[value];
        break;

    case 'd':
    case 'D':
        PORTD = seven_segment[value];
        break;

    default:
        break;
    }
}
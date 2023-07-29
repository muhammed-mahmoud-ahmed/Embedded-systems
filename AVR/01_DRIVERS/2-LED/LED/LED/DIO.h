/*
 * DIO.h
 *
 * Created: 2/6/2023 6:28:21 PM
 *  Author: muhammed mahmoud
 */

#ifndef DIO_H_
#define DIO_H_

// #include "Common_Macros.h"
void DIO_vSetPinDir(unsigned char port_name, unsigned char pin_num, unsigned char pin_direction);
void DIO_vWritePinValue(unsigned char port_name, unsigned char pin_num, unsigned char pin_value);
void DIO_vTogglePin(unsigned char port_name, unsigned char pin_num);
void DIO_vSetPortDir(unsigned char port_name, unsigned char port_direction);
void DIO_vWritePortValue(unsigned char port_name, unsigned char port_value);
void DIO_vTogglePort(unsigned char port_name);

#endif /* DIO_H_ */
#ifndef _EEPROM_H_
#define _EEPROM_H_

//write function
void EEPROM_vWrite(unsigned short address,unsigned char data);

//read function
unsigned char EEPROM_vRead(unsigned short address);

#endif
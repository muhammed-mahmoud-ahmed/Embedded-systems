/*
 * EEPROM_I2C.h
 *
 * Created: 7/27/2023 10:19:21 AM
 *  Author: muhammed mahmoud
 */ 


#ifndef EEPROM_I2C_H_
#define EEPROM_I2C_H_

void EEPROM_I2C_vWRITE_DATA(unsigned char eeprom_address, unsigned char data_address, unsigned char data);
unsigned char EEPROM_I2C_u8READ_DATA(unsigned char eeprom_address, unsigned char data_address);




#endif /* EEPROM_I2C_H_ */
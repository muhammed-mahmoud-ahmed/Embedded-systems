//not working


//EEPROM data register
#define EEPROM_DATA_REG (*((unsigned char *)0x003D))

//EEPROM address register low
#define EEPROM_ADDLOW_REG (*((unsigned char *)0x003E))

//EEPROM address register high
#define EEPROM_ADDHIGH_REG (*((unsigned char *)0x003F))

//EEPROM control reg
//#define EEPROM_CONTROL_REG *((unsigned char*)0x003C) //not working
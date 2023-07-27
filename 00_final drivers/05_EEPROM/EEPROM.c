#include <avr/io.h>
#include "my_eeprom_machros.h"
#include "Common_Macros.h"
//Write function
void EEPROM_vWrite(unsigned short address,unsigned char data)
{
    EEPROM_ADDLOW_REG=(char)(address);
    EEPROM_ADDHIGH_REG=(char)(address>>8);
    EEPROM_DATA_REG=data;
    SET_BIT(EECR,EEMWE);//eemwe refers to master write bit 2 
    SET_BIT(EECR,EEWE);
    while(READ_BIT(EECR,EEWE)==1);//to make sure that writing process has been completed and EEWE returned 0  
}

//Read function
unsigned char EEPROM_vRead(unsigned short address)
{
    EEPROM_ADDLOW_REG=(char)(address);
    EEPROM_ADDHIGH_REG=(char)(address>>8);
    SET_BIT(EECR,EERE);
    return EEPROM_DATA_REG;
}
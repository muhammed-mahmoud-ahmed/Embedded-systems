/*
 * I2C.h
 *
 * Created: 7/26/2023 2:07:22 PM
 *  Author: muhammed mahmoud
 */ 


#ifndef I2C_H_
#define I2C_H_

void I2C_vMASTER_INT(unsigned long SCL_CLK);
void I2C_vSTART(void);
void I2C_vSTOP(void);
void I2C_vSET_ADDRESS(unsigned char address);
void I2C_vWRITE_ADDRESS(unsigned char address);
void I2C_vWRITE_DATA(unsigned char data);
unsigned char I2C_u8SLAVE_READ(void);
unsigned char I2C_u8MASTER_READ_DATA_No_ACK(void);
void I2C_vMASTER_READ_ADDRESS(unsigned char address);





#endif /* I2C_H_ */
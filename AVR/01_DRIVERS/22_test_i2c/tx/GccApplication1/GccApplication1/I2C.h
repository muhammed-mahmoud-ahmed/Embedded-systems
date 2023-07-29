/*
 * I2C.h
 *
 * Created: 7/26/2023 2:07:22 PM
 *  Author: muhammed mahmoud
 */

#ifndef I2C_H_
#define I2C_H_

#define I2C_WRITE 0 // to choose write while sending address
#define I2C_READ 1  // to choose read while sending address

void I2C_vMASTER_INT(unsigned long SCL_CLK);
void I2C_vSTART(void);
void I2C_vSET_ADDRESS(unsigned char address);
void I2C_vSEND_ADDRESS(unsigned char address , unsigned char R_W);
void I2C_vWRITE_DATA(unsigned char data);
unsigned char I2C_u8SLAVE_READ(void);
void I2C_vSTOP(void);
void I2C_vSTART_REPEAT(void);
unsigned char I2C_read_with_NO_ACK(void);
unsigned char I2C_read_with_ACK(void);

#endif /* I2C_H_ */
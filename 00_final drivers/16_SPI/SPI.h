/*
 * SPI.h
 *
 * Created: 7/26/2023 10:45:03 AM
 *  Author: muhammed mahmoud
 */ 


#ifndef SPI_H_
#define SPI_H_

void SPI_vINT_MASTER(void);
void SPI_vINT_SLAVE(void);
unsigned char  SPI_u8MASTER_TRANSMITE_RECEIVE(unsigned char data);
unsigned char SPI_u8SLAVE_TRANSMITE_RECEIVE(unsigned char data);
void SPI_vMASTER_SEND_STRING(unsigned char *ptr);




#endif /* SPI_H_ */
/*
 * LED.h
 *
 * Created: 2/7/2023 5:33:51 PM
 *  Author: muhammed mahmoud
 */ 


#ifndef LED_H_
#define LED_H_

void LED_vInitialize(unsigned char port_name,unsigned char pin_num); // led initialize
void LED_vOn(unsigned char port_name,unsigned char pin_num); // led on
void LED_vOff(unsigned char port_name,unsigned char pin_num); // led off 
void LED_vToggle(unsigned char port_name,unsigned char pin_num); //toggle led

#endif /* LED_H_ */
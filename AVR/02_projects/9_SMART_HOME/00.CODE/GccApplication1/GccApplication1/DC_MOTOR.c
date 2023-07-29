/*
 * DC_MOTOR.c
 *
 * Created: 7/15/2023 6:59:23 PM
 *  Author: muhammed mahmoud
 */ 
#include "timer.h"

void DC_MOTOR_DUTY_CYCLE(unsigned char duty_cycle)
{
	//it's connected to timer 0
	//enter duty cycle in percentage like 0:100
	//(ocr/TCNT)*100 = duty_cycle
	//ocr=(duty_cycle/100)*tcnt-->(duty_cycle/100)*255
	unsigned char ocr_value=(duty_cycle/100.0F)*255;//you should convert in number to float in dividing because it will give you zero
	timer_vSelect_mode(0,TIMER_MODE_FAST_PWM,ocr_value);
}
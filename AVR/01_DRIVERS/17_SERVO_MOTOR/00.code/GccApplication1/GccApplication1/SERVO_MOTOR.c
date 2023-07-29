/*
 * SERVO_MOTOR.c
 *
 * Created: 7/29/2023 9:07:33 AM
 *  Author: muhammed mahmoud
 */ 
#include "timer.h"

void SERVO_MOTOR_180()
{
	TIMER1_WAVE_FAST_PWM(1);
}

void SERVO_MOTOR_0()
{
	TIMER1_WAVE_FAST_PWM(2);
}

void SERVO_MOTOR_90()
{
	TIMER1_WAVE_FAST_PWM(1.5);
}
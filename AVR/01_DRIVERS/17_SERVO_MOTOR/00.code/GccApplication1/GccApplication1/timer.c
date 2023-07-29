/**
@file    timer.c
@version 1.0.0
@brief
@author  Muhammed Mahmoud (muhammed76mahmoud.ahmed@gmail.com)
@date    2023-06-28
*/
#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"
#include "DIO.h"
#define F_CPU 8000000UL
#include <util/delay.h>


void TIMER1_WAVE_FAST_PWM(double value)
{
	/* set OC1A as output pin */
	SET_BIT(DDRD,5);
	/* select fast PWM mode*/
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	/* load a value in OCR1A,ICR1 */
	OCR1A=value*1000;
	ICR1=19999;
	/* select timer clock, PRESCALLER/8 */
	SET_BIT(TCCR1B,1);
	/* clear OC1A on compare match, set OC1A at BOTTOM,(non inverting mode)*/
	SET_BIT(TCCR1A,COM1A1);

}

unsigned char TIMER_ICU_dutyCycle_highFerq()
{
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned short duty_high;
	unsigned char duty_cycle;
	unsigned short period;
    unsigned short frequency;
	
	
	TCCR1A=0;// i am working in normal mode with | i am not generating signal i am capturing
	TIFR = (1<<ICF1);//clear flag --> don't remove
    SET_BIT(TCCR1B,0);//select no prescaller 
	SET_BIT(TCCR1B,7);//enable noise cancelling
	
    
	
	/*second rising edge*/
	SET_BIT(TCCR1B,6);//trigger on rising edge
	while(READ_BIT(TIFR,ICF1)==0);//pooling on flag until it's got triggerd
	c=ICR1;//load value from start to second rising
	SET_BIT(TIFR,ICF1);//clear flag by writing one on it
	
	duty_high=b-a;
	period=c-a;
	duty_cycle=((float)duty_high/period)*100;
    //frequency=F_CPU/period;
    return duty_cycle;

}


unsigned short TIMER_ICU_measureFreq_highFerq()
{
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned short duty_high;
	unsigned char duty_cycle;
	unsigned short period;
    unsigned short frequency;
	
	
	TCCR1A=0;// i am working in normal mode with | i am not generating signal i am capturing
	TIFR = (1<<ICF1);//clear flag --> don't remove
    SET_BIT(TCCR1B,0);//select no prescaller 
	SET_BIT(TCCR1B,7);//enable noise cancelling
	
	/*first rising edge*/
	SET_BIT(TCCR1B,6);//trigger on rising edge
	while(READ_BIT(TIFR,ICF1)==0);//pooling on flag until it's got triggerd
	a=ICR1;//load value from start to first rising edge
	SET_BIT(TIFR,ICF1);//clear flag by writing one on it
	
	
	/*first falling edge*/
	RESET_BIT(TCCR1B,6);//trigger on falling edge 
	while(READ_BIT(TIFR,ICF1)==0);//pooling on flag until it's got triggerd	
	b=ICR1;//load value from start to first falling 
	SET_BIT(TIFR,ICF1);//clear flag by writing one on it
	
	
	/*second rising edge*/
	SET_BIT(TCCR1B,6);//trigger on rising edge
	while(READ_BIT(TIFR,ICF1)==0);//pooling on flag until it's got triggerd
	c=ICR1;//load value from start to second rising
	SET_BIT(TIFR,ICF1);//clear flag by writing one on it
	
	TCCR1B = 0;
	
	
	duty_high=b-a;
	period=c-a;
	//duty_cycle=((float)duty_high/period)*100;
    frequency=F_CPU/period;
	return frequency;
}

unsigned short TIMER_ICU_measureFreq_lowFerq()
{
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned short duty_high;
	unsigned char duty_cycle;
	unsigned short period;
    unsigned short frequency;
	
	
	TCCR1A=0;// i am working in normal mode with | i am not generating signal i am capturing
	TIFR = (1<<ICF1);//clear flag --> don't remove
    SET_BIT(TCCR1B,1);//select prescaller /8
	SET_BIT(TCCR1B,7);//enable noise cancelling
	
	/*first rising edge*/
	SET_BIT(TCCR1B,6);//trigger on rising edge
	while(READ_BIT(TIFR,ICF1)==0);//pooling on flag until it's got triggerd
	a=ICR1;//load value from start to first rising edge
	SET_BIT(TIFR,ICF1);//clear flag by writing one on it
	
	
	/*first falling edge*/
	RESET_BIT(TCCR1B,6);//trigger on falling edge 
	while(READ_BIT(TIFR,ICF1)==0);//pooling on flag until it's got triggerd	
	b=ICR1;//load value from start to first falling 
	SET_BIT(TIFR,ICF1);//clear flag by writing one on it
	
	
	/*second rising edge*/
	SET_BIT(TCCR1B,6);//trigger on rising edge
	while(READ_BIT(TIFR,ICF1)==0);//pooling on flag until it's got triggerd
	c=ICR1;//load value from start to second rising
	SET_BIT(TIFR,ICF1);//clear flag by writing one on it
	
	TCCR1B = 0;
	
	
	duty_high=b-a;
	period=c-a;
	//duty_cycle=((float)duty_high/period)*100;
    frequency=F_CPU/(8ul*period);
	return frequency;
}

unsigned char TIMER_ICU_dutyCycle_lowFerq()
{
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned short duty_high;
	unsigned char duty_cycle;
	unsigned short period;
    unsigned short frequency;
	
	
	TCCR1A=0;// i am working in normal mode with | i am not generating signal i am capturing
	TIFR = (1<<ICF1);//clear flag --> don't remove
    SET_BIT(TCCR1B,1);//select prescaller /8
	SET_BIT(TCCR1B,7);//enable noise cancelling
	
	/*first rising edge*/
	SET_BIT(TCCR1B,6);//trigger on rising edge
	while(READ_BIT(TIFR,ICF1)==0);//pooling on flag until it's got triggerd
	a=ICR1;//load value from start to first rising edge
	SET_BIT(TIFR,ICF1);//clear flag by writing one on it
	
	/*first falling edge*/
	RESET_BIT(TCCR1B,6);//trigger on falling edge 
	while(READ_BIT(TIFR,ICF1)==0);//pooling on flag until it's got triggerd	
	b=ICR1;//load value from start to first falling 
	SET_BIT(TIFR,ICF1);//clear flag by writing one on it
	
	/*second rising edge*/
	SET_BIT(TCCR1B,6);//trigger on rising edge
	while(READ_BIT(TIFR,ICF1)==0);//pooling on flag until it's got triggerd
	c=ICR1;//load value from start to second rising
	SET_BIT(TIFR,ICF1);//clear flag by writing one on it
	
	duty_high=b-a;
	period=c-a;
	duty_cycle=((float)duty_high/period)*100;
    //frequency=F_CPU/period;
    return duty_cycle;
}


// note if you are using overflow mode you can put any value for OCR
void timer_vSelect_mode(unsigned char timer_num_select, unsigned char timer_mode_select, unsigned char timer_pwm_value)
{

    switch (timer_num_select)
    {
    case 0:
    {
        switch (timer_mode_select)
        {
        case TIMER_MODE_OVERFLOW: // user choosed overflow mode

            /*set timer clk*/
            /*assume 8MHZ is the mcu clk*/
            /*timer clk will be 8MHZ/1024 --> 7.8123KHZ */
            /*timer tick time --> 1/timer_clk = 128uT */
            /*the timer overflow time = 256 * 128uT = 32.768ms */
            SET_BIT(TCCR0, CS00);
            SET_BIT(TCCR0, CS02);

            sei();                 // enable interrupt in system
            SET_BIT(TIMSK, TOIE0); // enable interrupt of OVERFLOW timer0

            break;

        case TIMER_MODE_CTC: // user choosed ctc mode.

            /*set bits of TCCR0 to choose ctc mode*/
            /*to enable that wgm01 = 1 and wgm00 = 0*/
            SET_BIT(TCCR0, WGM01);

            OCR0 = 80; // to make it 10ms so it can be configurable

            /*set timer clk*/
            /*assume 8MHZ is the mcu clk*/
            /*timer clk will be 8MHZ/1024 --> 7.8123KHZ */
            /*timer tick time --> 1/timer_clk = 128uT */
            SET_BIT(TCCR0, CS00);
            SET_BIT(TCCR0, CS02);

            sei();                 // enable interrupt in system
            SET_BIT(TIMSK, OCIE0); // enable interrupt of CTC timer0
            break;

        case TIMER_MODE_NON_PWM:

            SET_BIT(DDRB, 3); // set bin 3B as output

            /*set bits of TCCR0 to choose ctc mode*/
            /*to enable that wgm01 = 1 and wgm00 = 0*/
            SET_BIT(TCCR0, WGM01);

            OCR0 = 64; // value of ocr0 to decide frequency

            /*set timer clk*/
            /*assume 8MHZ is the mcu clk*/
            /*timer clk will be 8MHZ/1024 --> 7.8123KHZ */
            /*timer tick time --> 1/timer_clk = 128uT */
            SET_BIT(TCCR0, CS00);
            SET_BIT(TCCR0, CS02);

            SET_BIT(TCCR0, COM00); // toggle oc0 on compare match
            break;

        case TIMER_MODE_FAST_PWM_INVERTING:

            DIO_vSetPinDir('b', 3, 1); // set pinB3 as O/P

            /*select fast pwm mode*/
            SET_BIT(TCCR0, WGM00);
            SET_BIT(TCCR0, WGM01);

            OCR0 = timer_pwm_value;

            /*set timer clk*/
            /*assume 8MHZ is the mcu clk*/
            /*timer clk will be 8MHZ/1024 --> 7.8123KHZ */
            /*timer tick time --> 1/timer_clk = 128uT */
            SET_BIT(TCCR0, CS00);
            SET_BIT(TCCR0, CS02);

            /*set oc0 compare on compare match,clear on overflow*/
            SET_BIT(TCCR0, COM00);
            SET_BIT(TCCR0, COM01);
            break;

        case TIMER_MODE_FAST_PWM:
            DIO_vSetPinDir('b', 3, 1); // set pinB3 as O/P

            /*select fast pwm mode*/
            SET_BIT(TCCR0, WGM00);
            SET_BIT(TCCR0, WGM01);

            OCR0 = timer_pwm_value;

            /*set timer clk*/
            /*assume 8MHZ is the mcu clk*/
            /*timer clk will be 8MHZ/1024 --> 7.8123KHZ */
            /*timer tick time --> 1/timer_clk = 128uT */
            SET_BIT(TCCR0, CS00);
            SET_BIT(TCCR0, CS02);

            /*set oc0 compare on compare match,clear on overflow*/
            SET_BIT(TCCR0, COM01);
            break;

        default:
            break;
        }
    }
    break;

    case 2:
    {
        switch (timer_mode_select)
        {
        case TIMER_OVERFLOW_EXT_OSC:
        {
            /*this driver is built as it will be used in Real Time Clock */
            /*set bit AS2 to choose external clk on pin TOSC1*/
            SET_BIT(ASSR, AS2);

            /*set timer prescaller to 128 */
            SET_BIT(TCCR2, CS20);
            SET_BIT(TCCR2, CS22);

            /*enable interrupt*/
            sei(); // global interrupt
            SET_BIT(TIMSK, TOIE2);
        }
        break;

        default:
            break;
        }
    }
    }
}

/* --------------------- Revision Log ---------------------

    Date                  By                  Description
    ------------          ------------        ------------
    23/12/2002            Muhammed Mahmoud    hello world

----------------------------------------------------------*/
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

// note if you are using overflow mode you can put any value for OCR
timer_vSelect_mode(unsigned char timer_num_select, unsigned char timer_mode_select, unsigned char timer_pwm_value)
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
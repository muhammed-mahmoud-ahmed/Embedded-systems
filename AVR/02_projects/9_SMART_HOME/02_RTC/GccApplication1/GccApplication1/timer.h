/**
@file    timer.h
@version 1.0.0
@brief
@author  Muhammed Mahmoud (muhammed76mahmoud.ahmed@gmail.com)
@date    2023-06-28
*/

#ifndef TIMER_H_
#define TIMER_H_

#define TIMER_MODE_OVERFLOW 0           // macro for timer overflow
#define TIMER_MODE_CTC 1                // macro for timer ctc
#define TIMER_MODE_NON_PWM 2            // generating square wave signal
#define TIMER_MODE_FAST_PWM_INVERTING 3 // generating pwm signal with specific duty cycle
#define TIMER_MODE_FAST_PWM 4           // generating pwm signal with specific duty cycle
#define TIMER_OCR0_DEFAULT_VALUE 0xFF   // default value of ocr0 for pwm
#define TIMER_OVERFLOW_EXT_OSC 5        // choose this to set timer 2 to get clk from external osc.
/*mode selecting function*/
timer_vSelect_mode(unsigned char timer_num_select, unsigned char timer_mode_select, unsigned char timer_pwm_value);

#endif

/* --------------------- Revision Log ---------------------

    Date                  By                  Description
    ------------          ------------        ------------
    23/12/2002            Muhammed Mahmoud    hello world

----------------------------------------------------------*/

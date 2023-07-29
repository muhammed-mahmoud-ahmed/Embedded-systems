/**
@file    timer.h
@version 1.0.0
@brief
@author  Muhammed Mahmoud (muhammed76mahmoud.ahmed@gmail.com)
@date    2023-06-28
*/

#ifndef TIMER_H_
#define TIMER_H_

#define TIMER_MODE_OVERFLOW 0 // macro for timer overflow
#define TIMER_MODE_CTC 1      // macro for timer ctc
#define TIMER_MODE_NON_PWM 2  //generating square wave signal

/*mode selecting function*/
timer_vSelect_mode(unsigned char timer_num_select, unsigned char timer_mode_select);

#endif

    /* --------------------- Revision Log ---------------------

        Date                  By                  Description
        ------------          ------------        ------------
        23/12/2002            Muhammed Mahmoud    hello world

    ----------------------------------------------------------*/

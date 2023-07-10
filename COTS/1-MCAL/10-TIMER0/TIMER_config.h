/*************************************************************/
/*************************************************************/
/******************    Author: Sherif Taher ******************/
/******************    Layer:  MCAL         ******************/
/******************    SWC:    TIMER        ******************/
/******************    Version:1.00         ******************/
/*************************************************************/
/*************************************************************/

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

/*choose:1-TIMER_OFF
 * 		 2-NO_PRESCALER
 * 		 3-PRESCALER_8
 * 		 4-PRESCALER_64
 * 		 5-PRESCALER_256
 * 		 6-PRESCALER_1024
 * 		 7-EXTERNAL_CLOACK_FALLING_EDGE
 * 		 8-EXTERNAL_CLOACK_RISING_EDGE*/

#define Prescaler		PRESCALER_256

/*Choose: 1-Normal_Mode
 * 		  2-Phase_Correct
 * 		  3-CTC
 * 		  4-Fast_PWM*/

#define TIMER_MODE		Normal_Mode
#endif

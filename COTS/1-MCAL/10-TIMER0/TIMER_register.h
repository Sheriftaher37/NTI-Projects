/*************************************************************/
/*************************************************************/
/******************    Author: Sherif Taher ******************/
/******************    Layer:  MCAL         ******************/
/******************    SWC:    TIMER        ******************/
/******************    Version:1.00         ******************/
/*************************************************************/
/*************************************************************/

#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

#define TCCR0			*((volatile u8*)0x53)		/*Contol register*/
#define TCCR0_FOC0				7			/*Force output compare*/
#define TCCR0_WGM00				6			/*waveform generation mode(Normal,Phase correct,CTC,Fast PWM)*/
#define TCCR0_COM01				5			/*Compare match output mode(OC0 disconnect,Toggle OC0,Clear OC0,Set OC0)*/
#define TCCR0_COM00				4			/*Compare match output mode(OC0 disconnect,Toggle OC0,Clear OC0,Set OC0)*/
#define TCCR0_WGM01				3			/*waveform generation mode(Normal,Phase correct,CTC,Fast PWM)*/
#define TCCR0_CS02				2			/*Clock set(No clock source,No prescalling,from prescaler.....)*/
#define TCCR0_CS01				1			/*Clock set(No clock source,No prescalling,from prescaler.....)*/
#define TCCR0_CS00				0			/*Clock set(No clock source,No prescalling,from prescaler.....)*/

#define TCNT0			*((volatile u8*)0x52)		/*READ and Write register*/
#define OCR0			*((volatile u8*)0x5C)		/*Compare register with TCNT0*/

#define TIMSK			*((volatile u8*)0x59)		/*Interrupt mask register*/
#define TIMSK_OCIE0					1			/*1 for compare match interupt enable*/
#define TIMSK_TOIE0					0			/*1 for Overflow interrupt enable*/

#define TIFR			*((volatile u8*)0x58)		/*Interrupt flag register*/
#define TIFR_OCF0					1			/*Output compare flag*/
#define TIFR_TOV0					0			/*Overflow flag*/

#define SFIOR			*((volatile u8*)0x50)		/*Special function register*/
#define PSR10					0			/*1 for prescaler reset*/

#endif

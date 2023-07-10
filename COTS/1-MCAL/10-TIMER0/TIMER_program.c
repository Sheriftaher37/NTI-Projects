/*************************************************************/
/*************************************************************/
/******************    Author: Sherif Taher ******************/
/******************    Layer:  MCAL         ******************/
/******************    SWC:    TIMER        ******************/
/******************    Version:1.00         ******************/
/*************************************************************/
/*************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER_interface.h"
#include "TIMER_config.h"
#include "TIMER_private.h"
#include "TIMER_register.h"

/*global pointer to function to hold TIMER0 ISR address*/
static void (*TIMER0_pvCallBackNotificationFunc)(void) = NULL;

void TIMER0_voidInit(void)
{
	/*Set Timer/Counter0 Mode*/
#if TIMER_MODE==Normal_Mode

	CLR_BIT(TCCR0,TCCR0_WGM01);
	CLR_BIT(TCCR0,TCCR0_WGM00);

	/*Enable interrupt*/
	SET_BIT(TIMSK,TIMSK_TOIE0);

#elif TIMER_MODE==Phase_Correct
	CLR_BIT(TCCR0,TCCR0_WGM01);
	SET_BIT(TCCR0,TCCR0_WGM00);

#elif TIMER_MODE==CTC

	SET_BIT(TCCR0,TCCR0_WGM01);
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_FOC0);		/*set fource output compare*/


#elif TIMER_MODE==Fast_PWM

	SET_BIT(TCCR0,TCCR0_WGM01);
	SET_BIT(TCCR0,TCCR0_WGM00);

#else
#error	"Timer Mode Error"
#endif

	/*Set timer/Counter0 Prescaler*/
	TCCR0 &= 0b11111000;
	TCCR0 |= Prescaler;

	/*Enable interrupt*/

}


u8 TIMER0_u8SetCallBack(void(*Copy_pvTIMER0Func)(void))
{
	u8 Local_u8ErrorStatus=OK;
	if(Copy_pvTIMER0Func != NULL)
	{
		TIMER0_pvCallBackNotificationFunc=Copy_pvTIMER0Func;
	}
	else
	{
		Local_u8ErrorStatus=NULL_POINTER;
	}

	return Local_u8ErrorStatus;
}

void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{
	if(TIMER0_pvCallBackNotificationFunc!= NULL)
	{
		EXTI_pvInt0Func();
	}
	else
	{
		/*do nothing*/
	}
}

/*************************************************************/
/*************************************************************/
/******************    Author: Sherif Taher ******************/
/******************    Layer:  MCAL         ******************/
/******************    SWC:    INT0         ******************/
/******************    Version:1.00         ******************/
/*************************************************************/
/*************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "INT0_interface.h"
#include "INT0_private.h"
#include "INT0_config.h"
#include "INT0_register.h"

/*global pointer to function to hold INT0 ISR address*/
void (*EXTI_pvInt0Func)(void)=NULL;


void EXTI_voidInt0Init(void)
{
	/*check sense control*/
#if INT0_SENSE == LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);

#elif INT0_SENSE == ON_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);

#elif INT0_SENSE == FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);

#elif INT0_SENSE == RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);
#else
#error "Wrong INT0_SENSE configration option"
#endif

	/*check peripheral interrupt enable (SIE) initial state*/
#if INT0_INITIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT0);
#elif INT0_INITIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT0);
#else
#error "Wrong INT0_INITIAL_STATE configration"
#endif
}



u8 EXTI_u8Int0SetSenseControl(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState=OK;

	switch(Copy_u8Sense)
	{
	case LOW_LEVEL:
		CLR_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);
		break;
	case ON_CHANGE:
		SET_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);
		break;
	case FALLING_EDGE:
		CLR_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);
		break;
	case RISING_EDGE:
		SET_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);
		break;
	default:
		Local_u8ErrorState=NOK;
		break;
	}

	return Local_u8ErrorState;
}

void EXTI_u8Int0Enable(void)
{
		SET_BIT(GICR,GICR_INT0);
}


void EXTI_u8IntDisable(void)
{
		CLR_BIT(GICR,GICR_INT0);
}


u8 EXTI_u8Int0SetCallBack(void(*Copy_pvInt0Func)(void))
{
	u8 Local_u8ErrorStatus=OK;
	if(Copy_pvInt0Func != NULL)
	{
		EXTI_pvInt0Func=Copy_pvInt0Func;
	}
	else
	{
		Local_u8ErrorStatus=NULL_POINTER;
	}

	return Local_u8ErrorStatus;
}

void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if(EXTI_pvInt0Func!= NULL)
	{
		EXTI_pvInt0Func();
	}
	else
	{
		/*do nothing*/
	}
}


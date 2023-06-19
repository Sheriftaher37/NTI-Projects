/*************************************************************/
/*************************************************************/
/******************    Author: Sherif Taher ******************/
/******************    Layer:  MCAL         ******************/
/******************    SWC:    EXTI         ******************/
/******************    Version:1.00         ******************/
/*************************************************************/
/*************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "INT1_interface.h"
#include "INT1_private.h"
#include "INT1_config.h"
#include "INT1_register.h"

/*global pointer to function to hold INT0 ISR address*/
void (*EXTI_pvInt1Func)(void)=NULL;


void EXTI_voidInt1Init(void)
{
	/*check sense control*/
#if INT1_SENSE == LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC11);
	CLR_BIT(MCUCR,MCUCR_ISC10);

#elif INT1_SENSE == ON_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);

#elif INT1_SENSE == FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);

#elif INT1_SENSE == RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);
#else
#error "Wrong INT1_SENSE configration option"
#endif

	/*check peripheral interrupt enable (SIE) initial state*/
#if INT1_INITIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT1);
#elif INT1_INITIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT1);
#else
#error "Wrong INT1_INITIAL_STATE configration"
#endif
}


u8 EXTI_u8Int1SetSenseControl(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState=OK;

	switch(Copy_u8Sense)
	{
	case LOW_LEVEL:
		CLR_BIT(MCUCR,MCUCR_ISC11);
		CLR_BIT(MCUCR,MCUCR_ISC10);
		break;
	case ON_CHANGE:
		SET_BIT(MCUCR,MCUCR_ISC10);
		CLR_BIT(MCUCR,MCUCR_ISC11);
		break;
	case FALLING_EDGE:
		CLR_BIT(MCUCR,MCUCR_ISC10);
		SET_BIT(MCUCR,MCUCR_ISC11);
		break;
	case RISING_EDGE:
		SET_BIT(MCUCR,MCUCR_ISC10);
		SET_BIT(MCUCR,MCUCR_ISC11);
		break;
	default:
		Local_u8ErrorState=NOK;
		break;
	}

	return Local_u8ErrorState;
}


void EXTI_u8Int1Enable(void)
{
		SET_BIT(GICR,GICR_INT1);
}

void EXTI_u8Int1Disable(void)
{
		CLR_BIT(GICR,GICR_INT1);
}

u8 EXTI_u8Int1SetCallBack(void(*Copy_pvInt1Func)(void))
{
	u8 Local_u8ErrorStatus=OK;
	if(Copy_pvInt1Func != NULL)
	{
		EXTI_pvInt1Func=Copy_pvInt1Func;
	}
	else
	{
		Local_u8ErrorStatus=NULL_POINTER;
	}

	return Local_u8ErrorStatus;
}

void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	if(EXTI_pvInt1Func!= NULL)
	{
		EXTI_pvInt1Func();
	}
	else
	{
		/*do nothing*/
	}
}



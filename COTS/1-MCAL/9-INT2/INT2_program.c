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

#include "INT2_interface.h"
#include "INT2_private.h"
#include "INT2_config.h"
#include "INT2_register.h"

/*global pointer to function to hold INT0 ISR address*/

void (*EXTI_pvInt2Func)(void)=NULL;



void EXTI_voidInt2Init(void)
{
	/*check sense control*/

#if INT2_SENSE == FALLING_EDGE
	CLR_BIT(MCUCSR,MCUCSR_INT2);

#elif INT2_SENSE == RISING_EDGE
	SET_BIT(MCUCSR,MCUCSR_INT2);
#else
#error "Wrong INT2_SENSE configration option"
#endif

	/*check peripheral interrupt enable (SIE) initial state*/
#if INT2_INITIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT2);
#elif INT2_INITIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT2);
#else
#error "Wrong INT2_INITIAL_STATE configration"
#endif
}


u8 EXTI_u8Int2SetSenseControl(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState=OK;

	switch(Copy_u8Sense)
	{
	case FALLING_EDGE:
		CLR_BIT(MCUCSR,MCUCSR_INT2);
		break;
	case RISING_EDGE:
		SET_BIT(MCUCSR,MCUCSR_INT2);
		break;
	default:
		Local_u8ErrorState=NOK;
		break;
	}

	return Local_u8ErrorState;
}

void EXTI_u8Int2Enable(void)
{

		SET_BIT(GICR,GICR_INT2);

}
void EXTI_u8Int2Disable(void)
{
		CLR_BIT(GICR,GICR_INT2);
}


u8 EXTI_u8Int2SetCallBack(void(*Copy_pvInt2Func)(void))
{
	u8 Local_u8ErrorStatus=OK;
	if(Copy_pvInt2Func != NULL)
	{
		EXTI_pvInt2Func=Copy_pvInt2Func;
	}
	else
	{
		Local_u8ErrorStatus=NULL_POINTER;
	}

	return Local_u8ErrorStatus;
}

void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	if(EXTI_pvInt2Func!= NULL)
	{
		EXTI_pvInt2Func();
	}
	else
	{
		/*do nothing*/
	}
}

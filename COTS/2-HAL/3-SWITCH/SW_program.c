/*************************************************************/
/*************************************************************/
/******************    Author: Sherif Taher ******************/
/******************    Layer:  HAL          ******************/
/******************    SWC:    SWITCH       ******************/
/******************    Version:1.00         ******************/
/*************************************************************/
/*************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SW_interface.h"
#include<util/delay.h>

u8 SW_u8GetState(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8SwitchType,u8 Copy_u8PullType)
{
	u8 Local_u8ErrorState=0;
	/* SET CONNECTED PIN TO SWITCH*/
	DIO_u8SetPinDirection(Copy_u8Port,Copy_u8Pin,DIO_u8PIN_INPUT);
	if(Copy_u8PullType==SW_PULL_UP)
	{
		if(Copy_u8SwitchType==SW_MAINTAINED)
		{
			/* ACTIVATE INTERNAL PULL UP RESISTOR*/
			DIO_u8SetPinValue(Copy_u8Port,Copy_u8Pin,DIO_u8PIN_HIGH);
			/* RETURN CONDITION */
			return ~(GET_BIT(Copy_u8Port,Copy_u8Pin));
		}
		else if(Copy_u8SwitchType==SW_TEMPORARY)
		{
			/* ACTIVATE INTERNAL PULL UP RESISTOR*/
			DIO_u8SetPinValue(Copy_u8Port,Copy_u8Pin,DIO_u8PIN_HIGH);

			/* RETURN CONDITION */
			while(1)
			{
				return ~(GET_BIT(Copy_u8Port,Copy_u8Pin));
				_delay_ms(100);
			}

		}
		else
		{
			return Local_u8ErrorState=1;
		}
	}
	else if(Copy_u8PullType==SW_PULL_DOWN)
	{
		if(Copy_u8SwitchType==SW_MAINTAINED)
		{
			return GET_BIT(Copy_u8Port,Copy_u8Pin);
		}
		else if(Copy_u8SwitchType==SW_TEMPORARY)
		{
			while(1)
			{
				return ~(GET_BIT(Copy_u8Port,Copy_u8Pin));
				_delay_ms(100);
			}
		}
		else
		{
			return Local_u8ErrorState=1;
		}
	}
	else
	{
		return Local_u8ErrorState=1;
	}
}

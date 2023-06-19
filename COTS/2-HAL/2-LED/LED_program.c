/*************************************************************/
/*************************************************************/
/******************    Author: Sherif Taher ******************/
/******************    Layer:  HAL          ******************/
/******************    SWC:    LED          ******************/
/******************    Version:1.00         ******************/
/*************************************************************/
/*************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_register.h"
#include "DIO_interface.h"

#include "LED_interface.h"
#include "LED_config.h"
#include "LED_private.h"

u8 LED_u8TurnOn(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8ConnectionType)
{
	u8 Local_u8ErrorState=0;
	if(Copy_u8ConnectionType==LED_COM_AN)
	{
		switch(Copy_u8Port)
		{
		case DIO_u8PORTA: DIO_u8SetPinValue(PORTA,Copy_u8Pin,DIO_u8PIN_LOW); break;
		case DIO_u8PORTB: DIO_u8SetPinValue(PORTB,Copy_u8Pin,DIO_u8PIN_LOW); break;
		case DIO_u8PORTC: DIO_u8SetPinValue(PORTC,Copy_u8Pin,DIO_u8PIN_LOW); break;
		case DIO_u8PORTD: DIO_u8SetPinValue(PORTD,Copy_u8Pin,DIO_u8PIN_LOW); break;
		default: Local_u8ErrorState=1; break;
		}
	}
	else if(Copy_u8ConnectionType==LED_COM_CA)
	{
		switch(Copy_u8Port)
		{
		case DIO_u8PORTA: DIO_u8SetPinValue(PORTA,Copy_u8Pin,DIO_u8PIN_HIGH); break;
		case DIO_u8PORTB: DIO_u8SetPinValue(PORTB,Copy_u8Pin,DIO_u8PIN_HIGH); break;
		case DIO_u8PORTC: DIO_u8SetPinValue(PORTC,Copy_u8Pin,DIO_u8PIN_HIGH); break;
		case DIO_u8PORTD: DIO_u8SetPinValue(PORTD,Copy_u8Pin,DIO_u8PIN_HIGH); break;
		default: Local_u8ErrorState=1; break;
		}
	}
	else
	{
		return Local_u8ErrorState=1;
	}

	return Local_u8ErrorState;

}


u8 LED_u8TurnOff(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8ConnectionType)
{
	u8 Local_u8ErrorState=0;
	if(Copy_u8ConnectionType==LED_COM_AN)
	{
		switch(Copy_u8Port)
		{
		case DIO_u8PORTA: DIO_u8SetPinValue(PORTA,Copy_u8Pin,DIO_u8PIN_HIGH); break;
		case DIO_u8PORTB: DIO_u8SetPinValue(PORTB,Copy_u8Pin,DIO_u8PIN_HIGH); break;
		case DIO_u8PORTC: DIO_u8SetPinValue(PORTC,Copy_u8Pin,DIO_u8PIN_HIGH); break;
		case DIO_u8PORTD: DIO_u8SetPinValue(PORTD,Copy_u8Pin,DIO_u8PIN_HIGH); break;
		default: Local_u8ErrorState=1; break;
		}
	}
	else if(Copy_u8ConnectionType==LED_COM_CA)
	{
		switch(Copy_u8Port)
		{
		case DIO_u8PORTA: DIO_u8SetPinValue(PORTA,Copy_u8Pin,DIO_u8PIN_LOW); break;
		case DIO_u8PORTB: DIO_u8SetPinValue(PORTB,Copy_u8Pin,DIO_u8PIN_LOW); break;
		case DIO_u8PORTC: DIO_u8SetPinValue(PORTC,Copy_u8Pin,DIO_u8PIN_LOW); break;
		case DIO_u8PORTD: DIO_u8SetPinValue(PORTD,Copy_u8Pin,DIO_u8PIN_LOW); break;
		default: Local_u8ErrorState=1; break;
		}
	}
	else
	{
		return Local_u8ErrorState=1;
	}


	return Local_u8ErrorState;
}

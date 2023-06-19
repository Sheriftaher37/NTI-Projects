#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "DCMOTOR_config.h"
#include "DCMOTOR_interface.h"
#include "DCMOTOR_private.h"

void DCMOTOR_voidON(u8 Copy_u8Direction)
{
	if(Copy_u8Direction==DCMOTOR_CLOCKWISE)
	{
		DIO_u8SetPinValue(DCMOTOR_PORT,DCMOTOR_PIN2,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DCMOTOR_PORT,DCMOTOR_PIN1,DIO_u8PIN_HIGH);
	}
	else if(Copy_u8Direction==DCMOTOR_ANTICLOCKWISE)
	{
		DIO_u8SetPinValue(DCMOTOR_PORT,DCMOTOR_PIN1,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DCMOTOR_PORT,DCMOTOR_PIN2,DIO_u8PIN_HIGH);
	}
}

void DCMOTOR_voidOFF()
{
	DIO_u8SetPinValue(DCMOTOR_PORT,DCMOTOR_PIN1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DCMOTOR_PORT,DCMOTOR_PIN2,DIO_u8PIN_LOW);
}

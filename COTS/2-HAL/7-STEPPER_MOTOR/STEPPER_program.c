/*************************************************************/
/*************************************************************/
/******************    Author: Sherif Taher ******************/
/******************    Layer:  HAL          ******************/
/******************    SWC: STEPPER_MOTOR   ******************/
/******************    Version:1.00         ******************/
/*************************************************************/
/*************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "PORT_interface.h"

#include "STEPPER_interface.h"
#include "STEPPER_config.h"
#include "STEPPER_private.h"

u8 STEPPER_u8Clockwise(u8 Copy_u8Angle)
{
	u8 Local_u8ErrorState=0;

	u8 Local_NoOfIretations;

	Local_NoOfIretations=(Copy_u8Angle/0.7);

	for(u8 Local_u8Loop=0;Local_u8Loop<Local_NoOfIretations;Local_u8Loop++)
	{

	/*First Step*/
	DIO_u8SetPinValue(STEPPER_PORT,STEPPER_BLUEWIRE1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PINKWIRE2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STEPPER_PORT,STEPPER_YELLOWWIRE3,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STEPPER_PORT,STEPPER_ORANGEWIRE4,DIO_u8PIN_HIGH);

	/*Second Step*/
	DIO_u8SetPinValue(STEPPER_PORT,STEPPER_BLUEWIRE1,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PINKWIRE2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(STEPPER_PORT,STEPPER_YELLOWWIRE3,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STEPPER_PORT,STEPPER_ORANGEWIRE4,DIO_u8PIN_HIGH);

	/*Third Step*/
	DIO_u8SetPinValue(STEPPER_PORT,STEPPER_BLUEWIRE1,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PINKWIRE2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STEPPER_PORT,STEPPER_YELLOWWIRE3,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(STEPPER_PORT,STEPPER_ORANGEWIRE4,DIO_u8PIN_HIGH);

	/*Fourth Step*/
	DIO_u8SetPinValue(STEPPER_PORT,STEPPER_BLUEWIRE1,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PINKWIRE2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STEPPER_PORT,STEPPER_YELLOWWIRE3,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STEPPER_PORT,STEPPER_ORANGEWIRE4,DIO_u8PIN_LOW);

	}

	return Local_u8ErrorState;
}

u8 STEPPER_u8AntiClockwise(u8 Copy_u8Angle)
{
	u8 Local_u8ErrorState=0;

		u8 Local_NoOfIretations;

		Local_NoOfIretations=(Copy_u8Angle/0.7);

		for(u8 Local_u8Loop=0;Local_u8Loop<Local_NoOfIretations;Local_u8Loop++)
		{

		/*First Step*/
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_BLUEWIRE1,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PINKWIRE2,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_YELLOWWIRE3,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_ORANGEWIRE4,DIO_u8PIN_LOW);

		/*Second Step*/
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_BLUEWIRE1,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PINKWIRE2,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_YELLOWWIRE3,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_ORANGEWIRE4,DIO_u8PIN_HIGH);

		/*Third Step*/
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_BLUEWIRE1,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PINKWIRE2,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_YELLOWWIRE3,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_ORANGEWIRE4,DIO_u8PIN_HIGH);

		/*Fourth Step*/
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_BLUEWIRE1,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PINKWIRE2,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_YELLOWWIRE3,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_ORANGEWIRE4,DIO_u8PIN_HIGH);

		}

		return Local_u8ErrorState;
}

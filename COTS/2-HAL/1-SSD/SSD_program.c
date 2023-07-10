/*************************************************************/
/*************************************************************/
/******************    Author: Sherif Taher ******************/
/******************    Layer:  HAL          ******************/
/******************    SWC:    SSD          ******************/
/******************    Version:1.00         ******************/
/*************************************************************/
/*************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SSD_interface.h"
#include "SSD_config.h"
#include "SSD_private.h"



u8 SSD_u8Enable(SSD_T*SSD)
{
	u8 Local_u8ErrorState=0;
	if(SSD->Port<=DIO_u8PORTD)
	{
		DIO_u8SetPortDirection(SSD->Port,DIO_u8PORT_OUTPUT);
		DIO_u8SetPinDirection(SSD->CommonEnablePort,SSD->CommonEnablePin,DIO_u8PIN_OUTPUT);
	}

	else
	{
		return Local_u8ErrorState=1;
	}

	return Local_u8ErrorState;
}

u8 SSD_u8Disable(SSD_T*SSD)
{
	u8 Local_u8ErrorState=0;

	if(SSD->CommonType==SSD_COM_AN)
	{
		DIO_u8SetPortDirection(SSD->Port,DIO_u8PORT_INPUT);
		DIO_u8SetPinDirection(SSD->CommonEnablePort,SSD->CommonEnablePin,DIO_u8PIN_INPUT);
	}
	else
	{
		return Local_u8ErrorState=1;
	}

	return Local_u8ErrorState;
}

u8 SSD_u8SetNumber(u8 Copy_u8Number,SSD_T*SSD)
{
	u8 Local_u8ErrorState=0;
if(SSD->CommonType==SSD_COM_AN)
{
DIO_u8SetPortValue(SSD->Port,Copy_u8Number);
}
else if(SSD->CommonType==SSD_COM_CA)
{
	DIO_u8SetPortValue(SSD->Port,~(Copy_u8Number));
}
else
{
	return Local_u8ErrorState=1;
}
	return Local_u8ErrorState;
}

#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "PORT_interface.h"
#include "STEPPER_interface.h"

void main(void)
{

	PORT_voidInit();
	STEPPER_u8Clockwise(90);

	while(1)
	{

	}
}

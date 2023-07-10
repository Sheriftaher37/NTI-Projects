#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "PORT_interface.h"

#include "LCD_interface.h"
#include "ADC_interface.h"

#include <util/delay.h>

static u16 Global_u8Read=0;
static u16 Millivolt;
void main(void)
{
	PORT_voidInit();
	ADC_voidInit();
	LCD_voidInit();

	u8 Local_u8Temp=0;
	while(1)
	{


		ADC_u8StartConversion_Synch(0,&Global_u8Read);
		Millivolt=(u16)((u32)Global_u8Read*5000UL)/256UL;
		Local_u8Temp=Millivolt;
		LCD_voidGoToXY(0,0);
		//LCD_voidSendCommand(0x01);
		//LCD__voidSendString("Temp:");
		LCD_voidSendNumber(Millivolt);

	}
}

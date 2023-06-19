#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "ADC_interface.h"
#include "LCD_interface.h"
#include <util/delay.h>

int main (void)
{
	u8 Local_u8Read1,Local_u8Read2;
	u16 Local_u16Millivolt1,Local_u16Millivolt2,Local_u16Ohm;
	PORT_voidInit();
	LCD_voidInit();

	while(1)
	{
		ADC_u8StartConversion_Synch(DIO_u8PIN0,&Local_u8Read1);
		ADC_u8StartConversion_Synch(DIO_u8PIN1,Local_u8Read2);
		Local_u16Millivolt1=(u16)((u32) Local_u8Read1*5000UL)/256UL;
		Local_u16Millivolt2=(u16)((u32) Local_u8Read2*5000UL)/256UL;
		Local_u16Ohm/20000=Local_u16Millivolt2-Local_u16Millivolt1;
		LCD_voidGoToXY(0,0);
		LCD_voidSendNumber(Local_u16Ohm);
		_delay_ms(1000);
	}
}

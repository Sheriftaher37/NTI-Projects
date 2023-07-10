#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "LCD_interface.h"
#include "ADC_interface.h"
#include "INT0_interface.h"
#include "INT1_interface.h"
#include "GIE_interface.h"
#include "KPD_interface.h"
#include <util/delay.h>

void INT0_ISR(void);
void INT1_ISR(void);
int main(void)
{
	PORT_voidInit();
	LCD_voidInit();
	ADC_voidInit();
	EXTI_voidInt0Init();
	EXTI_voidInt1Init();
	GIE_voidEnable();
	EXTI_u8Int0SetCallBack(&INT0_ISR);

	u8 Local_u8KPDreading;
	while(1)
	{
		LCD__voidSendString("Enter Time:");
		do
		{
			Local_u8KPDreading=KPD_u8GetPressedKey();
		}while(Local_u8KPDreading==0xFF);
		LCD_voidSendNumber(Local_u8KPDreading);
		_delay_ms(1000);

		for(u8 i=0;i<Local_u8KPDreading;i++)
		{
			LCD_voidSendCommand(0x01);
			LCD_voidGoToXY(0,8);
			LCD_voidSendNumber(Local_u8KPDreading-i);
			_delay_ms(1000);
		}

		DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_HIGH);
	}
}

void INT0_ISR(void)
{
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
}

void INT1_ISR(void)
{
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_LOW);
}

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "PORT_interface.h"

#include "GIE_interface.h"
#include "INT0_interface.h"
#include "INT1_interface.h"

#include "LCD_interface.h"

#include <util/delay.h>

static u8 Global_u8Counter=0;

void INT0_ISR(void);
void INT1_ISR(void);

int main(void)
{
	EXTI_u8Int0SetCallBack(INT0_ISR);
	EXTI_u8Int1SetCallBack(INT1_ISR);
	PORT_voidInit();
	EXTI_voidInt0Init();
	EXTI_voidInt1Init();
	GIE_voidEnable();
	LCD_voidInit();


	while(1)
	{
		LCD_voidSendCommand(0x01);
		LCD_voidSendNumber(Global_u8Counter);
	}
	return 0;
}

void INT0_ISR(void)
{
	//LCD_voidGoToXY(1,1);
	//LCD_voidSendData('A');
	Global_u8Counter++;
	_delay_ms(250);
}

void INT1_ISR(void)
{
	//LCD_voidGoToXY(1,2);
	LCD_voidSendData('B');
	Global_u8Counter=0;
	_delay_ms(250);
}


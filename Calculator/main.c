#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "PORT_interface.h"
#include "LCD_interface.h"
#include "KPD_interface.h"


#include <util/delay.h>

u16 arr[3];
void main(void)
{
	PORT_voidInit();
	LCD_voidInit();

	while(1)
	{
		u8 Local_u8Num;
		LCD__voidSendString("Num 1:");
		do
		{
			Local_u8Num=KPD_u8GetPressedKey();
			arr[0]=Local_u8Num;
		}while(Local_u8Num==0xFF);
		LCD_voidSendNumber(Local_u8Num);
		LCD_voidGoToXY(1,0);


		LCD__voidSendString("op:");
		do
		{
			Local_u8Num=KPD_u8GetPressedKey();
		}while(Local_u8Num==0xFF);
		LCD_voidSendData(Local_u8Num);
		arr[1]=Local_u8Num;



		LCD__voidSendString("Num 2:");
		do
		{
			Local_u8Num=KPD_u8GetPressedKey();
		}while(Local_u8Num==0xFF);
		LCD_voidSendNumber(Local_u8Num);
		arr[2]=Local_u8Num;

		switch(arr[1])
		{
		case '+':
			LCD_voidSendCommand(0x01);
			LCD_voidGoToXY(0,0);
			Local_u8Num=arr[0]+arr[2];
			LCD_voidSendNumber(Local_u8Num);
			_delay_ms(5000);
			break;

		case '-':
			LCD_voidSendCommand(0x01);
			LCD_voidGoToXY(0,0);
			Local_u8Num=arr[0]-arr[2];
			LCD_voidSendNumber(Local_u8Num);
			_delay_ms(5000);
			break;

		case '*':
			LCD_voidSendCommand(0x01);
			LCD_voidGoToXY(0,0);
			Local_u8Num=arr[0]*arr[2];
			LCD_voidSendNumber(Local_u8Num);
			_delay_ms(5000);
			break;

		case '/':
			LCD_voidSendCommand(0x01);
			LCD_voidGoToXY(0,0);
			Local_u8Num=arr[0]/arr[2];
			LCD_voidSendNumber(Local_u8Num);
			_delay_ms(5000);
			break;

		default:
			LCD_voidSendCommand(0x01);
			LCD_voidGoToXY(0,0);
			LCD__voidSendString("wrong operation");
			_delay_ms(5000);
		}
	}
}



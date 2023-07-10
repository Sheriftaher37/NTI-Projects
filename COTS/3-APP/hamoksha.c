#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "LCD_interface.h"
#include "ADC_interface.h"

int main()
{
	u8 number=0;

	u8 flag=0;

	u8 Character1[8] = {
			0b00100,
			0b01010,
			0b01010,
			0b10101,
			0b01110,
			0b00100,
			0b01010,
			0b10001
	};
	u8 Character2[8] = {
			0b00000,
			0b00000,
			0b01000,
			0b10100,
			0b10100,
			0b01000,
			0b01010,
			0b01101
	};

	LCD_voidWriteSpecialCharacter(Character1,0,0,0);
	LCD_voidWriteSpecialCharacter(Character2,1,1,0);

	LCD_voidInit();
	ADC_voidInit();

	while(1)
	{
		ADC_u8StartConversion_Synch(DIO_u8PIN0,&number);
		if(number > 100 &&flag==0){
			LCD_voidSendData(1);
			flag=1;

		}
		if (number<100 &&flag==1)
		{
			LCD_voidSendData(0);
			flag=0;

		}
	}
	return 0;
}

/*************************************************************/
/*************************************************************/
/******************    Author: Sherif Taher ******************/
/******************    Layer:  HAL          ******************/
/******************    SWC:    CLCD         ******************/
/******************    Version:1.00         ******************/
/*************************************************************/
/*************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <util/delay.h>

#include "DIO_interface.h"

#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"

void LCD_voidSendCommand(u8 Copy_u8Command)
{
#if LCD_Bit_Mode == Eight_Bits_Mode
	/* Set RS Pin to Low for Command */
	DIO_u8SetPinValue(LCD_CTRL_8_PORT,LCD_RS_PIN,DIO_u8PIN_LOW);

	/* Set RW to Low for Write */
	DIO_u8SetPinValue(LCD_CTRL_8_PORT,LCD_RW_PIN,DIO_u8PIN_LOW);

	/* Set Command to Data Pins */
	DIO_u8SetPortValue(LCD_DATA_8_PORT,Copy_u8Command);

	/* Send Enable Pulse */
	DIO_u8SetPinValue(LCD_CTRL_8_PORT,LCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_CTRL_8_PORT,LCD_E_PIN,DIO_u8PIN_LOW);

#elif LCD_Bit_Mode == Four_Bits_Mode

	/* Set RS Pin to Low for Command */
	DIO_u8SetPinValue(LCD_CTRL_4_PORT,LCD_CTRL_4_RS,DIO_u8PIN_LOW);

	/* Set RW to Low for Write */
	DIO_u8SetPinValue(LCD_CTRL_4_PORT,LCD_CTRL_4_RW,DIO_u8PIN_LOW);

	/* Set Command to Data Pins */
	DIO_u8SetPinValue(LCD_DATA_4_PORT,LCD_DATA_7,((Copy_u8Command>>7)&1));
	DIO_u8SetPinValue(LCD_DATA_4_PORT,LCD_DATA_6,((Copy_u8Command>>6)&1));
	DIO_u8SetPinValue(LCD_DATA_4_PORT,LCD_DATA_5,((Copy_u8Command>>5)&1));
	DIO_u8SetPinValue(LCD_DATA_4_PORT,LCD_DATA_4,((Copy_u8Command>>4)&1));

	/* Send Enable Pulse */
	DIO_u8SetPinValue(LCD_CTRL_4_PORT,LCD_CTRL_4_E,DIO_u8PIN_HIGH);
	_delay_ms(30);
	DIO_u8SetPinValue(LCD_CTRL_4_PORT,LCD_CTRL_4_E,DIO_u8PIN_LOW);
	_delay_ms(2);

	DIO_u8SetPinValue(LCD_DATA_4_PORT,LCD_DATA_7,((Copy_u8Command>>3)&1));
	DIO_u8SetPinValue(LCD_DATA_4_PORT,LCD_DATA_6,((Copy_u8Command>>2)&1));
	DIO_u8SetPinValue(LCD_DATA_4_PORT,LCD_DATA_5,((Copy_u8Command>>1)&1));
	DIO_u8SetPinValue(LCD_DATA_4_PORT,LCD_DATA_4,((Copy_u8Command>>0)&1));

	/* Send Enable Pulse */
	DIO_u8SetPinValue(LCD_CTRL_4_PORT,LCD_CTRL_4_E,DIO_u8PIN_HIGH);
	_delay_ms(30);
	DIO_u8SetPinValue(LCD_CTRL_4_PORT,LCD_CTRL_4_E,DIO_u8PIN_LOW);
	_delay_ms(2);

#else
#error "Wrong LCD mode configration"
#endif
}

void LCD_voidSendData(u8 Copy_u8Data)
{
#if LCD_Bit_Mode == Eight_Bits_Mode
	/* Set RS Pin to High for Data */
	DIO_u8SetPinValue(LCD_CTRL_8_PORT,LCD_RS_PIN,DIO_u8PIN_HIGH);

	/* Set RW to Low for Write */
	DIO_u8SetPinValue(LCD_CTRL_8_PORT,LCD_RW_PIN,DIO_u8PIN_LOW);

	/* Set Data to Data Pins */
	DIO_u8SetPortValue(LCD_DATA_8_PORT,Copy_u8Data);

	/* Send Enable Pulse */
	DIO_u8SetPinValue(LCD_CTRL_8_PORT,LCD_E_PIN,DIO_u8PIN_HIGH);

	_delay_ms(2);

	DIO_u8SetPinValue(LCD_CTRL_8_PORT,LCD_E_PIN,DIO_u8PIN_LOW);

#elif LCD_Bit_Mode == Four_Bits_Mode
	/* Set RS Pin to High for Data */
	DIO_u8SetPinValue(LCD_CTRL_4_PORT,LCD_CTRL_4_RS,DIO_u8PIN_HIGH);

	/* Set RW to Low for Write */
	DIO_u8SetPinValue(LCD_CTRL_4_PORT,LCD_CTRL_4_RW,DIO_u8PIN_LOW);
	/* Set Data to Data Pins */
	DIO_u8SetPinValue(LCD_DATA_4_PORT,LCD_DATA_7,((Copy_u8Data>>7)&1));
	DIO_u8SetPinValue(LCD_DATA_4_PORT,LCD_DATA_6,((Copy_u8Data>>6)&1));
	DIO_u8SetPinValue(LCD_DATA_4_PORT,LCD_DATA_5,((Copy_u8Data>>5)&1));
	DIO_u8SetPinValue(LCD_DATA_4_PORT,LCD_DATA_4,((Copy_u8Data>>4)&1));

	/* Send Enable Pulse */
	DIO_u8SetPinValue(LCD_CTRL_4_PORT,LCD_CTRL_4_E,DIO_u8PIN_HIGH);
	_delay_ms(30);
	DIO_u8SetPinValue(LCD_CTRL_4_PORT,LCD_CTRL_4_E,DIO_u8PIN_LOW);
	_delay_ms(2);


	DIO_u8SetPinValue(LCD_DATA_4_PORT,LCD_DATA_7,((Copy_u8Data>>3)&1));
	DIO_u8SetPinValue(LCD_DATA_4_PORT,LCD_DATA_6,((Copy_u8Data>>2)&1));
	DIO_u8SetPinValue(LCD_DATA_4_PORT,LCD_DATA_5,((Copy_u8Data>>1)&1));
	DIO_u8SetPinValue(LCD_DATA_4_PORT,LCD_DATA_4,((Copy_u8Data>>0)&1));

	/* Send Enable Pulse */
	DIO_u8SetPinValue(LCD_CTRL_4_PORT,LCD_CTRL_4_E,DIO_u8PIN_HIGH);
	_delay_ms(30);
	DIO_u8SetPinValue(LCD_CTRL_4_PORT,LCD_CTRL_4_E,DIO_u8PIN_LOW);
	_delay_ms(2);

#else
#error "Wrong LCD mode configration"
#endif
}

void LCD_voidInit(void)
{
#if LCD_Bit_Mode == Eight_Bits_Mode
	/* Wait for More Than 30 ms */
	_delay_ms(40);

	/* Function Set Command: 2 Lines, 5*8 Font Size */
	LCD_voidSendCommand(0b00111000);

	/* Wait for More Than 30 us */
	_delay_ms(1);

	/* Display On Off Control: Display Enable, Disable cursor, No blink Curser */
	LCD_voidSendCommand(0b00001100);

	/* Clear Display */
	LCD_voidSendCommand(0b00000001);

#elif LCD_Bit_Mode == Four_Bits_Mode


	// Wait for More Than 30 ms
	_delay_ms(30);

	// Function Set Command: 2 Lines, 5*8 Font Size
	LCD_voidSendCommand(0x02);
	LCD_voidSendCommand(0x28);
	LCD_voidSendCommand(0x0C);


	//LCD_voidSendCommand(0x28);  (2y hexa 7nkshet al mo3ed)

	// Wait for More Than 30 us
	_delay_ms(1);

	// Display On Off Control: Display Enable, Disable cursor, No blink Curser
	LCD_voidSendCommand(0x06);  //shift Cursor to right
	LCD_voidSendCommand(0x01);   // clear
	//LCD_voidSendCommand(0x0c);


//	// Wait for More Than 30 us
//	_delay_ms(1);
//	// Clear Display
//	//LCD_voidSendCommand(0x02);
//	//LCD_voidSendCommand(0x01);
//	LCD_voidSendCommand(0b00000000);
//	LCD_voidSendCommand(0b00010000);


#else
#error "Wrong LCD mode configration"
#endif
}

void LCD__voidSendString(const char* Copy_pcString)
{
	u8 Local_u8Counter=0;
	while(Copy_pcString[Local_u8Counter]!='\0')
	{
		LCD_voidSendData(Copy_pcString[Local_u8Counter]);
		Local_u8Counter++;
	}
}

void LCD_voidGoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos)
{
	u8 Local_u8Address;
	if(Copy_u8XPos==0)
	{
		/*location is at first line*/
		Local_u8Address=Copy_u8YPos;
	}
	else if(Copy_u8XPos==1)
	{
		/*location is at second line*/
		Local_u8Address=Copy_u8YPos+0x40;
	}
	/*set bit number 7 for set DDRAM address command then send the command*/
	LCD_voidSendCommand(Local_u8Address+128);
}

void LCD_voidWriteSpecialCharacter(u8* Copy_pu8Pattern,u8 Copy_u8PatternNumber,u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	u8 Local_u8CGRAMAddress=0, Local_u8Iterator;
	/* Calculate CGRAM address whose each block is 9 bytes */
	Local_u8CGRAMAddress=Copy_u8PatternNumber*8;

	/*send CGRAM address command to LCD, with setting bit 6, clearing bit 7*/
	LCD_voidSendCommand(Local_u8CGRAMAddress+64);

	for(Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++)
	{
		LCD_voidSendData(Copy_pu8Pattern[Local_u8Iterator]);
	}
	/*go back to DDRAM to display the pattern*/
	LCD_voidGoToXY(Copy_u8XPos,Copy_u8YPos);
	/*display the pattern written in the CGRAM*/
	LCD_voidSendData(Copy_u8PatternNumber);
}

void LCD_voidSendNumber(u32 Copy_Number)
{
	u8 Local_u8Number,Local_u8FirstNum=0;
	u32 Local_u32Loop;
	if(Copy_Number==0)
	{
		LCD_voidSendData(48);
	}
	else
	{
		for(Local_u32Loop=1000000;Local_u32Loop>0;Local_u32Loop/=10)
		{
			Local_u8Number=Copy_Number/Local_u32Loop;
			if(Local_u8Number==0 && Local_u8FirstNum==0)
			{
				continue;
			}
			else
			{
				LCD_voidSendData(Local_u8Number+48);
				Copy_Number=Copy_Number%Local_u32Loop;
				Local_u8FirstNum=1;
			}
		}
	}
}

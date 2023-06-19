/*************************************************************/
/*************************************************************/
/******************    Author: Sherif Taher ******************/
/******************    Layer:  HAL          ******************/
/******************    SWC:    CLCD         ******************/
/******************    Version:1.00         ******************/
/*************************************************************/
/*************************************************************/

/* PREPROCESSOR FILE GUARD */
#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_voidSendCommand(u8 Copy_u8Command);

void LCD_voidSendData(u8 Copy_u8Data);

void LCD_voidInit(void);

void LCD__voidSendString(const char* Copy_pcString);

void LCD_voidGoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos);

void LCD_voidWriteSpecialCharacter(u8* Copy_pu8Pattern,u8 Copy_u8PatternNumber,u8 Copy_u8XPos,u8 Copy_u8YPos);

void LCD_voidSendNumber(u32 Copy_Number);

#endif

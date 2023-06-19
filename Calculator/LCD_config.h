/*************************************************************/
/*************************************************************/
/******************    Author: Sherif Taher ******************/
/******************    Layer:  HAL          ******************/
/******************    SWC:    CLCD         ******************/
/******************    Version:1.00         ******************/
/*************************************************************/
/*************************************************************/

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/* select LCD mode: 1-Four_Bits_Mode
 * 					2-Eight_Bits_Mode
 */

#define LCD_Bit_Mode			Four_Bits_Mode

/******************* Eight_Bits_Mode *************************************/

/* select LCD control port  */
#define LCD_CTRL_8_PORT	 	   	DIO_u8PORTB

/* LCD data port  */
#define LCD_DATA_8_PORT			DIO_u8PORTB

/* LCD register select pin */
#define LCD_RS_8_PIN			DIO_u8PIN5
/* LCD read/write pin */
#define LCD_RW_8_PIN			DIO_u8PIN6
/* LCD enable pin */
#define LCD_E_8_PIN				DIO_u8PIN7

/******************* Four_Bits_Mode ****************************************/

/* select LCD control port  */
#define LCD_CTRL_4_PORT			DIO_u8PORTB

#define LCD_CTRL_4_RS			DIO_u8PIN2
#define LCD_CTRL_4_RW			DIO_u8PIN1
#define LCD_CTRL_4_E			DIO_u8PIN0

/* LCD Data port  */
#define LCD_DATA_4_PORT			DIO_u8PORTA

#define LCD_DATA_7				DIO_u8PIN0
#define LCD_DATA_6				DIO_u8PIN1
#define LCD_DATA_5				DIO_u8PIN2
#define LCD_DATA_4				DIO_u8PIN3



#endif /* LCD_CONFIG_H_ */

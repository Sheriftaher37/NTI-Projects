/*************************************************************/
/*************************************************************/
/******************    Author: Sherif Taher ******************/
/******************    Layer:  HAL          ******************/
/******************    SWC:    SSD          ******************/
/******************    Version:1.00         ******************/
/*************************************************************/
/*************************************************************/

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

/* Numbers */

#define SSD_NUMBER0     0b0111111
#define SSD_NUMBER1     0b0000110
#define SSD_NUMBER2     0b1011011
#define SSD_NUMBER3     0b1001111
#define SSD_NUMBER4     0b1100110
#define SSD_NUMBER5     0b1101101
#define SSD_NUMBER6     0b1111101
#define SSD_NUMBER7     0b0000111
#define SSD_NUMBER8     0b1111111
#define SSD_NUMBER9     0b1101111

u8 SSD_NUMBERS[10]={0b0111111,0b0000110,0b1011011,0b1001111,0b1100110
		           ,0b1101101,0b1111101,0b0000111,0b1111111,0b1101111};
/* SSD COMMON TYPE */

#define SSD_COM_AN      0
#define SSD_COM_CA      1

/* SSD COMMON ENABLE PIN */

#define SSD_ON      DIO_u8PIN_HIGH
#define SSD_OFF     DIO_u8PIN_LOW


typedef struct
{
	u8 CommonType;
	u8 Port;
	u8 CommonEnablePort;
	u8 CommonEnablePin;

}SSD_T;


u8 SSD_u8Enable(SSD_T*);
u8 SSD_u8SetNumber(u8 Copy_u8Number,SSD_T*);
u8 SSD_u8Disable(SSD_T*);

#endif

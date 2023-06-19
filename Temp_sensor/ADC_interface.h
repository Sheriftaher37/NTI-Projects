/*************************************************************/
/*************************************************************/
/******************    Author: Sherif Taher ******************/
/******************    Layer:  MCAL         ******************/
/******************    SWC:    ADC          ******************/
/******************    Version:1.00         ******************/
/******************    Date:   1/5/2023     ******************/
/*************************************************************/
/*************************************************************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

typedef struct
{
	u8* Channel;
	u16* Result;
	u8 Size;
	void (*NotificationFunc)(void);

}Chain_t;

void ADC_voidInit(void);

u8 ADC_u8StartConversion_Synch(u8 Copy_u8Channel,u16* Copy_pu8Reading);

u8 ADC_u8StartConversion_A_Synch(u8 Copy_u8Channel,u8* Copy_pu8Reading,void (*Copy_pvNotificationFunc)(void));

u8 ADC_u8StartChainAsynch(Chain_t * Copy_Chain);


#endif // ADC_INTERFACE_H_

/*************************************************************/
/*************************************************************/
/******************    Author: Sherif Taher ******************/
/******************    Layer:  MCAL         ******************/
/******************    SWC:    USART        ******************/
/******************    Version:1.00         ******************/
/******************    Date:   1/5/2023     ******************/
/*************************************************************/
/*************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_config.h"
#include "USART_interface.h"
#include "USART_private.h"
#include "USART_register.h"

void USART_Init(void)
{
	/*Mask register UCSRC*/
	u8 Local_u8UCSRC=0;

	/*Turn off interrupts (recive,transimit and empty interrupts)*/
	CLR_BIT(UCSRB,UCSRB_RXCIE);
	CLR_BIT(UCSRB,UCSRB_TXCIE);
	CLR_BIT(UCSRB,UCSRB_UDRIE);

	/*Set character size to 8-bits*/
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
	SET_BIT(Local_u8UCSRC,UCSRC_UCSZ1);
	SET_BIT(Local_u8UCSRC,UCSRC_UCSZ0);


	/*SeT URSEL to choose UCSRC register*/
	SET_BIT(Local_u8UCSRC,UCSRC_URSEL);

	/*mode selet Asynch*/
	CLR_BIT(Local_u8UCSRC,UCSRC_UMSEL);

	/*no parity mode*/
	CLR_BIT(Local_u8UCSRC,UCSRC_UPM1);
	CLR_BIT(Local_u8UCSRC,UCSRC_UPM0);

	/*1 stop bit*/
	CLR_BIT(Local_u8UCSRC,UCSRC_USBS);

	/*Return mask of UCSRC*/
	UCSRC=Local_u8UCSRC;

	/*Choose baud rate*/
	UBRRL=51;		/*9600 Bit/second*/

	/*Set transimitter and reciver enable bits*/

	SET_BIT(UCSRB,UCSRB_RXEN);
	SET_BIT(UCSRB,UCSRB_TXEN);
}

void USART_voidSend(u8 Copy_u8Data)
{
	/*Wait until transmit data is empty*/
	while(GET_BIT(UCSRA,UCSRA_UDRE));

	UDR=Copy_u8Data;
}

u8 USART_u8Recive(void)
{
	while(GET_BIT(UCSRA,UCSRA_RXC) == 0);

	return UDR;
}

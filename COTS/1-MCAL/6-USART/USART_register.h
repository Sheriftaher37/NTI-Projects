/*************************************************************/
/*************************************************************/
/******************    Author: Sherif Taher ******************/
/******************    Layer:  MCAL         ******************/
/******************    SWC:    USART        ******************/
/******************    Version:1.00         ******************/
/******************    Date:   1/5/2023     ******************/
/*************************************************************/
/*************************************************************/

#ifndef USART_REGISTER_H_
#define USART_REGISTER_H_

#define UDR				*((volatile u8*)0x2c)			/*Input and Output data register (RXB & TXB) with the same gate UDR*/

#define UCSRA			*((volatile u8*)0x2b)			/*Control and status register A*/
#define UCSRA_RXC				7						/*Recive complete flag*/
#define UCSRA_TXC				6						/*Transmit complete flag*/
#define UCSRA_UDRE				5						/*Data empty flag*/
#define UCSRA_FE				4						/*Frame error flag*/
#define UCSRA_DOR				3						/*Data over run flag*/
#define UCSRA_PE				2						/*Parity error flag*/
#define UCSRA_U2X				1						/*Double transmission speed*/
#define UCSRA_MPCM				0						/*Multi processor communication mode*/

#define UCSRB			*((volatile u8*)0x2a)			/*Control and status register B*/
#define UCSRB_RXCIE				7						/*Recive complete interrupt enable*/
#define UCSRB_TXCIE				6						/*Transmit complete interrupt enable*/
#define UCSRB_UDRIE				5						/*Data empty interrupt enable*/
#define UCSRB_RXEN				4						/*Receiver enable*/
#define UCSRB_TXEN				3						/*Transmitter enable*/
#define UCSRB_UCSZ2				2						/*Character size control Bit2*/
#define UCSRB_RXB8				1						/*Recive data Bit8 (if you recive 9 bits this will be the 9th Bit)*/
#define UCSRB_TXB8				0						/*Transmit data Bit8 (if you send 9 bits and write it before low UDR)*/

#define UCSRC			*((volatile u8*)0x40)			/*Control and status register C (same address with UBRRH)*/
#define UCSRC_URSEL					7					/*Register select (select 1 to write on UCSRC and 0 for UBRRH)*/
#define UCSRC_UMSEL					6					/*Mode select (synch,Asynch)*/
#define UCSRC_UPM1					5					/*Parity mode*/
#define UCSRC_UPM0					4					/*Parity mode*/
#define UCSRC_USBS					3					/*Stop bit select (1bit or 2 bits)*/
#define UCSRC_UCSZ1					2					/*Character size control Bit1*/
#define UCSRC_UCSZ0					1					/*Character size control Bit0*/
#define UCSRC_UCPOL					0					/*Clock polarity (rising edge or falling edge)*/

#define UBRRH			*((volatile u8*)0x40)			/*Baud rate higher register (same address with UCSRC)*/
#define UBRRH_URSEL					7					/*Register select (select 1 to write on UCSRC and 0 for UBRRH)*/
#define UBRRH_UBRR11				3					/*12-Bit Baud rate*/
#define UBRRH_UBRR10				2					/*12-Bit Baud rate*/
#define UBRRH_UBRR9					1					/*12-Bit Baud rate*/
#define UBRRH_UBRR8					0					/*12-Bit Baud rate*/

#define UBRRL			*((volatile u8*)0x29)			/*Baud rate lower register*/
#define UBRRH_UBRR7					7					/*12-Bit Baud rate*/
#define UBRRH_UBRR6					6					/*12-Bit Baud rate*/
#define UBRRH_UBRR5					5					/*12-Bit Baud rate*/
#define UBRRH_UBRR4					4					/*12-Bit Baud rate*/
#define UBRRH_UBRR3					3					/*12-Bit Baud rate*/
#define UBRRH_UBRR2					2					/*12-Bit Baud rate*/
#define UBRRH_UBRR1					1					/*12-Bit Baud rate*/
#define UBRRH_UBRR0					0					/*12-Bit Baud rate*/
#endif

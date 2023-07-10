/*************************************************************/
/*************************************************************/
/******************    Author: Sherif Taher ******************/
/******************    Layer:  MCAL         ******************/
/******************    SWC:    SPI          ******************/
/******************    Version:1.00         ******************/
/*************************************************************/
/*************************************************************/
#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_

#define SPCR						*((volatile u8*)0x2D)		/*SPI Control register*/
#define SPCR_SPIE								7				/*SPI interrupt enable*/
#define SPCR_SPE								6				/*SPI enable*/
#define SPCR_DORD								5				/*SPI Data order (write zero to transfier MSB first)*/
#define SPCR_MSTR								4				/*SPI Master/slave select*/
#define SPCR_CPOL								3				/*SPI Clock polarity*/
#define SPCR_CPHA								2				/*SPI Clock phase*/
#define SPCR_SPR1								1				/*SPI interrupt enable*/
#define SPCR_SPR0								0				/*SPI Clock rate (Prescaler)*/


#define SPSR						*((volatile u8*)0x2E)		/*SPI Status register*/
#define SPSR_SPIF								7				/*SPI Interrupt flag*/
#define SPSR_WCOL								6				/*SPI Write collision flag*/
#define SPSR_SPI2X								0				/*SPI Douple speed*/


#define SPDR						*((volatile u8*)0x2F)		/*SPI Data register*/


#endif

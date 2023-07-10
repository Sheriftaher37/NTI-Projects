/*************************************************************/
/*************************************************************/
/******************    Author: Sherif Taher ******************/
/******************    Layer:  MCAL         ******************/
/******************    SWC:    SPI          ******************/
/******************    Version:1.00         ******************/
/*************************************************************/
/*************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_register.h"
#include "SPI_config.h"
#include "SPI_private.h"

void SPI_voidMasterInit(void)
{
	/*Select as Master*/
	SET_BIT(SPCR,SPCR_MSTR);

	/*Data order (MSB send first)*/
	CLR_BIT(SPCR,SPCR_DORD);

	/*Set clock polarity as (Leading edge---> Rising)*/
	CLR_BIT(SPCR,SPCR_CPOL);

	/*SET clock phase (Leading edge---> Sample)*/
	CLR_BIT(SPCR,SPCR_CPHA);

	/*SET clock rate (Prescaler on 64)*/
	SET_BIT(SPSR,SPSR_SPI2X);
	SET_BIT(SPCR,SPCR_SPR1);
	SET_BIT(SPCR,SPCR_SPR0);

	/*SPI Enable*/
	SET_BIT(SPCR,SPCR_SPE);
}

void SPI_voidSlaveInit(void)
{
	/*Select as Slave*/
	CLR_BIT(SPCR,SPCR_MSTR);

	/*Data order (MSB send first)*/
	CLR_BIT(SPCR,SPCR_DORD);

	/*Set clock polarity as (Leading edge---> Rising)*/
	CLR_BIT(SPCR,SPCR_CPOL);

	/*SET clock phase (Leading edge---> Sample)*/
	CLR_BIT(SPCR,SPCR_CPHA);

	/*SET clock rate (Prescaler on 64)*/
	SET_BIT(SPSR,SPSR_SPI2X);
	SET_BIT(SPCR,SPCR_SPR1);
	SET_BIT(SPCR,SPCR_SPR0);

	/*SPI Enable*/
	SET_BIT(SPCR,SPCR_SPE);
}

void SPI_voidSendData(u8 Copy_u8Data)
{
	SPDR=Copy_u8Data;
}

u8 SPI_u8ReciveData(void)
{
	while((GET_BIT(SPSR,SPSR_SPIF))==0);
	return SPDR;
}

/*************************************************************/
/*************************************************************/
/******************    Author: Sherif Taher ******************/
/******************    Layer:  MCAL         ******************/
/******************    SWC:    ADC          ******************/
/******************    Version:1.00         ******************/
/******************    Date:   1/5/2023     ******************/
/*************************************************************/
/*************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_config.h"
#include "ADC_private.h"
#include "ADC_register.h"
#include "ADC_interface.h"

static u8* ADC_pu8Reading = NULL;
static void (*ADC_pvCallBackNotificationFunc)(void) = NULL;

static u8* ADC_pu8ChainChannelArr = NULL;			/*Global variable to carry chain Array*/
static u8 ADC_u8ChainSize;							/*Global variable to carry number of channels*/
static u16* ADC_pu16ChainResultArr=NULL;			/*Global variable to carry chain result*/
static u8 ADC_u8ChainConversionIndex=0;				/*Global variable to carry current conversion Index*/

static u8 ADC_u8ISRSource;

u8 ADC_u8BusyState = IDLE;

void ADC_voidInit(void)
{
	/*set voltage refrence selection*/

	ADMUX &= 0b0011111;
	ADMUX|= ADC_Refrence_Seletion;

	/*set left agdjust result*/
#if (ADC_Resolution == Eight_Bits)
	SET_BIT(ADMUX,ADMUX_ADLAR);
#elif (ADC_Resolution == Ten_Bits)
	CLR_BIT(ADMUX,ADMUX_ADLAR);
#else
#error "set resolution error"
#endif

	/*set prescaler*/
	ADCSRA &= 0b11111000;
	ADCSRA |= ADC_Prescaler;

	/*set conversion mode*/
#if (ADC_Conversion == Single_conversion)
	CLR_BIT(ADCSRA,ADCSRA_ADATE);
#elif (ADC_Conversion == Auto_Trigger)
	SET_BIT(ADCSRA,ADCSRA_ADATE);
	/*Adjust Auto Trigger Source*/
	SFIOR &= 0b00011111;
	SFIOR |= ADC_Auto_Trigger_source;

	/*start first conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);
#else
#error	"Converion set error"
#endif

	/*enable peripheral*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}

u8 ADC_u8StartConversion_Synch(u8 Copy_u8Channel,u16* Copy_pu8Reading)
{
	u32 Local_u32Counter=0;
	u8 Local_u8ErrorState=OK;
	if (ADC_u8BusyState == IDLE)
	{
		/*ADC is now busy*/
		ADC_u8BusyState = BUSY;
		/*clear theMUX bits in ADMUX register*/
		ADMUX &= 0b11100000;

		/*set the required channel into the MUX bits*/
		ADMUX |= Copy_u8Channel;

#if (ADC_Conversion == Single_conversion)
		/*start conversion*/
		SET_BIT(ADCSRA,ADCSRA_ADSC);

		/*polling (busy waiting) until the conversion complete flag is set or counter reaching timeout value*/
		while(((GET_BIT(ADCSRA,ADCSRA_ADIF)) == 0) && (Local_u32Counter != ADC_u32TIMEOUT))
		{
			Local_u32Counter++;
		}
		if (Local_u32Counter== ADC_u32TIMEOUT)
		{
			/*Loop is broken because the timeout is reached*/
			Local_u8ErrorState=NOK;
		}
		else
		{
			/*Loop is broken because flag is raised*/
			/*clear the conversion complete flag*/
			SET_BIT(ADCSRA,ADCSRA_ADIF);

			/*return the reading*/
			/*ADC is finishied, return it to IDLE*/
#if 	(ADC_Resolution == Eight_Bits)
			*Copy_pu8Reading= ADCH;
			ADC_u8BusyState = IDLE;
#elif	(ADC_Resolution == Ten_Bits)
			*Copy_pu8Reading= ADC;
			ADC_u8BusyState = IDLE;
#else
#error "Resolution error"
#endif
		}
#endif

		/*return the reading*/
		/*ADC is finishied, return it to IDLE*/
#if 	(ADC_Resolution == Eight_Bits)
		*Copy_pu8Reading= ADCH;
		ADC_u8BusyState = IDLE;
#elif	(ADC_Resolution == Ten_Bits)
		*Copy_pu8Reading= ADC;
		ADC_u8BusyState = IDLE;
#else
#error "Resolution error"
#endif
	}
	else
	{
		Local_u8ErrorState=BUSY_FUNCTION;
	}
	return Local_u8ErrorState;
}

u8 ADC_u8StartConversion_A_Synch(u8 Copy_u8Channel,u8* Copy_pu8Reading,void (*Copy_pvNotificationFunc)(void))
{
	u8 Local_u8ErrorState=OK;
	if (ADC_u8BusyState == IDLE)
	{
		if ((Copy_pu8Reading == NULL) || (Copy_pvNotificationFunc == NULL))
		{
			Local_u8ErrorState=NULL_POINTER;
		}
		else
		{
			/*make ADC busy in order not to work until being IDLE*/
			ADC_u8BusyState=BUSY;

			/*make ISR source: Single channel asynchronous*/
			ADC_u8ISRSource = SINGLE_CHANNEL_ASYNCH;

			/*initialize the reading variable globally*/
			ADC_pu8Reading = Copy_pu8Reading;

			/*initialize the callback notification function globally*/
			ADC_pvCallBackNotificationFunc = Copy_pvNotificationFunc;

			/*clear theMUX bits in ADMUX register*/
			ADMUX &= 0b11100000;

			/*set the required channel into the MUX bits*/
			ADMUX |= Copy_u8Channel;
#if (ADC_Conversion == Single_conversion)
			/*start conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);
#endif
			/*ADC interrupt enable*/
			SET_BIT(ADCSRA,ADCSRA_ADIE);
		}
	}
	else
	{
		Local_u8ErrorState = BUSY_FUNCTION;
	}

	return Local_u8ErrorState;
}

u8 ADC_u8StartChainAsynch(Chain_t * Copy_Chain)
{
	u8 Local_u8ErrorState=OK;

	/*check NULL pointer*/
	if(Copy_Chain == NULL)
	{
		Local_u8ErrorState=NULL_POINTER;
	}
	else
	{
		if(ADC_u8BusyState==IDLE)
		{
			/*make ADC Busy*/
			ADC_u8BusyState= BUSY;

			/*make ISR source: chain Asynchronus*/
			ADC_u8ISRSource = CHAIN_ASYNCH;

			/*Initialize chain channel array*/
			ADC_pu8ChainChannelArr=Copy_Chain->Channel;

			/*Initialize result array*/
			ADC_pu16ChainResultArr=Copy_Chain->Result;

			/*Initialize chain Size*/
			ADC_u8ChainSize=Copy_Chain->Size;

			/*Initialize Notification Function*/
			ADC_pvCallBackNotificationFunc= Copy_Chain->NotificationFunc;

			/*Initialize Current Conversion Index*/
			ADC_u8ChainConversionIndex=0;

			/*Set required channel (First channel)*/
			ADMUX &= 0b11100000;
			ADMUX |= ADC_pu8ChainChannelArr[ADC_u8ChainConversionIndex];

			/*start conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);

			/*Enable conversion complete interrupt*/
			SET_BIT(ADCSRA,ADCSRA_ADIE);
		}
		else
		{
			Local_u8ErrorState=BUSY_FUNCTION;
		}
	}

	return Local_u8ErrorState;
}

void __vector_16 (void)     __attribute__((signal));
void __vector_16 (void)
{
	if(ADC_u8ISRSource == SINGLE_CHANNEL_ASYNCH)
	{
		/*read ADC result*/
#if 	(ADC_Resolution == Eight_Bits)
		*ADC_pu8Reading= ADCH;
#elif	(ADC_Resolution == Ten_Bits)
		*ADC_pu8Reading= ADC;
#else
#error "Resolution error"
#endif

		/*make ADC state be IDLE because it finished*/
		ADC_u8BusyState = IDLE;

		/*Invoke the callback notification function*/
		ADC_pvCallBackNotificationFunc();

		/*disable ADC conversion complete interrupt*/
		CLR_BIT(ADCSRA,ADCSRA_ADIE);
	}
	else if(ADC_u8ISRSource == CHAIN_ASYNCH) /*ISR source is chain */
	{
		/*Read the current conversion*/

#if 	(ADC_Resolution == Eight_Bits)
		ADC_pu16ChainResultArr[ADC_u8ChainConversionIndex]= ADCH;
#elif	(ADC_Resolution == Ten_Bits)
		ADC_pu16ChainResultArr[ADC_u8ChainConversionIndex]= ADC;
#else
#error "Resolution error"
#endif

		/*increment chain index*/
		ADC_u8ChainConversionIndex++;

		/*Check chain is finished or not*/
		if(ADC_u8ChainConversionIndex == ADC_u8ChainSize)
		{
			/*chain is finished*/
			/*ADC is now IDLE*/
			ADC_u8BusyState=IDLE;

			/*Invoke the callback notification function*/
			ADC_pvCallBackNotificationFunc();

			/*Disable ADC conversion complete interrupt*/
			CLR_BIT(ADCSRA,ADCSRA_ADIE);
		}
		else
		{
			/*chain is not finished*/
			/*set new required channel*/
			ADMUX &= 0b11100000;
			ADMUX |= ADC_pu8ChainChannelArr[ADC_u8ChainConversionIndex];

			/*start conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);
		}

	}
}

#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "SSD_interface.h"
#include "util/delay.h"


void main(void)
{
	SSD_T SSD1;

	SSD1.CommonType=SSD_COM_CA;
	SSD1.Port=DIO_u8PORTA;
	SSD1.CommonEnablePort=DIO_u8PORTC;
	SSD1.CommonEnablePin=DIO_u8PIN0;

while(1)
{
	SSD_u8Enable(&SSD1);
	SSD_u8SetNumber(SSD_NUMBER0,&SSD1);
	_delay_ms(1000);
	SSD_u8Disable(&SSD1);
	_delay_ms(1000);
}
}

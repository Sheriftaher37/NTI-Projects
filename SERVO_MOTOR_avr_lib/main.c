#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "PORT_interface.h"
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	PORT_voidInit();
	TCCR1A=0b10000010;
	TCCR1B=0b00011010;
	OCR1A=2000;
	ICR1=40000;

	while(1)
	{
		OCR1A=2200;
		_delay_ms(1000);
		OCR1A=2400;
		_delay_ms(1000);
		OCR1A=2600;
		_delay_ms(1000);
		OCR1A=2800;
		_delay_ms(1000);
		OCR1A=3000;
		_delay_ms(1000);
		OCR1A=3500;

	}
}



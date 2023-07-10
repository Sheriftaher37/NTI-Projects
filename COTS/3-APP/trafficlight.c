#include<avr/io.h>
#include<util/delay.h>


void red (int x);
void green (int x);
void yellow (int x);
int number[10]={0b0111111,   //0
		        0b0000110,   //1
				0b1011011,    //2
				0b1001111,    //3
				0b1100110,    //4
				0b1101101,    //5
				0b1111101,    //6
				0b0000111,    //7
				0b1111111,    //8
				0b1101111};    //9


void main(void)
{
	DDRA=0XFF;
	DDRD=0XFF;
	DDRC=0XFF;

			while(1)
			{
				red(number[10]);
				green(number[10]);
				yellow(number[10]);
			}
}

void red (int x)
{
	int i;
		for(i=15;i>0;i--)
		{
			if(i>=10)
			{
				PORTD=~number[1];
				PORTA=~number[i-10];
				PORTC=0b00000001; //red led
				_delay_ms(1000);
			}
			else if(i<10)
			{
				PORTD=~number[0];
				PORTA=~number[i];
				PORTC=0b00000001; //red led
				_delay_ms(1000);
			}

		}
		PORTC=0b00000000;
}

void green (int x)
{
	int i;
			for(i=15;i>0;i--)
			{
				if(i>=10)
				{
					PORTD=~number[1];
					PORTA=~number[i-10];
					PORTC=0b00000100; //green led
					_delay_ms(1000);
				}
				else if(i<10)
				{
					PORTD=~number[0];
					PORTA=~number[i];
					PORTC=0b00000100; //green led
					_delay_ms(1000);
				}

			}
			PORTC=0b00000000;
}

void yellow (int x)
{
	int i;
			for(i=5;i>0;i--)
			{
				if(i>=10)
				{
					PORTD=~number[1];
					PORTA=~number[i-10];
					PORTC=0b0000010; //yellow led
					_delay_ms(1000);
				}
				else if(i<10)
				{
					PORTD=~number[0];
					PORTA=~number[i];
					PORTC=0b0000010; //yellow led
					_delay_ms(1000);
				}

			}
			PORTC=0b00000000;
}

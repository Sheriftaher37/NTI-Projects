#include<avr/io.h>
#include<util/delay.h>

void main()
{
	int x,y,z;
	DDRA=0x00;
	PORTA=0xff;
	DDRC=0xff;
	while(1)
	{
		switch(PINA)
		{


		case 0b11111110:   //1  flash
			PORTC=0xff;
			_delay_ms(500);
			PORTC=0b00000000;
			_delay_ms(500);
			break;


		case 0b11111101:   //2  shift left
			PORTC=0b00000001;
			_delay_ms(250);
			for(y=1;y<8;y++)
			{
				z=PORTC<<1;
				PORTC=z;
				_delay_ms(250);
			}

		break;


		case 0b11111011:     //3   shift right
			PORTC=0b10000000;
					_delay_ms(250);
					for(y=1;y<8;y++)
					{
						z=PORTC>>1;
						PORTC=z;
						_delay_ms(250);
					}

				break;


		case 0b11110111:    //4   converging

			y=0b00000001;
			z=0b10000000;
			PORTC=y+z;
			_delay_ms(300);
			for(x=1;x<4;x++)
			{
				y=y<<1;
				z=z>>1;
				PORTC=y+z;
				_delay_ms(300);
			}

			break;


		case 0b11101111:     //5   diverging
			z=0b00010000;
			y=0b00001000;
						PORTC=y+z;
						_delay_ms(300);
						for(x=1;x<4;x++)
						{
							y=y>>1;
							z=z<<1;
							PORTC=y+z;
							_delay_ms(300);
						}

						break;


		case 0b11011111:   //6   ping pong
			PORTC=0b00000001;

						for(y=1;y<8;y++)
						{
							z=PORTC<<1;
							PORTC=z;
							_delay_ms(250);
						}
						for(y=1;y<8;y++)
						{
							z=PORTC>>1;
							PORTC=z;
							_delay_ms(250);
						}

			break;


		case 0b10111111:   //7 snake
			y=0b00000000;
			PORTC=y;
			_delay_ms(300);
			for(x=1;x<9;x++)
			{
				y=(y<<1)+1;
				PORTC=y;
				_delay_ms(300);
			}

			break;


		case 0b01111111:    //8   converging and diverging

			            y=0b00000001;
						z=0b10000000;
						PORTC=y+z;
						_delay_ms(300);
						for(x=1;x<4;x++)
						{
							y=y<<1;
							z=z>>1;
							PORTC=y+z;
							_delay_ms(300);
						}

						for(x=1;x<3;x++)
						{
							y=y>>1;
							z=z<<1;
							PORTC=y+z;
							_delay_ms(300);
						}

			break;


		default:
			PORTC=0b11111111;
			break;


		}
	}
}

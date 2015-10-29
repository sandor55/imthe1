#include <avr/io.h>
#include <util/delay.h>

#include "hd44780.h"

int main(void)
{


	while(1)
	{
		lcd_init();
			lcd_clrscr();
			lcd_puts("sandor is een");
			_delay_ms(1000);


		lcd_init();
		lcd_clrscr();
		lcd_puts("baas");
		_delay_ms(1000);
	}
}

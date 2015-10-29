/*
 * main.c
 *
 *  Created on: 17 sep. 2015
 *      Author: sandor
 */


#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRC = 0xFF; // poort C als output
	PORTC = 0x00;
	while(1) //loop
	{
		PORTC = 0xFF; // led aan
		_delay_ms(1000); // 1 seconde delay
		PORTC = 0x00; // alles uit;
		_delay_ms(1000); // 1 seconde delay
	}
}

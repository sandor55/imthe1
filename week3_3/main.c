/*
 * main.c
 *
 *  Created on: 28 mei 2015
 *      Author: sandor
 */




#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>


//rood is voor output
//blauw is ook output
//poortD 0 = A
//poortd 1 = B
//poortd 2 = C
//poortd 3 = D
//poortd 4 = E
//poortd 5 = F
//poortd 6 = G
//poortd 7 = DP
//PB01 = rechter
//pb02 = linker



//poort pb01 = is voor nr 13 pb 02(rechternr) voor nummer 14(linkernmmr)

//potschakelaar
//

static inline void initADC0(void)
{
ADMUX |= (1<<REFS0);  										//verwijst naar volt op AVCC
ADCSRA |= (1 << ADPS0) | (1 << ADPS1) | ( 1<< ADPS2) ;  	//adc clock prescaler / 8
ADCSRA |= (1 << ADEN);										// zet adc aan.
}

int main(void)
{

	uint16_t adcValue;
	uint8_t count;



	  int numb[16];
	  	  	  	  	  	  	  //Waardes hexa 1 -15
	  numb[0] = 0b00111111;  	//0
	  numb[1] = 0b00000110;   	//1
	  numb[2] = 0b01011011;   	//2
	  numb[3] = 0b01001111;	  	//3
	  numb[4] = 0b01100110;	  	//4
	  numb[5] = 0b01101101;	  	//5
	  numb[6] = 0b01111101;	  	//6
	  numb[7] = 0b00000111;		//7
	  numb[8] = 0b01111111;		//8
	  numb[9] = 0b01101111;		//9
	  numb[10]=	0b01110111;		//A
	  numb[11]= 0b01111100;		//B
	  numb[12]=	0b00111001;		//C
	  numb[13]= 0b01011110;  	//D
	  numb[14]= 0b01111001;		//E
	  numb[15]= 0b01110001;		//F
	  DDRD = 0xFF; //Alle D als output.
	  DDRB = 0xFF; //alle B as output


	initADC0();


	while(1)
	{
		ADCSRA |= (1<< ADSC);  //start ad conversion
		loop_until_bit_is_clear(ADCSRA,ADSC);  //wacht to die klaar is
		adcValue = ADC; 	//lees adc in
		count = adcValue;
				PORTB = 0b00000010; //eerste getal
				PORTD = ~numb[count%16];
				_delay_ms(1);
				PORTB = 0b0000100; //led 1
				PORTD = ~numb[count/16];
				_delay_ms(1);

	}

}

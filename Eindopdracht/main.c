/*
 * main.c
 *
 *  Created on: 18 jan. 2016
 *      Author: sandor
 */

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <math.h>
#include <avr/interrupt.h>
#include "mcp9800.h"

#define DISPLAYDDR 	DDRD 	//led display DDR
#define LED_DELAY 	5		//voor de RGB-led
#define LED_PORT 	PORTD	//LEDDDR
#define LED_PORT_NR PORTB
#define PWM_ROOD 	5
#define PWM_GROEN 	4
#define PWM_BLAUW	3
#define LINKSLED	PB1
#define RECHTSLED 	PB2
#define PIN_INPUT_DRUK PINB
#define PIN_INPUT	PB0


//poortD 0 = A
//poortd 1 = B
//poortd 2 = C
//poortd 3 = D
//poortd 4 = E
//poortd 5 = F
//poortd 6 = G
//poortd 7 = DP <<<niet gebruikt extra pin daardoor
//poort pb01 = is voor nr 13 pb 02(rechter-nr) voor nummer 14(linker-nr)


static inline void initADC0(void)
{
ADMUX |= (1<<REFS0);  										//verwijst naar volt op AVCC
ADCSRA |= (1 << ADPS0) | (1 << ADPS1) | ( 1<< ADPS2) ;  	//adc clock prescaler / 8
ADCSRA |= (1 << ADEN);										// zet adc aan.
}


  int main(void)
  {
		uint16_t adcValue = 0;						//default 0
		int numb[10];
		uint8_t temp = 0;							//default 0
		int instelling = 0;  						//ingestelde waarde temperatuur default 0
		int bool = 0;								//welke weergave op scherm

		//PORT instellingen
		DISPLAYDDR = 0xFF; //Alle D als output.
		DDRB = 0xFF; //alle B as output
		LED_PORT_NR = 0xFF;

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



	  DISPLAYDDR = 0xFF; //Alle D als output.
	  DDRB = 0xFF; //alle B as output
	  LED_PORT_NR = 0xFF;



	  //adc aan
	  initADC0();

	  //thermometer instellingen
	  mcp_init();
	  mcp_set_power_mode(MCP_POWER_UP);



  while(1) //loop
  {

      temp = mcp_read_temp_float();


		ADCSRA |= (1<< ADSC) ;  //start ad conversion
		loop_until_bit_is_clear(ADCSRA,ADSC);  //wacht to die klaar is
		adcValue = ADC;

			//check of pb0 hoog is, is die hoog. verander led getal naar instelling of temp.
			if((PIN_INPUT_DRUK & (1<<PIN_INPUT)) == 1)
			  	  	  {
				  			  if(bool == 1)
				  			  {
				  				  bool = 0;
				  			  }
				  			  else
				  			  {
				  				  	 bool = 1;
				  			  }
				  			_delay_ms(200);
				  		  //vertraging anders telt hij door

				  	  }

			PIN_INPUT_DRUK &= ~(1<<PIN_INPUT);  //pin weer 0 nadat hij hoog is, anders doet die niks meer
	if((bool == 1) && (instelling == temp))
	{
	  	LED_PORT_NR = (1<<LINKSLED)|(1<<PWM_BLAUW);  	//eerste getal + rood en groen aan
		LED_PORT =~ numb[temp%10];
		_delay_ms(10);
		LED_PORT_NR = (1<<RECHTSLED)|(1<<PWM_BLAUW) ; //tweede getal + rood en groen aan
		LED_PORT =~ numb[temp/10];
		_delay_ms(10);
	}
	if((bool == 1) && (instelling > temp))
	{
	  	LED_PORT_NR = (1<<LINKSLED)|(1<<PWM_BLAUW)| (1<<PWM_GROEN);  //eerste getal + rood aan
		LED_PORT =~ numb[temp%10];
		_delay_ms(10);
		LED_PORT_NR = (1<<RECHTSLED)|(1<<PWM_BLAUW)| (1<<PWM_GROEN);  //tweede getal + rood aan
		LED_PORT =~ numb[temp/10];
		_delay_ms(10);
	}
	if((bool == 1) && (instelling < temp))
	{
	  	LED_PORT_NR = (1<<LINKSLED)|(1<<PWM_BLAUW)| (1<<PWM_ROOD); 	//eerste getal + groen aan
		LED_PORT =~ numb[temp%10];
		_delay_ms(10);
		LED_PORT_NR = (1<<RECHTSLED)|(1<<PWM_BLAUW)| (1<<PWM_ROOD); 	//tweede getal + groen
		LED_PORT =~ numb[temp/10];
		_delay_ms(10);
	}
if(bool == 0)
	{
	instelling = adcValue/30;  //max instelbare waarde is 34 hierdoor
	LED_PORT_NR = (1<<LINKSLED)|(1<<PWM_GROEN)| (1<<PWM_ROOD); //eerste getal + blauw aan
		LED_PORT =~ numb[instelling%10];
		_delay_ms(10);
		LED_PORT_NR = (1<<RECHTSLED)|(1<<PWM_GROEN)| (1<<PWM_ROOD); //led 1+ blauw aan
		LED_PORT =~ numb[instelling/10];
		_delay_ms(10);
	}



 }

}

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
//#include <avr/interrupt.h>


#define LED_DELAY 	1
#define LED_DDR 	DDRB
#define LED_PORT 	PORTB
#define PWM_ROOD 	1
#define PWM_GROEN 	2
#define PWM_BLAUW	3
#define DRUK_DDR	DDRD
#define DRUK_PORT 	PORTD
#define DRUK_PIN	PIND
#define DRUK_INPUT	PD2
static inline void initADC0(void)
{
ADMUX |= (1<<REFS0);  										//verwijst naar volt op AVCC
ADCSRA |= (1 << ADPS0) | (1 << ADPS1) | ( 1<< ADPS2) ;  	//adc clock prescaler / 8
ADCSRA |= (1 << ADEN);										// zet adc aan.
}



int main()
{
	  //pwm instellingen
	  uint8_t roodbrightness = 0;
	  uint8_t blauwbrightness = 0;
	  uint8_t groenbrightness = 0;
	  uint8_t i;
	  uint8_t count = 0;
	  LED_DDR = 0xFF;
	  LED_PORT = 0xFF;										//alles uit

	  //druk knop instellingen
	  DRUK_DDR = 0x00;
	  DRUK_PORT = 0x00;

	  //adc
	  uint16_t adcValue;
	  initADC0();




	void pwm(int kleur,int brightness)						//regelt lichtweergave per kleur
	{
	// PWM
	    for (i = 0; i < 255; i++)
	    {
	      if (i < brightness)								//off/
	      {

	        LED_PORT &= ~(1<<kleur);                        /* turn on */
	      }
	      else
	      {
	    	  LED_PORT |= (1<<kleur);
	      }                                 				/* turn off */

	    }
	}
	 void potmeter()
	 {


		 ADCSRA |= (1<< ADSC);  							//start ad conversion
		 loop_until_bit_is_clear(ADCSRA,ADSC);  			//wacht to die klaar is
		 adcValue = ADC; 									//lees adc in
		  if(count == 0)
		  	  {
		  		  roodbrightness = adcValue/4; 				// gedeeld door 4 omdat 1024(moet 255)

		  	  }
		  if(count == 1)
		  	  {
		  		  blauwbrightness = adcValue/4; 			// gedeeld door 4 omdat 1024(moet 255)

		  	  }
		  if(count == 2)
		  	  {
		  		  groenbrightness = adcValue/4;			// gedeeld door 4 omdat 1024(moet 255)

		  	  }

	 }

  while(1)
  {

		 pwm(PWM_ROOD,roodbrightness);						//pwm regelen
		 pwm(PWM_BLAUW,blauwbrightness);
		 pwm(PWM_GROEN,groenbrightness);
		  if((DRUK_PIN & (1<<DRUK_INPUT)) == 1)
		  	  {
		  		  count = count + 1;						//count is voor PWM-licht
		  		  _delay_ms(200);
		  	  }
		  else
		  		 DRUK_PIN &= ~(1<<DRUK_INPUT);  //pin weer 0 nadat hij is hoog geweest
		  		  if(count > 2)					//count 0 als hij boven 2 komt.
		  		  	  {
		  			  	  count = 0;
		  		  	  }



		  potmeter();

  }

  return 0;
}

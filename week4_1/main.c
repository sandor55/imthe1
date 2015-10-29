#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>



#define LED_DELAY 	1
#define LED_DDR 	DDRB
#define LED_PORT 	PORTB
#define PWM_ROOD 	1
#define PWM_GROEN 	2
#define PWM_BLAUW	3
static inline void initADC0(void)
{
ADMUX |= (1<<REFS0);  										//verwijst naar volt op AVCC
ADCSRA |= (1 << ADPS0) | (1 << ADPS1) | ( 1<< ADPS2) ;  	//adc clock prescaler / 8
ADCSRA |= (1 << ADEN);										// zet adc aan.
}
int main()
{
	  //pwm instellingen
	  LED_DDR = 0xFF;
	  uint8_t roodbrightness = 0;
	  uint8_t blauwbrightness = 0;
	  uint8_t groenbrightness = 0;
	  uint8_t i;

	  //adc
	  uint16_t adcValue;
	  initADC0();
	void pwm(int kleur,int brightness)							//regelt lichtweergave per kleur
	{
	// PWM
	    for (i = 0; i < 255; i++)
	    {
	      if (i < brightness)									//off/
	      {

	        LED_PORT &= ~(1<<kleur);                             /* turn on */
	      }
	      else
	      {
	    	  LED_PORT |= (1<<kleur);
	      }                                 					/* turn off */

	    }
	 void potmeter()
	 {
		 ADCSRA |= (1<< ADSC);  //start ad conversion
		 		loop_until_bit_is_clear(ADCSRA,ADSC);  //wacht to die klaar is
		 		adcValue = ADC; 	//lees adc in
	 }
	}
  while(1)
  {
	  	 potmeter();
		 pwm(PWM_ROOD,adcValue);						//pwm regelen



  }

  return 0;
}

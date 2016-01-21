/*
 * main.c
 *
 *  Created on: 2 jun. 2015
 *      Author: sandor
 */


#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>




#define LED_DELAY 	20
#define LED_DDR 	DDRB
#define LED_PORT 	PORTB
#define PWM_ROOD 	1
#define PWM_GROEN 	2
#define PWM_BLAUW	3





int main(void)
{

  uint8_t roodbrightness = 0;
  uint8_t blauwbrightness = 0;
  uint8_t groenbrightness = 0;
  int8_t rooddirection = 1;
  int8_t blauwdirection = 1;
  int8_t groendirection = 1;


  LED_DDR = 0xFF;  //alles output
  LED_PORT = 0xFF; //alles uit

  /* Init all LEDs */
void downRood()
{

	 if(roodbrightness == 255)
		 {
			 rooddirection = 0;
		 }
	 else
	 	 {
		 	 rooddirection = 1;
	 	 }
	 for(int a = 0; a < 255; a++)
	 {
	roodbrightness += rooddirection;


	  for (int i = 0; i < 255; i++)
	      {
	        if (i < roodbrightness)
	        {

	          LED_PORT |= (1<<PWM_ROOD);                            /* turn on */
	        }
	        else
	        {
	      	  LED_PORT &= LED_PORT & ~(1<<PWM_ROOD);			//uit
	        }
	        _delay_us(LED_DELAY);
	      }
	 }
}


void downGroen()
{


	 if(groenbrightness == 255)
		 {
		 groendirection = 0;
		 }
	 else
		 	 {
			 	 groendirection = 1;
		 	 }
	 for(int a = 0; a < 255; a++)
	 {
		 groenbrightness += groendirection;


	  for (int i = 0; i < 255; i++)
	      {
	        if (i < groenbrightness)
	        {

	          LED_PORT |= (1<<PWM_GROEN);                            /* turn on */
	        }
	        else
	        {
	      	  LED_PORT &= LED_PORT & ~(1<<PWM_GROEN);			//uit
	        }
	        _delay_us(LED_DELAY);
	      }
	 }
}
void downBlauw()
{

	if(blauwbrightness == 255)
			 {
			 blauwdirection = 0;
			 }
	 else
		 	 {
			 	 blauwdirection = 1;
		 	 }
		 for(int a = 0; a < 255; a++)
		 {
			 blauwbrightness += blauwdirection;


		  for (int i = 0; i < 255; i++)
		      {
		        if (i < blauwbrightness)
		        {

		          LED_PORT |= (1<<PWM_BLAUW);                            /* turn on */
		        }
		        else
		        {
		      	  LED_PORT &= LED_PORT & ~(1<<PWM_BLAUW);			//uitzetten
		        }
		        _delay_us(LED_DELAY);
		      }
		 }
}
void upRood()
{

	 if(roodbrightness == 0)
		 {
			 rooddirection = 0;
		 }
	 else
	 	 {
		 rooddirection = -1;
	 	 }
	 for(int a = 0; a < 255; a++)
	 {
	roodbrightness += rooddirection;


	  for (int i = 0; i < 255; i++)
	      {
	        if (i < roodbrightness)
	        {

	          LED_PORT |= (1<<PWM_ROOD);                            /* turn on */
	        }
	        else
	        {
	      	  LED_PORT &= LED_PORT & ~(1<<PWM_ROOD);			//uit
	        }
	        _delay_us(LED_DELAY);
	      }
	 }
}
void upGroen()
{

	 if(groenbrightness == 0)
		 {
			 groendirection = 0;
		 }
	 else
	 	 {
		 groendirection = -1;
	 	 }
	 for(int a = 0; a < 255; a++)
	 {
	groenbrightness += groendirection;


	  for (int i = 0; i < 255; i++)
	      {
	        if (i < groenbrightness)
	        {

	          LED_PORT |= (1<<PWM_GROEN);                            /* turn on */
	        }
	        else
	        {
	      	  LED_PORT &= LED_PORT & ~(1<<PWM_GROEN);			//uit
	        }
	        _delay_us(LED_DELAY);
	      }
	 }
}
void upBlauw()
{

	 if(blauwbrightness == 0)
		 {
			 blauwdirection = 0;
		 }
	 else
	 	 {
		 blauwdirection = -1;
	 	 }
	 for(int a = 0; a < 255; a++)
	 {
	blauwbrightness += blauwdirection;


	  for (int i = 0; i < 255; i++)
	      {
	        if (i < blauwbrightness)
	        {

	          LED_PORT |= (1<<PWM_BLAUW);                            /* turn on */
	        }
	        else
	        {
	      	  LED_PORT &= LED_PORT & ~(1<<PWM_BLAUW);			//uit
	        }
	        _delay_us(LED_DELAY);
	      }
	 }
}

while (1)
  {
//	rood groen blauw

upRood();
upBlauw();
upGroen();

//	rood groen
downBlauw();

//	rood
downGroen();

//	rood blauw
upBlauw();

//	blauw
downRood();

//blauw groen
upGroen();

//	groen
downBlauw();


  }                                            /* End event loop */
	  return (0);                            /* This line is never reached */
}

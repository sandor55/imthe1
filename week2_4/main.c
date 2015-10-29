/*
 * main.c
 *
 *  Created on: 2 jun. 2015
 *      Author: sandor
 */


#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>




#define LED_DELAY 	1
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
  uint8_t i;
  int counter = 0;


  LED_DDR = 0xff;
  /* Init all LEDs */
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
}
void roodup()												//rood omhoog
{
	if (roodbrightness == 0)
		{
		rooddirection = 1;

		}
	if(roodbrightness == 255)
		{
		rooddirection = 0;
		}
	roodbrightness += rooddirection;						//kleur verandering rood


}
void rooddown()												//rood omlaag
{
	if (roodbrightness > 250)
		{
		rooddirection = -1;

		}
	if(roodbrightness == 0)
		{
		rooddirection = 0;
		}
	roodbrightness += rooddirection;


}
void blauwup()												//idem dito rood
{
	if (blauwbrightness == 0)
		{
		blauwdirection = 1;

		}
	if(blauwbrightness == 255)
		{
		blauwdirection = 0;
		}
	blauwbrightness += blauwdirection;


}
void blauwdown()										//zelfde als rood
{
	if (blauwbrightness > 250)
		{
		blauwdirection = -1;

		}
	if(blauwbrightness == 0)
		{
		blauwdirection = 0;
		}
	blauwbrightness += blauwdirection;


}
void groenup()											//zelfde als rood
{
	if (groenbrightness == 0)
		{
		groendirection = 1;

		}
	if(groenbrightness == 255)
		{
		groendirection = 0;
		}
	groenbrightness += groendirection;


}
void groendown()										//zelfde als rood
{
	if (groenbrightness > 250)
		{
		groendirection = -1;

		}
	if(groenbrightness == 0)
		{
		groendirection = 0;
		}
	groenbrightness += groendirection;


}
  while (1)
  {
		 pwm(PWM_ROOD,roodbrightness);						//pwm regelen
		 pwm(PWM_BLAUW,blauwbrightness);
		 pwm(PWM_GROEN,groenbrightness);
	  if(counter == 1)
	 	{
	 roodup();											//alle kleuren aan
	 blauwup();
	 groenup();

	 	}
	  if(counter == 2)
	  {
	 groendown();

	  }
	 if(counter == 3)
		 {
		 	 blauwdown();

		 }
	 if(counter == 4)
	 {
		 groenup();

	 }

	 if(counter == 5)
	 {
		 rooddown();
	 }
	 if(counter == 6)
	 {
		 blauwup();

	 }
	 if(counter == 7)
	 {
		 groendown();
	 }
	 if(counter == 8)
	 {
		 blauwdown();
	 }
	 if(counter > 9)
	 {
		 counter = 0;
	 }
	 counter += 1;
	  }                                                  /* End event loop */
	  return (0);                            /* This line is never reached */
}

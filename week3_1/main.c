#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>



int main(void)
{
  //Makes first pin of PORTC as Output
  // OR DDRC = 0x01;
	DDRC = 0x00;//Makes first pin of PORTB as Input
	PORTC = 0x00;
	DDRB = 0xFF; // maakt uitput van porten B
	PORTB = 0x00;

	int status = 0;
  while(1) //infinite loop
  {
	  if((PINC & (1<<PC0)) == 1) //als PC0 hoog geeft(als knop is gedrukt).
		 {
		  	  if(status == 0)  //status = 0 ,gaat dan status 1
		  	  {
		  		  status = 1;
		  	  }
		  	  else
		  		  status = 0;
		  	  _delay_ms(200);

		 }
	  if(status == 1)  //als status 1 is, hoog niveau op B(led aan).
	  {
		  PORTB = 0xFF;
	  }
	  else   		//anders uit.
		  PORTB = 0x00;
  }
}



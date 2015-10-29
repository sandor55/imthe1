
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <math.h>
#include <avr/interrupt.h>



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


  int main(void)
  {
	  int count = 0;

	  int numb[10];
	  numb[0] = 0b00111111;
	  numb[1] = 0b00000110;
	  numb[2] = 0b01011011;
	  numb[3] = 0b01001111;
	  numb[4] = 0b01100110;
	  numb[5] = 0b01101101;
	  numb[6] = 0b01111101;
	  numb[7] = 0b00000111;
	  numb[8] = 0b01111111;
	  numb[9] = 0b01101111;

	  DDRB = 0xFF; //alle B as output
	  DDRD = 0xFF; //Alle D als output.

	  DDRC = 0x00; // C als input
	  PORTC = 0x00;


  while(1) //loop
  {
	  if((PINC & (1<<PC0)) == 1)
	  	  {
	  		  count = count + 1;
	  		  _delay_ms(200); //vertraging anders telt hij door

	  	  }

	  else
		  PINC &= ~(1<<PC0);  //pin weer 0 nadat hij is hoog, anders telt hij niet meer na druk
	  if(count > 99)
	  		  { count = 0;}

	  		  PORTB = 0b00000010; //eerste getal
	  	  	PORTD =~ numb[count%10];
	  	  	 _delay_ms(5);
	  	     PORTB = 0b0000100; //led nr1
	  	     PORTD =~ numb[count/10];
	  	     _delay_ms(5);
  }

}

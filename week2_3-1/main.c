

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

//poort pb00 = A
//poort pb01 = B
//poort pb02 = c etc...


//poort pb01 = is voor nr 13 pb 02(rechternr) voor nummer 14(linkernmmr)

  int main(void)
  {
	  int count = 0;
	  int numb[10];
	  int tellen = 0;
	  	  	  	  	  	  	  //hexadeci-waardes
	  numb[0] = 0b00111111;    //0x3F
	  numb[1] = 0b00000110;    //0x06
	  numb[2] = 0b01011011;    //0x51
	  numb[3] = 0b01001111;	   //
	  numb[4] = 0b01100110;
	  numb[5] = 0b01101101;
	  numb[6] = 0b01111101;
	  numb[7] = 0b00000111;
	  numb[8] = 0b01111111;
	  numb[9] = 0b01101111;

	  DDRB = 0xFF;  // alle B als output
	  DDRD = 0xFF; //alle D als uitput
  while(1) //loop
  {
	if(count > 99)
		{
			count = 0;
		}
	PORTB = 0b00000010; //eerste getal
	PORTD =~ numb[count%10];
	_delay_ms(10);
	PORTB = 0b0000100; //led 1
	PORTD =~ numb[count/10];   //bij de herkansing ineens =~ . als sla je me dood waarom ineens...
	_delay_ms(10);

	tellen = tellen +1;
	if(tellen >= 50)  //50 omdat 2 delays van 10 = 20. 1000 /20 = 50. dus elke 50 tellen = 1 sec.
		{
			tellen = 0;
			count = count + 1;
		}
  }
}

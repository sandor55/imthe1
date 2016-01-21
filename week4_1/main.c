#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>
#include <avr/delay.h>
#include <stdio.h>

#define _ms(n) (17*n)

void wait(unsigned int a) //basic wait
{
volatile unsigned int b,c;
for(b=0;b!= a; b++)for(c=0;c!= 50;c++);
return;
}

int const bitsize=16;
unsigned int one_pwm[16];
unsigned int two_pwm[16];
unsigned int three_pwm[16];
unsigned int p1=1; // Set value of point to rightmost zero in array
unsigned int p2=1;
unsigned int p3=1;

void init_pwm () // Initialize pwm arrays
{
 unsigned int tel=0;
 for (tel=1;tel<bitsize;tel++)
 {
  one_pwm[tel]=0;
  two_pwm[tel]=0;
  three_pwm[tel]=0;
 }
 one_pwm[0]=1; // Set value of rightmost bit in array
 two_pwm[0]=1;
 three_pwm[0]=1;
 p1=1; // Set value of point to rightmost zero in array
 p2=1;
 p3=1;
 return;
}


unsigned char port_write=0b00000000;
unsigned int bitje=0;

ISR(SIG_OUTPUT_COMPARE1A)
{
 if (one_pwm[bitje]==1)
  { port_write |= (1<<0);}
 else
  {port_write &= ~(1<<0);}
 if (two_pwm[bitje]==1)
  { port_write |= (1<<1);}
 else
  {port_write &= ~(1<<1);}
 if (three_pwm[bitje]==1)
  { port_write |= (1<<2);}
 else
  {port_write &= ~(1<<2);}

 bitje++;
 if (bitje>=bitsize) {bitje=0;}
 PORTB=port_write;
 return;
}

void ioinit (void)
{
   DDRC  = 0b11000111; //1 = output, 0 = input
   PORTC = 0b00111000; //Enable pin 5, 4 and 3 internal pullup
   DDRB  = 0b11111111; //1= output, 0 = input
   PORTB = 0b00000111; //Set PB pins 0, 1 and 2 to high
}


#define BTUP() (bit_is_clear(PINC,4))
#define BTDOWN() (bit_is_clear(PINC,5))
#define SWITCH() (bit_is_clear(PINC,3))

int main(void)
{
TIMSK1 = _BV(OCIE1A); //Enable Interrupt Timer/Counter 1,Output Compare A
TCCR1B = _BV(CS11) | _BV(WGM12); //Clock/8, 0.000008 secs/tick, Mode=CTC
OCR1A = 16; // SIG_COMPARE1A triggered every 0.000008*16 Seconds

init_pwm();
sei();
ioinit();
//lcd_init();

unsigned int maxdelay=1;
unsigned int thisport=1;

while (1)
{
 if (SWITCH()) // Button for other color control has been pushed
  {
   thisport++;
   if (thisport>3) {thisport=1;} // Note: only 3 ports in use
   _delay_ms(maxdelay*4);
  }

 if (BTUP())  // Button for pwm increase has been pushed
  {
   switch (thisport)
   {
    case 1: if (p1<bitsize)
                {
                         one_pwm[p1]=1;
                         p1++;
                        }
                        break;
        case 2: if (p2<bitsize)
                {
                 two_pwm[p2]=1;
                         p2++;
                        }
                        break;
        case 3: if (p3<bitsize)
                {
                         three_pwm[p3]=1;
                         p3++;
                        }
                        break;
        default: break;
   }
  _delay_ms(maxdelay);
  }
 if (BTDOWN())  // Button for pwm decrease has been pushed
  {
   switch (thisport)
   {
    case 1: if (p1>0)
                {
              p1--;
                         one_pwm[p1]=0;
                        }

        break;
        case 2: if (p2>0)
                {
                         p2--;
                         two_pwm[p2]=0;
                        }
                        break;
        case 3: if (p3>0)
                {
                         p3--;
                         three_pwm[p3]=0;
                        }
                        break;
        default: break;
   }
  _delay_ms(maxdelay);
  }
 //char buffer[16];
 //sprintf(buffer, "%2d %2d %2d  P%1d",p1,p2,p3,thisport);
 //lcd_goto(0);
 //lcd_puts(buffer);
 _delay_ms(maxdelay);
}
}

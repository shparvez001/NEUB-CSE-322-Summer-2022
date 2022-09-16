#include<avr/io.h>

int main()
{
  //Setup/Initialization
  //DDRB = (1<<DDB3)|(1<<DDB2)|(1<<DDB1)|(1<<DDB0); //Declaring B0 to B3 as outputs
  //DDRB|=(1<<2); //Declare PB2 as output
  DDRB=0xff; //Declaring full port B as output
  DDRD=0x00; //Declaring full port D as input
  //DDRC=0b00001111;
  unsigned int i;
  while(1)
  {
    i=PIND; //Store the value of D (PD0-PD7) in i.
    PORTB=i; //Output value of I to port B.
  }
}

# NEUB CSE 322 Summer 2022 Lab 8

Find all Codes at  [Lab 8](https://github.com/shparvez001/NEUB-CSE-322-Summer-2022/tree/main/lab-8).

## Task 1
Basic Input and output code for AVR.

Circuit:

![Lab 8 Task 1 Circuit in breadboard](https://raw.githubusercontent.com/shparvez001/NEUB-CSE-322-Summer-2022/main/lab-8/CSE-322-2202-lab8-task-1CKT_bb.png)

Code
```c
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
```

## Task 2
LED blinking code in AVR.

Circuit:

![Lab 8 Task 2 Circuit in breadboard](https://raw.githubusercontent.com/shparvez001/NEUB-CSE-322-Summer-2022/main/lab-8/CSE-322-2202-lab8-task-2CKT_bb.png)

Code
```c
#include<avr/io.h>
#include<util/delay.h>

int main()
{
  PORTB=0xff; //Declare full port B as output

  while(1)
  {
    PORTB=0x00; //turn of all output
    _delay_ms(1000);
    PORTB=0xff; //turn on all output
    _delay_ms(1000);
  }
}
```

# NEUB CSE 322 Summer 2022 Lab 9

Find all Codes at  [Lab 9](https://github.com/shparvez001/NEUB-CSE-322-Summer-2022/tree/main/lab-9).

## Task 1
EEPROM read and write code.

Circuit:

![Lab 9 Task 1 Circuit in breadboard](https://raw.githubusercontent.com/shparvez001/NEUB-CSE-322-Summer-2022/main/lab-9/CSE-322-2202-lab9-task-1CKT_bb.png)

Code
```c
#include<avr/io.h>
#include<avr/eeprom.h>
#include<util/delay.h>

int main()
{
  unsigned char i;
  DDRC=0xFF;
  for(i=0;i<10;i++)
  {
    eeprom_write_byte((unsigned char *)i,i);
  }
  for(i=0;i<10;i++)
  {
    PORTC=eeprom_read_byte((unsigned char *)i);
    _delay_ms(1000);
  }

  while(1)
  {    
  }  
}

```

## Task 2
Using EEPROM to store a pattern of LED and pulsing through the pattern.

Circuit:

![Lab 9 Task 2 Circuit in breadboard](https://raw.githubusercontent.com/shparvez001/NEUB-CSE-322-Summer-2022/main/lab-9/CSE-322-2202-lab9-task-2CKT_bb.png)

Code
```c
#include<avr/io.h>
#include<avr/eeprom.h>
#include<util/delay.h>

int main()
{
  unsigned char i;
  DDRC=0xFF;

  eeprom_write_byte((unsigned char *)0,0);
  eeprom_write_byte((unsigned char *)1,15);
  eeprom_write_byte((unsigned char *)2,1);
  eeprom_write_byte((unsigned char *)3,2);
  eeprom_write_byte((unsigned char *)4,4);
  eeprom_write_byte((unsigned char *)5,8);
  while(1)
  {
    for(i=0;i<6;i++)
    {
      PORTC=eeprom_read_byte((unsigned char*)i);
      _delay_ms(1000);
    }
  }
}

```

## Task 3
Create a function to output PWM with a specified duty cycle to any given port. eg: pwm(port, dutyCycle);.

Circuit:

//To be done by students

Code
```c
//To be done by students
```

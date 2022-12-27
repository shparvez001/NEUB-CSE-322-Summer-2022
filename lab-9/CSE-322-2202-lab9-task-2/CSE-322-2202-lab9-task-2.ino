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

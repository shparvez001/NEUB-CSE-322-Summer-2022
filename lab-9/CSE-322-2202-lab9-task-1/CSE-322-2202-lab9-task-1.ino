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

int switchPin=7;
int ledPin=13;
float vref=5.00;
float volt=0; 
int threshold=0;

void setup()
{
  Serial.begin(115200);//Baudrate=115200
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  sensorValue=analogRead(A0);
  volt=vref*(float)sensorValue/1023;
  Serial.print("Sensor Value= ");
  Serial.print(sensorValue);
  Serial.print("   Volatge= ");
  Serial.print(volt);
  if(sensorValue<treshold)
  {
    digitalWrite(ledPin,HIGH);
    delay(100);
  }
  else
  {
    digitalWrite(ledPin,LOW);
    delay(100);
  }
}

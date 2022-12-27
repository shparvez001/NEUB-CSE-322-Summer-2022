int sensorPin=A0;
int sensorValue=0;
float vref=5.00;
float volt=0; 

void setup()
{
  Serial.begin(115200);//Baudrate=115200
}

void loop()
{
  sensorValue=analogRead(A0);
  volt=vref*(float)sensorValue/1023;
  Serial.println(volt);
}

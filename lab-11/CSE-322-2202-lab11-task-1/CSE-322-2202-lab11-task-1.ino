int switchPin=7;
int switchStatus=0;
int ledPin=13;
bool ledStatus=false;

void setup()
{
  Serial.begin(115200);//Baudrate=115200
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  switchStatus=digitalRead(switchPin);
  Serial.println(switchStatus);
  if(switchStatus)
  {
    if(ledStatus)
    {
      ledStatus=false;
    }
    else
    {
      ledStatus=true;
    }
  }  
  digitalWrite(ledPin, ledStatus);
  delay(500);
}

int switchPin = 2;
int switchStatus = 0;
int ledPin = 13;
bool ledStatus = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT);
  attachInterrupt(0,outputToggle,FALLING);
}

void loop() {
  
}

void outputToggle()
{
  ledStatus=!ledStatus;
  digitalWrite(ledPin, ledStatus);
}

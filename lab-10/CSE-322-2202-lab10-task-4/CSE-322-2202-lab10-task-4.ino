int switchPin=7;
int switchStatus=0;
int ledPin=13;

void setup()
{
  Serial.begin(115200);//Baudrate=115200
  pinMode(swicthPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  switchStatus=digitalRead(switchPin);
  Serial.println(switchStatus);
  digitalWrite(ledPin, switchStatus);
  delay(500);
}

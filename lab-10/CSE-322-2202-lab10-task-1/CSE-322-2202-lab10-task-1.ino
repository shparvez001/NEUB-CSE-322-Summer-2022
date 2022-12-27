int sensorPin=A0;
int sensorValue=0;
int ledPin=13;

void setup()
{
  pinMode(ledPin, INPUT);
}

void loop()
{
  sensorValue=analogRead(A0);
  digitalWrite(ledPin, HIGH);
  delay(sensorValue);
  digitalWrite(ledPin, LOW);
  delay(sensorValue);
}

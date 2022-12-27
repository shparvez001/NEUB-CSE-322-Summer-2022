int switchPin = 7;
int switchStatus = 0;
int currentSwitchStatus = 0;
int lastSwitchStatus = 0;
int ledPin = 13;
bool ledStatus = false;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup()
{
  Serial.begin(115200);//Baudrate=115200
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  switchStatus = digitalRead(switchPin);
  Serial.println(switchStatus);
  if (switchStatus != lastSwitchStatus)
  {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay)
  {
    if (switchStatus != currentSwitchStatus) {
      currentSwitchStatus = switchStatus;
      if (currentSwitchStatus == HIGH)
      {
        ledStatus = !ledStatus;
        lastSwitchStatus = switchStatus;
      }
    }
  }
  digitalWrite(ledPin, ledStatus);
}

# NEUB CSE 322 Summer 2022 Lab 11

Find all Codes at  [Lab 11](https://github.com/shparvez001/NEUB-CSE-322-Summer-2022/tree/main/lab-11).

## Task 1
Write an arduino code change the status of LED (on or off) based on switch input.

Circuit:

![Lab 11 Task 1 Circuit in breadboard](https://raw.githubusercontent.com/shparvez001/NEUB-CSE-322-Summer-2022/main/lab-11/CSE-322-2202-lab11-task-1CKT_bb.png)

Code
```c
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
```

## Task 2
Write an arduino code change the status of LED (on or off) based on switch input with a debounce delay of 50us.

Circuit:

![Lab 11 Task 2 Circuit in breadboard](https://raw.githubusercontent.com/shparvez001/NEUB-CSE-322-Summer-2022/main/lab-11/CSE-322-2202-lab11-task-2CKT_bb.png)

Code
```c
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
```

## Task 3
Using switch with interrupt.

Circuit:

//To be done by students

Code
```c
//To be done by students
```

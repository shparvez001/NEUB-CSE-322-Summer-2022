# NEUB CSE 322 Summer 2022 Lab 10

Find all Codes at  [Lab 10](https://github.com/shparvez001/NEUB-CSE-322-Summer-2022/tree/main/lab-10).

## Task 1
Reading analong value using built-in ADC.

Circuit:

![Lab 10 Task 1 Circuit in breadboard](https://raw.githubusercontent.com/shparvez001/NEUB-CSE-322-Summer-2022/main/lab-10/CSE-322-2202-lab10-task-1CKT_bb.png)

Code
```c
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
```

## Task 2
Reading voltage using built-in ADC and showing it inb serial monitor.

Circuit:

![Lab 10 Task 2 Circuit in breadboard](https://raw.githubusercontent.com/shparvez001/NEUB-CSE-322-Summer-2022/main/lab-10/CSE-322-2202-lab10-task-2CKT_bb.png)

Code
```c
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
```

## Task 3
Using LDR as sensor.

Circuit:

![Lab 10 Task 3 Circuit in breadboard](https://raw.githubusercontent.com/shparvez001/NEUB-CSE-322-Summer-2022/main/lab-10/CSE-322-2202-lab10-task-3CKT_bb.png)


Code
```c
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
```

## Task 4
Basic switch Operation.

Circuit:

![Lab 10 Task 4 Circuit in breadboard](https://raw.githubusercontent.com/shparvez001/NEUB-CSE-322-Summer-2022/main/lab-10/CSE-322-2202-lab10-task-4CKT_bb.png)


Code
```c
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
```

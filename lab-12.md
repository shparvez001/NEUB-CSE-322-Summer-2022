# NEUB CSE 322 Summer 2022 Lab 12

Find all Codes at  [Lab 12](https://github.com/shparvez001/NEUB-CSE-322-Summer-2022/tree/main/lab-12).

## Task 1
Using switch with interrupt.

//Last days task but solution given to students.

Circuit:

![Lab 12 Task 1 Circuit in breadboard](https://raw.githubusercontent.com/shparvez001/NEUB-CSE-322-Summer-2022/main/lab-12/CSE-322-2202-lab12-task-1CKT_bb.png)

Code
```c
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
```

## Task 2
Write a code to drive a dc motor using L298 motor driver.

Circuit:

![Lab 12 Task 2 Circuit in breadboard](https://raw.githubusercontent.com/shparvez001/NEUB-CSE-322-Summer-2022/main/lab-12/CSE-322-2202-lab12-task-2CKT_bb.png)

![L298 Motor Driver Module pinout](https://raw.githubusercontent.com/shparvez001/NEUB-CSE-322-Summer-2022/main/lab-12/L298-Motor-Driver-02-1100x1100.jpg)

Code
```c
int mls1=3;
int mls2=4;
int mrs1=5;
int mrs2=6;
int mlen=10;
int mren=11;

void setup() {
  pinMode(mls1,OUTPUT);
  pinMode(mls2,OUTPUT);
  pinMode(mrs1,OUTPUT);
  pinMode(mrs2,OUTPUT);
  pinMode(mlen,OUTPUT);
  pinMode(mren,OUTPUT);
  Serial.begin(115200);
  digitalWrite(mlen, HIGH);
  digitalWrite(mren, HIGH);
}

void loop() {
  //Move forward
  //MOve motor 1 Clockwise
  digitalWrite(mls1,HIGH);
  digitalWrite(mls2,LOW);
  //MOve motor 2 Clockwise
  digitalWrite(mrs1,HIGH);
  digitalWrite(mrs2,LOW);
  delay(1000);

  //Move Backward
  //move motor 1 anticlockwise
  digitalWrite(mls1,LOW);
  digitalWrite(mls2,HIGH);
  //move motor 2 anticlockwise
  digitalWrite(mrs1,LOW);
  digitalWrite(mrs2,HIGH);
  delay(1000);

  //Move Forward Right
  //move motor 1 clockwise
  digitalWrite(mls1,HIGH);
  digitalWrite(mls2,LOW);
  //Stop Motor 2
  digitalWrite(mrs1,LOW);
  digitalWrite(mrs2,LOW);
  delay(1000);

  //Move Forward Left
  //Stop Motor 2
  digitalWrite(mls1,LOW);
  digitalWrite(mls2,LOW);
  //Move motor 2 clockwise
  digitalWrite(mrs1,HIGH);
  digitalWrite(mrs2,LOW);
}
```

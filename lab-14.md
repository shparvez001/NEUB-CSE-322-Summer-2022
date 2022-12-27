# NEUB CSE 322 Summer 2022 Lab 14

Find all Codes at  [Lab 14](https://github.com/shparvez001/NEUB-CSE-322-Summer-2022/tree/main/lab-14).

## Task 1
Write a code to drive dc motors with variable speed using L298 motor driver. Different movement should be incorporated using individual functions.

//Last days task but solution given to students.


Circuit:

![Lab 14 Task 1 Circuit in breadboard](https://raw.githubusercontent.com/shparvez001/NEUB-CSE-322-Summer-2022/main/lab-14/CSE-322-2202-lab14-task-1CKT_bb.png)

Code
```c
int mls1=3;
int mls2=4;
int mrs1=5;
int mrs2=6;
int mlen=10;
int mren=11;

void moveForward(int speedPercent)
{
  int pwmVal=map(speedPercent,0,100,0,255);
  analogWrite(mlen,pwmVal);
  analogWrite(mren,pwmVal);
  //Move forward
  //MOve motor 1 Clockwise
  digitalWrite(mls1,HIGH);
  digitalWrite(mls2,LOW);
  //MOve motor 2 Clockwise
  digitalWrite(mrs1,HIGH);
  digitalWrite(mrs2,LOW);
}

void moveBackward(int speedPercent)
{
  int pwmVal=map(speedPercent,0,100,0,255);
  analogWrite(mlen,pwmVal);
  analogWrite(mren,pwmVal);
  //Move Backward
  //move motor 1 anticlockwise
  digitalWrite(mls1,LOW);
  digitalWrite(mls2,HIGH);
  //move motor 2 anticlockwise
  digitalWrite(mrs1,LOW);
  digitalWrite(mrs2,HIGH);
}

void moveForwardRight(int speedPercent)
{
  int pwmVal=map(speedPercent,0,100,0,255);
  analogWrite(mlen,pwmVal);
  analogWrite(mren,pwmVal);
  //Move Forward Right
  //move motor 1 clockwise
  digitalWrite(mls1,HIGH);
  digitalWrite(mls2,LOW);
  //Stop Motor 2
  digitalWrite(mrs1,LOW);
  digitalWrite(mrs2,LOW);
}

void moveForwardLeft(int speedPercent)
{
  int pwmVal=map(speedPercent,0,100,0,255);
  analogWrite(mlen,pwmVal);
  analogWrite(mren,pwmVal);
  //Move Forward Left
  //Stop Motor 2
  digitalWrite(mls1,LOW);
  digitalWrite(mls2,LOW);
  //Move motor 2 clockwise
  digitalWrite(mrs1,HIGH);
  digitalWrite(mrs2,LOW);
}

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
  moveForward(40);
  delay(1000);
  moveForwardRight(50);
  delay(1000);
  moveForwardLeft(50);
  delay(1000);
  moveBackward(100);
  delay(1000);
}
```

## Task 2
Servo motor driving.

Circuit:

![Lab 14 Task 2 Circuit in breadboard](https://raw.githubusercontent.com/shparvez001/NEUB-CSE-322-Summer-2022/main/lab-14/CSE-322-2202-lab14-task-2CKT_bb.png)


Code
```c
#include<Servo.h>

Servo myservo1;
int servo1Pin=9;
int value;

void setup() {
  myservo1.attach(servo1Pin);
  Serial.begin(115200);
}

void loop() {
  if(Serial.available()>0)
  {
    value=Serial.read(); //Expecting something between 0-9
    Serial.print(value);
    value=value-48;
    value=value*20;
    Serial.print(" - angle=");
    Serial.println(value);
    myservo1.write(value);
    delay(500);
  }
}
```

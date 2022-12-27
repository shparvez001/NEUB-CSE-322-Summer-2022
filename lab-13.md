# NEUB CSE 322 Summer 2022 Lab 13

Find all Codes at  [Lab 13](https://github.com/shparvez001/NEUB-CSE-322-Summer-2022/tree/main/lab-13).

## Task 1
Write a code to drive dc motors using L298 motor driver. Different movement should be incorporated using individual functions.


Circuit:

![Lab 13 Task 1 Circuit in breadboard](https://raw.githubusercontent.com/shparvez001/NEUB-CSE-322-Summer-2022/main/lab-13/CSE-322-2202-lab13-task-1CKT_bb.png)

Code
```c
int mls1=3;
int mls2=4;
int mrs1=5;
int mrs2=6;
int mlen=10;
int mren=11;

void moveForward()
{
  //Move forward
  //MOve motor 1 Clockwise
  digitalWrite(mls1,HIGH);
  digitalWrite(mls2,LOW);
  //MOve motor 2 Clockwise
  digitalWrite(mrs1,HIGH);
  digitalWrite(mrs2,LOW);
}

void moveBackward()
{
  //Move Backward
  //move motor 1 anticlockwise
  digitalWrite(mls1,LOW);
  digitalWrite(mls2,HIGH);
  //move motor 2 anticlockwise
  digitalWrite(mrs1,LOW);
  digitalWrite(mrs2,HIGH);
}

void moveForwardRight()
{
  //Move Forward Right
  //move motor 1 clockwise
  digitalWrite(mls1,HIGH);
  digitalWrite(mls2,LOW);
  //Stop Motor 2
  digitalWrite(mrs1,LOW);
  digitalWrite(mrs2,LOW);
}

void moveForwardLeft()
{
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
  moveForwardRight();
  delay(1000);
  moveForwardLeft();
  delay(1000);
  moveBackward();
  delay(1000);
}
```

## Task 2
Write a code to drive dc motors with variable speed using L298 motor driver. Different movement should be incorporated using individual functions.

Circuit:

//To be done by students

Code
```c
//To be done by students
```

## Tasks to be done by students
1. Change the code in task 1 to include backward right, backward left and brake functionality.
2. Change the code in task 2 to include backward right, backward left and brake functionality.

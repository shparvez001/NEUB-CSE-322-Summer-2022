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

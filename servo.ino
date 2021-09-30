#include <Servo.h>

Servo myServo;
Servo myServo2;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(9);
  myServo2.attach(10);
 Serial.begin(9600);
}

void loop() {
 float x= analogRead(A0);
 x=map(x,0,1023,0,180);
 float y= analogRead(A1);
 y=map(y,0,1023,0,180);

 myServo.write(x);
 myServo2.write(y);

}

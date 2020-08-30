#include <Servo.h>


Servo servo;
Servo servo1;

const int servoPin = 3;
const int servoPiN = 4;

void setup() {
  servo.attach(servoPin);
  servo1.attach(servoPiN);
  


}

void loop() {
  servo.write(120);
  servo1.write(60);
  delay(3000);
  servo.write(60);
  servo1.write(120);
  delay(3000);
}



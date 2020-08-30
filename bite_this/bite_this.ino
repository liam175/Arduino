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
  servo.write(90);
  servo1.write(90);
  delay(random(100, 10000));
  servo.write(60);
  servo1.write(140);
  delay(1000);
  
}
     

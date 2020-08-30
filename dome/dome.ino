#include <Servo.h>
const int servoPin = 2;
int switcH = 13;

Servo servo;
void setup() {
  servo.attach(servoPin);
 
  servo.write(0);
  // put your setup code here, to run once:

}

void loop() {
   if ( digitalRead(switcH) == HIGH) {
    servo.write(90);
    
   }
   if ( digitalRead(switcH) == LOW) {
    servo.write(0);
   }
  // put your main code here, to run repeatedly:

}

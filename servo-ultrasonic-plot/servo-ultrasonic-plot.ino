#include <Servo.h>

#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

Servo servo;

#define MAX_DIST 20

const int servoPin = 3;

const int trigPin = 9;
const int echoPin = 10;

void setup() {
  servo.attach(servoPin);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(trigPin, LOW);
  Serial.begin(9600);
;

}

void senseDistance(int angle, int column, int row)
{
  servo.write(angle);
  delay(400);
  printDistance(column, row);
  delay(0);
}

int printDistance(int column, int row)
{
  unsigned long distance = readDistance() / 10;
  int dist = distance > MAX_DIST ? MAX_DIST : distance; 
  Serial.print("  " );
  Serial.print( dist );
}

unsigned long readDistance()
{
  int duration;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1);
  digitalWrite(trigPin, LOW);
  return pulseIn(echoPin, HIGH);
}

void loop() {
  for (;;) {
    senseDistance(70,0,0);
    senseDistance(80,2,1);
    senseDistance(90,6,0);
    senseDistance(100,8,1);
    senseDistance(110,12,0);
    senseDistance(100,8,1);
    senseDistance(90,6,0);
    senseDistance(80,2,1);
    Serial.println("  ");
  }
}



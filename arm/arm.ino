#include <Servo.h>

Servo rotate;
Servo main1;
Servo main2;
Servo main3;
Servo clamp;

int xPin = A1;
int yPin = A0;
int clic = A2;
int xPin1 = A4;
int yPin1 = A3;

int rotatePin = 7;
int main1Pin = 6;
int main2Pin = 5;
int main3Pin = 4;
int clampPin = 3;

int xPos;
int yPos;
int xPos1;
int yPos1;
int clicked;
int timer = 50;
int toggle = 0;

float servPos;
float servPos1;
float servPos2;
float servPos3;

void setup() 
{
  rotate.attach(rotatePin);
  main1.attach(main1Pin);
  main2.attach(main2Pin);
  main3.attach(main3Pin);
  clamp.attach(clampPin); 
  
  clamp.write(30);
  
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(xPin1, INPUT);
  pinMode(yPin1, INPUT);
  pinMode(clic, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  xPos = analogRead(xPin);
  yPos = analogRead(yPin);
  xPos1 = analogRead(xPin1);
  yPos1 = analogRead(yPin1);
  clicked = analogRead(clic);

  if(clicked == 1 && toggle == 0 && timer < 0)
  {
    timer = 25;
    clamp.write(30);
    toggle = 1;
  }
  if(clicked == 1 && toggle == 1 && timer < 0)
  {
    timer = 25;
    clamp.write(0);
    toggle = 0;
  }
  servPos = yPos / 10 ;
  rotate.write(servPos2);
  servPos1 = xPos / 10 ;
  main1.write(servPos);
  servPos2 = yPos1 / 10 ;
  main2.write(servPos1);
  servPos3 = xPos1 / 10 ;
  main3.write(servPos3);

  timer = timer - 1;
  
  delay(10);
}

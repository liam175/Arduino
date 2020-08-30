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

float servPos = 50;
float servPos1 = 50;
float servPos2 = 50;
float servPos3 = 50;

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
  pinMode(clic, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  xPos = analogRead(xPin);
  yPos = analogRead(yPin);
  xPos1 = analogRead(xPin1);
  yPos1 = analogRead(yPin1);
  clicked = analogRead(clic);
  xPos = map(xPos, 0, 1023, -1000, 1000);
  yPos = map(yPos, 0, 1023, -1000, 1000);
  xPos1 = map(xPos1, 0, 1023, -1000, 1000);
  yPos1 = map(yPos1, 0, 1023, -1000, 1000);
  
  Serial.println(clicked);
  
  if(clicked > 10 && toggle == 0 && timer <= 0)
  {
    timer = 25;
    clamp.write(30);
    toggle = 1;
  }
  if(clicked > 10 && toggle == 1 && timer <= 0)
  {
    timer = 25;
    clamp.write(0);
    toggle = 0;
  }
  if(xPos > 50 or xPos < -50)
  {
    servPos = servPos + xPos / 900;
  }
  if(yPos > 50 or yPos < -50)
  {
    servPos1 = servPos1 + yPos / 900;
  }
  if(xPos1 > 50 or xPos1 < -50)
  {
    servPos2 = servPos2 + xPos1 / 900;
  }
  if(yPos1 > 50 or yPos1 < -50)
  {
    servPos3 = servPos3 + yPos1 / 900;
  }

  
  rotate.write(servPos3);
  main1.write(servPos1);
  main2.write(servPos);
  main3.write(servPos2);

  timer = timer - 1;
  
  delay(1);
}

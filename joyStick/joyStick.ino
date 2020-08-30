#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
Servo sv1;
Servo sv2;

int trg=4;
int eco=3;

int xPin = A0;
int yPin = A1;
int clic = A2;

int sv1Pin = 7;
int sv2Pin = 6;

int iniPos = 90;

int clicked;
int xPos;
int yPos;
float servPos;
float servPos1;
float dist;
int duration;

void setup() 
{
  lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
  lcd.clear();
  lcd.print("test");

  pinMode(trg, OUTPUT);
  pinMode(eco, INPUT);
  
  sv1.attach(sv1Pin);
  sv1.write(iniPos);
  sv2.attach(sv2Pin);
  sv2.write(iniPos);
  
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  
  
  xPos = analogRead(xPin);
  yPos = analogRead(yPin);
  clicked = analogRead(clic);
  yPos = map(yPos, 0, 1023, 1023, 0);
   
  if (clicked <= 1)
  {
    lcd.clear();
    
    digitalWrite(trg, LOW);
    delayMicroseconds(2);
    digitalWrite(trg, HIGH);
    delayMicroseconds(10);
    digitalWrite(trg, LOW);
    
    duration = pulseIn(eco, HIGH);
    dist =  duration*0.034/2-1;
    Serial.println(dist);
    Serial.println();
    lcd.print(dist);
    
  }
  servPos = yPos / 10 ;
  sv1.write(servPos);
  servPos1 = xPos / 10 ;
  sv2.write(servPos1);
  delay(10);
}

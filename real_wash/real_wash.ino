#include <LiquidCrystal_I2C.h>
#include <LCD.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
int butt = 13;
#include <Servo.h>
Servo servo;
int pull = 7;
void setup() {
  lcd.begin(16, 2);
  pinMode(butt, INPUT);
  servo.attach(pull);
  servo.write(0);
}

void loop()
{
  lcd.clear();
  lcd.setCursor(1, 3);
  if (butt == HIGH) {
    lcd.print(" washing ");
    servo.write(90);
    delay(1000);
    servo.write(0);
  }




}

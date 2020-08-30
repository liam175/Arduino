
#include <LiquidCrystal_I2C.h>
#include <LCD.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
int butt = 13;
#include <Servo.h>
Servo servo;

int onButt =0;
void setup(){
  lcd.begin(16, 2);
  lcd.print("test");
  pinMode(butt, INPUT);
  delay(1000);
}

void loop()
{
  onButt==digitalRead(butt);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("press to start");
  delay(10000);
  if (onButt = HIGH){
      lcd.clear();
      lcd.print("pull handel in");
      delay(3000);
      lcd.clear();
      lcd.print("3");
      delay(750);
      lcd.clear();
      lcd.print("2");
      delay(750);
      lcd.clear();
      lcd.print("1");
      delay(2000);
      lcd.clear();
      lcd.print("stop");
      delay(1000);
      lcd.clear();
      lcd.print("remove clothing");
      delay(5000);
    }
    
  delay(10);
  
  
  
  
  
}

#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);



void setup() {
  Serial.begin(9600);
  lcd.begin(2, 20);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("This is");
  lcd.setCursor(0,1);
  lcd.print("Awesome Dude");

}

void loop() {
  delay(300);
  if (Serial.available())
  {
    char ch = Serial.read();
    if (ch == '#')
    {
      lcd.clear();
    }
    else if (ch == '/')
    {
      lcd.setCursor(0,1);
    }
    else
  {
      lcd.write(ch);
    }
  }
  
}


#include <LiquidCrystal.h>
//LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);
LiquidCrystal lcd(2, 3, 4, 9, 10, 11, 12);


void setup() {
  Serial.begin(9600);
  lcd.begin(2, 20);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("This is");
  lcd.setCursor(0,1);
  lcd.print("Awsome Dude");

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

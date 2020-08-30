#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
void setup() {
  lcd.begin(16,2);

}

void loop() {
  // put your main code here, to run repeatedly:
   lcd.print("W"); 
   delay(200);
   lcd.print("I");
   delay(200);
   lcd.print("N");
   delay(1000); 
   lcd.clear();  
   lcd.print("WIN");
   delay(400);
   lcd.clear();
   lcd.print("WIN");
   delay(400);
   lcd.clear();
   lcd.print("WIN");
   delay(400);
   lcd.clear();
   delay(100000);
}

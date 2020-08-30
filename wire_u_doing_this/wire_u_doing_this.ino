#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
int win=13;

int ma=1;
int hi=0;
int ti=2;



void setup() {

 lcd.begin(16, 2);
 lcd.clear();
 pinMode(ma, INPUT);
 pinMode(win, INPUT);
 lcd.setCursor(0,1);
 lcd.write("test");
 delay(1000);
  
}
void loop{
}
}



#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
int win=13;

int main=1;
int hit=0;
int timE=2;



void setup() {

 lcd.begin(16, 2);
 lcd.clear();
 pinMode(main, INPUT);
 pinMode(win, INPUT);
 lcd.setCursor(0,1);
 lcd.write("test");
 delay(1000);
  
}

void loop() {
  lcd.clear();
  if(main==HIGH);{
    hit++;
    delay(50);}
   if(win==HIGH);{
   
   lcd.print(10-hit+(10-timE+2));
   delay(2000);
   lcd.clear();}
 if (10-hit+(10-timE)>=20){
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
}else{
   lcd.print("lose");}


timE++;
delay(975);
  // put your main code here, to run repeatedly:

}

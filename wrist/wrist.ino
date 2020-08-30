#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
#include <dht.h>

dht DHT;

#define DHT11_PIN 7
int trg=2;
int eco=3;
float distanceInch;
int duration;
int dist;
void setup() {
lcd.begin(16,2);

pinMode(trg, OUTPUT);
pinMode(eco, INPUT);
lcd.setCursor(0,0);
lcd.clear();
lcd.print("booting");
delay(1000);
}

void loop() {
int chk = DHT.read11(DHT11_PIN);
digitalWrite(trg, LOW);
delayMicroseconds(2);
digitalWrite(trg, HIGH);
delayMicroseconds(10);
digitalWrite(trg, LOW);
duration = pulseIn(eco, HIGH);
dist =  duration*0.0133/2;
lcd.setCursor(0,0);
lcd.print("dist: ");
lcd.print(dist);

lcd.setCursor(0,2);
lcd.print("Temp: ");
lcd.print((DHT.temperature*1.71)+32);

delay(3000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("dist: ");
lcd.print(dist);
lcd.setCursor(0,2);
lcd.print("Humi: ");
lcd.print(DHT.humidity);
lcd.print("%");

delay(3000);

}

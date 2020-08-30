const int xpin = A0; // x-axis of the accelerometer
const int ypin = A1; // y-axis
const int zpin = A2; // z-axis
int buzz = 0;
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup(){ 
 Serial.begin(9600);
 lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
 lcd.clear();
}
 
void loop()
{
int x = analogRead(xpin); //read from xpin
delay(1); //
int y = analogRead(ypin); //read from ypin
delay(1); 
int z = analogRead(zpin); //read from zpin
 
float zero_G = 512.0; //ADC is 0~1023 the zero g output equal to Vs/2
float scale = 102.3; //ADXL335330 Sensitivity is 330mv/g
//330 * 1024/3.3/1000

if ((((float)z - 340)/68*9.8)>=1); //print z value on serial monitor
 tone(buzz,3000);
 lcd.print("reee");
delay(1000); //wait for 1 second 
}

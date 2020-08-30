#include <config.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Servo.h>




Servo servo1;
Servo servo2;

int servoPin1 = 7;


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
bool left;
bool right;

void setup() {
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.clearDisplay();
  servo1.attach(servoPin1);

  Serial.begin(115200);
    
}

void loop() 
{
  display.clearDisplay();
  display.drawCircle(32,32, 10, WHITE);
  display.drawCircle(96,32, 10, WHITE);
  display.drawLine(42,50,86,50, WHITE);
  display.display();
  delay(1000); 
  display.clearDisplay();
  display.drawLine(22,32,42,32, WHITE);
  display.drawLine(86,32,106,32, WHITE);
  display.drawLine(42,50,86,50, WHITE);
  display.display();
  delay(100);
  display.clearDisplay();
  display.drawCircle(32,32, 10, WHITE);
  display.drawCircle(96,32, 10, WHITE);
  display.drawLine(42,50,86,50, WHITE);
  display.display();
  delay(1000);
  servo1.write(45);
  delay(500);
  servo1.write(0);
  delay(1000);
}

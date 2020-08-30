#include <config.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Servo.h>
#include <ds3231.h>

struct ts t;

Servo servo1;
Servo servo2;

int servoPin1 = 7;
int servoPin2 = 6;

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
  
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  Serial.begin(115200);
    
}

void loop() 
{
  DS3231_get(&t);

  if(t.hour > 20 or t.hour < 10)
  {
    left = false;
    right = false;
  }
  else
  {
    left = true;
    right = true;
  }
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(100, 50);
  display.print(t.sec);
  display.setCursor(0, 20);
  display.print("   ");
  if(left == true)
  {
    servo1.write(0);
    display.print("open");
    display.drawLine(22, 37, 38, 37, WHITE);
  }
  else
  {
    servo1.write(90);
    display.print("close");
    display.drawLine(30, 30, 30, 45, WHITE);
  }
  display.print("       ");
  if(right == true)
  {
    servo2.write(0);
    display.print("open");
    display.drawLine(91, 37, 105, 37, WHITE);
  }
  else
  {
    servo2.write(90);
    display.print("close");
    display.drawLine(98, 30, 98, 45, WHITE); 
  }


  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  // Display static text
  display.print("   ");
  display.print(t.hour);
  display.print(":");
  if(t.min < 10)
  {
    display.print("0");
  }
  display.print(t.min);
  
  
  display.drawLine(0, 30, 128, 30, WHITE);
  display.drawLine(0, 45, 45, 45, WHITE);
  display.drawLine(82, 45, 128, 45, WHITE);
  display.drawLine(45, 45, 45, 64, WHITE);
  display.drawLine(82, 45, 82, 64, WHITE);
  
  
  display.display(); 
}

/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Button
*/
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
// constants won't change. They're used here to set pin numbers:
const int buttonPin = 13;     // the number of the pushbutton pin
     // the number of the LED pin
int led = 2;
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
float t = 0;
void setup() {
  // initialize the LED pin as an output:
  Serial.begin(9600);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  pinMode(led, OUTPUT);
  #include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x3f, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == LOW) {
    lcd.clear();
    digitalWrite(led, HIGH);
    Serial.print(t/100);
    lcd.print(t/100);
    delay(5000);
    Serial.println();
    lcd.clear();
    lcd.print("scramble");
    Serial.print("scramble");
    delay (10000);
    Serial.println();
    Serial.print("5 seconds");
    lcd.clear();
    lcd.print("5 sec");
    delay(5000);
    Serial.println();
    digitalWrite(led, LOW);
    lcd.clear();
    Serial.print("go");
    lcd.print("GO");
    Serial.println();
    t = 0;
  } else {
    // turn LED off:
    delay(10);
    t++; 
  }
}

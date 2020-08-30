// Reset is pulled up to 3.3V through a resistor; only output a low value
const byte LCD_PIN_RESET = 7;
const byte LCD_PIN_DC    = 6;
const byte LCD_PIN_SDIN  = 5;
const byte LCD_PIN_SCLK  = 4;
// LCD backlight tied LOW through a resistor; not necessary; just lights LEDs
// Chip enable is active-low; tied low through a resistor

#define LCD_C     LOW
#define LCD_D     HIGH

#define LCD_X     84
#define LCD_Y     48
//make things https://docs.google.com/document/d/1R7EZeiGqeLo9TDM9AeGjsq7c1zG8d1NocxtldIKXhOY/edit?usp=sharing
static const byte LCD_ASCII[][5] =
  {(0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
  
  };

void LCDInitialize(void)
{
  pinMode(LCD_PIN_DC, OUTPUT);
  pinMode(LCD_PIN_SDIN, OUTPUT);
  pinMode(LCD_PIN_SCLK, OUTPUT);

  digitalWrite(LCD_PIN_RESET, LOW);
  pinMode(LCD_PIN_RESET, OUTPUT);
  delay(10);
  pinMode(LCD_PIN_RESET, INPUT);

  LCDWrite(LCD_C, 0x21);  // LCD Extended Commands.
  LCDWrite(LCD_C, 0xB1);  // Set LCD Vop (Contrast). 
  LCDWrite(LCD_C, 0x04);  // Set Temp coefficent. //0x04
  LCDWrite(LCD_C, 0x14);  // LCD bias mode 1:48. //0x13
  LCDWrite(LCD_C, 0x20);  // LCD Basic Commands
  LCDWrite(LCD_C, 0x0C);  // LCD in normal mode.
  LCDClear();
}

void LCDCharacter(const char character)
{
  for (byte index = 0; index < 5; index++)
    LCDWrite(LCD_D, LCD_ASCII[character - ' '][index]);
  LCDWrite(LCD_D, 0x00);
}

void LCDClear(void)
{
  for (int index = 0; index < LCD_X * LCD_Y / 8; index++)
    LCDWrite(LCD_D, 0x00);
}

// Display an ASCII string
//
// 0 <= x <= 83, 0 <= y <= 5
void LCDString(byte x, byte y, const char *characters)
{
  LCDWrite(LCD_C, 0x80 | x);
  LCDWrite(LCD_C, 0x40 | y);
  while (*characters) LCDCharacter(*characters++);
}

void LCDWrite(byte dc, byte data)
{
  digitalWrite(LCD_PIN_DC, dc);
  shiftOut(LCD_PIN_SDIN, LCD_PIN_SCLK, MSBFIRST, data);
}

void setup() {
  LCDInitialize();
  LCDString(0,0,"$ $ $ $ $ $ $     smile     $ $ $ $ $ $ $ % of smile 100$ $ $ $ $ $ $");
  delay(1000);
}

void loop() {
}

}


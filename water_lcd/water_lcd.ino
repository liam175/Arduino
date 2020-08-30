

#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
#include <dht.h>

dht DHT;

#define DHT11_PIN 7

int motor = 3;
int LDR = A2;       // select the input pin for the LDR
int resval = 0;  // holds the value
int respin = A0; // sensor pin used
int oneday= 0;
void(* resetFunc) (void) = 0;//declare reset function at address 0
byte la[] = {
  B00000,
  B00000,
  B01110,
  B01110,
  B00100,
  B01010,
  B01010,
  B01010};

  byte sun[] = {
  B00111,
  B00111,
  B00011,
  B01000,
  B11100,
  B01000,
  B11100,
  B11100
};

byte temp[] = {
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B01110,
  B01110,
  B01110
};

byte no[] = {
  B00000,
  B00000,
  B10001,
  B01010,
  B00100,
  B01010,
  B10001,
  B00000
};

byte yes[] = {
  B00000,
  B00000,
  B10000,
  B01000,
  B00101,
  B00010,
  B00000,
  B00000
};

void setup() {
Serial.begin(9600);  
lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
lcd.clear();
pinMode(LDR, INPUT);
lcd.createChar(1, la);
lcd.createChar(2, sun);
lcd.createChar(3, temp);
lcd.createChar(4, no);
lcd.createChar(5, yes);
pinMode(motor, OUTPUT);
digitalWrite(motor, HIGH);
delay(1000);
digitalWrite(motor,LOW);
oneday=0;
}
void loop() {

  

  lcd.setCursor(0,0);
  lcd.print("moisture level");
  lcd.setCursor(7,1);
  lcd.write(1);
  lcd.setCursor(0,1);
  resval = analogRead(respin); //Read data from analog pin and store it to resval variable
  Serial.println(analogRead(A0));
  if (resval<=450){ lcd.print("Empty");oneday++;
    } else if (resval>450 && resval<=500){ lcd.print("Low");oneday++;
    } else if (resval>500 && resval<=550){ lcd.print("Medium"); 
    } else if (resval>550){ lcd.print("High"); 
  }
  delay(3000); 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("light level");
  lcd.setCursor(7,1);
  lcd.write(2);
  lcd.setCursor(0,1);
   
   if (LDR<=450){ lcd.print("day time"); 
    } else if (LDR>450 && LDR<=750){ lcd.print("daytime"); 
    } else if (LDR>750 && LDR<=900){ lcd.print("daytime"); 
    } else if (LDR>900){ lcd.print("daytime"); 
    Serial.print(LDR);
  
  }
  delay(3000);
  lcd.clear();
  int chk = DHT.read11(DHT11_PIN);
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  if (DHT.temperature<=4.44444){ lcd.print("bad");}
    else lcd.print((DHT.temperature*1.71)+32);
  lcd.print((char)223);
  lcd.print("F");
  lcd.print(" ");
  lcd.write(3);
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print("%");
  delay(3000);
  lcd.clear();
  
  if (oneday>25200 and oneday<25200  ){lcd.print("watering");lcd.print(" ");lcd.write(5); {digitalWrite(motor, HIGH);delay(5000);
  digitalWrite(motor, LOW);oneday=0;}}
    else(lcd.print("im fine"));lcd.print(" ");lcd.print(oneday);lcd.write(4);
  delay(3000);
  lcd.clear();
  
  
 }

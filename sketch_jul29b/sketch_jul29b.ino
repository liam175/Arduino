#include <LiquidCrystal.h>
//LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);
LiquidCrystal lcd(2, 3, 4, 9, 10, 11, 12);

int resval = 0;  // holds the value
int respin = A5; // sensor pin used

void setup() {
  Serial.begin(9600);
  lcd.begin(2, 20);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("This is");
  lcd.setCursor(0,1);
  lcd.print("Awsome Dude");

}

void loop() {
  resval = analogRead(respin); //Read data from analog pin and store it to resval variable
   
  if (resval<=49){ lcd.write("Water Level: Empty"); 
    } else if (resval>50 && resval<=200){ lcd.write("Water Level: Low"); 
    } else if (resval>201 && resval<=330){ Serial.println("Water Level: Medium"); 
    } else if (resval>330){ Serial.println("Water Level: High"); 
  }
  delay(1000); 
}

  delay(300);
  if (Serial.available())
  {
    char ch = Serial.read();
    if (ch == '#')
    {
      lcd.clear();
    }
    else if (ch == '/')
    {
      lcd.setCursor(0,1);
    }
    else
  {
      lcd.write(ch);
    }
  }
  
}

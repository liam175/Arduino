int resval = 0;  // holds the value
int respin = A5; // sensor pin used
  
void setup() { 
 
  // start the serial console
  Serial.begin(9600);
} 
  
void loop() { 
   
  resval = analogRead(respin); //Read data from analog pin and store it to resval variable
   
  if (resval<=49){ Serial.println("Water Level: Empty"); 
    } else if (resval>50 && resval<=200){ Serial.println("Water Level: Low"); 
    } else if (resval>201 && resval<=330){ Serial.println("Water Level: Medium"); 
    } else if (resval>330){ Serial.println("Water Level: High"); 
  }
  delay(1000); 
}


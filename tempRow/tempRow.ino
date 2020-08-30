#include <dht.h>
dht DHT;
#define DHT11_PIN 7
int pin1 = 4;
int pin2 = 5;
int pin3 = 6;
int pin4 = 8;
int pin5 = 9;
int pin6 = 10;
int pin7 = 11;

void setup() {
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);
  pinMode(pin7, OUTPUT);
  Serial.begin(9600);
  
}



void loop() {
  
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
  digitalWrite(pin5, LOW);
  digitalWrite(pin6, LOW);
  digitalWrite(pin7, LOW);
  
 int chk = DHT.read11(DHT11_PIN);
Serial.println(DHT.temperature);
if (DHT.temperature< 0){ digitalWrite(pin7, HIGH); 
    } else if (DHT.temperature>=0 and DHT.temperature<10){ digitalWrite(pin7,LOW);digitalWrite(pin6,HIGH); 
    
    } else if (DHT.temperature>=10 and DHT.temperature<21){ digitalWrite(pin6,LOW);digitalWrite(pin5,HIGH);
   
    } else if (DHT.temperature>=21 and DHT.temperature<28){ digitalWrite(pin5,LOW);digitalWrite(pin4,HIGH);

    } else if (DHT.temperature>=28 and DHT.temperature<34){ digitalWrite(pin4,LOW);digitalWrite(pin3,HIGH);
 
    } else if (DHT.temperature>=34 and DHT.temperature<38){ digitalWrite(pin3,LOW);digitalWrite(pin2,HIGH);

    } else if (DHT.temperature>=38 and DHT.temperature<100){ digitalWrite(pin2,LOW);digitalWrite(pin1,HIGH); 
    
    }   
delay(1000);
}

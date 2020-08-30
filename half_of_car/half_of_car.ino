#include <IRremote.h>
int pin3 = 3;
const int RECV_PIN = 7;
decode_results results;
IRrecv irrecv(RECV_PIN);

int motor;

void setup() {
 Serial.begin(9600);
 irrecv.enableIRIn(); 
 pinMode(pin3, OUTPUT);
// digitalWrite(pin3, HIGH);
// delay(2000);
 digitalWrite(pin3, LOW);
 motor = LOW;
}

void loop() {
   if (irrecv.decode(&results)){
     if (results.value == 0xFFFFFFFF) {
     } else
        motor = LOW;
        switch(results.value){
          case 0xFD20DF:
          Serial.println("ul");
          motor = HIGH;  
          break;
          case 0xFD609F:
          Serial.println("uR");
          break;
          case 0xFD10EF:
          Serial.println("dL");
          break;
          case 0xFD50AF:
          Serial.println("dR");
          break;
        }
        irrecv.resume();
   } else {
     motor = LOW;
   }
   digitalWrite(pin3, motor);
   delay(200);
}

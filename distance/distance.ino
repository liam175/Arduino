int r=9;
int y=8;
int g=7;
int trg=2;
int eco=3;
int d5= 5;
float dist;
int duration;
int dist;
void setup() {
pinMode(d5, OUTPUT);  
digitalWrite(d5,HIGH);
Serial.begin(9600);
pinMode(trg, OUTPUT);
pinMode(eco, INPUT);
pinMode(r, OUTPUT);
pinMode(y, OUTPUT);
pinMode(g, OUTPUT);
digitalWrite(r, LOW);
digitalWrite(y, LOW);
digitalWrite(g, LOW);

digitalWrite(r, HIGH);
delay(200);
digitalWrite(r, LOW);
digitalWrite(y, HIGH);
delay(200);
digitalWrite(y, LOW);
digitalWrite(g, HIGH);
delay(200);
digitalWrite(g, LOW);






}

void loop() {
Serial.print(dist);
digitalWrite(trg, LOW);
delayMicroseconds(2);
digitalWrite(trg, HIGH);
delayMicroseconds(10);
digitalWrite(trg, LOW);
duration = pulseIn(eco, HIGH);
dist =  duration*0.0133/2;
digitalWrite(r, LOW);
digitalWrite(y, LOW);
digitalWrite(g, LOW);
if (dist<13){ digitalWrite(r, HIGH);
    } else if (dist>13 && dist<121){ digitalWrite(y, HIGH);
    } else if (dist>121){ digitalWrite(g, HIGH);

   }
   delay(1000);
}

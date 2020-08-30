int Blue = 8;
int Green = 9;
int Red = 10;
void setup() {
 pinMode(Blue, OUTPUT);
 pinMode(Green, OUTPUT);
 pinMode(Red, OUTPUT);
 digitalWrite(Blue, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

delay(4000);
digitalWrite(Green, HIGH);
delay(4000);
digitalWrite(Blue, LOW);
delay(4000);
digitalWrite(Red, HIGH);
delay(4000);
digitalWrite(Green, LOW);
delay(4000);
digitalWrite(Blue, HIGH);
delay(4000);
digitalWrite(Green, HIGH);
delay(4000);
digitalWrite(Green, LOW);
digitalWrite(Red, LOW);

}

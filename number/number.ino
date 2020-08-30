
int s1 =(3);
int s2 = (2);
int s3 = (5);
int s4 = (10);
int s5 = (11);
int s6 = (12);

void setup() {
  // put your setup code here, to run once:
pinMode(s1, OUTPUT);
pinMode(s2, OUTPUT);
pinMode(s3, OUTPUT);
pinMode(s4, OUTPUT);
pinMode(s5, OUTPUT);
pinMode(s6, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(s1, HIGH);
delay(50);
digitalWrite(s6, LOW);
delay(75);
digitalWrite(s2, HIGH);
delay(50);
digitalWrite(s1, LOW);
delay(75);
digitalWrite(s3, HIGH);
delay(50);
digitalWrite(s2, LOW);
delay(75);
digitalWrite(s4, HIGH);
delay(50);
digitalWrite(s3, LOW);
delay(75);
digitalWrite(s5, HIGH);
delay(150);
digitalWrite(s4, LOW);
delay(75);
digitalWrite(s6, HIGH);
delay(50);
digitalWrite(s5, LOW);
delay(75);

}

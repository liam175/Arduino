int l=3;
void setup() {
 pinMode(l, OUTPUT);
 digitalWrite(l,HIGH);
}

void loop() {
  digitalWrite(l,HIGH);
  delay(1000);
  digitalWrite(l,LOW);
  delay(5000);
  
  
}

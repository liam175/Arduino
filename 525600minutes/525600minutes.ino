int five = 5;
int two = 7;
int six = 6;

void setup() {
  pinMode(six, OUTPUT);
  pinMode(five, OUTPUT);
  pinMode(two, OUTPUT);

}

void loop() {
  digitalWrite(five, HIGH);
  delay(900);
  digitalWrite(two, HIGH);
  delay(1500);
  digitalWrite(six, HIGH);
  delay(3000);
  digitalWrite(five, LOW);
  digitalWrite(six, LOW);
  digitalWrite(two, LOW);
  delay(5000);
}

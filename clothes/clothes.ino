
int motor=13;

void setup() {
  pinMode(motor, OUTPUT);
 
  digitalWrite(motor, HIGH);
  delay(random(750,1251));
  digitalWrite(motor, LOW);

}  void loop(){
  }

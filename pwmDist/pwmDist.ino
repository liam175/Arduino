int led = 3;
int delay1 = 250;
const int trigPin = 5;
const int echoPin = 4;
int duration;
int cyclePulse = 50;
int cycPul;
int i;
int numReadings = 10;
int value;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(led, HIGH);
  delayMicroseconds(delay1); // Approximately 10% duty cycle @ 1KHz
  digitalWrite(led, LOW);
  delayMicroseconds(1000 - delay1);
  if(cycPul == 0){
    pulse();
  }else{
    cycPul = cycPul - 1;
  }
}

void pulse(){
  for (i = 0; i < numReadings; i++){
    
    cycPul = cyclePulse;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    Serial.println(delay1);
    duration = map(duration,-10000,10000,2000,0);
    value = value + duration;
    delay(10);
    
  }
  
  value = value / numReadings;
  delay1 = duration;
  
}

const int buttonPin = 13;     // the number of the pushbutton pin
     // the number of the LED pin
int led = 2;
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
float t = 0;
void setup() {
  // initialize the LED pin as an output:
  Serial.begin(9600);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
Serial.print(t/10);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == LOW) {
    digitalWrite(led, HIGH);
    
    delay(5000);
    Serial.println();
    Serial.print("scramble");
    delay (10000);
    Serial.println();
    Serial.print("5 seconds");
    delay(5000);
    Serial.println();
    digitalWrite(led, LOW);
    Serial.print("go");
    Serial.println();
    t = 0;
  } else {
    // turn LED off:
    delay(10);
    t++;  
    
  }
}

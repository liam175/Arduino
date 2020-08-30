int pins[8]={1, 2, 3, 4, 5, 6, 7, 8};
int numbers[10][8] = {
  {1,1,1,0,1,1,1,0},
  {0,0,1,0,1,0,0,0},
  {1,1,1,0,1,1,0,0},
  {0,1,1,0,1,1,0,1},
  {0,0,1,0,1,0,1,1},
  {0,1,1,0,0,1,1,1},
  {1,1,1,0,0,1,1,1},
  {0,0,1,0,1,1,0,0},
  {1,1,1,0,1,1,1,1},
  {0,0,1,0,1,1,1,1}
};
void setup() {
  // put your setup code here, to run once:
for (int i = 0; i<8; i++){
  pinMode(pins[i],OUTPUT);
  digitalWrite(pins[i],HIGH);
  delay(1000);
  digitalWrite(pins[i],LOW);
}


}

void loop() {
  // put your main code here, to run repeatedly:

}

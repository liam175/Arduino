/*
  Read Analog Voltage
  
  Reads an analog input voltage on pin A5 & common ground, converts it to voltage, 
  and prints the result to the Serial Monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground. 
  Includes a Loop Command for future use
  // Indicates Notes & Compiler Does Not Include
  ;  Semi Colon After Each Command
  
  Chad J. Stoltzmann 04-08-2015
*/

  // The setup routine Runs once when you press Reset:
  
  int Counter =0; //Simple Counter Loop (See Below to Close Loop)
  void setup() {  //Needed in all Code!
    
  // Initialize serial communication at 9600 bits per second
  
  Serial.begin(9600); //BAUD Rate
  Serial.println("*****Upload to Micro-Controller Complete*****"); //Text
  Serial.println("*****Reading Device Analog Voltage Input*****"); //Text
}

  // The loop routine runs over and over again forever:
    
  void loop() {  //Needed in all Code
  int sensorValue = analogRead(A5);  // Read Input V on Analog Pin (A5) and Ground on UNO R.3
  
  // Convert the Analog Reading (which goes from 0.00 - 1023) to a voltage (0.01 - 1V):
  
  float Voltage_mV = sensorValue * (5.0 / 1023); // Voltage Adjustments
   
  Serial.println(Counter = Counter + 1);  //Simple Counter Loop Adjust (1) with Integers
  Serial.println(Voltage_mV);     //Input Voltage Value
  Serial.println("Volts(mV)");    //Text
  Serial.println("_________");    //Text
  delay(1500);                    //Delay(ms)
 }

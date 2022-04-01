/*
Codigo de ejemplo dispositivo de alertamiento para iplanta de distribucion de gas,

Se realiza la lectura de sensor de GAS, sensor de Flama
Se envia lectura de sensor de temperatura 

*/
int sensorFlama = A1;
int sensorGas = A2;
int sensorTemp = A0;
int tempValue = 0;
int gasFlag = 0;
int flamaFlag = 0;




// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(sensorFlama, INPUT);
  pinMode(sensorGas, INPUT);

  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(500);                       // wait for a second
  gasFlag = digitalRead(sensorGas);
  flamaFlag = digitalRead(sensorFlama);
  tempValue = analogRead(sensorTemp);
  float millivolts = (tempValue / 1023.0) * 5000;
  float celsius = millivolts / 10; 
  Serial.print(celsius);
  Serial.print(" ,");
  Serial.print(gasFlag);
  Serial.print(",");
  Serial.print(flamaFlag);
  Serial.println(",");
  
 
  
  
}

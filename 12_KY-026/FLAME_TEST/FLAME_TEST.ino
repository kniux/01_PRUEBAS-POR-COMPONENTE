/*
  Autor: Edgar Cano
  Rev: 09/04/2024   
*/

#define redLED 22
#define greenLED 23
#define flameSensorA A0
#define flameSensorD 2

int flameDigital = 0;
float flameAnalog = 0; 

void setup(){
  pinMode(redLED, OUTPUT);	
  pinMode(greenLED, OUTPUT);  
  pinMode(flameSensorA, INPUT);  
  pinMode(flameSensorD, INPUT); 
  Serial.begin(9600);   
}

void loop(){
 
 flameAnalog = analogRead(flameSensorA);
 flameDigital = digitalRead(flameSensorD);
 
 Serial.print("Valor Analogico: ");
 Serial.print(flameAnalog);
 Serial.print("   Valor Digital: ");
 Serial.println(flameDigital);
 
 delay(100);
}

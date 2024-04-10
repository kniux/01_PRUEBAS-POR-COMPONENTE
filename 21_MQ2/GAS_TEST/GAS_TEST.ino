/*
  Autor: Edgar Cano
  Rev: 10/04/2024   
*/

#define redLED 9
#define greenLED 7
#define gasSensor A0
int gasStatus=0;

void setup(){
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(gasSensor, INPUT); 
  Serial.begin(9600);   
}

void loop(){
  gasStatus=digitalRead(gasSensor);
  if (gasStatus==0) {
    digitalWrite(redLED,LOW);
    digitalWrite(greenLED,HIGH);   
  } else {
    digitalWrite(redLED,HIGH);
    digitalWrite(greenLED,LOW);   
  }
}

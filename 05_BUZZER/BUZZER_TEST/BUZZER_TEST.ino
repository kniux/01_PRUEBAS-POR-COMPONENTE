/*
  Autor: Edgar Cano
  Rev: 09/04/2024   
*/
const int buzzerPin =  2;      

void setup() {  
  pinMode(buzzerPin, OUTPUT);  
}

void loop() {
    digitalWrite(buzzerPin , HIGH);
    delay(200);   
    digitalWrite(buzzerPin , LOW);  
    delay(2000);   
}

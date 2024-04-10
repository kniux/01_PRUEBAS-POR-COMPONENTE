/*
  Autor: Edgar Cano
  Rev: 09/04/2024   
*/
const int CH1 = 2;
const int CH2 = 3;
const int CH3 = 5;
const int CH4 = 6;

void setup(){  
  pinMode(CH1, OUTPUT);
  pinMode(CH2, OUTPUT);
  pinMode(CH3, OUTPUT);
  pinMode(CH4, OUTPUT);
  digitalWrite(CH1, HIGH);
  digitalWrite(CH2, HIGH);
  digitalWrite(CH3, HIGH);
  digitalWrite(CH4, HIGH);  
}

void loop() {
             
      digitalWrite(CH1, LOW);
      delay(1000);              
      digitalWrite(CH1, HIGH);
      delay(1000); 

      digitalWrite(CH2, LOW);
      delay(1000);              
      digitalWrite(CH2, HIGH);
      delay(1000);              
    
      digitalWrite(CH3, LOW);
      delay(1000);           
      digitalWrite(CH3, HIGH);
      delay(1000);                          

      digitalWrite(CH4, LOW);
      delay(1000);           
      digitalWrite(CH4, HIGH);
      delay(1000);                          

}

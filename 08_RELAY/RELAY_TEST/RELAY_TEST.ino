/*
  Autor: Edgar Cano
  Rev: 09/04/2024   
*/

const int CH1 = 12;

void setup(){  
  pinMode(CH1, OUTPUT);     // Declarar el relé como salida.
  digitalWrite(CH1, HIGH);  // Suponiendo que el relé está apagado.
  Serial.begin(9600);
}

void loop() {
             
      Serial.println("Prendiendo el Rele");
      digitalWrite(CH1, LOW);
      delay(1000);              
      Serial.println("Apagando el Rele");
      digitalWrite(CH1, HIGH);
      delay(1000); 
}

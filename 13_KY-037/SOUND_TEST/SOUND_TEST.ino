
/*
  Autor: Edgar Cano
  Rev: 10/04/2024   
*/

int MIC = 2;       
int LED = 23;       

int SoundDigital = 0;          
float SoundAnalog = 0; 

void setup(){
  pinMode(MIC, INPUT);      
  pinMode(LED, OUTPUT);     
  Serial.begin(9600);   
}

void loop(){
  SoundDigital = digitalRead(MIC);
  SoundAnalog = analogRead(A0);
  
  if (SoundDigital == HIGH){          
    digitalWrite(LED, LOW);   
  }
  if (SoundDigital == LOW){         
    digitalWrite(LED, HIGH);  
  } 
 
  Serial.print("Valor Analogico: ");
  Serial.print(SoundAnalog);
  Serial.print("   Valor Digital: ");
  Serial.println(SoundDigital);
 delay(500);                   // demora de medio seg. para evitar pulsos espureos

}

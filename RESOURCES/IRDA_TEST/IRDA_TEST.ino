/*
  Autor: Edgar Cano
  Rev: 10/04/2024   
*/
const int LED = 21;
const int sensor = 5;
int valor;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(sensor, INPUT);
  Serial.begin(9600); 
}

void loop() {
  valor = digitalRead(sensor);
  
  if (valor == 0){
    digitalWrite(LED, HIGH);  
  }else{
      digitalWrite(LED, LOW);  
    }    
  Serial.println(valor);
  delay(500);  
}

/*
  Autor: Edgar Cano
  Rev: 10/04/2024   
*/
#define echoPin 26
#define trigPin 25
#define LED     10

void setup() {
  Serial.begin (9600);
  pinMode(LED, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  float duracion, distancia;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duracion = pulseIn(echoPin, HIGH);
  distancia = (duracion / 2) * 0.0344;
  
  if (distancia >= 400 || distancia <= 2){
    Serial.print("Distancia = ");
    Serial.println("Fuera del rango");
  }
  else {
    Serial.print("Distancia = ");
    Serial.print(distancia);
    Serial.println(" cm");
    delay(500);

    if (distancia <= 20 && distancia >= 0){  // si distancia entre 0 y 20 cms.
       digitalWrite(LED, HIGH);      // enciende LED
       delay(distancia * 10);        // demora proporcional a la distancia
       digitalWrite(LED, LOW);     // apaga LED
    }
    
  }
  delay(500);
}

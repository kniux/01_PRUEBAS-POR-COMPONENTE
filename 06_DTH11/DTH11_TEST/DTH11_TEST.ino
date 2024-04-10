/*
  Autor: Edgar Cano
  Rev: 09/04/2024   
*/
#include <DHT.h>

#define DHTPin  7
#define DHTType DHT11

DHT dht11(DHTPin, DHTType);

unsigned long previousMillis = 0;
long interval = 2000;     // leer cada 2 seg.

void setup() {
  Serial.begin(9600);
  dht11.begin();
}

void loop() {
 unsigned long currentMillis = millis();
 int tempC;
 int hum;
 
  if ( (currentMillis - previousMillis) >= interval ){
    previousMillis = currentMillis;

    tempC = dht11.readTemperature();
    hum = dht11.readHumidity();
    
    Serial.print(" Temperatura: "); 
    Serial.print(tempC);
    Serial.print("°C /");  
    Serial.print(" Humedad: "); 
    Serial.print(hum);
    Serial.println("%");  
    Serial.print("Millisegundos "); 
    Serial.println(previousMillis); 
  }
}

/*
  Autor: Edgar Cano
  Rev: 08/04/2024 
*/

#include "Adafruit_VL53L0X.h"
Adafruit_VL53L0X lox = Adafruit_VL53L0X();

void setup() {
  Serial.begin(9600);
  
  while (! Serial) {
    delay(1);
  }
  
  Serial.println("VL53L0X Test");
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }
  // power 
  Serial.println(F("VL53L0X API Simple Ranging example")); 
}

void loop() {
  VL53L0X_RangingMeasurementData_t measure;
    
  Serial.print("Reading a measurement... ");
  lox.rangingTest(&measure, false); // ¡Pasar 'true' para obtener impresiones de datos de depuración!

  if (measure.RangeStatus != 4) { 
    Serial.print("Distance (mm): "); Serial.println(measure.RangeMilliMeter);
  } else {
    Serial.println(" out of range ");
  }    
  delay(100);
}

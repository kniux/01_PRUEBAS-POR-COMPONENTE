/*
  Autor: Edgar Cano
  Rev: 10/04/2024   
*/

#include <Wire.h>
#include <Adafruit_BMP280.h>

#define BMP_SDA 7   // Cambia estos valores según la configuración de tu placa
#define BMP_SCL 6

Adafruit_BMP280 bmp; // Instancia del sensor BMP280

void setup() {
  Serial.begin(9600);
  if (!bmp.begin()) {
    Serial.println("No se pudo encontrar el sensor BMP280, verifica la conexión!");
    while (1);
  }
  Serial.println("Sensor BMP280 encontrado!");
}

void loop() {
  Serial.print("Temperatura = ");
  Serial.print(bmp.readTemperature());
  Serial.println(" *C");

  Serial.print("Presion = ");
  Serial.print(bmp.readPressure() / 100.0);
  Serial.println(" hPa");

  Serial.println();

  delay(1000);         // Espera 1 segundo entre lecturas
}


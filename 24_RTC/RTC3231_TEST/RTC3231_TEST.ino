/*
 * Name: RTCDS3231
  Autor: Edgar Cano
  Rev: 10/04/2024 
*/

#include "RTClib.h"
#include <Wire.h>

RTC_DS3231 rtc;

void setup() {
  Wire.begin();                             
  rtc.begin();
  /* obteniendo parametros de la PC */
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));  
  Serial.begin(9600);                
  delay(500);    
}

void loop() {
  displayFecha();
  displayHora();
  displayTemperatura();
  delay(1000);
}
void displayFecha(){
  DateTime now = rtc.now();
  char _bufferFecha[12];

  formatoFecha( _bufferFecha, now.day(), now.month(), now.year() );

    Serial.print("Date: ");
    Serial.println(_bufferFecha);    
}
void displayHora(){
  DateTime now = rtc.now();
  char _bufferHora[10];

  formatoHora( _bufferHora, now.hour(), now.minute(), now.second() );
    Serial.print("Hora: ");
    Serial.println(_bufferHora);    
  
}
void formatoFecha(char bufferFecha[12], int numDia, int numMes, int numA){
  sprintf(bufferFecha, "%02d/%02d/%04d", numDia, numMes, numA);
}
void formatoHora(char bufferHora[10], int hora, int minu, int seg){
  sprintf(bufferHora, "%02d:%02d:%02d", hora, minu, seg);
}
void displayTemperatura(){
   char symbol = 223;   
    Serial.print("Temperature: ");
    Serial.print(rtc.getTemperature());
    Serial.println(" C");
}

/* Prueba de tiras LED inteligentes WS2812B / WS2812
Debe instalar la libreria "Adafruit_NeoPixel.h" para que funcione el programa
Conexiones:
ARDUINO   TIRA LED
  5V        +5V ROJO
  GND       GND BLANCO
  3         Din Verde

  Autor: Edgar Cano
  Rev: 08/04/2024 
*/

#include <Adafruit_NeoPixel.h>    // importa libreria, debe indtalarla previamente

int nleds=1;  // Numero de LEDs a Probar
int pinled=12;  // Numero de LEDs a Probar
int retardo = 150; // más alto mas lenta la secuencia
int brillo = 50; // Brillo del LED

Adafruit_NeoPixel tira = Adafruit_NeoPixel(nleds, pinled, NEO_GRB + NEO_KHZ800);  // Pin 3 del Arduino es salida de datos

void setup(){
  tira.begin();       // inicializacion de la tira
  tira.show();        
}

void loop(){
tira.setBrightness(brillo); // Brillo de los LEDs

for (int i=0;i<nleds;i++){ 
 tira.setPixelColor(i,255,255,255); // Blanco
 tira.show();
 delay(retardo);
 tira.setPixelColor(i,0,0,0); 
 }
for (int i=0;i<nleds;i++){ 
 tira.setPixelColor(i,255,0,0); // ROJO
 tira.show();
 delay(retardo);
 tira.setPixelColor(i,0,0,0); 
 }
for (int i=0;i<nleds;i++){ 
 tira.setPixelColor(i,0,255,0); // VERD
 tira.show();
 delay(retardo);
 tira.setPixelColor(i,0,0,0); 
 }
for (int i=0;i<nleds;i++){ 
 tira.setPixelColor(i,0,0,255); // AZUL
 tira.show();
 delay(retardo);
 tira.setPixelColor(i,0,0,0); 
 }
}

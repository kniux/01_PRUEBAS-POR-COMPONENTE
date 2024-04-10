/* Controlar el RGB en el MKR WiFi 1010 es ligeramente diferente a cualquier experiencia 
 * previa que puedas haber tenido con un componente similar. 
 * En primer lugar, no podemos acceder a él directamente, necesitamos utilizar 
 * las funcionalidades de la biblioteca WiFiNINA. 
 * Más específicamente, necesitamos acceder a un archivo llamado wifi_drv.h 
 * para poder trabajar con él. 
 * A continuación, se muestra un fragmento de código que explica 
 * cómo incluir este archivo en tu boceto:
 */

#include <WiFiNINA.h>
#include <utility/wifi_drv.h>

/* Después de haberlo incluido, es bastante sencillo.
 * El componente RGB utiliza los pines 25 (verde), 26 (rojo) y 27 (azul), 
 * por lo que necesitamos definir esos pines utilizando los siguientes comandos: 
 */
 
void setup() {
  WiFiDrv::pinMode(25, OUTPUT); //define green pin
  WiFiDrv::pinMode(26, OUTPUT); //define red pin
  WiFiDrv::pinMode(27, OUTPUT); //define blue pin 
}
// Y para controlarlos dentro del loop(), simplemente usamos:
void loop() {
  WiFiDrv::analogWrite(25, 255);
  WiFiDrv::analogWrite(26, 0);
  WiFiDrv::analogWrite(27, 0);

  delay(1000);
/* O, si queremos usar digitalWrite() (para simplemente encender con brillo total), podemos escribirlo así:
  WiFiDrv::digitalWrite(25, HIGH); //GREEN
  WiFiDrv::digitalWrite(26, LOW);   //RED
  WiFiDrv::digitalWrite(27, LOW);   //BLUE
  */
  WiFiDrv::analogWrite(25, 0);
  WiFiDrv::analogWrite(26, 255);
  WiFiDrv::analogWrite(27, 0);

  delay(1000);

  WiFiDrv::analogWrite(25, 0);
  WiFiDrv::analogWrite(26, 0);
  WiFiDrv::analogWrite(27, 255);

  delay(1000);

  WiFiDrv::analogWrite(25, 0);
  WiFiDrv::analogWrite(26, 0);
  WiFiDrv::analogWrite(27, 0);

  delay(1000);
}

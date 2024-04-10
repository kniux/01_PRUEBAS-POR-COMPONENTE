/*
  Autor: Edgar Cano
  Rev: 10/04/2024   
*/
int inputPin = 14;               // PIR sensor
int pirState = LOW;             // al empezar se asume que NO hay movimiento detectado
int val = 0;                    // variable para lectura del estado del pin
 
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);      
  pinMode(inputPin, INPUT);     
  Serial.begin(9600);
}
 
void loop(){
  val = digitalRead(inputPin);  // lectura del PIR
  if (val == HIGH) {            // si esta en alto
    digitalWrite(LED_BUILTIN, HIGH);  // LED ON
    if (pirState == LOW) {
      // acabamos de encender
      Serial.println("Motion detected!");
      // imprimir en el cambio de la salida, no del estado.
      pirState = HIGH;
    }
  } else {
    digitalWrite(LED_BUILTIN, LOW); // LED OFF
    if (pirState == HIGH){
      // acabamos de apagar
      Serial.println("Motion ended!");
      // imprimir en el cambio de la salida, no en el estado
      pirState = LOW;
    }
  }
}

/*
  Autor: Edgar Cano
  Rev: 10/04/2024   
*/

int LED = 10;      // LED en pin 3
int VALOR= 0;         // almacena valor leido de entrada A0
int PWM = 0;

void setup(){
  pinMode(LED, OUTPUT);   // pin 3 como salida
  Serial.begin(9600);
  // entradas analogicas no requieren inicialización
}


void loop(){
  VALOR = analogRead(A0);   
  PWM = map(VALOR, 0, 1023, 255, 0);  // convierte valores de entrada 0-1023 a 255-0 para brillo
  analogWrite(LED, PWM);              // escribe valor al LED
  Serial.print("VALOR: ");
  Serial.print(VALOR);
  Serial.print("  PWM: ");
  Serial.println(PWM);
}

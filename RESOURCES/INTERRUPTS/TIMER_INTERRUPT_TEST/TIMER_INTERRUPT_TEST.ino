/*
  Autor: Edgar Cano
  Rev: 10/04/2024   
*/
#define ledPin 10

ISR(TIMER1_COMPA_vect){                         // interrupción por igualdade de comparación en TIMER1
  digitalWrite(ledPin, digitalRead(ledPin) ^ 1); //invierte estado del LED
}
void setup(){
  pinMode(ledPin, OUTPUT);
  
  // Configurando TIMER1
  TCCR1A = 0;               // El registro de control A queda todo en 0
  TCCR1B = 0;               // limpia registrador
  TCNT1  = 0;               // Inicializa el temporizador
  OCR1A = 0x3D08;           // carga el registrador de comparación: 16MHz/1024/1Hz -1 = 15624 = 0X3D08
  TCCR1B |= (1 << WGM12)|(1<<CS10)|(1 << CS12);   // modo CTC, prescaler de 1024: CS12 = 1 e CS10 = 1  
  TIMSK1 |= (1 << OCIE1A);  // habilita interrupción por igualdade de comparación
}
void loop(){
  //loop principal.
}


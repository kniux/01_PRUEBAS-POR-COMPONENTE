/*
  Autor: Edgar Cano
  Rev: 10/04/2024   
*/
volatile int cont = 0;
int anterior = 0;

void setup() {
  pinMode(3, INPUT_PULLUP);      
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(3),service, RISING);
}

void loop() {
  if (anterior != cont){
    Serial.println(cont);
    anterior = cont;
  }
}

// Interrupt Service Routine
void service(){
  cont++;  
}

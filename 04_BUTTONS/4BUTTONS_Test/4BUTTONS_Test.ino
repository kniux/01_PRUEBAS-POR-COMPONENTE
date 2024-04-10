/*
  Autor: Edgar Cano
  Rev: 08/04/2024 
*/

// Las constantes no cambiarán. Se utilizan aquí para establecer los números de pin.
const int buttonPin = 2;     
const int buttonPin2 = 3;    
const int buttonPin3 = 4;    
const int buttonPin4 = 5;    

int buttonState = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;

void setup() {
  
  Serial.begin(9600); 
  
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // lee el estado del valor del botón pulsador:
  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);

 // verifica si algun botón pulsador está presionado. Si lo está, el estado del botón es BAJO
  if ( (buttonState == LOW)||(buttonState2 == LOW)||(buttonState3 == LOW)||(buttonState4 == LOW) ){
    
    Serial.println("ON");
    digitalWrite(LED_BUILTIN,HIGH);

  } else {
    
    Serial.println("OFF");
    digitalWrite(LED_BUILTIN,LOW);
  }
}

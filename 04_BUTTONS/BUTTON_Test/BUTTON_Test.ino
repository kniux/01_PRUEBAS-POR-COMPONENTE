/*
  Autor: Edgar Cano
  Rev: 08/04/2024 
*/
const int buttonPin = 2;

int buttonState = 0;

void setup() {  
  Serial.begin(9600);
 
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {
    Serial.println("ON");
    digitalWrite(LED_BUILTIN,HIGH);

  } else {
    Serial.println("OFF");
    digitalWrite(LED_BUILTIN,LOW);
  }
}

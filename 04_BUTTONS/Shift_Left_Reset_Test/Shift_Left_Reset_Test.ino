/*
  Autor: Edgar Cano
  Rev: 08/04/2024 
*/
const int buttonReset = 8;     
const int buttonShift = 9;
const int buttonLatch = 10;

int Latch = 13;  
int Shift = 12;  
int Reset = 11;  

int buttonState1 = 0;         
int buttonState2 = 0;         
int buttonState3 = 0;  

void setup() {
  pinMode(buttonReset, INPUT_PULLUP);
  pinMode(buttonShift, INPUT_PULLUP);
  pinMode(buttonLatch, INPUT_PULLUP);
  pinMode(Latch, OUTPUT);
  pinMode(Shift, OUTPUT);
  pinMode(Reset, OUTPUT);
  digitalWrite(Reset, HIGH);
  digitalWrite(Shift, LOW);
  digitalWrite(Latch, LOW);
  Serial.begin(9600);
}

void loop() {
  buttonState1 = digitalRead(buttonReset);
  buttonState2 = digitalRead(buttonShift);
  buttonState3 = digitalRead(buttonLatch);

  if (buttonState1 == LOW) {  //RESET
    digitalWrite(Reset, LOW);
    Serial.println("PRESS RESET");    
    delay(200);
  }
  if (buttonState2 == LOW) {  //SHIFT
    digitalWrite(Shift, HIGH);
    Serial.println("PRESS SHIFT");    
    delay(200);
  }  
  if (buttonState3 == LOW) {  //LATCH
    digitalWrite(Latch, HIGH);
    Serial.println("PRESS LATCH");    
    delay(200);
  }  
  digitalWrite(Reset, HIGH);  
  digitalWrite(Shift, LOW);
  digitalWrite(Latch, LOW);    
  delay(20);
}

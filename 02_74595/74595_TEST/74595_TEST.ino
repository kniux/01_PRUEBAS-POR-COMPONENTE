/*
  Autor: Edgar Cano
  Rev: 08/04/2024 
*/

const int shiftClock = 13;
const int latchClock = 12;
const int serialPin = 7;

void setup() {
  
pinMode(shiftClock, OUTPUT);
pinMode(latchClock, OUTPUT);
pinMode(serialPin, OUTPUT);
}

void loop() {

  for (int numberToDisplay = 0; numberToDisplay  < 256; numberToDisplay++){
    digitalWrite(latchClock, LOW);
    shiftOut(serialPin, shiftClock, MSBFIRST, numberToDisplay);
    digitalWrite(latchClock, HIGH);
    delay(500);
  }
}

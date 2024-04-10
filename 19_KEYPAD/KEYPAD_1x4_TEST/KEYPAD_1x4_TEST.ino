/*
  Autor: Edgar Cano
  Rev: 10/04/2024   
*/
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 1;

char hexaKeys[ROWS][COLS] = {
  {'2'},
  {'1'},
  {'4'},
  {'3'}
};

byte rowPins[ROWS] = {12, 11, 10, 9};
byte colPins[COLS] = {8};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup(){
  Serial.begin(9600);
}

void loop(){
  char customKey = customKeypad.getKey();
  if (customKey){
    Serial.println(customKey);
  }
}

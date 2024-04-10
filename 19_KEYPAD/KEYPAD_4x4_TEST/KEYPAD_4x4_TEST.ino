/*
  Autor: Edgar Cano
  Rev: 10/04/2024   
*/
#include <Wire.h> 
#include <Keypad.h>

#define Password_Length 8 

char Data[Password_Length]; 
char Master[Password_Length] = "123A456"; 
byte data_count = 0, master_count = 0;
bool Pass_is_good;
char customKey;

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {33,35,37,39}; // Conectar a las salidas de fila del teclado.
byte colPins[COLS] = {41,43,45,47}; // Conectar a las salidas de columna del teclado.

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup(){
  Serial.begin(9600);
  Serial.println("Enter Password:");
}

void loop(){
   customKey = customKeypad.getKey();
  if (customKey){
    Data[data_count] = customKey; 
    Serial.print(Data[data_count]);    
    data_count++; 
    }

  if(data_count == Password_Length-1){

    if(!strcmp(Data, Master)){
      Serial.println();    
      Serial.println("Correct");    
      }
    else{
      Serial.println();    
      Serial.println("Incorrect");    
      }    
    clearData();  
  }
  delay(100);
}

void clearData(){
  while(data_count !=0){
    Data[data_count--] = 0; 
  }
  return;
}

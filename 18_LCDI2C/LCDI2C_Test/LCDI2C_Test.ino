/*
  Autor: Edgar Cano
  Rev: 10/04/2024   
*/
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

char array1[]=" Texto para mostrar ...     ";
char array2[]="Test LCD por I2C              ";
int tim = 250;              // valor de retardo

LiquidCrystal_I2C lcd(0x27,16,2); 

void setup(){
  lcd.init(); 
  lcd.backlight();
}

void loop() {
  lcd.setCursor(15,0);
  for (int positionCounter1 = 0; positionCounter1 < 26; positionCounter1++)  {
    lcd.scrollDisplayLeft();              // Desplaza el contenido de la pantalla una posición hacia la izquierda.
    lcd.print(array1[positionCounter1]);  // Imprime un mensaje en el LCD.
    delay(tim); 
  }
  lcd.clear();  
  lcd.setCursor(15,1);          // establecer el cursor en la columna 15, línea 1

  for (int positionCounter = 0; positionCounter < 26; positionCounter++)  {
    lcd.scrollDisplayLeft();    // Desplaza el contenido de la pantalla una posición hacia la izquierda.
    lcd.print(array2[positionCounter]);
    delay(tim); 
  }
  lcd.clear(); 
}

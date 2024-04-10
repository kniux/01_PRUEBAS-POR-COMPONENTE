/*
  Autor: Edgar Cano
  Rev: 10/04/2024 
*/
#include <SPI.h>
#include <RFID.h>           //48 52
  unsigned char my_rfid[] = {89,249,89,194,59}; // ID DEL LLAVERO
  
RFID rfid(48,49);  //D48--RFID module SDA pinã€D49 RFID module RST pin
void setup()
{
  Serial.begin(9600);
  SPI.begin();
  rfid.init();
}

void loop()
{
 //search card
  if (rfid.isCard()) {
    Serial.println("Se encontró la tarjeta.!");
   //read serial number
    if (rfid.readCardSerial()) {
      Serial.print("El número de la tarjeta es : ");
      Serial.print(rfid.serNum[0]);
         Serial.print(",");
      Serial.print(rfid.serNum[1]);
         Serial.print(",");
      Serial.print(rfid.serNum[2]);
          Serial.print(",");
      Serial.print(rfid.serNum[3]);
          Serial.print(",");
      Serial.print(rfid.serNum[4]);
      Serial.println(" ");
      if (compare_rfid(rfid.serNum,my_rfid))
       Serial.println("Esta tarjeta coincide con nuestros registros.!");
      else
       Serial.println("Not match!");
    }
 
    rfid.selectTag(rfid.serNum);
  }
  
  rfid.halt();
}
boolean compare_rfid(unsigned char x[],unsigned char y[])
{
  for (int i=0;i<5;i++)
  {
    if(x[i]!=y[i]) return false;
  }
  return true;
}

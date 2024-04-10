/*
  Autor: Edgar Cano
  Rev: 09/04/2024   
*/
#include <IRremote.h>  

const int irReceiverPin = 8;      //El pin SIG del módulo receptor está conectado al pin 2.
unsigned long codigo = 0xCF20D;

IRrecv irrecv(irReceiverPin);     // Crea una variable de tipo IRrecv
decode_results results;    

void setup(){
  Serial.begin(115200);    
  irrecv.enableIRIn();                  // Habilitar el módulo receptor de infrarrojos
}

void loop() {
  if (irrecv.decode(&results)){          // si el módulo receptor de infrarrojos recibe datos    
    Serial.print("irCode: ");           //print "irCode: "        
    Serial.print(results.value, HEX);   // imprimir el valor en hexadecimal
    Serial.print(",  bits: ");          //print" , bits: "         
    Serial.println(results.bits);       //print  bits
      if (codigo == results.value){
          Serial.print("Es el Codigo: ");    //print "irCode: "        
          Serial.println(codigo);
          Serial.println(codigo,HEX);
      }    
    irrecv.resume();                    // Recibir el siguiente valor
  }  
  delay(600); 
}

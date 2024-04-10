/*
  Transmisión Serial 
  Dispositivo Tx
  by Edgar Cano 
  05 Dic 2023
  
  This example code is in the public domain.
*/
const int buttonCLK = 10; 
const int buttonPinCarry = 9;
const int buttonPinZ = 8;    
const int buttonPinY = 7;    
const int buttonPinX = 6;    

const int ledPinQ0 =  4; 
const int ledPinQ1 =  3; 
const int ledPinQ2 =  2; 
const int ledPinTx =  5; 

boolean State_X = 0;       
boolean State_Y= 0;        
boolean State_Z= 0;  
boolean State_CLK = 0;         // variable for reading the pushbutton status
boolean State_Carry = 0;

uint8_t previous_state;            
uint8_t dataSend[3];
uint8_t DatoTx = 0;
uint8_t countBits = 0;

uint8_t Rising_edge(int btn) {
  uint8_t newValue = digitalRead(btn);
  uint8_t result = previous_state != newValue && newValue == 1;
  previous_state = newValue;  
  if(result){
    delay(200);
  }
  return result;
}

void RegistroDatos(){
  Serial.println("Pulse CLK para establecer el Registro X..."); 
  do{
    State_X = digitalRead(buttonPinX);
    State_Y = digitalRead(buttonPinY);
    State_Z = digitalRead(buttonPinZ);
    State_Carry = digitalRead(buttonPinCarry);
    State_CLK = digitalRead(buttonCLK);
    
    dataSend[0] = State_X;
    dataSend[1] = State_Y;
    dataSend[2] = State_Z;  
    
    digitalWrite(ledPinQ0,dataSend[0]);
    digitalWrite(ledPinQ1,dataSend[1]);
    digitalWrite(ledPinQ2,dataSend[2]);  
    
  }while(!Rising_edge(buttonCLK)); 
  
  Serial.println("Registro X a enviar...");        
  Serial.println("[Carry][2][1][0]");
  Serial.print("   ");
  Serial.print(State_Carry);
  Serial.print("    ");
  Serial.print(dataSend[2]);
  Serial.print("  "); 
  Serial.print(dataSend[1]);
  Serial.print("  ");
  Serial.println(dataSend[0]);      
}

void setup() {
  // initialize the LED pin as an output:
  Serial.begin(19200);
 
  // initialize the pushbutton pin as an input:
  pinMode(buttonPinX, INPUT);
  pinMode(buttonPinY, INPUT);
  pinMode(buttonPinZ, INPUT);
  pinMode(buttonCLK, INPUT);
  pinMode(buttonPinCarry, INPUT);
  
  pinMode(ledPinQ0, OUTPUT);
  pinMode(ledPinQ1, OUTPUT);
  pinMode(ledPinQ2, OUTPUT);
  pinMode(ledPinTx, OUTPUT);

  RegistroDatos();  
  
}

void loop() {   
  if (Rising_edge(buttonCLK)){
      State_Carry = digitalRead(buttonPinCarry);
      
      DatoTx = dataSend[0];
      dataSend[0] = dataSend[1];
      dataSend[1] = dataSend[2];
      dataSend[2] = State_Carry;        

      Serial.println();
      Serial.print("Enviando Bit[");
      Serial.print(countBits, DEC);
      Serial.println("]");  
      Serial.println("[Carry][2][1][0]  [Tx]");
      Serial.print("   ");
      Serial.print(State_Carry);
      Serial.print("    ");
      Serial.print(dataSend[2]);
      Serial.print("  "); 
      Serial.print(dataSend[1]);
      Serial.print("  ");
      Serial.print(dataSend[0]);
      Serial.print("     ");
      Serial.println(DatoTx);

      digitalWrite(ledPinQ0,dataSend[0]);
      digitalWrite(ledPinQ1,dataSend[1]);
      digitalWrite(ledPinQ2,dataSend[2]);     
      digitalWrite(ledPinTx,DatoTx);       
      ++countBits;  
  }
  if (countBits > 2){      
      countBits = 0;
      Serial.println();     
      Serial.println("Registro X enviado...");      
      Serial.println();
      Serial.println();     
      RegistroDatos();  
      digitalWrite(ledPinTx,LOW);     
  }   
}

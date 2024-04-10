/*
  Transmisión Serial 
  Dispositivo RX
  by Edgar Cano 
  05 Dic 2023
  
  This example code is in the public domain.
*/
const int buttonCLK = A0; 
const int PinRx = A1;
const int ledPinQ0 =  49; 
const int ledPinQ1 =  51; 
const int ledPinQ2 =  53; 

boolean State_Rx = 0;       
boolean State_CLK = 0;       

uint8_t previous_state;
uint8_t countBits = 0; 
uint8_t dataReceive[3];

uint8_t Rising_edge(int btn) {
  uint8_t newValue = digitalRead(btn);
  uint8_t result = previous_state != newValue && newValue == 1;
  previous_state = newValue;  
  if(result){
    delay(200);
  }
  return result;
}

void setup() {
  Serial.begin(9600); 
  pinMode(PinRx, INPUT);
  pinMode(buttonCLK, INPUT);  
  pinMode(ledPinQ0, OUTPUT);
  pinMode(ledPinQ1, OUTPUT);
  pinMode(ledPinQ2, OUTPUT);

  dataReceive[0] = 0;
  dataReceive[1] = 0;
  dataReceive[2] = 0;    

  digitalWrite(ledPinQ0,dataReceive[0]);
  digitalWrite(ledPinQ1,dataReceive[1]);
  digitalWrite(ledPinQ2,dataReceive[2]);   

  Serial.println("En espera de CLK para lectura de Datos ...");  
  do{
  }while(!Rising_edge(buttonCLK));        

  Serial.println();
  Serial.println("CLK de inicio recibido...");
  Serial.println("Registro Y de inicio: [2][1][0]");
  Serial.print(" Valores               ");
  Serial.print(dataReceive[2]);
  Serial.print("  "); 
  Serial.print(dataReceive[1]);
  Serial.print("  ");
  Serial.println(dataReceive[0]);   
  Serial.println();    
}

void loop() {
 if (Rising_edge(buttonCLK)){
      delay(500);
      State_Rx = digitalRead(PinRx);
      
      Serial.println("Recibe un bit...");  

      dataReceive[0] = dataReceive[1];  
      dataReceive[1] = dataReceive[2];
      dataReceive[2] = State_Rx;         

      Serial.println("[Rx]->[2][1][0]");
      Serial.print("  ");
      Serial.print(State_Rx); 
      Serial.print("    ");
      Serial.print(dataReceive[2]);
      Serial.print("  "); 
      Serial.print(dataReceive[1]);
      Serial.print("  ");
      Serial.println(dataReceive[0]);   

      digitalWrite(ledPinQ0,dataReceive[0]);
      digitalWrite(ledPinQ1,dataReceive[1]);
      digitalWrite(ledPinQ2,dataReceive[2]); 
      countBits++;
  }  
 if (countBits > 2){
    countBits  = 0;
    Serial.println();
    Serial.println("Registro Y escrito: [2][1][0]");
    Serial.print(" Valores             ");
    Serial.print(dataReceive[2]);
    Serial.print("  "); 
    Serial.print(dataReceive[1]);
    Serial.print("  ");
    Serial.println(dataReceive[0]);   
    Serial.println();   
    Serial.println("En espera de CLK para nueva lectura de Datos ...");  
    do{
    }while(!Rising_edge(buttonCLK));
    Serial.println("CLK de inicio recibido...");
    dataReceive[0] = 0;
    dataReceive[1] = 0;
    dataReceive[2] = 0;
 }
}

/*
  Autor: Edgar Cano
  Rev: 31/05/2024   
*/
#include <Keypad.h>
const byte ROWS = 1;
const byte COLS = 4;
 /* Pines Shield Osoyoo  , adaptando un teclado de 4x4.
  *  Filas :   33 35 37 39    --->  1  4  7  * 
  *  Columnas: 41 43 45 47    --->  1  2  3  A
  *  
  */
char hexaKeys[ROWS][COLS] = {'1','2','3','4'};
byte rowPins[ROWS] = {33};
byte colPins[COLS] = {41, 43, 45, 47};

Keypad keypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS );
byte ledPin = 10; 
byte buzzerPin = 6; 

boolean blink = false;
boolean ledPin_state;

boolean button1_Press  = false;
boolean button2_Press  = false;
boolean button3_Press  = false;
boolean button4_Press  = false;
boolean button1_Hold = false;
boolean button2_Hold = false;
boolean button3_Hold = false;
boolean button4_Hold = false;

void setup(){
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);              // Sets the digital pin as output.
    digitalWrite(ledPin, HIGH);           // Turn the LED on.
    ledPin_state = digitalRead(ledPin);   // Store initial LED state. HIGH when LED is on.
    keypad.addEventListener(keypadEvent); // Add an event listener for this keypad
}

void loop(){
    char key = keypad.getKey();

    if (key) {
        Serial.println(key);
    }
    if (blink){
        digitalWrite(ledPin,!digitalRead(ledPin));    // Change the ledPin from Hi2Lo or Lo2Hi.
        delay(100);
    }
}

// Taking care of some special events.
void keypadEvent(KeypadEvent key){
    switch (keypad.getState()){
    case PRESSED:
    sounds(1);
        if (key == '1') {               
            digitalWrite(ledPin,!digitalRead(ledPin));
            ledPin_state = digitalRead(ledPin);        // Remember LED state, lit or unlit.
            button1_Press = true;  
            Serial.print("button1_Press: ");  
            Serial.println(button1_Press);        
        }
        if (key == '2') {                
            button2_Press = true;     
            Serial.print("button2_Press: "); 
            Serial.println(button2_Press);     
        }
        if (key == '3') {                
            button3_Press = true;          
            Serial.print("button3_Press: ");   
            Serial.println(button3_Press);
        }
        if (key == '4') {                
            button4_Press = true; 
            Serial.print("button4_Press: ");
            Serial.println(button4_Press);         
        }         
        break;
    case HOLD:
    sounds(2);
        if (key == '1') {      
            blink = true;    // Blink the LED when holding the 1 key.
            button1_Hold = true;  
            Serial.print(" | button1_Hold: "); 
            Serial.println(button1_Hold);        
        }
        if (key == '2') {                
            button2_Hold = true;  
            Serial.print(" | button2_Hold: ");
            Serial.println(button2_Hold);        
        }
        if (key == '3') {                
            button3_Hold = true;  
            Serial.print(" | button3_Hold: "); 
            Serial.println(button3_Hold);        
        }
        if (key == '4') {                
            button4_Hold = true;    
            Serial.print(" | button4_Hold: ");
            Serial.println(button4_Hold);      
        }    
        break;
    case RELEASED:
    //sounds(3);
        if (key == '1') {    
            digitalWrite(ledPin,ledPin_state);    // Restore LED state from before it started blinking.
            blink = false;     
            button1_Press = false;        
            button1_Hold = false;    
            Serial.println("button1 RELEASED");
        }
        if (key == '2') {             
            button2_Press = false;           
            button2_Hold = false;          
            Serial.println("button2 RELEASED");
        }
        if (key == '3') {                
            button3_Press = false;        
            button3_Hold = false;          
            Serial.println("button3 RELEASED");
        }
        if (key == '4') {                
            button4_Press = false;        
            button4_Hold = false;          
            Serial.println("button4 RELEASED");
        }
        break;
    }
}

void sounds(byte type){
  if(type == 1){      //key sound
    digitalWrite(buzzerPin, HIGH);
    delay(50);
    digitalWrite(buzzerPin, LOW);  
  }
  if(type == 2){      //set configuration sound
    digitalWrite(buzzerPin, HIGH);
    delay(50);      
    digitalWrite(buzzerPin, LOW);
    delay(50);      
    digitalWrite(buzzerPin, HIGH);
    delay(50);
    digitalWrite(buzzerPin, LOW);    
  }
  if(type == 3){      //end configuration sound
    delay(150);
    digitalWrite(buzzerPin, LOW);  
    digitalWrite(buzzerPin, HIGH);
    delay(200);      
    digitalWrite(buzzerPin, LOW);
    delay(50);      
    digitalWrite(buzzerPin, HIGH);
    delay(200);
    digitalWrite(buzzerPin, LOW);    
  }
  if(type == 4){      //Free food sound
    digitalWrite(buzzerPin, HIGH);
    delay(500);    
    digitalWrite(buzzerPin, LOW); 
    delay(500);  
    digitalWrite(buzzerPin, HIGH);
    delay(500);    
    digitalWrite(buzzerPin, LOW);
  }  
}

/*
  Button FF


*/

// constants won't change. They're used here to set pin numbers:
const int buttonPinX = 2;     // the number of the pushbutton pin
const int buttonPinY = 3;     // the number of the pushbutton pin
const int buttonPinZ = 4;     // the number of the pushbutton pin

const int buttonCLK = 5;     // the number of the pushbutton pin
const int buttonPreset = 6;     // the number of the pushbutton pin
const int buttonClear = 7;     // the number of the pushbutton pin

const int ledPinQ0 =  8;      // the number of the LED pin
const int ledPinQ1 =  9;      // the number of the LED pin
const int ledPinQ2 =  10;      // the number of the LED pin

// variables will change:
int State_X = 0;         // variable for reading the pushbutton status
int State_Y= 0;         // variable for reading the pushbutton status
int State_Z= 0;         // variable for reading the pushbutton status

int State_CLK = 0;         // variable for reading the pushbutton status
int State_PRESET= 0;         // variable for reading the pushbutton status
int State_CLEAR= 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  Serial.begin(9600);
 
  // initialize the pushbutton pin as an input:
  pinMode(buttonPinX, INPUT_PULLUP);
  pinMode(buttonPinY, INPUT_PULLUP);
  pinMode(buttonPinZ, INPUT_PULLUP);
  pinMode(buttonCLK, INPUT_PULLUP);
  pinMode(buttonPreset, INPUT_PULLUP);
  pinMode(buttonClear, INPUT_PULLUP);

  pinMode(ledPinQ0, OUTPUT);
  pinMode(ledPinQ1, OUTPUT);
  pinMode(ledPinQ2, OUTPUT);
}

void loop() {
  // read the state of the pushbutton value:
  State_CLK = digitalRead(buttonCLK);
  State_PRESET = digitalRead(buttonPreset);
  State_CLEAR = digitalRead(buttonClear);


  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (State_PRESET == LOW) {
    // turn LED off:
    Serial.println("PRESET");
    digitalWrite(ledPinQ0,HIGH);
    digitalWrite(ledPinQ1,HIGH);
    digitalWrite(ledPinQ2,HIGH);    

  } else if (State_CLEAR == LOW) {
    // turn LED on:
    Serial.println("CLEAR");
    digitalWrite(ledPinQ0,LOW);
    digitalWrite(ledPinQ1,LOW);
    digitalWrite(ledPinQ2,LOW);    
  }
  else
    if(State_CLK == LOW){
        Serial.println("CLK");
      State_X = digitalRead(buttonPinX);
      State_Y = digitalRead(buttonPinY);
      State_Z = digitalRead(buttonPinZ);

        digitalWrite(ledPinQ0,State_X);
        digitalWrite(ledPinQ1,State_Y);
        digitalWrite(ledPinQ2,State_Z);  
    }
}

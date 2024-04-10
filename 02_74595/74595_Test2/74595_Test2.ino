
const int shiftClock = 13;
const int latchClock = 12;
const int serialPin = 7;

int dataArray[16] = { 
/*abcdefgp */
B11111100,  
B01100000,   
B11011010,  
B11110010,   
B10110110,   
B10111110,  
B11100000, 
B11111110,
B11110110,
B11101110,
B00111110,
B10011100,
B01111010,
B10011110,
B10001110};
      
void setup() {
  // put your setup code here, to run once:
pinMode(shiftClock, OUTPUT);
pinMode(latchClock, OUTPUT);
pinMode(serialPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int num = 0; num < 16; num++){
    digitalWrite(latchClock, LOW);
    shiftOut(serialPin, shiftClock, LSBFIRST, dataArray[num]);
    digitalWrite(latchClock, HIGH);
    delay(1000);
  }
}

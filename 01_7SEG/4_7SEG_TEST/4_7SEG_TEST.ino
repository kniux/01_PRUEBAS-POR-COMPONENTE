/*
  Autor: Edgar Cano
  Rev: 08/04/2024 
*/
const int pins[7] = { 2, 3, 4, 5, 6, 7, 8 }; 
               //     a  b  c  d  e  f  g

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);    
  
  for(int i = 0; i < 7; i++) {
    pinMode(pins[i], OUTPUT);  
  }
}

void loop() {

  boolean  A = digitalRead(A0);
  boolean  B = digitalRead(A1);
  boolean  C = digitalRead(A2);
  boolean  D = digitalRead(A3);

   digitalWrite(2, ( A|C|(!B&!D)|(B&D))) ;                      //a
   digitalWrite(3, ( (C&D)|(!C&!D)|!B) ) ;                      //b
   digitalWrite(4, ( (!C|D|B)) );                               //c
   digitalWrite(5, ( (A|(B&!C&D)|(!B&!D)|(C&!D)|(!B&C))) );     //d
   digitalWrite(6, ( (C&!D)|(!B&!D)) );                         //e
   digitalWrite(7, ( ( A|(!C&!D)|(B&!C)|(B&!D))) );             //f
   digitalWrite(8, ( ( A|(B&!D)|(B&!C)|(C&!D)|(!B&C))) );       //g
 delay(50);  
}

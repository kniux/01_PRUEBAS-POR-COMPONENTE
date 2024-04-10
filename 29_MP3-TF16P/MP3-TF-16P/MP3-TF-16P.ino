/*
  Autor: Edgar Cano
  Rev: 08/04/2024 
*/

#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

//Pulsadores
const int s1 = 5; // pulsadores
const int s2 = 6;

const int led = 13; // led

int state1 = 0; // estados para las entradas digitales
int last1 = 1;
int state2 = 0;
int last2 = 1;

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

void setup()
{
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);

  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));

  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while (true);
  }
  Serial.println(F("DFPlayer Mini online."));

  myDFPlayer.setTimeOut(500); //Set serial communictaion time out 500ms

  //----Set volume----
  myDFPlayer.volume(10);  //Set volume value (0~30).
  myDFPlayer.volumeUp(); //Volume Up
  myDFPlayer.volumeDown(); //Volume Down

  //----Set different EQ----
  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);

  //----Set device we use SD as default----
  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);

  pinMode(s1, INPUT_PULLUP);
  pinMode(s2, INPUT_PULLUP);

  pinMode(led, OUTPUT);

}

void loop()
{
  state1 = digitalRead(s1);
  state2 = digitalRead(s2);

  if (state1 != last1) {
    if (state1 == HIGH) {
      myDFPlayer.play(1);
      Serial.print(state1);
      digitalWrite(led, 1);
      delay(1000);
    }
  }
  last1  = state1;

  if (state2 != last2 ) {
    if (state2 == HIGH) {
      myDFPlayer.play(2);
      digitalWrite(led, 0);
      delay(1000);
    }
  }
  last2  = state2;

}

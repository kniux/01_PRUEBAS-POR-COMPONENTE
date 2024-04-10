int ledPin = 2;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.print("Hola ");
  digitalWrite(ledPin, HIGH);
  delay(500);
  
  Serial.println("Mundo");
  digitalWrite(ledPin, LOW);
  delay(500);
}

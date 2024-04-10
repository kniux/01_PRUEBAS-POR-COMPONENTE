int redLedPin = 2; // Pin Red LED conectado al pin 2 
int count = 0; 
void setup(){ 
  pinMode(redLedPin, OUTPUT); //Establecer pin led en salida
  Serial.begin(9600); //Establecer serie en l9600 bps
  while (! Serial); // Permitir que el serial se inicialice 
  Serial.println("Introduzca Y para encender el LED:"); 
} 
void loop(){ 
  if (Serial.available())  {  
    char ch = Serial.read();  
    if (ch == 'y'||ch == 'Y'){  
      digitalWrite(redLedPin, HIGH);  
      Serial.println("Has encendido el LED!!");  
      Serial.print("El LED estuvo apagado por ");  
      Serial.print(count);  
      Serial.println(" segundos");  
      Serial.println("Si desea desactivarlo, simplemente ingrese N o n!"); 
      count = 0;  
    }  
    if(ch == 'n'||ch == 'N')  {  
      digitalWrite(redLedPin, LOW);  
      Serial.println("Has apagado el LED!!");  
      Serial.print("El LED estuvo encendido por ");  
      Serial.print(count);  
      Serial.println(" segundos");  
      Serial.println("Si desea encenderlo, simplemente ingrese Y o y!");  
      count = 0;  
    }  
  }  
  delay(1000);  count += 1; 
}

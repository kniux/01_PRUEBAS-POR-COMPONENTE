
// Incluir la biblioteca para el IC BQ24195
#include <BQ24195.h>

//define variables
float rawADC;           //valor ADC sin procesar
float voltADC;          //ADC convertida en voltaje
float voltBat;          //voltaje calculado en la batería

//definir los valores de resistencia en el divisor de voltaje
  
int R1 =  330000;       // resistencia entre el terminal de la batería y el pin SAMD PB09
int R2 = 1000000;       // resistencia entre el pin SAMD PB09 y tierra

int max_Source_voltage; // voltaje de fuente superior para la batería

// definir el voltaje al que la batería está llena/vacía
float batteryFullVoltage = 4.2;   //límite de voltaje superior para la batería
float batteryEmptyVoltage = 3.5;  //límite de voltaje inferior para la batería

float batteryCapacity = 0.750;            //establecer la capacidad de la batería en Ah

void setup() {
   
  Serial.begin(9600);               // iniciar puerto serie con una velocidad en baudios de 9600bps
  
  analogReference(AR_DEFAULT);      //el valor superior de ADC se establece en 3,3 V
  analogReadResolution(12);         //esto nos dará 4096 (2^12) niveles en el ADC

  //configurar BQ24195 PMIC
  PMIC.begin();                                               // inicia la conexión PMIC I2C
  PMIC.enableBoostMode();                                     // aumenta la salida de la batería a 5V
  
  PMIC.setMinimumSystemVoltage(batteryEmptyVoltage);          // establezca la salida mínima de la batería en 3,5 V
  PMIC.setChargeVoltage(batteryFullVoltage);                  // establecer el voltaje de la batería en carga completa

  PMIC.setChargeCurrent(batteryCapacity/2);                   // establezca la corriente de la batería en C/2 en amperios

  PMIC.enableCharge();                                        // permitir la carga de la batería

  // La fórmula para calcular la salida de un divisor de voltaje es
  // Vout = (Vsource x R2)/(R1 + R2)
  // Si consideramos que 3.3V es el máximo que se puede aplicar a Vout, entonces el voltaje máximo de la fuente se calcula como
  max_Source_voltage = (3.3 * (R1 + R2))/R2;

}

void loop()
{
  
  rawADC = analogRead(ADC_BATTERY);                     //el valor obtenido directamente en el pin de entrada PB09
  voltADC = rawADC * (3.3/4095.0);                      //convierte el valor ADC al voltaje leído en el pin
  voltBat = voltADC * (max_Source_voltage/3.3);         //no podemos usar map ya que requiere entradas/salidas de tipo int
  
  int new_batt = (voltBat - batteryEmptyVoltage) * (100) / (batteryFullVoltage - batteryEmptyVoltage);    //función de mapa flotante personalizada

  //reportar información a través de serie
  Serial.print("El ADC en PB09 lee un valor de: ");
  Serial.print(rawADC);
  Serial.print(", que es equivalente a: ");
  Serial.print(voltADC);
  Serial.println("V.");
  Serial.print("Esto significa que el voltaje de la batería es ");
  Serial.print(voltBat);
  Serial.print("V. Lo que equivale a un nivel de carga de ");
  Serial.print(new_batt);
  Serial.println("%.");

  delay(500);
}

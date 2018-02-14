/*
 Determinacinn del rango de valores de un sensor LDR
 J.A. Vacas

 */

const int LDRPin = A0;

const long CalibrationTime=1000;

int maxValue=0;       // Nos aseguramos que se calculen bien
int minValue=10000;

void setup() {
  Serial.begin(9600);
  Serial.println("Calibrando. Modifique la iluminacion");
  long startCalibrationTime=millis();
  while( ( millis() - startCalibrationTime ) < CalibrationTime ){
    int ldrValue = analogRead(LDRPin);
    if( maxValue < ldrValue) maxValue = ldrValue;
    if( minValue > ldrValue) minValue = ldrValue;
  }


}

void loop() {
  // Ahora podemos reescalar los valroes entre minValue y maxValue
  int valorEscalado = map( analogRead(LDRPin), minValue, maxValue,0,255);

}

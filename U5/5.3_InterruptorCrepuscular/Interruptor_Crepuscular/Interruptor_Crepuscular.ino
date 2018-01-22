/*
   Interruptor Crepuscular:
   Sistema para controlar el encendido de un led
   en funcion de la intensidad luminosa
   
   LDR pin A0
   LED pin 12
   
   Noviembre 207
   Jose Pujol
*/

// variables constantes para los pines
const int ldrPin = A0;    // establece el pin de la LDR
const int ledPin = 12; // establece el pin del LED rojo

// variables que pueden cambiar
int ldrValue = 0; // variable para almacenar el valor de la LDR
int ldrlevel=200; // nivel de cambio del valor de la LDR

void setup() {
  // establece el LED como una salida
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // lee el valor del sensor
  ldrValue = analogRead(ldrPin);
  // si el valor es menor enciende los LEDs
  if (ldrValue < ldrlevel) {
    digitalWrite(ledPin, HIGH);
  }
  // sino los apaga
  else {
    digitalWrite(ledPin, LOW);
  }
}

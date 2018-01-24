/*
 Controla la lumninosidad LED con potenciómetro
Jose Pujol
 */
 
// Variables globales
// Variables constantes para los pines
const int potPin = A0; // selecciona el pin de entrada para el potenciómetro
const int ledPin = 9;  // selecciona pin 9 para el LED 

// variables que almacenan los datos
int potValue = 0; // variable para almacenar los valores del potenciómetro 0-1023
int bright = 0; // variable que almacena el valor del sensor mapeado 0-255

void setup() {
  // nada que declarar en el setup
}

void loop() {
  // lee el valor del sensor 0-1023
  potValue = analogRead(potPin);
  // mapea el valor a escala 0-255
  bright = map(potValue, 0, 1023, 0, 255);
  // escribimos el valor en analogico en el LED
  analogWrite(ledPin, bright);
}


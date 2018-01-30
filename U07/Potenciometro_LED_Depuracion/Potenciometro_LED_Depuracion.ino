/*
 Control de la lumninosidad de un LED con un potenciómetro
 
 LED pin 9
 Potenciometro pin A0
 
 Noviembre 2017
 Jose Pujol


 Trazas añadidas por JAVacas

 */
 
// Variables globales
// Variables constantes para los pines
const int potPin = A0; // selecciona el pin de entrada para el potenciómetro
const int ledPin = 9;  // selecciona pin 9 para el LED 

// variables que almacenan los datos
int potValue = 0; // variable para almacenar los valores del potenciómetro 0-1023
int bright = 0; // variable que almacena el valor del sensor mapeado 0-255

void setup() {
  Serial.begin(9600);
}

void loop() {
  // lee el valor del sensor 0-1023
  Serial.println("Leemos el sensor");
  potValue = analogRead(potPin);
  // mapea el valor a escala 0-255
  Serial.println("Reescalamos el valor a PWM");
  bright = map(potValue, 0, 1023, 0, 255);
  Serial.print("pot=");
  Serial.print(potValue);
  Serial.print(" PWM=");
  Serial.println(bright);
  // escribimos el valor en analogico en el LED
  Serial.println("Escribimos el valor PWM");
  analogWrite(ledPin, bright);
}



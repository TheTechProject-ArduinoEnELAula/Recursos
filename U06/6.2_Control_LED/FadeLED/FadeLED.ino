/*
    Programa para encender y apagar un LED gradualmente
    Subida y bajada de 2,5s
    
    LED pin 9
    
    Basado en el programa Fade de Arduino
    Jose Pujol
    Noviembre de 2017
*/

// Variables globales constantes
const int ledPin = 9; // LED conectado a Pin 9

void setup() {
  // nada que declarar en el set up
}
void loop() {
  // Encendido gradual del LED en 2,5s
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    analogWrite(ledPin, fadeValue);   // establece el valor de 0 a 255
    delay(50);                        // espera de 50 ms
  }
  // Apagado gradual del LED en 2,5
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    analogWrite(ledPin, fadeValue);     // establece el valor de 255 a 0
    delay(50);                        // espera de 50 ms
  }
}

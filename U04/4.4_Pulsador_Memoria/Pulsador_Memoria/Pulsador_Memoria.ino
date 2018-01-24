/*
 * Pulsador con Memoria
 Pulsador para controlar un LED con memoria
 
 Pulsador pin 2
 LED pin 12
 
 * Noviembre de 2017
 * Jose Pujol
 */
// constantes que no cambian se usan para establecer los pines
const int buttonPin = 2;     // el numero del pin del pulsador
const int ledPin = 12;       // el numero de pin del led

// variables que cambian
int ledState = LOW;         // Estado actual del led apagado
int buttonState = 0;        // variable para almacenar el estado del pulsador

void setup() {
  // inicializa los pines como entradas y salidas
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // lee el estado del pulsador y lo almacena en variable
  buttonState = digitalRead(buttonPin);

  // revisa si el pulsador esta presionado
  if (buttonState == HIGH) {
    // si el estado del led es bajo
    if (ledState == LOW) {
      ledState = HIGH;  // lo establece como alto
    }
    // en caso contario lo establece como bajo
    else {
      ledState = LOW;
    }
    // tiempo que evita que el programa siga cumpliendo la condicion
    delay(200);
  }
  // establece el estado del LED:
  digitalWrite(ledPin, ledState);
}

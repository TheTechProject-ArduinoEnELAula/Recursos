/*
  Control de un PIR para encender un LED con retardo de tiempo
  Jose Pujol
  Noviembre de 2017
*/

// constantes que no cambian
const int ledPin =  12;  // el número de pin del led
const int pirPin = 3; // pin asociado al PIR

// variables que cambian
int pirValue = 0; // estado del sensor PIR

// Variables de tiempo
unsigned long previousTime = 0;        // almacena el tiempo anterior
// constantes que no cambian
const long interval = 5000;           // intervalo de retardo del LED (milisegundos)

void setup() {
  pinMode(pirPin, INPUT); // establece el PIR como entrada digital
  pinMode(ledPin, OUTPUT); // establece el led como salida digital
}

void loop() {

  // lectura del tiempo actual y almacenamiento en la variable
  unsigned long currentTime = millis();
  pirValue = digitalRead(pirPin); // lectura del sensor PIR
 
  // si el sensor esta activado
  if (pirValue == HIGH) {
    digitalWrite(ledPin, HIGH);     // enciende el led
    // actualiza el tiempo anterior al actual
    previousTime = currentTime;
  }

  // si el tiempo actual menos el anterior es mayor que el intervalo
  if ((currentTime - previousTime) >= interval) {
    digitalWrite(ledPin, LOW);    // Apaga el LED
  }
}

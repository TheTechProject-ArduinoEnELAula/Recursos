/*
  Secuencias
  Semaforo verde, amarillo y rojo
  verde 6s
  amarillo 2s
  rojo 4s
  Jose Pujol
  Octubre 2017
*/

// Declaracion de variables de tipo constante entero
const int ledRPin = 12; // LED rojo asociado al pin 12
const int ledAPin = 10; // LED amarillo asociado al pin 10
const int ledVPin = 8; // LED verde asociado al pin 8

// la funcion set up se ejecuta una sola vez
void setup() {
  // inicializa los pines como una salida digital
  pinMode(ledRPin, OUTPUT);
  pinMode(ledAPin, OUTPUT);
  pinMode(ledVPin, OUTPUT);
}

// la funcion loop se ejecuta repetidamente de forma infinita
void loop() {
  // ESTADO SEMAFORO VERDE
  digitalWrite(ledRPin, LOW); // establece 0v en el pin del LED rojo
  digitalWrite(ledAPin, LOW); // establece 0v en el pin del LED amarillo
  digitalWrite(ledVPin, HIGH); // establece 5v en el pin del LED verde
  delay(6000);    // espera seis segundos
  // ESTADO SEMAFORO AMARILLO
                              // establece 5v en el pin del LED amarillo
                              // establece 0v en el pin del LED rojo
                              // establece 0v en el pin del LED verde                             
  delay(2000);    // espera dos segundos
  // ESTADO SEMAFORO ROJO

  delay(4000);    // espera cuatro segundos
}

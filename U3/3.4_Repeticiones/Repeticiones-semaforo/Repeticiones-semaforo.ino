/*
  Semaforo verde, amarillo y rojo
  verde 6s
  amarillo 2s- 10 parpadeos
  rojo 4s
  Jose Pujol
  Octubre 2017
*/

// Declaracion de variables de tipo constante entero
const int ledRPin = 12; // LED rojo asociado al pin 12
const int ledAPin = 10; // LED amarillo asociado al pin 10
const int ledVPin = 8; // LED verde asociado al pin 8

const int zumbPin = 6; // zumbador asociado al pin 6

// la funcion set up se ejecuta una sola vez
void setup() {
  // inicializa los pines como una salida digital
  pinMode(ledRPin, OUTPUT);
  pinMode(ledAPin, OUTPUT);
  pinMode(ledVPin, OUTPUT);
  pinMode(zumbPin, OUTPUT);
}

// la funcion loop se ejecuta repetidamente de forma infinita
void loop() {
  // ESTADO SEMAFORO VERDE
  digitalWrite(ledRPin, LOW); // establece 0v en el pin del LED rojo
  digitalWrite(ledAPin, LOW); // establece 0v en el pin del LED amarillo
  digitalWrite(ledVPin, HIGH); // establece 5v en el pin del LED verde
  digitalWrite(zumbPin, LOW); // establece 0v en el pin del zumbador
  delay(6000);    // espera seis segundos

  // ESTADO SEMAFORO AMARILLO
  digitalWrite(ledRPin, LOW);  // establece 0v en el pin del LED rojo
  digitalWrite(ledVPin, LOW); // establece 0v en el pin del LED verde
  // bucle de repetición
  for (int i = 0; i < 5; i++) {
    digitalWrite(ledAPin, HIGH); // establece 5v en el pin del LED amarillo
    digitalWrite(zumbPin, HIGH); // establece 5v en el pin del zumbador
    delay(200);                 // espera 0,2 segundos
    digitalWrite(ledAPin, LOW); // establece 0v en el pin del LED amarillo
    digitalWrite(zumbPin, LOW); // establece 0v en el pin del zumbador
    delay(200);                 // espera 0,2 segundos
  }

  // ESTADO SEMAFORO ROJO
  digitalWrite(ledRPin, HIGH); // establece 5v en el pin del LED rojo
  digitalWrite(ledAPin, LOW); // establece 0v en el pin del LED amarillo
  digitalWrite(ledVPin, LOW); // establece 0v en el pin del LED verde
  digitalWrite(zumbPin, LOW); // establece 0v en el pin del zumbador
  delay(4000);    // espera cuatro segundos
}

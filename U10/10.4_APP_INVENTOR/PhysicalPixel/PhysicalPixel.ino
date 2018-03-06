const int ledPin = 13; // pin al que el led esta conectado
int incomingByte;      // variable para leer los bytes de entrada

void setup() {
  // inicializamos la comunicacion serie
  Serial.begin(9600);
  // inicializamos el led como pin digital salida
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // comprobamos si hay datos de entrada
  if (Serial.available() > 0) {
    // lectura del byte mas antiguo del buffer serial
    incomingByte = Serial.read();
    // si el byte es H (ASCII 72) enciende el LED
    if (incomingByte == 'H') {
      digitalWrite(ledPin, HIGH);
    }
    // si el byte es L (ASCII 76) apaga el LED
    if (incomingByte == 'L') {
      digitalWrite(ledPin, LOW);
    }
  }
}

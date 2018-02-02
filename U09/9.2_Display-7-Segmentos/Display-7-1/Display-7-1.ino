/*
   Control de un display de 7 segmentos mediante
   un registro de desplazamiento 74hc595
   Realización de un contador de 0-9
   
   Enero de 2018
   Jose Pujol
*/

const int pinLatch = 11;  //Pin para el latch de los 74CH495
const int pinData = 10;  //Pin para Datos serie del 74CH495
const int pinClock = 12;  //Pin para reloj del 74CH495

// Codificación binaria de los dígitos en el display de 7 segmentos
byte numbers [10] = {B00000011, B10011111, B00100101, B00001101,B10011001,
                     B01001001, B01000001, B00011111, B00000001, B00001001};

void setup() {
  // declaramos los pines del latch, datos y el reloj
  pinMode(pinLatch, OUTPUT);
  pinMode(pinData, OUTPUT);
  pinMode(pinClock, OUTPUT);
}

void loop() {
  // se repite el proceso 10 veces i 0-9
  for (int i = 0; i < 10; i++) {
    // se establece el registro en modo escucha 
    digitalWrite(pinLatch, LOW);
    // se manda el byte numbers[i]
    shiftOut(pinData, pinClock, LSBFIRST, numbers[i]);
    // se fija el valor del registro
    digitalWrite(pinLatch, HIGH);
    delay(1000);  // se espera 1 segundo
  }
}


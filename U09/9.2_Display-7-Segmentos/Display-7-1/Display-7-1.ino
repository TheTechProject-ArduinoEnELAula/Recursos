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
byte numbers [10] = {B00000011, B10011111, B00100101, B00001101,
                     B10011001, B01001001, B01000001, B00011111, B00000001, B00001001
                    };

void setup() {
  // declaramos los pines del latch, datos y el reloj
  pinMode(pinLatch, OUTPUT);
  pinMode(pinData, OUTPUT);
  pinMode(pinClock, OUTPUT);
}

int pinLatch = 11;  //Pin para el latch de los 74CH495
int pinDatos = 10;  //Pin para Datos serie del 74CH495
int pinReloj = 12;  //Pin para reloj del 74CH495

// Codificación hexadecimal de los dígitos decimales en el display de 7 segmentos
byte numbers [10] = {B00000011, B10011111, B00100101, B00001101, B10011001, B01001001, B01000001, B00011111, B00000001, B00001001};

void setup() {
  pinMode(pinLatch, OUTPUT);
  pinMode(pinDatos, OUTPUT);
  pinMode(pinReloj, OUTPUT);
  //Serial.begin(9600);
}

void loop() {

  for (int i = 0; i < 10; i++) {
    digitalWrite(pinLatch, LOW);
    //mandamos la unidad que pasa al display2
    shiftOut(pinDatos, pinReloj, LSBFIRST, numbers[i]);
    // mandamos la decena que pasa al display 1
    digitalWrite(pinLatch, HIGH);
    delay(1000);
  }
}



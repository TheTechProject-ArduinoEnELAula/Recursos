/*
  Programa para monitorizar el valor del acelerómetro
  Noviembre 2017
  JosePujol
*/

const int xPin = A2;    // pin donde conectamos el sensor analogico
const int yPin = A3;    // pin donde conectamos el sensor analogico
int xValue = 0;  // variable para alamacenar los valores del sensor
int yValue = 0;  // variable para alamacenar los valores del sensor

void setup() {
  Serial.begin(9600);        // abrimos el puerto serie y configuramos velocidad
}

void loop() {
  xValue = analogRead(xPin);    // lee el valor del sensor
  yValue = analogRead(yPin);    // lee el valor del sensor
  Serial.print(xValue);         // Imprime el valor del sensor
  Serial.print("\t");           // Imprime un tabulador
  Serial.println(yValue);       // Imprime el valor del sensor
  delay(100);                    // Espera 0.1 segundo
}

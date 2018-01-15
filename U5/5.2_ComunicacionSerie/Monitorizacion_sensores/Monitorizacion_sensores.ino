/*
 * Programa para monitorizar sensores
 * y conocer que valores da según las condiciones
 * Noviembre 2017
 * Jose Pujol
 */
 
const int sensorPin = A0;    // establece el pin del sensor
int sensorValue = 0;        // variable para almacenar el valor del sensor

void setup() {
  // abre el puerto serie
  // y establece la velocidad de conexion en baudios
  Serial.begin(9600);
}

void loop() {
  // lee el valor del sensor
  sensorValue = analogRead(sensorPin);
  // Imprime un texto
  Serial.print("Valor Sensor=");
  // Imprime el valor de la variable por el puerto serie
  Serial.println(sensorValue);
  // tiempo de espera para visibilidad
  delay(1000);
}

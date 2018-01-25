/*
  Programa para imprimir el tiempo por puerto serie
  usando control de tiempo por reloj interno
  
  Jose Pujol
  Noviembre 2017
*/

// Variables de tiempo
unsigned long previousTime = 0;        // almacena el tiempo ultima actualizacion

// constantes que no cambian
const long interval = 1000;           // intervalo de impresion del tiempo

void setup() {
  // abrimos el puerto serie y configuramos la velocidad de comunicación
  Serial.begin(9600);
}

void loop() {

  // lectura del tiempo actual y almacenamiento en la variable
  unsigned long currentTime = millis();
  // si el tiempo actual menos el anterior es mayor que el intervalo
  if (currentTime - previousTime >= interval) {
    // actualiza el tiempo anterior al nuevo ciclo
    previousTime = currentTime;
    // Imprime el tiempo actual
    Serial.println(currentTime);
  }
}


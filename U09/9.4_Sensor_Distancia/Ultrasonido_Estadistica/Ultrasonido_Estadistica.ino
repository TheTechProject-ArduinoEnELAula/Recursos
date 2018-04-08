/*
 * Codigo para medir distancia con sensor de ultrasonidos
 * Se mide por intervalo de tiempo mediante reloj interno
 * Se realiza calculo estadistico de valor minimo, media y máximo
 * de un array y se imprime por el puerto serie
 * 
 * Sensor de Ultrasonidos: HCSR04
 * Trigger pin 11
 * Echo pin 12
 * 
 * Jose Pujol
 * Jose Antonio vacas
 * Enero 2018
 */

// Conexion pines del sensor de distancia
const int triggerPin = 11; // Pin donde conectamos el emisor
const int echoPin = 12; // Pin donde conectamos el receptor

// variables para almacenar tiempo actual y tiempo anterior
unsigned long current_time = 0;
unsigned long previous_time = 0;

// constante con el intervalo de tiempo en el calculan las medidas
const long interval = 1000; 

// Variables para guardar el valor minimo el medio y el maximo
float fMinimun,fAverage, fMaximun;

void setup() {
  Serial.begin(9600); // Abrimos el puerto serie
  pinMode(triggerPin, OUTPUT); // Configuramos trigger como salida digital
  pinMode(echoPin, INPUT); // Configuramos echo como entrada digital
}

void loop() {
  current_time = millis();  // grabamos el tiempo
  // si el tiempo es mayor que el intervalo medimos
  if (current_time - previous_time > interval) {
    previous_time = current_time; // actualizamos el tiempo
    // llamada a la funcion statisticdata
    statisticdata();
    // se imprimen por pantalla los valores
    Serial.print (fMinimun);  // minimo
    Serial.print (",");
    Serial.print (fAverage);  // media
    Serial.print (",");
    Serial.println (fMaximun); // maximo
  }
}

// funcion para medir la distancia
float  measuringdistance() {
  // Variable para almacenar el tiempo de la onda y la distancia
  float duration, distance;
  //Inicializamos el sensor
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(5);
  // Enviamos una señal activando la salida trigger durante 10 microsegundos
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  // Medimos el ancho del pulso, cuando la lectura sea HIGH
  // devuelve el tiempo transcurrido en microsegundos
  duration = pulseIn(echoPin, HIGH, 15000);
  // Calculamos la distancia en cm y la guardamos en distance
  distance = duration * 0.01715;
  // devolvemos la distancia
  return distance;
}

// Funcion para hacer estadistica sobre las medidas tomadas
void statisticdata() {
  const int numMeasures = 10; // Numero de medidas que se toman
  float measures[numMeasures];  // array con las medidas de distancia obtenidas
  int numData = 0;    // variable que cuuenta el numero de datos con valor >0
  fMinimun = 5000.0;  // se asigna un valor maximo alto
  fMaximun = 0.0;     // valor minimo cero
  float fSum = 0;     // variable para almacenar la suma

  // se guarda el array con las medidas
  for (int i = 0 ; i < numMeasures; i++) {
    measures[i] = measuringdistance(); // llamada a funcion measuringdistance y se almacena en el array 
    if (measures[i] > 0) numData++; // se cuenta el numero de medidas >0
  }

  // se calculan el minimo el maximo y la suma
  for (int i = 0 ; i < numMeasures; i++) {
    if (fMinimun > measures[i]  && measures[i] > 0) fMinimun = measures[i]; // se obtiene el minimo
    if (fMaximun < measures[i]) fMaximun = measures[i]; // se obtiene el maximo
    fSum = measures[i] + fSum; // Obtenemos la suma de la serie
  }
  // se obtiene la media en caso de que el numero de datos sea mayor de cero
  if (numData > 0) fAverage = fSum / numData;

}

// Conexion pines del sensor de distancia
const int triggerPin = 11; // Pin donde conectamos el emisor
const int echoPin = 12; // Pin donde conectamos el receptor

// variables para almacenar tiempo actual y tiempo anterior
unsigned long current_time = 0;
unsigned long previous_time = 0;

const long interval = 1000; // intervalo de tiempo

const int numMeasures = 10; // Numero de medidas que se toman

// Variables para guardar el valor medio, el minimo y el maximo
float fAverage, fMinimun, fMaximun;



void setup() {
  Serial.begin(9600); // Abrimos el puerto serie
  pinMode(triggerPin, OUTPUT); // Configuramos trigger como salida digital
  pinMode(echoPin, INPUT); // Configuramos echo como entrada digital
}

void loop() {
  // grabamos el tiempo
  current_time = millis();
  // si el tiempo es mayor que el intervalo medimos
  if (current_time - previous_time > interval) {
    previous_time = current_time;
    // Tomamos NumSamples medidas
    statisticdata();
    Serial.print (fMinimun);
    Serial.print (",");
    Serial.print (fAverage);
    Serial.print (",");
    Serial.println (fMaximun);
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

// Funcion para hacer estadistica sobre las medidas
void statisticdata() {
  float measures[numMeasures];
  int numData = 0;
  fMinimun = 5000.0;
  fMaximun = 0.0;
  float fSum = 0;

  for (int i = 0 ; i < numMeasures; i++) {
    measures[i] = measuringdistance();
    if (measures[i] > 0) numData++;
  }

  for (int i = 0 ; i < numMeasures; i++) {
    if (fMinimun > measures[i]  && measures[i] > 0) fMinimun = measures[i];
    if (fMaximun < measures[i]) fMaximun = measures[i];
    fSum = measures[i] + fSum;
  }

  if (numData > 0) fAverage = fSum / numData;
}



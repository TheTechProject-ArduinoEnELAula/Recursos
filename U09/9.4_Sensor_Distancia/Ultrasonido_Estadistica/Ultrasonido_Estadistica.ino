// Conexion pines del sensor de distancia
const int triggerPin = 11; // Pin donde conectamos el emisor
const int echoPin = 12; // Pin donde conectamos el receptor

// variables para almacenar tiempo actual y tiempo anterior
unsigned long current_time = 0;
unsigned long previous_time = 0;

long interval=100; // intervalo de tiempo 

// Variables para guardar el valor medio, el minimo y el maximo
float fAverage,fMinimun,fMaximun;

const int numMeasures=10; // Numero de medidas que se toman
int numData; // Numero de datos que tenemos

void setup() {
  Serial.begin(9600); // Abrimos el puerto serie
  pinMode(triggerPin, OUTPUT); // Configuramos trigger como salida digital
  pinMode(echoPin, INPUT); // Configuramos echo como entrada digital
}
void loop() {
 // grabamos el tiempo
  current_time = millis();
  // si el tiempo es mayor que el intervalo medimos
  if (current_time - previous_time > 100) {
    previous_time = current_time;
    // Tomamos NumSamples medidas 
    statisticData();
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
void statisticData(){
  fAverage=0; // actualizamos la media a cero
  // Damos valores extremos a Min y Max para asegurar que se van calcular bien
  fMinimun=10000000;
  fMaximun=0; 
  
  numData=0;
  for(int i = 0 ; i < numMeasures; i++){
    float cm = measuringdistance ();
    if (cm!=0) {  // Solo tomamos valores distintos de 0 
      numData++;
      if(fMinimun>cm)  fMinimun=cm;  // Tenemos un nuevo minimo
      if(fMaximun<cm)  fMaximun=cm;  // Tenemos un nuevo maximo
      fAverage=fAverage+cm;
    }
  } 
  if(numData>0) fAverage=fAverage/numData;  
}

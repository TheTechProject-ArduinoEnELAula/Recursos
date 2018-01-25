/*
Curso de Arduino
Control de un motor usando L298


Descripcion
Control de sentido de giro y de la velocidad de un motor usando L298

Montaje

EnB       6
In3       9
In4       8

by JAVacasM
*/

// Variables globales

const int EnB=6;
const int In3=9;
const int In4=8;

// Valores de velocidad maxima y minima
const int Max_Speed=255;
const int Min_Speed=0;



void setup() {
  pinMode(In3,OUTPUT);  // Establecemos los pines In3 e In4 como salida
  pinMode(In4,OUTPUT);
}
// Establece la velocidad con el valor del PWM del pin EnB
void setSpeed(int speed){
  analogWrite(EnB,speed);
}

// Arrancamos a maxima velocidad
void start(){
    analogWrite(EnB,Max_Speed);
}

// Paramos el motor
void stop(){
   analogWrite(EnB,Min_Speed);
}

// El motor gira en sentido horario
void clockWise(){
  digitalWrite(In3,HIGH);
  digitalWrite(In4,LOW);
}

// El motor gira en sentido antihorario
void antiClockWise(){
  digitalWrite(In3,LOW);
  digitalWrite(In4,HIGH);
}

void loop() {
  clockWise();
  // Vamos aumentando la velocidad
  for(int i=0;i<=255;i+=5){
    setSpeed(i);
    delay(200);  
  }
  stop();
  delay(1000);
  antiClockWise();
  // Vamos aumentando la velocidad
  for(int i=0;i<=255;i+=5){
    setSpeed(i);
    delay(200);  
  }
  stop();
  delay(1000);
}


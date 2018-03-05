/*
 * Programa para controlar la posición de un servo
 * en función de un potenciómetro
 * Diciembre de 2017
 * Jose Pujol
 * Basado en programa Knob IDE Arduino- Michal Rinott
 */

// incluye la libreria servo
#include <Servo.h>
// crea el objeto myservo tipo servo
Servo myservo;

// constantes para conexion oines
const int potPin = A0;  // pin de conexion de potenciometro
const int servoPin=8; // pin de conexion de servo

// variables que cambian
int potValue=0;    // variable para alamacenar el valor del potenciometro
int angle = 0; // numero de grados del servo

void setup()
{
  myservo.attach(servoPin);   // vincula el servo al pin digital 8
}

void loop()
{
  potValue = analogRead(potPin);   // lectura del potenciometro 0-1023
  angle = map(potValue, 0, 1023, 0, 180);   // convierte el potenciometro a valor angulo 0-180
  myservo.write(angle);   // posiciona el servo al angulo
  delay(15);  // tiempo de espera para que el servo alcance la posicion
}


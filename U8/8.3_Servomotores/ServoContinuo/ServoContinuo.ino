/*
 * Programa para controlar velocidad de un servo continuo
 * en función de un potenciómetro
 * Diciembre de 2017
 * Jose Pujol
 * Basado en programa Knob IDE Arduino- Michal Rinott
 */

// incluye la libreria servo
#include <Servo.h>
// crea el objeto myservo tipo servo
Servo myservo;

const int potPin = A0;  // pin de conexion de potenciometro
int potValue=0;    // variable para alamacenar el valor del potenciometro
int vel = 0; // velocidad del servo

void setup()
{
  myservo.attach(8);   // vincula el servo al pin digital 8
}

void loop()
{
  potValue = analogRead(potPin);   // lectura del potenciometro 0-1023
  vel = map(potValue, 0, 1023, 0, 180);   // convierte el potenciometro a valor velocidad 0-180
  myservo.write(vel);   // velocidad del servo
  delay(15);  // tiempo de espera para que el servo alcance la posicion
}


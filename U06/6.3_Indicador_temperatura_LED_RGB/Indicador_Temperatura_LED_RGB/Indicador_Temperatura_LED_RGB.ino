/*
Curso de Arduino
Cambio de color de una tira de LED  RGB en funcion de la temperatura
Medimos la temperatura con un TMP36

Descripcion
Mostraremos la temperatura con una escala de colores:
Frio-Azul             Calor-Rojo

Montaje

Sensor de temperatura TMP6        A0

RGB_B     9
RGB_R    10
RGB_G    11

by JAVacasM
*/

// Variables globales

const int TMP36Pin=A0;

const int ledPWM_G=11;
const int ledPWM_R=10;
const int ledPWM_B=9;


//Para escalar el color definimos una temperatura minima y una maxima
const int TEMP_MINIMA=15;
const int TEMP_MAXIMA=25;

float temperaturaC;    // Guardamos la temperatura actual

void setup() {
  Serial.begin(9600);
  analogWrite(ledPWM_G, 0); // Apagamos el verde porque no lo vamos a usar
}

void loop() {
  
  int iValorAnalogico=analogRead(TMP36Pin);  // Leemos el sensor TMP36

  float voltaje = iValorAnalogico * 5.0 / 1024.0; // voltios
  temperaturaC = (voltaje - 0.5) * 100 ;          // temperatura 

  // Enviamos la temperatura por el puerto serie
  Serial.print(iValorAnalogico);
  Serial.print(" ");
  Serial.println(temperaturaC);

  // Filtramos la temperatura fuera de rango (suelen ser problemas del sensor)
  if( (temperaturaC > TEMP_MINIMA ) && (temperaturaC < TEMP_MAXIMA)){

    // Escalamos directamente proporcial  la temperatura y el rojo
    int iBrightR=map(int(temperaturaC),TEMP_MINIMA,TEMP_MAXIMA,0,255);
    // Escalamos inversamente proporcial la temperatura y el azul
    int iBrightB=map(int(temperaturaC),TEMP_MINIMA,TEMP_MAXIMA,255,0);
  
    analogWrite(ledPWM_R, iBrightR); // establecemos el brillo de rojo
    analogWrite(ledPWM_B, iBrightB); // establecemos el brillo de azul
    
  } else {
    Serial.print("Error de lectura: ");
    Serial.println(temperaturaC);
  }
   
  delay(200);   // Esperamos un tiempo a que se estabilice el brillo
}


/*
 Calculo de media sin usar Array
 J.A. Vacas

 */


float newSensorValue=100;

float Sum = 0;    // guarda el acumulado de los valores medidos
int NumData = 0; // guarda el número de medidas ralizados
int MaxNumData = 1000;

void setup() {
    Serial.begin(9600);
}

void loop() {

   Sum = Sum + analogRead(A0);  // Agregamos el nuevo valor
   NumData = NumData + 1;         // Incrementamos el número de medidas

   if ( NumData > MaxNumData ){ //Reiniciamos la suma
      float average = Sum / NumData; // Calculamos la media
      Serial.println(average);
      Sum = 0;
      NumData = 0;
   }

}

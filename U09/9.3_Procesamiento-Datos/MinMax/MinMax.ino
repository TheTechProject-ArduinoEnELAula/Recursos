/*
 Cálculo del mínimo y máximo de los valores de un array
 J.A. Vacas

 */


const int NumOfData=10;

void setup() {
}

void loop() {
  int data[NumOfData];

  for(int i = 0 ; i < NumOfData ; i++ ){
      data[i]=analogRead(A0); // Lectura del sensor
  }

  int maxValue=data[0];
  int minValue=data[0];

  for(int i = 0 ; i < NumOfData ; i++ ){
    if( maxValue < data[i]) maxValue = data[i];
    if( minValue > data[i]) minValue = data[i];
  }

}

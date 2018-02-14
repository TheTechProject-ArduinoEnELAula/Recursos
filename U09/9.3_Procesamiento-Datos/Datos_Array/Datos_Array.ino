/*
 Almacenamiento de datos en Array
 J.A. Vacas

 */

int valueSensor=10;

const int NumOfData=10;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  int data[NumOfData];
  for(int i = 0 ; i < NumOfData ; i++ ){
      data[i]=valueSensor; // Lectura del sensor
  }
}

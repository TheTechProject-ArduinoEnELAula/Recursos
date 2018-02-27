/*
*
* Copyright 2009 Ken Shirriff
* http://arcfn.com
* 
* Adaptado y traducido por J.A. Vacas
*/
#include <IRremote.h>      // Importamos la libreria IRremote

const int RECV_PIN = 11;   // Pin donde conectamos el Receptor infrarrojo

IRrecv irrecv(RECV_PIN);   // Receptor de datos IR
decode_results result;     // resultado de la decodificacion
/*  result.value           // codigo
    result.decode_type     // fabricante
    result.rawbuf          // Datos en bruto (bits)
*/
void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();      // Activamos el receptor 
}

void loop() {
  if ( irrecv.decode(&result)) {        // Decodificamos y guardamos en result
    if (result.value != 0xFFFFFFFF ) {  // Filtramos codigos de interferencias
      Serial.println(result.value, HEX);// Mostramos el codigo en formato hexadecimal
    }
    irrecv.resume();                       // Recibimos el siguiente valor
  }
  delay(100);
}

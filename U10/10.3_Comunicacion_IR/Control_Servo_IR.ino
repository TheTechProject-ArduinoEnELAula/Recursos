#include <IRremote.h>
#include <Servo.h>

const int RECV_PIN = 11;
const int Servo_Pin = 7;

IRrecv irrecv(RECV_PIN);
decode_results results;
Servo servoContinuo;

void setup() {
  irrecv.enableIRIn();              // Arrancamos el receptor
  servoContinuo.attach(Servo_Pin);  // Configuramos el servo
}

void loop() {
if ( irrecv.decode(&results)) {
    if (results.value != 0xFFFFFFFF ) {  // Filtramos interferencias
        Serial.println(results.value, HEX);
    
        switch(results.value){  // Segun los valores movemos o paramos el servo 
          case 0xFFA25D:  // Tecla CH-
             servoContinuo.write(0);
             break;
          case 0xFF629D:   // Tecla CH
             servoContinuo.write(90);
             break;
          case 0xFFE21D:  // Tecla CH+
             servoContinuo.write(180);
             break;
        }
    }
    irrecv.resume(); // Recibimos el siguiente valor
  }
}

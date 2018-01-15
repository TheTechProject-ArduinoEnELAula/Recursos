/*
 Secuencia de antirrobo de una casa
 JA Vacas

 Realizamos una secuencia iluminando las distintas habitaciones de la casa

 Dormitorio: Led Rojo   pin 11
 Salon:      Led Azul   pin 8
 Cocina:     Led Azul   pin 5
 Entrada:    Led Verde  pin 2
 */

// declaracion de variables 

// Conexiones
const int  ledDormitorioPin=11; // LED que simula la luz del dormitorio
const int  ledSalonPin=8;       // LED que simula la luz del salon
const int  ledCocinaPin=5;      // LED que simula la luz de la cocina
const int  ledEntradaPin=2;     // LED que simula la luz de la entrada 

// Tiempo entre pasos
int duracionTarde=1000;         // Duracion del estado Tarde
int duracionNoche=2000;         // Duracion del estado Noche
int duracionMadrugada=500;      // Duracion del estado Madrugada

// Configuración 
void setup() {
  // configuramos los pines como salidas
  pinMode(ledDormitorioPin,OUTPUT);
  pinMode(ledSalonPin,OUTPUT);
  pinMode(ledCocinaPin,OUTPUT);
  pinMode(ledEntradaPin,OUTPUT);
}

// Bucle que se repite
void loop() {
  
  // ESTADO TARDE
  
  digitalWrite(ledSalonPin,HIGH);     // Encendemos el salon
  digitalWrite(ledCocinaPin,HIGH);    // Encendemos el salon
  digitalWrite(ledDormitorioPin,LOW); // Apagamos el dormitorio
  digitalWrite(ledEntradaPin,LOW);    // Apagamos la entrada
  
  delay(duracionTarde);   //Esperamos hasta el siguiente estado


  // ESTADO NOCHE

                                      // Apagamos Salon
                                      // Apagamos Cocina
                                      // Encendemos Dormitorio
                                      // Apagamos Entrada

                          // Esperamos  hasta el siguiente estado   
    
  // ESTADO MADRUGADA

    // ....
}

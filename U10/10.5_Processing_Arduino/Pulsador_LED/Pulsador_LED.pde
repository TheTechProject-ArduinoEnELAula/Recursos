/*
Programa para controlar el encendido de un LED 
con un pulsador por cimunicacion a traves del puerto serie
En Arduino hay que usar Ejemplos--> Communication --> Physical Pixel
*/

import processing.serial.*;
Serial myPort;                       // The serial port
// variables pulsador
int xpos, ypos;  
int altura=75;
int longitud=100;
boolean overButton = false;
int colorButton=125;
// variables LED
boolean ledStatus=false;
int radio=75;
int colorRLED=100;

void setup() {
  size(500, 300);  // Stage size
  noStroke();      // No border on the next thing drawn

  // Set the starting position of the ball (middle of the stage)
  xpos = width/3;
  ypos = height/2;

  // Print a list of the serial ports, for debugging purposes:
  printArray(Serial.list());

  // I know that the first port in the serial list on my mac
  // is always my  FTDI adaptor, so I open Serial.list()[0].
  // On Windows machines, this generally opens COM1.
  // Open whatever port is the one you're using.
  String portName = Serial.list()[5];
  myPort = new Serial(this, portName, 9600);
}

void draw() {
  
  background(0);  // definimos el fondo
 
 // dibujamos el pulsador
  fill(colorButton);
  // Draw the shape
  rectMode(CENTER);
  rect(xpos, ypos, longitud, altura, 8);
  
 // dibujamos el LED
   fill(colorRLED, 0, 0);
  ellipse(width*2/3, height/2, radio, radio);
  
  // Si el raton está encima del pulsador
  if (mouseX > xpos-longitud/2 && mouseX < xpos+longitud/2 && 
    mouseY > ypos-altura/2 && mouseY < ypos+altura/2) {
    overButton = true;
    colorButton=200;
  } else {
    overButton = false;
    colorButton=150;
  }
}

void mousePressed() {
  if(overButton) { 
    if (ledStatus){
    colorRLED= 100;
    myPort.write('L');
    ledStatus=false;
    }
    else{
    colorRLED= 255;
    ledStatus=true;
    myPort.write('H');
    }
  }
}

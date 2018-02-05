/*
 Medida de temperatura con sensor TMP36
 Mostramos la temperatura por el monitor serie y un  LCD I2C
 JA. Vacas

 Descripción

 Sensor TMP36 
 pin V del sensor conectado a 5V de Arduino
 pin central del sensor Vout a A0 de Arduino
 pin GND a GND de Arduino
 
 */
#include <Wire.h>                         // Incluimos las librerias necesarias
#include <LiquidCrystal_I2C.h>

const int TMP36Pin = A0;                  // Conectamos el pin central a A0
float temperatura = 0;                    // almacenamos la temperatura medida

LiquidCrystal_I2C lcd(0x3F,16,2);         // Objeto LCD_I2C

void setup() {
  Serial.begin(9600);                     // Configuramos la conexion con el PC
  lcd.init();                             // Inicializamos el LCD
  lcd.backlight();                        // Activamos la iluminacion
}
void loop() {
  int lectura = analogRead(TMP36Pin);     // Valor entre 0 y 1023
  float voltaje = lectura * 5.0 / 1024.0; // Voltaje entre 0 y 5V
  temperatura = (voltaje - 0.5) * 100;    // Temperatura en º Celsius
  
  lcd.clear();                            // Borramos la pantalla
  lcd.setCursor(0,0);                     // Ponemos cursor en (0,0)
  lcd.print("Temperatura:");              // Mostramos los datos
  lcd.print(temperatura);
  lcd.print("C");                         // Algunos caracteres dan error (como el º)

  Serial.print("Temperatura:");  
  Serial.print(temperatura);              // Mostramos la temperatura via serie
  Serial.println("C");

  delay(1000);                            // Esperamos para hacer la siguiente medida
}



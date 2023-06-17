#include "LedControl.h"
#include <LiquidCrystal.h>

LedControl ledControl = LedControl(51, 53, 49, 1);
LiquidCrystal pantalla(8, 9, 10, 11, 12, 13);

int ACEPTAR = 2, CANCELAR = 3;

void inicializarMatrizDriver()
{
    ledControl.shutdown(0, false);  // shutdown(# de dispositivo (indice), estado)
    ledControl.setIntensity(0, 15); // setIntensity(# de dispositivo (indice), intensidad de brillo del led de 0 a 15)
    ledControl.clearDisplay(0);     // clearDisplay(# de dispositivo), apaga todos los leds de la pantalla
}

void inicializarPinesTeclado(){
  // pines laterales del teclado del 25 al 28
  for (int j = 25; j <= 28; j++) {
      pinMode(j, INPUT);
  }

  // // pines superiores del teclado del 22 al 24
  for (int j = 22; j <= 24; j++) {
      pinMode(j, OUTPUT);
  }  
}

void setup() {
  Serial.begin(9600); // puerto bluetooh
  Serial1.begin(9600); // puerto virtual terminal
  Serial3.begin(9600); // puerto arduino secundario
  pantalla.begin(16,4);
  inicializarMatrizDriver();
  inicializarPinesTeclado();
  pinMode(ACEPTAR, INPUT_PULLUP);
  pinMode(CANCELAR, INPUT_PULLUP);
}

void loop() {
  pantalla.clear();
  pantalla.print(" GRUPO - 13 ");
  delay(100);
}

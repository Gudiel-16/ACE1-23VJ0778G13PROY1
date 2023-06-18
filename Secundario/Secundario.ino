#include "sensores.h"

void inicializarPinesBotones(){
  for (int i = 2; i <= 10; i++) {
      pinMode(i, INPUT_PULLUP);
  }
}

void setup() {
  Serial1.begin(9600); // puerto virtual terminal
  Serial3.begin(9600); // puerto arduino secundario
  inicializarPinesBotones();
}

void loop() {
  Serial1.println("SENSORES:");
  leerSensoresTemperatura();
  delay(5);
}

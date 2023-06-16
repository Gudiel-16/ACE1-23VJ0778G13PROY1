#include "Ultrasonico.h"
#include "Fotosensor.h"
#include "LCD.h"

void setup()
{
    // Inicializar los pines
    pinMode(pinTrigIz, OUTPUT);
    pinMode(pinEchoIz, INPUT);
    pinMode(pinTrigDer, OUTPUT);
    pinMode(pinEchoDer, INPUT);
    pinMode(pin_analogicoIz, INPUT);       // definimos como entrada
    pinMode(pin_digitalIz, INPUT_PULLUP);  // definimos como entrada
    pinMode(pin_analogicoDer, INPUT);      // definimos como entrada
    pinMode(pin_digitalDer, INPUT_PULLUP); // definimos como entrada
    // Iniciar comunicación serie
    Serial.begin(9600);
    // Inicializar el LCD con el número de  columnas y filas del LCD
    lcd.begin(16, 2);
}

void loop()
{

    MedirUltra(pinTrigIz, pinEchoIz, "Izq");
    MedirFoto(pin_analogicoIz, pin_digitalIz, "Izq");
    MedirUltra(pinTrigDer, pinEchoDer, "Der");
    MedirFoto(pin_analogicoDer, pin_digitalDer, "Der");
}

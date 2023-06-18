#include <Arduino.h>
#line 1 "G:\\Archivos\\Escritorio\\Ingenieria\\Junio 2023\\Arqui 1\\ACE1-23VJ0778G13PROY1\\Fisico\\Fisico.ino"
#include "Funciones.h"

#line 3 "G:\\Archivos\\Escritorio\\Ingenieria\\Junio 2023\\Arqui 1\\ACE1-23VJ0778G13PROY1\\Fisico\\Fisico.ino"
void setup();
#line 32 "G:\\Archivos\\Escritorio\\Ingenieria\\Junio 2023\\Arqui 1\\ACE1-23VJ0778G13PROY1\\Fisico\\Fisico.ino"
void loop();
#line 3 "G:\\Archivos\\Escritorio\\Ingenieria\\Junio 2023\\Arqui 1\\ACE1-23VJ0778G13PROY1\\Fisico\\Fisico.ino"
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

// Estados de Inicio
EstadoInicio estadoInicioIzq = NO_HAY;
EstadoInicio estadoInicioDer = NO_HAY;
EstadoValorInicial estadoValorInicialIzq = VACIO;
EstadoValorInicial estadoValorInicialDer = VACIO;

// Mediciones Iniciales
int distanciaIzq;
int distanciaDer;



void loop()
{
    if (estadoInicioIzq == NO_HAY)
    {
        estadoInicioIzq = Inicio(pinTrigIz, pinEchoIz, "Izquierda", 0, 0);
    }
    

    if (estadoInicioDer == NO_HAY)
    {
        estadoInicioDer = Inicio(pinTrigDer, pinEchoDer, "Derecha", 0, 1);
    }

    if (estadoInicioIzq == SI_HAY && MedirFoto(pin_analogicoIz, pin_digitalIz, "Izquierda") && estadoValorInicialIzq == VACIO)
    {
        MostrarLCD("Medicion inicial", 0, 0);
        delay(2000);
        distanciaIzq = MedirUltra(pinTrigIz, pinEchoIz, "Izquierda");
        Serial.println(distanciaIzq);
        MostrarLCD("                  ", 0, 0);
        MostrarLCD(String(distanciaIzq) + " cm", 0, 0);
        estadoValorInicialIzq = LLENO;
    }

    if (estadoInicioDer == SI_HAY && MedirFoto(pin_analogicoDer, pin_digitalDer, "Derecha") && estadoValorInicialDer == VACIO)
    {
        MostrarLCD("Medicion inicial", 0, 1);
        delay(2000);
        distanciaDer = MedirUltra(pinTrigDer, pinEchoDer, "Derecha");
        Serial.println(distanciaDer);
        MostrarLCD("                  ", 0, 1);
        MostrarLCD(String(distanciaDer) + " cm", 0, 1);
        estadoValorInicialDer = LLENO;
    }

    if (estadoValorInicialIzq == LLENO )
    {
        Monitorear(pin_analogicoIz, pin_digitalIz, "Izquierda", pinTrigIz, pinEchoIz, "Izquierda", 0, 0, distanciaIzq);
    }
    
    if (estadoValorInicialDer == LLENO)
    {
        Monitorear(pin_analogicoDer, pin_digitalDer, "Derecha", pinTrigDer, pinEchoDer, "Derecha", 0, 1, distanciaDer);
    }
}


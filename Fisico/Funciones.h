#ifndef FUNCIONES_H

#include "Ultrasonico.h"
#include "Fotosensor.h"
#include "LCD.h"

enum EstadoInicio
{
    SI_HAY,
    NO_HAY
};

enum EstadoValorInicial
{
    VACIO,
    LLENO
};

EstadoInicio Inicio(int pinTrigxd, int pinEchoxd, String lado, int columna, int fila)
{

    if (MedirUltra(pinTrigxd, pinEchoxd, lado) < 10)
    {
        Serial.println("Si hay" + lado);
        MostrarLCD("Ingresado", columna, fila);
        delay(2000);
        return SI_HAY;
    }
    else
    {
        Serial.println("No hay" + lado);
        MostrarLCD("Vacio", columna, fila);
        return NO_HAY;
    }
}

void Monitorear(int pin_analogicoxd, int pin_digitalxd, String tapa, int pinTrigxd, int pinEchoxd, String lado, int columna, int fila, int distanciaInicial)
{
    if (MedirFoto(pin_analogicoxd, pin_digitalxd, tapa) == false)
    {
        MostrarLCD("                  ", columna, fila);
        MostrarLCD("Puerta Abierta!", columna, fila);
        delay(500);
    }
    else if (MedirUltra(pinTrigxd, pinEchoxd, lado) > 10)
    {
        MostrarLCD("                  ", columna, fila);
        MostrarLCD("Vacio!", columna, fila);
        delay(500);
    }
    else if (MedirUltra(pinTrigxd, pinEchoxd, lado) < distanciaInicial || (MedirUltra(pinTrigxd, pinEchoxd, lado) > distanciaInicial && MedirUltra(pinTrigxd, pinEchoxd, lado) < 10))
    {
        MostrarLCD("                  ", columna, fila);
        MostrarLCD("No coincide!", columna, fila);
        delay(500);
    }
    else
    {
        MostrarLCD("                  ", columna, fila);
        MostrarLCD("Seguro", columna, fila);
        delay(500);
    }
}

#endif
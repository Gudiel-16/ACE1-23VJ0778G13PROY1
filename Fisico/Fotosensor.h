#ifndef FOTOSENSOR_H
#define FOTOSENSOR_H
#include "LCD.h"

int pin_analogicoIz = A1; // definimos los pines por los que
int pin_digitalIz = A0;   // conectamos las salidas del módulo
int pin_analogicoDer = A3; // definimos los pines por los que
int pin_digitalDer = A2;   // conectamos las salidas del módulo

void MedirFoto(int pin_analogicoxd, int pin_digitalxd, String tapa)
{
    // si la salida digital está en cero, es porque se ha superado el valor de referencia
    // entonces se desplegará el mensaje: "salida digital activa"

    if (digitalRead(pin_digitalxd) == LOW)

    {

        Serial.println("Tapa abierta" + tapa); // si la salida digital está en cero, es porque se ha superado el valor de referencia
        MostrarLCD("Tapa "+ tapa+" a" , 0, 1);
        delay(2000);
    }

    else

    {

        Serial.println("Tapa cerrada" + tapa); // de otra forma de deplegará "salida digital inactiva"
        MostrarLCD("Tapa "+ tapa+" c" , 0, 1);
        delay(2000); // esperamos para visualizar mejor
    }
}

#endif
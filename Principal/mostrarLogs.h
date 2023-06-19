#include "memoria.h"
#include "datosIntegrantes.h"

void enlistarLogs(LiquidCrystal pantalla)
{
    byte noLogs = obtenerNumeroLogs();
    int logSize = (int)noLogs;
    int contMostrados = 0;
    int contPintar = 0;
    String estado = "";

    while (contMostrados < logSize)
    {
        if (estado == "MOSTRAR")
        {
            while (contPintar < 4)
            {
                struct evento log = buscarLog(contMostrados);
                pintarCadenaMayorHorizontal(pantalla, 16, log.descripcion, contPintar);
                contMostrados++;
                contPintar++;
            }
            estado = "SELECCION";
            break;
        }
        else if (estado == "SELECCION")
        {
            if (digitalRead(2) == LOW) // SIGUIENTE PAGINA
            {                          // ACEPTAR
                estado = "MOSTRAR";
                contPintar = 0;
                break;
            }
            else if (digitalRead(3) == LOW) // SALIR DEL LOG
            {                               // CANCELAR
                contMostrados = logSize;
                break;
            }
        }
    }
}
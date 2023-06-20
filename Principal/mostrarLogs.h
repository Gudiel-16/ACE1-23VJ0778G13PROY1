#include "funcionalidadesUsuario.h"
#include "datosIntegrantes.h"

void enlistarLogs(LiquidCrystal pantalla)
{
    byte noLogs = obtenerNumeroLogs();
    int logSize = (int)noLogs;
    int contMostrados = 0;
    int contPintar = 0;
    String estado = "MOSTRAR";

    while (contMostrados < logSize)
    {
        if (estado == "MOSTRAR")
        {
            while (contPintar < 4 && contMostrados < logSize)
            {
                struct evento log = buscarLog(contMostrados);
                pintarCadenaMayorHorizontal(pantalla, log.descripcion, contPintar, 16);
                contMostrados++;
                contPintar++;
            }
            estado = "SELECCION";
        }
        else if (estado == "SELECCION")
        {
            if (digitalRead(2) == LOW) // SIGUIENTE PAGINA
            {                          // ACEPTAR
                estado = "MOSTRAR";
                contPintar = 0;
                pantalla.clear();
            }
            else if (digitalRead(3) == LOW) // SALIR DEL LOG
            {                               // CANCELAR
                contMostrados = logSize;
                pantalla.clear();
                break;
            }
        }
    }
}
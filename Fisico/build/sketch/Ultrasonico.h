#line 1 "G:\\Archivos\\Escritorio\\Ingenieria\\Junio 2023\\Arqui 1\\ACE1-23VJ0778G13PROY1\\Fisico\\Ultrasonico.h"
#ifndef ULTRASONICO_H
#define ULTRASONICO_H
#include "LCD.h"
// Definir los pines Trig y Echo del módulo ultrasónico
const int pinTrigIz = 2;
const int pinEchoIz = 3;
const int pinTrigDer = 4;
const int pinEchoDer = 5;

int MedirUltra(int pinTrigxd, int pinEchoxd, String lado)
{
    // Generar un pulso corto en el pin Trig
    digitalWrite(pinTrigxd, LOW);
    delayMicroseconds(2);
    digitalWrite(pinTrigxd, HIGH);
    delayMicroseconds(10);
    digitalWrite(pinTrigxd, LOW);

    // Medir la duración del pulso en el pin Echo
    int duration = pulseIn(pinEchoxd, HIGH);
    delay(25);
    // Calcular la distancia en centímetros
    int distance = duration * 0.034 / 2;

    // Imprimir la distancia en el Monitor Serie

    Serial.println("Dist " + lado + ":" + String(distance) + "cm");

    // Esperar un momento antes de realizar la próxima medición
    delay(1000);
    return distance;
}
#endif
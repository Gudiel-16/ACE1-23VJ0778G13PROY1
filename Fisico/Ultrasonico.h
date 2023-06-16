#ifndef ULTRASONICO_H
#define ULTRASONICO_H
#include "LCD.h"
// Definir los pines Trig y Echo del módulo ultrasónico
const int pinTrigIz = 2;
const int pinEchoIz = 3;
const int pinTrigDer = 4;
const int pinEchoDer = 5;

void MedirUltra(int pinTrigxd, int pinEchoxd, String lado)
{
    // Generar un pulso corto en el pin Trig
    digitalWrite(pinTrigxd, LOW);
    delayMicroseconds(2);
    digitalWrite(pinTrigxd, HIGH);
    delayMicroseconds(10);
    digitalWrite(pinTrigxd, LOW);

    // Medir la duración del pulso en el pin Echo
    long duration = pulseIn(pinEchoxd, HIGH);

    // Calcular la distancia en centímetros
    float distance = duration * 0.034 / 2;

    // Imprimir la distancia en el Monitor Serie
    Serial.print("Distancia"+ lado +": ");
    Serial.print(distance);
    Serial.println(" cm");

    MostrarLCD("Dist "+ lado +":" + String(distance) + "cm", 0, 0);
    // Esperar un momento antes de realizar la próxima medición
    delay(1000);
}
#endif
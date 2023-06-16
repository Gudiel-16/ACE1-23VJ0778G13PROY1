#ifndef LCD_H
#define LCD_H
#include <LiquidCrystal.h>

//Crear el objeto LCD con los números correspondientes (rs, en, d4, d5, d6, d7)
LiquidCrystal lcd(51, 49, 47, 45, 43, 41);
void MostrarLCD(String mensaje, int columna, int fila)
{
    lcd.setCursor(columna, fila);
    lcd.print(mensaje);
}
#endif
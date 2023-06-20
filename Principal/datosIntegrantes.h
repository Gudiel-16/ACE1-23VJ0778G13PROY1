#include <LiquidCrystal.h>

void pintarCadenaMayorHorizontal(LiquidCrystal pantalla, String cadena, int posY, int CASILLAS_PANTALLA)
{
  String varMostrar = "";
  for (int j = 0; j < cadena.length(); j++) // recorre cadena
    {
      char caracter = cadena.charAt(j);
      varMostrar = varMostrar + caracter;

      if (varMostrar.length() > CASILLAS_PANTALLA)
      {
        varMostrar = varMostrar.substring(1);
      }

      pantalla.setCursor(0, posY);
      pantalla.print(varMostrar);
      delay(50);
    }
}
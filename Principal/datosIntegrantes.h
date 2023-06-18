
void pintarCadenaMayorHorizontal(String cadena)
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

      pantalla.setCursor(0, 1);
      pantalla.print(varMostrar);
      delay(50);
    }
}

void mostrarDatosIntegrantes()
{
  // filling teamates
  equipo[0] = "Gustavo Alejandro Giron Arriola - 201900898";
  equipo[1] = "Cristian Aramis Lopez Bautista - 201904042";
  equipo[2] = "Christopher Alexander Acajabon Gudiel - 201404278";
  equipo[3] = "Erick Estuardo Muñoz Escalante - 201602947";
  equipo[4] = "Jose Pablo Ceron Urizar - 201908251";

  for (int i = 0; i < 5; i++) // recorrido integrantes
  {
    pantalla.setCursor(0, 0);
    pantalla.print("--INTEGRANTES--"); // tiempo en mostrar los datos de los integrantes

    varTemp = equipo[i];

    pintarCadenaMayorHorizontal(varTemp);
    delay(500);

    varTemp = "";
    pantalla.clear();
  }
}
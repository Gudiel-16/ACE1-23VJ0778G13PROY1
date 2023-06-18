#include "LedControl.h"
#include <LiquidCrystal.h>
#define INICIALIZAR_TECLADO char tecla = ' '

LedControl ledControl = LedControl(51, 53, 49, 1);
LiquidCrystal pantalla(8, 9, 10, 11, 12, 13);

int ACEPTAR = 2, CANCELAR = 3;
String cadena = "->";

char teclas[4][3] = {{'1', '2', '3'},
                     {'4', '5', '6'},
                     {'7', '8', '9'},
                     {'*', '0', '#'}};

// Estados del Flujo del programa
enum EstadoMenu
{
  DATOS_INTEGRANTES,
  MENU_PRINCIPAL,
  INICIO_SESION,
  REGISTRO,
  MENU_USUARIO,
  MENU_ADMIN,
  INGRESO_DISPOSITIVO,
  RETIRO_DISPOSITIVO,
  CERRAR_SESION,
  ELMINAR_USUARIO,
  VISTA_LOGS,
  ESTADO_SISTEMA
};
EstadoMenu estadoActual = DATOS_INTEGRANTES;

char leerTecla()
{
  for (int i = 22; i <= 24; i++)
  {
    digitalWrite(i, HIGH);
    for (int j = 25; j <= 28; j++)
    {
      if (digitalRead(j) == HIGH)
      {
        digitalWrite(i, LOW);
        return teclas[j - 25][i - 22];
      }
    }
    digitalWrite(i, LOW);
  }
  return ' ';
}

void inicializarMatrizDriver()
{
  ledControl.shutdown(0, false);  // shutdown(# de dispositivo (indice), estado)
  ledControl.setIntensity(0, 15); // setIntensity(# de dispositivo (indice), intensidad de brillo del led de 0 a 15)
  ledControl.clearDisplay(0);     // clearDisplay(# de dispositivo), apaga todos los leds de la pantalla
}

void inicializarPinesTeclado()
{
  // pines laterales del teclado del 25 al 28

  for (int j = 25; j <= 28; j++)
  {
    pinMode(j, INPUT);
  }

  // // pines superiores del teclado del 22 al 24
  for (int j = 22; j <= 24; j++)
  {
    pinMode(j, OUTPUT);
  }
}

void setup()
{
  Serial.begin(9600); // puerto bluetooh
  // Serial1.begin(9600); // puerto virtual terminal
  // Serial3.begin(9600); // puerto arduino secundario
  pantalla.begin(16, 4);
  inicializarMatrizDriver();
  inicializarPinesTeclado();
  pinMode(ACEPTAR, INPUT_PULLUP);
  pinMode(CANCELAR, INPUT_PULLUP);
}

INICIALIZAR_TECLADO;

void loop()
{
  // ---------------------Logica correspondiente al flujo del programa

  // opcion es unicamente para relleno, ni si quiera esta declarada
  switch (estadoActual)
  {
  case DATOS_INTEGRANTES:
    Serial.println("DATOS_INTEGRANTES");
    pantalla.setCursor(0, 0);
    pantalla.print("INTEGRANTES"); // tiempo en mostrar los datos de los integrantes
    pantalla.setCursor(0, 1);
    pantalla.print("INTE 1 2 3 4 5");
    delay(1000);
    estadoActual = MENU_PRINCIPAL;
    pantalla.clear();
    break;
  case MENU_PRINCIPAL:
    Serial.println("MENU_PRINCIPAL");

    pantalla.setCursor(0, 0);
    pantalla.print("MENU-PRINCIPAL");

    tecla = leerTecla();
    delay(165);
    if (tecla == '1')
    { // opcion iniciar sesion
      pantalla.setCursor(0, 1);
      pantalla.print("INIT-USER");
      delay(500);
      estadoActual = INICIO_SESION;
      pantalla.clear();
    }
    else if (tecla == '2')
    { // opcion registrar usuario
      pantalla.setCursor(0, 1);
      pantalla.print("REGISTRO");
      delay(500);
      estadoActual = REGISTRO;
      pantalla.clear();
    }
    break;
  case INICIO_SESION:
    Serial.println("INICIO_SESION");
    pantalla.setCursor(0, 0);
    pantalla.print("INICIANDO...");

    tecla = leerTecla();
    delay(165);
    if (tecla == '4')//------------------------
    { // opcion iniciar sesion
      pantalla.setCursor(0, 1);
      pantalla.print("INIT-USER");
      delay(500);
      estadoActual = MENU_USUARIO;
      pantalla.clear();
    }
    else if (tecla == '5')//----------------
    { // opcion registrar usuario
      pantalla.setCursor(0, 1);
      pantalla.print("INIT-ADMIN");
      delay(500);
      estadoActual = MENU_ADMIN;
      pantalla.clear();
    }
    break;
  case REGISTRO:
    Serial.println("REGISTRAR");
    pantalla.setCursor(0, 0);
    pantalla.print("REGISTRANDO...");
    pantalla.setCursor(0, 1);
    pantalla.print("3<-REGRESAR");
    delay(500);

    tecla = leerTecla();
    delay(165);
    if (tecla == '3')
    { // opcion iniciar sesion
      estadoActual = MENU_PRINCIPAL;
      pantalla.clear();
    }
    break;
  case MENU_USUARIO:
    Serial.println("MENU_USUARIO");
    pantalla.setCursor(0, 0);
    pantalla.print("MENU-USER...");

    tecla = leerTecla();
    delay(165);
    if (tecla == '6')//------------------------
    { 
      pantalla.setCursor(0, 1);
      pantalla.print("INGRESO-CEL");
      delay(500);
      estadoActual = INGRESO_DISPOSITIVO;
      pantalla.clear();
    } else if (tecla == '7'){
      pantalla.setCursor(0, 1);
      pantalla.print("RETIRO-CEL");
      delay(500);
      estadoActual = RETIRO_DISPOSITIVO;
      pantalla.clear();
    } else if (tecla == '8'){
      pantalla.setCursor(0, 1);
      pantalla.print("CERRAR-SESION");
      delay(500);
      estadoActual = CERRAR_SESION;
      pantalla.clear();
    } else if (tecla == '9'){
      pantalla.setCursor(0, 1);
      pantalla.print("DELETE-CUENTA");
      delay(500);
      estadoActual = ELMINAR_USUARIO;
      pantalla.clear();
    }
    
    break;
  case MENU_ADMIN:
    Serial.println("MENU_ADMIN"); // tomar en cuenta que el menu de administrador no tiene opcion par cerrar sesion del ususario
    pantalla.setCursor(0, 0);
    pantalla.print("MENU-ADIMN");

    tecla = leerTecla();
    delay(165);
    if (tecla == '1')//------------------------
    { 
      pantalla.setCursor(0, 1);
      pantalla.print("LOGS-STATE");
      delay(500);
      estadoActual = VISTA_LOGS;
      pantalla.clear();
    } else if (tecla == '2'){
      pantalla.setCursor(0, 1);
      pantalla.print("ESTADO-SIS");
      delay(500);
      estadoActual = ESTADO_SISTEMA;
      pantalla.clear();
    } else if (tecla == '3'){
      pantalla.setCursor(0, 1);
      pantalla.print("CERRAR-SESION");
      delay(500);
      estadoActual = MENU_PRINCIPAL;
      pantalla.clear();
    }
    break;
  case INGRESO_DISPOSITIVO:
    Serial.println("INGRESO_DISPOSITIVO");
    pantalla.setCursor(0, 0);
    pantalla.print("INGRESANDO...");

    tecla = leerTecla();
    delay(165);
    if (tecla == '1')//------------------------
    { 
      pantalla.setCursor(0, 1);
      pantalla.print("INGRESADO...");
      delay(500);
      estadoActual = MENU_USUARIO;
      pantalla.clear();
    }
    break;
  case RETIRO_DISPOSITIVO:
    Serial.println("RETIRO_DISPOSITIVO");
    pantalla.setCursor(0, 0);
    pantalla.print("RETIRO...");

    tecla = leerTecla();
    delay(165);
    if (tecla == '1')//------------------------
    { 
      pantalla.setCursor(0, 1);
      pantalla.print("RETIRADO...");
      delay(500);
      estadoActual = MENU_USUARIO;
      pantalla.clear();
    }
    break;
  case CERRAR_SESION:
    Serial.println("CERRAR_SESION");
    pantalla.setCursor(0, 0);
    pantalla.print("CERRAR-SESION...");

    tecla = leerTecla();
    delay(165);
    if (tecla == '1')//------------------------
    { 
      pantalla.setCursor(0, 1);
      pantalla.print("CLOSE-SESION");
      delay(500);
      estadoActual = MENU_PRINCIPAL;
      pantalla.clear();
    }
    break;
  case ELMINAR_USUARIO:
    Serial.println("ELMINAR_USUARIO");
    pantalla.setCursor(0, 0);
    pantalla.print("ELIMINANDO..");

    tecla = leerTecla();
    delay(165);
    if (tecla == '1')//------------------------
    { 
      pantalla.setCursor(0, 1);
      pantalla.print("ELIMINADO");
      delay(500);
      estadoActual = MENU_PRINCIPAL;
      pantalla.clear();
    }
    break;
  case VISTA_LOGS: // estados menu administrador
    Serial.println("VISTA_LOGS");
    pantalla.setCursor(0, 0);
    pantalla.print("LOGS...");

    tecla = leerTecla();
    delay(165);
    if (tecla == '1')//------------------------
    { 
      pantalla.setCursor(0, 1);
      pantalla.print("VIENDO...");
      delay(500);
      estadoActual = MENU_ADMIN;
      pantalla.clear();
    }
    break;
  case ESTADO_SISTEMA:
    Serial.println("ESTADO_SISTEMA");
    pantalla.setCursor(0, 0);
    pantalla.print("ESTADO-SIS...");

    tecla = leerTecla();
    delay(165);
    if (tecla == '1')//------------------------
    { 
      pantalla.setCursor(0, 1);
      pantalla.print("TESTEANDO..");
      delay(500);
      estadoActual = MENU_ADMIN;
      pantalla.clear();
    }
    break;
  default:
    break;
  }
}

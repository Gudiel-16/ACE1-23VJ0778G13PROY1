#include "LedControl.h"
#include <LiquidCrystal.h>
#include "loginRegistroPanel.h"
#include "funcionalidadesUsuario.h"
//hay que editar
#define LOOP while(true)
#define INICIALIZAR_TECLADO char tecla = ' '
//new
#define LINEA_VACIA "                "
//fin new
//-----prueba
const int NUM_INTEGRANTES = 5;
const int CASILLAS_PANTALLA = 16;
String varTemp = "";
String equipo[NUM_INTEGRANTES];

LedControl ledControl = LedControl(51, 53, 49, 1);
LiquidCrystal pantalla(8, 9, 10, 11, 12, 13);

int ACEPTAR = 2, CANCELAR = 3;
String cadena = "->";

// credenciales usuario activo
char nombreUsuarioActivo[12];
char contraUsuarioActivo[12];

char teclas[4][3] = {{'1', '2', '3'},
                     {'4', '5', '6'},
                     {'7', '8', '9'},
                     {'*', '0', '#'}};

// Estados del Flujo del programa
enum EstadoMenu
{
  ESPERANDO,
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

//INICIO CODIGO BLUE.
void enviarConfirmar(char* cadena) {
    Serial.println(cadena);
    bool hayAlgo = false;
    char recibidos[3];
    LOOP {
        while(Serial.available()) {
	    Serial.readBytes(recibidos, 2);
            hayAlgo = true;
        }
        if (hayAlgo && !Serial.available()) break;
    }
}

void limpiarBuffer() {
    int t0 = millis();
    int t1 = millis();
    LOOP {
        t1 = millis();
        while(Serial.available()) {
	    Serial.read();
        }
        if ((t1 - t0 >= 1000) && !Serial.available()) break;
    }
}

//FIN CODIGO BLUE.

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
  Serial1.begin(9600); // puerto virtual terminal
  Serial3.begin(9600); // puerto arduino secundario
  pantalla.begin(16, 4);
  inicializarMatrizDriver();
  inicializarPinesTeclado();
  pinMode(ACEPTAR, INPUT_PULLUP);
  pinMode(CANCELAR, INPUT_PULLUP);

  actualizarPrimerInicioToLR(); // inicializa valores EEPROM
//  registrarAdmin(); // guarda usuario admin en la EEPROM
}

INICIALIZAR_TECLADO;

//------------------------------------------------------------------

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

  for (int i = 0; i < NUM_INTEGRANTES ; i++) // recorrido integrantes
  {
    pantalla.setCursor(0, 0);
    pantalla.print("--INTEGRANTES--"); // tiempo en mostrar los datos de los integrantes

    varTemp = equipo[i];

    pintarCadenaMayorHorizontal(varTemp);
    delay(300);

    varTemp = "";
    pantalla.clear();
  }
}

//------------------------------------------------------------------
int tipo_espera;
//NEW
char nombre_tempp[11];
char contra_tempp[11];
char numero_tempp[9] ;

boolean entradaAceptada() {
    LOOP {
        if (digitalRead(2) == false) {
	    delay(210);
	    return true;
	}
        if (digitalRead(3) == false) {
	    delay(210);
	    return false;
	}
    }
}

void imprimirAsteriscos(char* cadena) {
    for (; *cadena; cadena++)
        pantalla.write('*');
}

//FIN NEW

void loop()
{
  // ---------------------Logica correspondiente al flujo del programa
  switch (estadoActual)
  {
  case DATOS_INTEGRANTES:
    //int tipo_espera;
    //mostrarDatosIntegrantes();
    delay(800);
    estadoActual = MENU_PRINCIPAL;
    pantalla.clear();
    break;
  //INICIO CODIGO BLUE

  case ESPERANDO: {
	    limpiarBuffer();
	    pantalla.clear();
	    pantalla.print(" Esperando  una ");
	    pantalla.setCursor(0, 1);
	    pantalla.print("   conexion...  ");
	    bool alguienPorAhi = false;
            char recibidos[3];
	    LOOP {
	        while(Serial.available()) {
		    Serial.readBytes(recibidos, 2);
		    alguienPorAhi = true;
		}
		if (alguienPorAhi && !Serial.available()) break;
	    }
      if(tipo_espera == 0){
        
        //estadoActual = INICIO_SESION;
        //pantalla.clear();
        //NEW

            memset(nombre_tempp, 0, 11);    
            memset(contra_tempp, 0, 11);    
            memset(numero_tempp, 0,  9);    
            struct usuario nuevo_usuario;
	    LOOP {
	        limpiarBuffer();
	        enviarConfirmar("Nombre:");
            	memset(nombre_tempp, 0, 11);    
                pantalla.clear();
                pantalla.print("L O G I N");
                pantalla.setCursor(0, 1);
                pantalla.print(" - NOMBRE:");
                pantalla.setCursor(0, 2);
                // OBTENER CADENA DE APLICACIÓN -- Nombre
                bool seEnvioAlgo = false;
                int indiceNombre = 0;
                long int t0 = millis();
                long int t1 = millis();
	        limpiarBuffer();
                LOOP {
                    // SI YA SE ENVIO ALGO DESDE LA APLICACION
                    while (Serial.available()) {
                        seEnvioAlgo = true;
                    //   RECIBIRLO
                        nombre_tempp[indiceNombre++] = Serial.read();
                    }
                    // CONTROLAR CUANTO HA PASADO DESDE QUE COME...
                    if (seEnvioAlgo) {
                        t1 = millis();
                        if (t1 - t0 >= 500) break;
                    } else {
                        t0 = millis();
                        t1 = millis();
                    }
                }
                pantalla.print(nombre_tempp);
                pantalla.setCursor(0, 3);
                pantalla.print("Correcto?       ");
                delay(500);
    	        if (entradaAceptada()){               
                //estadoActual = MENU_PRINCIPAL;
                break;
              }
                     
		pantalla.setCursor(0, 2);
		pantalla.print(LINEA_VACIA);
		pantalla.setCursor(0, 3);
		pantalla.print(LINEA_VACIA);
            }


            LOOP {
	        limpiarBuffer();
	        enviarConfirmar("Contraseña:");
            	memset(contra_tempp, 0, 11);    
                pantalla.clear();
                pantalla.print("L O G I N");
                pantalla.setCursor(0, 1);
                pantalla.print(" - Contras:");
                pantalla.setCursor(0, 2);
                // OBTENER CADENA DE APLICACIÓN -- Nombre
                bool seEnvioAlgo = false;
                int indiceContra = 0;
                long int t0 = millis();
                long int t1 = millis();
	        limpiarBuffer();
                LOOP {
                    // SI YA SE ENVIO ALGO DESDE LA APLICACION
                    while (Serial.available()) {
                        seEnvioAlgo = true;
                    //   RECIBIRLO
                        contra_tempp[indiceContra++] = Serial.read();
                    }
                    // CONTROLAR CUANTO HA PASADO DESDE QUE COME...
                    if (seEnvioAlgo) {
                        t1 = millis();
                        if (t1 - t0 >= 500) break;
                    } else {
                        t0 = millis();
                        t1 = millis();
                    }
                }
		imprimirAsteriscos(contra_tempp);
                pantalla.setCursor(0, 3);
                pantalla.print("Correcto?       ");
                delay(500);
    	        if (entradaAceptada()) break;
		pantalla.setCursor(0, 2);
		pantalla.print(LINEA_VACIA);
		pantalla.setCursor(0, 3);
		pantalla.print(LINEA_VACIA);
            }

      //FIN NEW
        
      }
      if(tipo_espera == 1){
        /*
        estadoActual = REGISTRO;
        pantalla.clear();*/
        //NEW


            memset(nombre_tempp, 0, 11);    
            memset(contra_tempp, 0, 11);    
            memset(numero_tempp, 0,  9);    
            struct usuario nuevo_usuario;
	    LOOP {
	        limpiarBuffer();
	        enviarConfirmar("Nombre:");
            	memset(nombre_tempp, 0, 11);    
                pantalla.clear();
                pantalla.print("R E G I S T R O");
                pantalla.setCursor(0, 1);
                pantalla.print(" - NOMBRE:");
                pantalla.setCursor(0, 2);
                // OBTENER CADENA DE APLICACIÓN -- Nombre
                bool seEnvioAlgo = false;
                int indiceNombre = 0;
                long int t0 = millis();
                long int t1 = millis();
	        limpiarBuffer();
                LOOP {
                    // SI YA SE ENVIO ALGO DESDE LA APLICACION
                    while (Serial.available()) {
                        seEnvioAlgo = true;
                    //   RECIBIRLO
                        nombre_tempp[indiceNombre++] = Serial.read();
                    }
                    // CONTROLAR CUANTO HA PASADO DESDE QUE COME...
                    if (seEnvioAlgo) {
                        t1 = millis();
                        if (t1 - t0 >= 500) break;
                    } else {
                        t0 = millis();
                        t1 = millis();
                    }
                }
                pantalla.print(nombre_tempp);
                pantalla.setCursor(0, 3);
                pantalla.print("Correcto?       ");
                delay(500);
    	        if (entradaAceptada()) break;
		pantalla.setCursor(0, 2);
		pantalla.print(LINEA_VACIA);
		pantalla.setCursor(0, 3);
		pantalla.print(LINEA_VACIA);
            }
	    LOOP {
	        limpiarBuffer();
	        enviarConfirmar("Celular:");
            	memset(numero_tempp, 0, 9);    
                pantalla.clear();
                pantalla.print("R E G I S T R O");
                pantalla.setCursor(0, 1);
                pantalla.print(" - Celular:");
                pantalla.setCursor(0, 2);
                // OBTENER CADENA DE APLICACIÓN -- Nombre
                bool seEnvioAlgo = false;
                int indiceNumero = 0;
                long int t0 = millis();
                long int t1 = millis();
	        limpiarBuffer();
                LOOP {
                    // SI YA SE ENVIO ALGO DESDE LA APLICACION
                    while (Serial.available()) {
                        seEnvioAlgo = true;
                    //   RECIBIRLO
                        numero_tempp[indiceNumero++] = Serial.read();
                    }
                    // CONTROLAR CUANTO HA PASADO DESDE QUE COME...
                    if (seEnvioAlgo) {
                        t1 = millis();
                        if (t1 - t0 >= 500) break;
                    } else {
                        t0 = millis();
                        t1 = millis();
                    }
                }
                pantalla.print(numero_tempp);
                pantalla.setCursor(0, 3);
                pantalla.print("Correcto?       ");
                delay(500);
    	        if (entradaAceptada()) break;
		pantalla.setCursor(0, 2);
		pantalla.print(LINEA_VACIA);
		pantalla.setCursor(0, 3);
		pantalla.print(LINEA_VACIA);
            }
	    LOOP {
	        limpiarBuffer();
	        enviarConfirmar("Contras:");
            	memset(contra_tempp, 0, 11);    
                pantalla.clear();
                pantalla.print("R E G I S T R O");
                pantalla.setCursor(0, 1);
                pantalla.print(" - Contras:");
                pantalla.setCursor(0, 2);
                // OBTENER CADENA DE APLICACIÓN -- Nombre
                bool seEnvioAlgo = false;
                int indiceContra = 0;
                long int t0 = millis();
                long int t1 = millis();
	        limpiarBuffer();
                LOOP {
                    // SI YA SE ENVIO ALGO DESDE LA APLICACION
                    while (Serial.available()) {
                        seEnvioAlgo = true;
                    //   RECIBIRLO
                        contra_tempp[indiceContra++] = Serial.read();
                    }
                    // CONTROLAR CUANTO HA PASADO DESDE QUE COME...
                    if (seEnvioAlgo) {
                        t1 = millis();
                        if (t1 - t0 >= 500) break;
                    } else {
                        t0 = millis();
                        t1 = millis();
                    }
                }
		imprimirAsteriscos(contra_tempp);
                pantalla.setCursor(0, 3);
                pantalla.print("Correcto?       ");
                delay(500);
    	        if (entradaAceptada()) break;
		pantalla.setCursor(0, 2);
		pantalla.print(LINEA_VACIA);
		pantalla.setCursor(0, 3);
		pantalla.print(LINEA_VACIA);
            }

      }
	    estadoActual = MENU_PRINCIPAL;
	    break;
        }

  //FIN CODIGO BLUE
  case MENU_PRINCIPAL:
    pantalla.clear();
    pantalla.setCursor(0, 0);
    pantalla.print("MENU-PRINCIPAL");

    tecla = leerTecla();
    delay(165);
    if (tecla == '1')             // 1 Iniciar Sesion
    { // opcion iniciar sesion
      pantalla.setCursor(0, 1);
      pantalla.print("INICIANDO-SESION");
      delay(500);
      estadoActual = INICIO_SESION;
      pantalla.clear();
    }
    else if (tecla == '2')      // 2 Registrar Usuario
    { // opcion registrar usuario
      pantalla.setCursor(0, 1);
      pantalla.print("ESTADO-REGISTRO");
      delay(500);
      estadoActual = REGISTRO;
      pantalla.clear();
    }
    break;
  case INICIO_SESION:
    pantalla.setCursor(0, 0);
    pantalla.print("METODO-INICIO");
    pantalla.setCursor(0, 1);
    pantalla.print("1-PANEL 2-APP");
    delay(500);

    tecla = leerTecla();
    delay(165);
    if (tecla == '1')       //1 INICIO SESION POR PANEL
    { 
      //FUNCIONALIDAD DE INICIO SESION POR PANEL ()
      pantalla.clear();
      pantalla.setCursor(0, 0);
      memset(nombreUsuarioActivo, 0, 12);
      memset(contraUsuarioActivo, 0, 12);  
      if(loginTeclado(pantalla, ledControl)){
        // guardamos credenciales
        memcpy(nombreUsuarioActivo, nombre_temp, 12);
        memcpy(contraUsuarioActivo, contra_temp, 12);
        if(tipoRol(nombreUsuarioActivo)){
          estadoActual = MENU_ADMIN;
        }else{
          estadoActual = MENU_USUARIO;
        }
      }else{
        estadoActual = DATOS_INTEGRANTES; // fallo de 2 intentos en login
      }
      delay(500);
      pantalla.clear();
    } else if (tecla == '2') //2 INICIO SESION POR APP
    { 
      //FUNCIONALIDAD DE INICIO SESION POR APP
      pantalla.clear();
      pantalla.setCursor(0, 0);
      pantalla.print("LOGINxAPP");
      Serial.print("LOGINxAPP");
      delay(1000);
      estadoActual = ESPERANDO;
      tipo_espera = 0;
      pantalla.clear();

    } 
    break;
  case REGISTRO:
    pantalla.setCursor(0, 0);
    pantalla.print("METODO-REGISTRO");
    pantalla.setCursor(0, 1);
    pantalla.print("1-PANEL 2-APP");
    delay(500);

    tecla = leerTecla();
    delay(165);
    if (tecla == '1')       //1 REGISTRO POR PANEL
    { 
      //FUNCIONALIDAD DE REGISTRO POR PANEL ()
      pantalla.clear();
      pantalla.setCursor(0, 0);
      if(registroTeclado(pantalla, ledControl)){
        estadoActual = MENU_PRINCIPAL;
      }
      delay(500);
      pantalla.clear();
    } else if (tecla == '2') //2 REGISTRO POR APP
    { 
      //FUNCIONALIDAD DE REGISTRO POR APP
     /* pantalla.clear();
      pantalla.setCursor(0, 0);
      pantalla.print("RESITROxAAP");
      delay(500);
      pantalla.clear();*/

      pantalla.clear();
      pantalla.setCursor(0, 0);
      pantalla.print("REGISTROxAPP");
      Serial.print("REGISTROxAPP");
      delay(500);
      estadoActual = ESPERANDO;
      tipo_espera = 1;
      pantalla.clear();

    } else if (tecla == '3') //3 REGRESAR
    { 
      //FUNCIONALIDAD DE REGRESAR
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
    if (tecla == '1') //------------------------1 INGRESO-CEL
    {
      pantalla.setCursor(0, 1);
      pantalla.print("INGRESO-CEL");
      delay(500);
      estadoActual = INGRESO_DISPOSITIVO;
      pantalla.clear();
    }
    else if (tecla == '2') //----------------2 RETIRO-CEL
    {
      pantalla.setCursor(0, 1);
      pantalla.print("RETIRO-CEL");

      delay(500);
      estadoActual = RETIRO_DISPOSITIVO;
      pantalla.clear();
    }
    else if (tecla == '3') //----------------3 CERRAR-SESION
    {
      pantalla.setCursor(0, 1);
      pantalla.print("CERRAR-SESION");
      delay(500);
      estadoActual = CERRAR_SESION;
      pantalla.clear();
    }
    else if (tecla == '4') //----------------4 ELIMINAR-USUARIO
    {
      pantalla.setCursor(0, 1);
      pantalla.print("DELETE-CUENTA");
      delay(500);
      estadoActual = ELMINAR_USUARIO;
      pantalla.clear();
    }

    break;
  case MENU_ADMIN: // tomar en cuenta que el menu de administrador no tiene opcion par cerrar sesion del ususario
    pantalla.setCursor(0, 0);
    pantalla.print("MENU-ADIMN");

    tecla = leerTecla();
    delay(165);
    if (tecla == '1') //------------------------
    {
      pantalla.setCursor(0, 1);
      pantalla.print("LOGS-STATE");
      delay(500);
      estadoActual = VISTA_LOGS;
      pantalla.clear();
    }
    else if (tecla == '2')
    {
      pantalla.setCursor(0, 1);
      pantalla.print("ESTADO-SIS");
      delay(500);
      estadoActual = ESTADO_SISTEMA;
      pantalla.clear();
    }
    else if (tecla == '3')
    {
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
    if (tecla == '1') //------------------------
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
    if (tecla == '1') //------------------------
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
    if (tecla == '1') //------------------------
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
    if (tecla == '1') //------------------------
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
    if (tecla == '1') //------------------------
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
    if (tecla == '1') //------------------------
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

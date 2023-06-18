#include "matrizCompartimento.h"

//////////////////////////////////////////////////////////////  PANEL DE CONTROL //////////////////////////////////////////////////////////////

int indiceActualIngresarToCompartimento = 0;
int posicionActualCaracterToCompartimento = 0;

char teclaToCompartimento = ' ';

char teclasToCompartimento[4][3] = { { '1', '2', '3' },
                      { '4', '5', '6' },
                      { '7', '8', '9' },
                      { '*', '0', '#' } };

byte caracteresTecladoLedToCompartimento[30][8] {
    {B00000000, B00111100, B01000010, B01111110, B01000010, B01000010, B01000010, B00000000}, // A
    {B00000000, B01111100, B01000010, B01111100, B01111100, B01000010, B01111100, B00000000}, // B
    {B00000000, B01111110, B01000000, B01000000, B01000000, B01000000, B01111110, B00000000}, // C
    {B00000000, B01111000, B01000100, B01000010, B01000010, B01000100, B01111000, B00000000}, // D
    {B00000000, B01111110, B01000000, B01111110, B01000000, B01000000, B01111110, B00000000}, // E
    {B00000000, B01111110, B01000000, B01111110, B01000000, B01000000, B01000000, B00000000}, // F
    {B00000000, B01111110, B01000000, B01000000, B01001110, B01000010, B01111110, B00000000}, // G
    {B00000000, B01000010, B01000010, B01111110, B01000010, B01000010, B01000010, B00000000}, // H
    {B00000000, B01111110, B00011000, B00011000, B00011000, B00011000, B01111110, B00000000}, // I
    {B00000000, B01111110, B00001000, B00001000, B00001000, B01001000, B00111000, B00000000}, // J
    {B00000000, B01100110, B01101000, B01110000, B01111000, B01100100, B01100110, B00000000}, // K
    {B00000000, B01000000, B01000000, B01000000, B01000000, B01000000, B01111110, B00000000}, // L
    {B00000000, B01100110, B01011010, B01011010, B01000010, B01000010, B01000010, B00000000}, // M
    {B00000000, B01000010, B01100010, B01010010, B01001010, B01000110, B01000010, B00000000}, // N
    {B00000000, B01111110, B01000010, B01000010, B01000010, B01000010, B01111110, B00000000}, // O
    {B00000000, B01111110, B01000010, B01111110, B01000000, B01000000, B01000000, B00000000}, // P
    {B00000000, B01111110, B01000010, B01000010, B01001010, B01000110, B01111110, B00000001}, // Q
    {B00000000, B01111110, B01000010, B01111110, B01010000, B01001000, B01000110, B00000000}, // R
    {B00000000, B01111110, B01000000, B01111110, B00000010, B00000010, B01111110, B00000000}, // S
    {B00000000, B01111110, B00011000, B00011000, B00011000, B00011000, B00011000, B00000000}, // T
    {B00000000, B01000010, B01000010, B01000010, B01000010, B01000010, B01111110, B00000000}, // U
    {B00000000, B01000100, B01000100, B01000100, B01000100, B00101000, B00010000, B00000000}, // V
    {B00000000, B01000010, B01000010, B01000010, B01011010, B01011010, B01100110, B00000000}, // W
    {B00000000, B01000010, B00100100, B00011000, B00011000, B00100100, B01000010, B00000000}, // X
    {B00000000, B01000010, B00100100, B00011000, B00011000, B00011000, B00011000, B00000000}, // Y
    {B00000000, B01111110, B00000100, B00001000, B00010000, B00100000, B01111110, B00000000}, // Z
    {B00000000, B00011000, B00100100, B00100100, B00100100, B00100100, B00011000, B00000000}, // 0
    {B00000000, B00100100, B01111110, B00100100, B00100100, B01111110, B00100100, B00000000}, // #
    {B00011000, B01111110, B01011000, B01111110, B00011010, B00011010, B01111110, B00011000}, // $
    {B00000000, B00011000, B00011000, B00011000, B00011000, B00000000, B00011000, B00000000}  // !
};

char leerTeclaToCompartimento() {
    for (int i = 22; i <= 24; i++) { // pines superiores
        digitalWrite(i, HIGH);
        for (int j = 25; j <= 28; j++) { // pines laterales
            if (digitalRead(j) == HIGH) {
                digitalWrite(i, LOW);
                return teclasToLR[j-25][i-22];
            }
        }
        digitalWrite(i, LOW);
    }
    return ' ';
}

void mostrarCaracterToCompartimento(int posicionMostrar, LedControl ledControl)
{
  for (int i = 0; i < 8; i++)
  {
    ledControl.setRow(0, i, caracteresTecladoLedToLR[posicionMostrar][i]);
  }
}

void funcionesTeclaToCompartimento(char teclaPresionada, LedControl ledControl, char dondeGuardar) {
   
  switch(teclaPresionada){
    case '1': {
      if(dondeGuardar == 'n'){
        nombre_temp[indiceActualIngresarToCompartimento++] = '1';
      } else if(dondeGuardar == 't'){
        telefono_temp[indiceActualIngresarToCompartimento++] = '1';
      } else {
        int indiceAcutalC = indiceActualIngresarToCompartimento;
        contra_temp[indiceAcutalC] = '1';
        contra_asteriscos[indiceAcutalC] = '*';
        indiceActualIngresarToCompartimento++;
      }
      break;
    }
    case '2': {
      if(dondeGuardar == 'n'){
        nombre_temp[indiceActualIngresarToCompartimento++] = '2';
      } else if(dondeGuardar == 't'){
        telefono_temp[indiceActualIngresarToCompartimento++] = '2';
      } else {
        int indiceAcutalC = indiceActualIngresarToCompartimento;
        contra_temp[indiceAcutalC] = '2';
        contra_asteriscos[indiceAcutalC] = '*';
        indiceActualIngresarToCompartimento++;
      }
      break;
    }
    case '3': {
      if(dondeGuardar == 'n'){
        nombre_temp[indiceActualIngresarToCompartimento++] = '3';
      } else if(dondeGuardar == 't'){
        telefono_temp[indiceActualIngresarToCompartimento++] = '3';
      } else {
        int indiceAcutalC = indiceActualIngresarToCompartimento;
        contra_temp[indiceAcutalC] = '3';
        contra_asteriscos[indiceAcutalC] = '*';
        indiceActualIngresarToCompartimento++;
      }
      break;
    }
    case '4': {
      if(dondeGuardar == 'n'){
        nombre_temp[indiceActualIngresarToCompartimento++] = '4';
      } else if(dondeGuardar == 't'){
        telefono_temp[indiceActualIngresarToCompartimento++] = '4';
      } else {
        int indiceAcutalC = indiceActualIngresarToCompartimento;
        contra_temp[indiceAcutalC] = '4';
        contra_asteriscos[indiceAcutalC] = '*';
        indiceActualIngresarToCompartimento++;
      }
      break;
    }
    case '5': {
      if(dondeGuardar == 'n'){
        nombre_temp[indiceActualIngresarToCompartimento++] = '5';
      } else if(dondeGuardar == 't'){
        telefono_temp[indiceActualIngresarToCompartimento++] = '5';
      } else {
        int indiceAcutalC = indiceActualIngresarToCompartimento;
        contra_temp[indiceAcutalC] = '5';
        contra_asteriscos[indiceAcutalC] = '*';
        indiceActualIngresarToCompartimento++;
      }
      break;
    }
    case '6': {
      if(dondeGuardar == 'n'){
        nombre_temp[indiceActualIngresarToCompartimento++] = '6';
      } else if(dondeGuardar == 't'){
        telefono_temp[indiceActualIngresarToCompartimento++] = '6';
      } else {
        int indiceAcutalC = indiceActualIngresarToCompartimento;
        contra_temp[indiceAcutalC] = '6';
        contra_asteriscos[indiceAcutalC] = '*';
        indiceActualIngresarToCompartimento++;
      }
      break;
    }
    case '7': {
      if(dondeGuardar == 'n'){
        nombre_temp[indiceActualIngresarToCompartimento++] = '7';
      } else if(dondeGuardar == 't'){
        telefono_temp[indiceActualIngresarToCompartimento++] = '7';
      } else {
        int indiceAcutalC = indiceActualIngresarToCompartimento;
        contra_temp[indiceAcutalC] = '7';
        contra_asteriscos[indiceAcutalC] = '*';
        indiceActualIngresarToCompartimento++;
      }
      break;
    }
    case '8': {
      if(dondeGuardar == 'n'){
        nombre_temp[indiceActualIngresarToCompartimento++] = '8';
      } else if(dondeGuardar == 't'){
        telefono_temp[indiceActualIngresarToCompartimento++] = '8';
      } else {
        int indiceAcutalC = indiceActualIngresarToCompartimento;
        contra_temp[indiceAcutalC] = '8';
        contra_asteriscos[indiceAcutalC] = '*';
        indiceActualIngresarToCompartimento++;
      }
      break;
    }
    case '9': {
      if(dondeGuardar == 'n'){
        nombre_temp[indiceActualIngresarToCompartimento++] = '9';
      } else if(dondeGuardar == 't'){
        telefono_temp[indiceActualIngresarToCompartimento++] = '9';
      } else {
        int indiceAcutalC = indiceActualIngresarToCompartimento;
        contra_temp[indiceAcutalC] = '9';
        contra_asteriscos[indiceAcutalC] = '*';
        indiceActualIngresarToCompartimento++;
      }
      break;
    }
    case '0': {
      if(dondeGuardar == 'n'){
        nombre_temp[indiceActualIngresarToCompartimento++] = caracteresTecladoPantalla[posicionActualCaracterToCompartimento];
      } else if(dondeGuardar == 't'){
        telefono_temp[indiceActualIngresarToCompartimento++] = caracteresTecladoPantalla[posicionActualCaracterToCompartimento];
      } else {
        int indiceAcutalC = indiceActualIngresarToCompartimento;
        contra_temp[indiceAcutalC] = caracteresTecladoPantalla[posicionActualCaracterToCompartimento];
        contra_asteriscos[indiceAcutalC] = '*';
        indiceActualIngresarToCompartimento++;
      }
      break;
    }
    case '*': {
      posicionActualCaracterToCompartimento--;
      if(posicionActualCaracterToCompartimento < 0){
        posicionActualCaracterToCompartimento = 29;
      }
      mostrarCaracterToCompartimento(posicionActualCaracterToCompartimento, ledControl);
//      Serial1.println(posicionActualCaracterToCompartimento);
      break;
    }
    case '#': {
      posicionActualCaracterToCompartimento++;
      if(posicionActualCaracterToCompartimento > 29){
        posicionActualCaracterToCompartimento = 0;
      }
      mostrarCaracterToCompartimento(posicionActualCaracterToCompartimento, ledControl);
//      Serial1.println(posicionActualCaracterToCompartimento);
      break;
    }
  }
}

//////////////////////////////////////////////////////////////  COMPARTIMENTO //////////////////////////////////////////////////////////////

char respuestaSensorTemperatura[2];
char respuestaSensorBoton[9];
int compartimentoLibre = 0;
int intentosPassword = 0;

int sensorTemperatura1 = 0;
int sensorTemperatura2 = 0;
int sensorTemperatura3 = 0;
int sensorTemperatura4 = 0;
int sensorTemperatura5 = 0;
int sensorTemperatura6 = 0;
int sensorTemperatura7 = 0;
int sensorTemperatura8 = 0;
int sensorTemperatura9 = 0;

char contra_tempoToCompartiemnto[13];
char contra_asteriscosToCompartiemnto[13];

void updateLecturaSensorTemperatura(char numeroSensor, int temperatura){
  switch(numeroSensor){
    case '1': {
      sensorTemperatura1 = temperatura;
      break;
    }
    case '2': {
      sensorTemperatura2 = temperatura;
      break;
    }
    case '3': {
      sensorTemperatura3 = temperatura;
      break;
    }
    case '4': {
      sensorTemperatura4 = temperatura;
      break;
    }
    case '5': {
      sensorTemperatura5 = temperatura;
      break;
    }
    case '6': {
      sensorTemperatura6 = temperatura;
      break;
    }
    case '7': {
      sensorTemperatura7 = temperatura;
      break;
    }
    case '8': {
      sensorTemperatura8 = temperatura;
      break;
    }
    case '9': {
      sensorTemperatura9 = temperatura;
      break;
    }
  }
}

void verificarTemperatura(char valor1, char valor2, char sensor){

  bool tempLeidaCorrecta = false;
  bool tempLeidaCorrecta2 = false;
  
  if(valor1 == '0' || valor1 == '1' || valor1 == '2' || valor1 == '3' || valor1 == '4' ||
    valor1 == '5' || valor1 == '6' || valor1 == '7' || valor1 == '8' || valor1 == '9'){
    tempLeidaCorrecta = true;
    //Serial1.println(valor1);
  }

  if(valor2 == '0' || valor2 == '1' || valor2 == '2' || valor2 == '3' || valor2 == '4' ||
    valor2 == '5' || valor2 == '6' || valor2 == '7' || valor2 == '8' || valor2 == '9'){
    tempLeidaCorrecta2 = true;
    //Serial1.println(valor2);
  }

  if(tempLeidaCorrecta == true && tempLeidaCorrecta2 == true){ // numero >= 10
    // formar numero leido
    String numeroLeido = "";
    numeroLeido.concat(valor1);
    numeroLeido.concat(valor2);
    
    int numeroReal = String(numeroLeido).toInt();
    updateLecturaSensorTemperatura(sensor, numeroReal);

//    Serial1.println(valor1);
//    Serial1.println(valor2);
//    Serial1.println(numeroReal);
    
  }
}

void lecturaSensores(LedControl ledControl){

  Serial3.print("S1");
  Serial3.readBytes(respuestaSensorTemperatura, 2);
  verificarTemperatura(respuestaSensorTemperatura[0], respuestaSensorTemperatura[1], '1');
  
  Serial3.print("S2");
  Serial3.readBytes(respuestaSensorTemperatura, 2);
  verificarTemperatura(respuestaSensorTemperatura[0], respuestaSensorTemperatura[1], '2');

  Serial3.print("S3");
  Serial3.readBytes(respuestaSensorTemperatura, 2);
  verificarTemperatura(respuestaSensorTemperatura[0], respuestaSensorTemperatura[1], '3');

  Serial3.print("S4");
  Serial3.readBytes(respuestaSensorTemperatura, 2);
  verificarTemperatura(respuestaSensorTemperatura[0], respuestaSensorTemperatura[1], '4');

  Serial3.print("S5");
  Serial3.readBytes(respuestaSensorTemperatura, 2);
  verificarTemperatura(respuestaSensorTemperatura[0], respuestaSensorTemperatura[1], '5');

  Serial3.print("S6");
  Serial3.readBytes(respuestaSensorTemperatura, 2);
  verificarTemperatura(respuestaSensorTemperatura[0], respuestaSensorTemperatura[1], '6');

  Serial3.print("S7");
  Serial3.readBytes(respuestaSensorTemperatura, 2);
  verificarTemperatura(respuestaSensorTemperatura[0], respuestaSensorTemperatura[1], '7');

  Serial3.print("S8");
  Serial3.readBytes(respuestaSensorTemperatura, 2);
  verificarTemperatura(respuestaSensorTemperatura[0], respuestaSensorTemperatura[1], '8');

  Serial3.print("S9");
  Serial3.readBytes(respuestaSensorTemperatura, 2);
  verificarTemperatura(respuestaSensorTemperatura[0], respuestaSensorTemperatura[1], '9');

  Serial3.print("Bx"); // lectura de botones
  Serial3.readBytes(respuestaSensorBoton, 9);
  updateMatrizCompartimento(respuestaSensorBoton);
  mostrarMatrizCompartimentos(ledControl);
  
  delay(1);
}

int buscarCompartimentoLibre(){
  for (int i = 0; i < 9; i++){
    if(respuestaSensorBoton[i] == '0'){ // compartimento en uso
      return i+1;
    }
  }

  return -1; // no encontrado
}

bool verificarEstadoCompartimentoIngresado(int comp){
  if(respuestaSensorBoton[comp-1] == '1'){ // compartimento en uso
    return true;
  }
  return false;
}

int temperaturaAcutalCompartimento(int comp){
  int valorARetornar = 0;
  switch(comp){
    case 1: {
      valorARetornar = sensorTemperatura1;
      break;
    }
    case 2: {
      valorARetornar = sensorTemperatura2;
      break;
    }
    case 3: {
      valorARetornar = sensorTemperatura3;
      break;
    }
    case 4: {
      valorARetornar = sensorTemperatura4;
      break;
    }
    case 5: {
      valorARetornar = sensorTemperatura5;
      break;
    }
    case 6: {
      valorARetornar = sensorTemperatura6;
      break;
    }
    case 7: {
      valorARetornar = sensorTemperatura7;
      break;
    }
    case 8: {
      valorARetornar = sensorTemperatura8;
      break;
    }
    case 9: {
      valorARetornar = sensorTemperatura9;
      break;
    }
  }

  return valorARetornar;
}

void ingresarCelular(LiquidCrystal pantalla, LedControl ledControl){

  lecturaSensores(ledControl);
  
  compartimentoLibre = buscarCompartimentoLibre();
  if(compartimentoLibre == -1){
    pantalla.clear();
    pantalla.print("INGRESO CEL");
    pantalla.setCursor(0, 1);
    pantalla.print(" - Lleno :c ");
    return;
  }

  while(true){

    lecturaSensores(ledControl);
    
    pantalla.clear();
    pantalla.print("INGRESO CEL");
    pantalla.setCursor(0, 1);
    pantalla.print(" - Libre: ");
    pantalla.print(compartimentoLibre);

    int temperaturaAcutalComp = temperaturaAcutalCompartimento(compartimentoLibre);
    if(temperaturaAcutalComp > 30){
      pantalla.setCursor(0, 2);
      pantalla.print("Temperatura alta...");
    }else{
      pantalla.setCursor(0, 2);
      pantalla.print("Coloque cel...");
      if(verificarEstadoCompartimentoIngresado(compartimentoLibre)){ // ACEPTAR
        Serial1.println("CELULAR COLOCADO");
        delay(50);
        break;
      }      
    }    
    delay(150);
  }

  intentosPassword = 0;
  indiceActualIngresarToCompartimento = 0;
  posicionActualCaracterToCompartimento = 0;
  memset(contra_tempoToCompartiemnto, 0, 13);   
  memset(contra_asteriscosToCompartiemnto, 0, 13);
  mostrarCaracterToCompartimento(posicionActualCaracterToCompartimento, ledControl);   

  while(true){
    pantalla.clear();
    pantalla.print("INGRESO CEL");
    pantalla.setCursor(0, 1);
    pantalla.print(" - PASSWORD:");
    pantalla.setCursor(0, 2);
    pantalla.print(contra_asteriscosToCompartiemnto);
    
    teclaToCompartimento = leerTeclaToCompartimento();
    if (teclaToLR != ' ') {
      Serial1.println(teclaToLR);
      funcionesTeclaToCompartimento(teclaToLR, ledControl, 'c');
      delay(75);
    }
    
    if(digitalRead(2) == LOW){ // ACEPTAR
//      if(verificarLogin(nombre_temp, contra_temp)){
//        // SUCCESS -> GUARDAR EN MEMORIA -> compartimentoLibre
//        Serial1.println("CELULAR GUARDADO");
//      }else{
//        memset(, 0, tamanioNombreTemp);
//        memset(contra_tempoToCompartiemnto, 0, 13);   
//        memset(contra_asteriscosToCompartiemnto, 0, 13);
//        indiceActualIngresarToCompartimento = 0;
//        intentosPassword++;
//        if(intentosPassword == 2){
//          intentosPassword = 0;
//          delay(10000); // bloquear por 10 segundos
//          // regresar a secuancia inicial
//          Serial1.println("REGRESAR A SECUENCIA INICIAL");
//        }
//        Serial1.println("USUARIO NO EXISTE");
//      }
    }

    if(digitalRead(3) == LOW){ // CANCELAR
      Serial1.println("CANCELAR");
      memset(contra_tempoToCompartiemnto, 0, 13);  
      memset(contra_asteriscosToCompartiemnto, 0, 13);
      indiceActualIngresarToCompartimento = 0;
      delay(50);
    }
    
    delay(150);
  }

}

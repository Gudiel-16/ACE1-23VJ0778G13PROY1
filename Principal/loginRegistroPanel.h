#include "LedControl.h"
#include <LiquidCrystal.h>
#include "panelOperacion.h"
#include "memoria.h"

<<<<<<< Updated upstream
// NOTAS:
// PARA PROBAR REGISTRO Y LOGIN, importar en el .ino: 
//    #include "loginRegistroPanel.h"
// LLAMAR LOS METODOS y pasarles como parametro la variable 'pantalla' y 'ledControl', ej:  
      // registroTeclado(pantalla, ledControl); 
      // loginTeclado(pantalla, ledControl);
=======
>>>>>>> Stashed changes

int tamanioNombreTemp = 13; // 'n'
int tamanioTelefonoTemp = 9; // 't'
int tamanioContraTemp = 13; // 'c'

char nombre_temp[13];
char telefono_temp[9];
char contra_temp[13];
char contra_asteriscos[13];

int posicionActualCaracter = 0;
int indiceActualIngresar = 0;
int intentosIniciarSesion = 0;

char caracteresTecladoPantalla[30] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '#', '$', '!'};
char numerosVal[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}; // para validar contra


void funcionesTecla(char teclaPresionada, LedControl ledControl, char dondeGuardar) {
   
  switch(teclaPresionada){
    case '1': {
      if(dondeGuardar == 'n'){
        nombre_temp[indiceActualIngresar++] = '1';
      } else if(dondeGuardar == 't'){
        telefono_temp[indiceActualIngresar++] = '1';
      } else {
        int indiceAcutalC = indiceActualIngresar;
        contra_temp[indiceAcutalC] = '1';
        contra_asteriscos[indiceAcutalC] = '*';
        indiceActualIngresar++;
      }
      break;
    }
    case '2': {
      if(dondeGuardar == 'n'){
        nombre_temp[indiceActualIngresar++] = '2';
      } else if(dondeGuardar == 't'){
        telefono_temp[indiceActualIngresar++] = '2';
      } else {
        int indiceAcutalC = indiceActualIngresar;
        contra_temp[indiceAcutalC] = '2';
        contra_asteriscos[indiceAcutalC] = '*';
        indiceActualIngresar++;
      }
      break;
    }
    case '3': {
      if(dondeGuardar == 'n'){
        nombre_temp[indiceActualIngresar++] = '3';
      } else if(dondeGuardar == 't'){
        telefono_temp[indiceActualIngresar++] = '3';
      } else {
        int indiceAcutalC = indiceActualIngresar;
        contra_temp[indiceAcutalC] = '3';
        contra_asteriscos[indiceAcutalC] = '*';
        indiceActualIngresar++;
      }
      break;
    }
    case '4': {
      if(dondeGuardar == 'n'){
        nombre_temp[indiceActualIngresar++] = '4';
      } else if(dondeGuardar == 't'){
        telefono_temp[indiceActualIngresar++] = '4';
      } else {
        int indiceAcutalC = indiceActualIngresar;
        contra_temp[indiceAcutalC] = '4';
        contra_asteriscos[indiceAcutalC] = '*';
        indiceActualIngresar++;
      }
      break;
    }
    case '5': {
      if(dondeGuardar == 'n'){
        nombre_temp[indiceActualIngresar++] = '5';
      } else if(dondeGuardar == 't'){
        telefono_temp[indiceActualIngresar++] = '5';
      } else {
        int indiceAcutalC = indiceActualIngresar;
        contra_temp[indiceAcutalC] = '5';
        contra_asteriscos[indiceAcutalC] = '*';
        indiceActualIngresar++;
      }
      break;
    }
    case '6': {
      if(dondeGuardar == 'n'){
        nombre_temp[indiceActualIngresar++] = '6';
      } else if(dondeGuardar == 't'){
        telefono_temp[indiceActualIngresar++] = '6';
      } else {
        int indiceAcutalC = indiceActualIngresar;
        contra_temp[indiceAcutalC] = '6';
        contra_asteriscos[indiceAcutalC] = '*';
        indiceActualIngresar++;
      }
      break;
    }
    case '7': {
      if(dondeGuardar == 'n'){
        nombre_temp[indiceActualIngresar++] = '7';
      } else if(dondeGuardar == 't'){
        telefono_temp[indiceActualIngresar++] = '7';
      } else {
        int indiceAcutalC = indiceActualIngresar;
        contra_temp[indiceAcutalC] = '7';
        contra_asteriscos[indiceAcutalC] = '*';
        indiceActualIngresar++;
      }
      break;
    }
    case '8': {
      if(dondeGuardar == 'n'){
        nombre_temp[indiceActualIngresar++] = '8';
      } else if(dondeGuardar == 't'){
        telefono_temp[indiceActualIngresar++] = '8';
      } else {
        int indiceAcutalC = indiceActualIngresar;
        contra_temp[indiceAcutalC] = '8';
        contra_asteriscos[indiceAcutalC] = '*';
        indiceActualIngresar++;
      }
      break;
    }
    case '9': {
      if(dondeGuardar == 'n'){
        nombre_temp[indiceActualIngresar++] = '9';
      } else if(dondeGuardar == 't'){
        telefono_temp[indiceActualIngresar++] = '9';
      } else {
        int indiceAcutalC = indiceActualIngresar;
        contra_temp[indiceAcutalC] = '9';
        contra_asteriscos[indiceAcutalC] = '*';
        indiceActualIngresar++;
      }
      break;
    }
    case '0': {
      if(dondeGuardar == 'n'){
        nombre_temp[indiceActualIngresar++] = caracteresTecladoPantalla[posicionActualCaracter];
      } else if(dondeGuardar == 't'){
        telefono_temp[indiceActualIngresar++] = caracteresTecladoPantalla[posicionActualCaracter];
      } else {
        int indiceAcutalC = indiceActualIngresar;
        contra_temp[indiceAcutalC] = caracteresTecladoPantalla[posicionActualCaracter];
        contra_asteriscos[indiceAcutalC] = '*';
        indiceActualIngresar++;
      }
      break;
    }
    case '*': {
      posicionActualCaracter--;
      if(posicionActualCaracter < 0){
        posicionActualCaracter = 29;
      }
      mostrarCaracter(posicionActualCaracter, ledControl);
//      Serial1.println(posicionActualCaracter);
      break;
    }
    case '#': {
      posicionActualCaracter++;
      if(posicionActualCaracter > 29){
        posicionActualCaracter = 0;
      }
      mostrarCaracter(posicionActualCaracter, ledControl);
//      Serial1.println(posicionActualCaracter);
      break;
    }
  }
}

void loginTeclado(LiquidCrystal pantalla, LedControl ledControl){
  indiceActualIngresar = 0;
  posicionActualCaracter = 0;
  mostrarCaracter(posicionActualCaracter, ledControl); // para que muestre el primer caracter de una vez
  memset(nombre_temp, 0, tamanioNombreTemp);
  memset(contra_temp, 0, tamanioContraTemp);   
  memset(contra_asteriscos, 0, tamanioContraTemp);    
  
  while(true){ // imprimiendo en pantalla
    pantalla.clear();
    pantalla.print("L O G I N");
    pantalla.setCursor(0, 1);
    pantalla.print(" - NOMBRE:");
    pantalla.setCursor(0, 2);
    pantalla.print(nombre_temp);
    
    tecla = leerTecla();
    if (tecla != ' ') {
      Serial1.println(tecla);
      funcionesTecla(tecla, ledControl, 'n');
      delay(75);
    }
    
    if(digitalRead(2) == LOW){ // ACEPTAR
      Serial1.println("ACEPTAR");
      delay(50);
      break;
    }

    if(digitalRead(3) == LOW){ // CANCELAR
      Serial1.println("CANCELAR");
      memset(nombre_temp, 0, tamanioNombreTemp);
      indiceActualIngresar = 0;
      delay(50);
    }
    
    delay(150);
  }

  indiceActualIngresar = 0;
  posicionActualCaracter = 0;
  mostrarCaracter(posicionActualCaracter, ledControl);

  while(true){ // imprimiendo en pantalla
    pantalla.clear();
    pantalla.print("L O G I N");
    pantalla.setCursor(0, 1);
    pantalla.print(" - PASSWORD:");
    pantalla.setCursor(0, 2);
    pantalla.print(contra_asteriscos);
    
    tecla = leerTecla();
    if (tecla != ' ') {
      Serial1.println(tecla);
      funcionesTecla(tecla, ledControl, 'c');
      delay(75);
    }
    
    if(digitalRead(2) == LOW){ // ACEPTAR
      Serial1.println("ACEPTAR");
      delay(50);
      break;
    }

    if(digitalRead(3) == LOW){ // CANCELAR
      Serial1.println("CANCELAR");
      memset(contra_temp, 0, tamanioContraTemp);  
      memset(contra_asteriscos, 0, tamanioContraTemp);
      indiceActualIngresar = 0;
      delay(50);
    }
    
    delay(150);
  }

  if(verificarLogin(nombre_temp, contra_temp)){
    // SUCCESS -> MOSTRAR MENU USUARIO
    Serial1.println("SESION INICIADA");
  }else{
    memset(nombre_temp, 0, tamanioNombreTemp);
    memset(contra_temp, 0, tamanioContraTemp);   
    memset(contra_asteriscos, 0, tamanioContraTemp);
    indiceActualIngresar = 0;
    intentosIniciarSesion++;
    if(intentosIniciarSesion == 2){
      intentosIniciarSesion = 0;
      delay(10000); // bloquear por 10 segundos
      // regresar a secuancia inicial
      Serial1.println("REGRESAR A SECUENCIA INICIAL");
    }
    Serial1.println("USUARIO NO EXISTE");
  }
  
  Serial1.println("END LOGIN");
}

bool validarNombreRegistro(){

  // nombre unico
  if(buscarUsuario(nombre_temp) != 0 ){
    Serial1.println("NOMBRE USUARIO EXISTENTE");
    memset(nombre_temp, 0, tamanioNombreTemp);
    indiceActualIngresar = 0;
    return false;
  }

  // nombre >= 8
  if(indiceActualIngresar < 8){
    Serial1.println("NOMBRE CONTIENE MENOS DE 8 CARACTERES");
    return false;
  }

  return true;
}

bool validarContraRegistro(){

  // contra >= 8
  if(indiceActualIngresar < 8){
    Serial1.println("CONTRASENIA CONTIENE MENOS DE 8 CARACTERES");
    return false;
  }

  // si contiene alguna letra
  bool hayAlgunaLetra = false;
  for(int i = 0; i < 26; i++){
    for(int j = 0; j < sizeof(contra_temp); j++){
      if(caracteresTecladoPantalla[i] == contra_temp[j]){
        hayAlgunaLetra = true;
        break;
      }
    }
    if(hayAlgunaLetra){
      break;
    }    
  }

  if(hayAlgunaLetra == false){
    Serial1.println("CONTRASENIA NO CONTIENE LETRAS");
    return false;
  }

  // si contiene algun caracter especial
  bool hayAlgunCaracer = false;
  for(int i = 27; i < 30; i++){
    for(int j = 0; j < sizeof(contra_temp); j++){
      if(caracteresTecladoPantalla[i] == contra_temp[j]){
        hayAlgunCaracer = true;
        break;
      }
    }
    if(hayAlgunCaracer){
      break;
    }    
  }

  if(hayAlgunCaracer == false){
    Serial1.println("CONTRASENIA NO CONTIENE CARACTERES ESPECIALES");
    return false;
  }

  // si contiene numeros
  bool hayAlgunNumero = false;
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < sizeof(contra_temp); j++){
      if(numerosVal[i] == contra_temp[j]){
        hayAlgunNumero = true;
        break;
      }
    }
    if(hayAlgunNumero){
      break;
    }    
  }

  if(hayAlgunNumero == false){
    Serial1.println("CONTRASENIA NO CONTIENE NUMEROS");
    return false;
  }
  
  return true;
}

void registroTeclado(LiquidCrystal pantalla, LedControl ledControl){

  indiceActualIngresar = 0;
  posicionActualCaracter = 0;
  mostrarCaracter(posicionActualCaracter, ledControl); // para que muestre el primer caracter de una vez
  memset(nombre_temp, 0, tamanioNombreTemp);
  memset(contra_temp, 0, tamanioContraTemp);   
  memset(contra_asteriscos, 0, tamanioContraTemp);    
  memset(telefono_temp, 0,  tamanioTelefonoTemp);  
  struct usuario nuevo_usuario;
  
  while(true){ // imprimiendo en pantalla
    pantalla.clear();
    pantalla.print("R E G I S T R O");
    pantalla.setCursor(0, 1);
    pantalla.print(" - NOMBRE:");
    pantalla.setCursor(0, 2);
    pantalla.print(nombre_temp);
    
    tecla = leerTecla();
    if (tecla != ' ') {
      Serial1.println(tecla);
      funcionesTecla(tecla, ledControl, 'n');
      delay(75);
    }
    
    if(digitalRead(2) == LOW){ // ACEPTAR
      Serial1.println("ACEPTAR");
      delay(50);
      if(validarNombreRegistro()){
        break;
      }   
    }

    if(digitalRead(3) == LOW){ // CANCELAR
      Serial1.println("CANCELAR");
      memset(nombre_temp, 0, tamanioNombreTemp);
      indiceActualIngresar = 0;
      delay(50);
    }
    
    delay(150);
  }

  indiceActualIngresar = 0;
  posicionActualCaracter = 0;
  mostrarCaracter(posicionActualCaracter, ledControl);

  while(true){ // imprimiendo en pantalla
    pantalla.clear();
    pantalla.print("R E G I S T R O");
    pantalla.setCursor(0, 1);
    pantalla.print(" - TELEFONO:");
    pantalla.setCursor(0, 2);
    pantalla.print(telefono_temp);
    
    tecla = leerTecla();
    if (tecla != ' ') {
      Serial1.println(tecla);
      funcionesTecla(tecla, ledControl, 't');
      delay(75);
    }
    
    if(digitalRead(2) == LOW){ // ACEPTAR
      Serial1.println("ACEPTAR");
      delay(50);
      if(indiceActualIngresar == 8){
        break;
      }else{
        Serial1.println("TELEFONO NO CONTIENE 8 NUMEROS");
      }
    }

    if(digitalRead(3) == LOW){ // CANCELAR
      Serial1.println("CANCELAR");
      memset(telefono_temp, 0,  tamanioTelefonoTemp);
      indiceActualIngresar = 0;
      delay(50); 
    }
    delay(150);
  }

  indiceActualIngresar = 0;
  posicionActualCaracter = 0;
  mostrarCaracter(posicionActualCaracter, ledControl);

  while(true){ // imprimiendo en pantalla
    pantalla.clear();
    pantalla.print("R E G I S T R O");
    pantalla.setCursor(0, 1);
    pantalla.print(" - PASSWORD:");
    pantalla.setCursor(0, 2);
    pantalla.print(contra_asteriscos);
    
    tecla = leerTecla();
    if (tecla != ' ') {
      Serial1.println(tecla);
      funcionesTecla(tecla, ledControl, 'c');
      delay(75);
    }
    
    if(digitalRead(2) == LOW){ // ACEPTAR
      Serial1.println("ACEPTAR");
      delay(50);
      if(validarContraRegistro()){
        break;
      }
    }

    if(digitalRead(3) == LOW){ // CANCELAR
      Serial1.println("CANCELAR");
      memset(contra_temp, 0, tamanioContraTemp);  
      memset(contra_asteriscos, 0, tamanioContraTemp);
      indiceActualIngresar = 0;
      delay(50);
    }
    
    delay(150);
  } 

  memcpy(nuevo_usuario.nombre, nombre_temp, 12);
  memcpy(nuevo_usuario.password, contra_temp, 12);
  memcpy(nuevo_usuario.phone, telefono_temp, 8);

  guardarMemoriaUsuario(nuevo_usuario);
  
  Serial1.println("END REGISTRO");
}

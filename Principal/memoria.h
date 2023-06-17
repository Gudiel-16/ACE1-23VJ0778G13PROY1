#include <EEPROM.h>

#define CLAVE1 1
#define CLAVE2 3

// se agrega 1 al tamaño por el caracter nulo al final de los arrays
struct usuario {
    char nombre[13];
    char password[13];
    char phone[9];
};

byte numero_usuarios;

void borrarEEPROM() {
    for (int i = 0 ; i < EEPROM.length() ; i++) {
      EEPROM.write(i, 0);
    }
}

// Encripta dos veces los datos del array
// Desencripta si se invierten las claves
void encriptar(char* info, int tamano_array, byte clave1, byte clave2) {
    for (int i=0; i<tamano_array; i++) {
        info[i] = info[i] ^ clave1;
        info[i] = info[i] ^ clave2;
    }
}

// ------------------------------------------ USUARIOS --------------------------------------------
struct usuario leerMemoriaUsuario(int posicion_memoria) {
    struct usuario buscar;
    EEPROM.get(posicion_memoria, buscar);

    encriptar(buscar.nombre, sizeof(buscar.nombre), CLAVE2, CLAVE1);
    encriptar(buscar.password, sizeof(buscar.password), CLAVE2, CLAVE1);
    encriptar(buscar.phone, sizeof(buscar.phone), CLAVE2, CLAVE1);
    return buscar;
}

int buscarUsuario(char* nombre) {
    struct usuario actual;
    int posicion_memoria = 1;
    EEPROM.get(0, numero_usuarios);
    bool encontrado = false;

    for(int i=0; i<numero_usuarios; i++) {
      actual = leerMemoriaUsuario(posicion_memoria);
      for (int j=0; j<12; j++) {
        if(actual.nombre[j] == nombre[j]) {
          encontrado = true;
        } else {
          encontrado = false;
          break;
        }
      }
      
      if(encontrado){
        break;
      }
      posicion_memoria += sizeof(struct usuario);
    }
    return encontrado? posicion_memoria : 0;
}

void guardarMemoriaUsuario(struct usuario nuevo_usuario) {

//    char nombre_temp[12];
//    char pass_temp[12];
//    char phone_temp[8];
//
//    // llenar el array con 0
//    memset(nombre_temp, 0, 12);
//    memset(pass_temp, 0, 12);
//    memset(phone_temp, 0, 8);
//
//    nombre_temp[0] = 'n';
//    nombre_temp[1] = '2';
//
//    // llenar el primer array con los datos del segundo
//    memcpy(nuevo2.nombre, nombre_temp, 12);
//    memcpy(nuevo2.password, pass_temp, 12);
//    memcpy(nuevo2.phone, phone_temp, 8);
//
//    EEPROM.put(sizeof(struct usuario)+1, nuevo2);

    int encontrado = buscarUsuario(nuevo_usuario.nombre);
    Serial1.println(encontrado);
    if(encontrado == 0) {
      Serial1.println("No se encontro nada");
    } else {
      Serial1.println(encontrado);
      return;
    }

    EEPROM.get(0, numero_usuarios);
    int siguiente_direccion = 1;
    for (int i=0; i<numero_usuarios; i++) {
        siguiente_direccion += sizeof(struct usuario);
    }

    encriptar(nuevo_usuario.nombre, sizeof(nuevo_usuario.nombre), CLAVE1, CLAVE2);
    encriptar(nuevo_usuario.password, sizeof(nuevo_usuario.password), CLAVE1, CLAVE2);
    encriptar(nuevo_usuario.phone, sizeof(nuevo_usuario.phone), CLAVE1, CLAVE2);
    EEPROM.put(siguiente_direccion, nuevo_usuario);

    // guardar en la primera celda de memoria la cantidad de usuarios existentes
    numero_usuarios++;
    EEPROM.put(0, numero_usuarios);
}

void guardarMemoriaLog() {
    
}

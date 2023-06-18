#include <EEPROM.h>

// carnet
// 201404278
// 201602947
// 201900898
// 201904042
// 201908251
#define CLAVE1 1
#define CLAVE2 7

// se agrega 1 al tamaño por el caracter nulo al final de los arrays
struct usuario {
    char nombre[13];
    char password[13];
    char phone[9];
};

struct evento {
    byte identificador[1];
    char descripcion[16];
};

struct compartimiento {
  char posicion[2];
  char pos_memoria[4];
};

byte numero_usuarios;
byte numero_logs;

//posicion inicial para la particion donde se almacenaran los eventos o logs
int particion_logs = (EEPROM.length() * 2 )/10 +1;

//posicion inicial para los compartimientos
int particion_compartimientos = EEPROM.length() - (sizeof(struct compartimiento)*9) -1;

void borrarEEPROM() {
    for (int i = 0 ; i < EEPROM.length() ; i++) {
      EEPROM.write(i, 0);
    }
}

void actualizarPrimerInicio() {
  if (EEPROM.read(0) == 255) {
    EEPROM.write(0, 0); 
  }
  if (EEPROM.read(particion_logs) == 255) {
    EEPROM.write(particion_logs, 0);
    Serial1.println(particion_logs);
  Serial1.println("logs");
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

bool verificarLogin(char* nombre, char* contr) {
    int pos_memoria = buscarUsuario(nombre);
    if(pos_memoria == 0) {
      Serial1.println("El usuario no existe");
      return false;
    }
    struct usuario actual;
    actual = leerMemoriaUsuario(pos_memoria);
    bool validar = false;
    for (int i=0; i<12; i++) {
      if(actual.password[i] == contr[i]) {
        validar = true;
      } else {
        validar = false;
        break;
      }
    }

    if (validar) {
      return true;
    } else {
      return false;
    }
}

void guardarMemoriaUsuario(struct usuario nuevo_usuario) {

//    char nombre_temp[13];
//    char pass_temp[13];
//    char phone_temp[9];
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

    int encontrado = buscarUsuario(nuevo_usuario.nombre);
    if(encontrado == 0) {
      Serial1.println("No se encontro nada");
    } else {
      Serial1.println("Ocupado: Ya existe");
      return;
    }

    EEPROM.get(0, numero_usuarios);
    Serial1.println(numero_usuarios);
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

// ------------------------ EVENTOS/LOGS --------------------------
void guardarMemoriaLog(struct evento evt) {
    encriptar(evt.identificador, 1, CLAVE1, CLAVE2);
    encriptar(evt.descripcion, sizeof(evt.descripcion), CLAVE1, CLAVE2);

    EEPROM.get(particion_logs, numero_logs);
    if (numero_logs > 99) {
      numero_logs = 99 - numero_logs;
    }

    int pos = particion_logs + (numero_logs*sizeof(struct evento)) +1;
    
    EEPROM.put(pos, evt);

    numero_logs++;
    EEPROM.put(particion_logs, numero_logs);
}

struct evento buscarLog(byte identificador) {
    struct evento log_buscar;
    int posicion = particion_logs + ((identificador-1)*sizeof(struct evento)) +1;
    EEPROM.get(posicion, log_buscar);

    encriptar(log_buscar.identificador, 1, CLAVE2, CLAVE1);
    encriptar(log_buscar.descripcion, sizeof(log_buscar.descripcion), CLAVE2, CLAVE1);

    return log_buscar;
}

// ----------------------------- COMPARTIMIENTOS -----------------------------
void guardarCompartimiento(struct compartimiento cmp) {
    int p = atoi(cmp.posicion);
  
    encriptar(cmp.posicion, sizeof(cmp.posicion), CLAVE1, CLAVE2);
    encriptar(cmp.pos_memoria, sizeof(cmp.pos_memoria), CLAVE1, CLAVE2);

    int pos = particion_compartimientos + (p*sizeof(struct compartimiento));
    EEPROM.put(pos, cmp);
}

// posicion siempre debe de un solo digito, 0-8
struct compartimiento buscarCompartimiento(char* posicion) {
    struct compartimiento cmp;
    int pos = particion_compartimientos + (atoi(posicion)*sizeof(struct compartimiento));
    EEPROM.get(pos, cmp);

    encriptar(cmp.posicion, sizeof(cmp.posicion), CLAVE2, CLAVE1);
    encriptar(cmp.pos_memoria, sizeof(cmp.pos_memoria), CLAVE2, CLAVE1);

    int estado = atoi(cmp.pos_memoria);

    if(estado == 0) {
        Serial1.println("Compartimiento vacio");
        struct compartimiento no_existe = {
            "0",
            "-10"
        };
        return no_existe;
    }
    return cmp;
}

// posicion siempre debe de un solo digito, 0-8
void vaciarCompartimiento(char* posicion) {
    int pos = particion_compartimientos + (atoi(posicion)*sizeof(struct compartimiento));

    char ceros[4] = "000";
    struct compartimiento cmp;
    memcpy(cmp.posicion, posicion, sizeof(posicion));
    memcpy(cmp.pos_memoria, ceros, sizeof(ceros));
    guardarCompartimiento(cmp);
}

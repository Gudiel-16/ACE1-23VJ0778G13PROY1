# 1 "C:\\Users\\ggiro\\Desktop\\ACE1-23VJ0778G13PROY1\\Fisico\\Fisico.ino"
# 2 "C:\\Users\\ggiro\\Desktop\\ACE1-23VJ0778G13PROY1\\Fisico\\Fisico.ino" 2
# 3 "C:\\Users\\ggiro\\Desktop\\ACE1-23VJ0778G13PROY1\\Fisico\\Fisico.ino" 2
# 4 "C:\\Users\\ggiro\\Desktop\\ACE1-23VJ0778G13PROY1\\Fisico\\Fisico.ino" 2

void setup()
{
    // Inicializar los pines
    pinMode(pinTrigIz, 0x1);
    pinMode(pinEchoIz, 0x0);
    pinMode(pinTrigDer, 0x1);
    pinMode(pinEchoDer, 0x0);
    pinMode(pin_analogicoIz, 0x0); // definimos como entrada
    pinMode(pin_digitalIz, 0x2); // definimos como entrada
    pinMode(pin_analogicoDer, 0x0); // definimos como entrada
    pinMode(pin_digitalDer, 0x2); // definimos como entrada
    // Iniciar comunicación serie
    Serial.begin(9600);
    // Inicializar el LCD con el número de  columnas y filas del LCD
    lcd.begin(16, 2);
}

void loop()
{

    MedirUltra(pinTrigIz, pinEchoIz, "Izq");
    MedirFoto(pin_analogicoIz, pin_digitalIz, "Izq");
    MedirUltra(pinTrigDer, pinEchoDer, "Der");
    MedirFoto(pin_analogicoDer, pin_digitalDer, "Der");
}

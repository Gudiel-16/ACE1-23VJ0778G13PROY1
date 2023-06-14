
void inicializarPinesBotones(){
  for (int i = 2; i <= 10; i++) {
      pinMode(i, INPUT_PULLUP);
  }
}

void setup() {
  Serial1.begin(9600); // puerto virtual terminal
  Serial3.begin(9600); // puerto arduino secundario
  inicializarPinesBotones();
}

void loop() {
  Serial1.println("SENSORES:");
  Serial1.println(analogRead(A0)); // sensor 1
  Serial1.println(analogRead(A1)); // sensor 2
  Serial1.println(analogRead(A2)); // sensor 3
  Serial1.println(analogRead(A3)); // sensor 4
  Serial1.println(analogRead(A4)); // sensor 5
  Serial1.println(analogRead(A5)); // sensor 6
  Serial1.println(analogRead(A6)); // sensor 7
  Serial1.println(analogRead(A7)); // sensor 8
  Serial1.println(analogRead(A8)); // sensor 9
  delay(2000);
}

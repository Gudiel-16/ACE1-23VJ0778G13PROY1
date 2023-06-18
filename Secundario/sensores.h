int valorSensorLeido;

char solicitudSensorTemperatura[2];
String valorSensorRetornar;

String valorSensorString(char numeroSensor){
  switch(numeroSensor){
    case '1': {
      valorSensorLeido = analogRead(A0); // sensor 1
      break;
    }
    case '2': {
      valorSensorLeido = analogRead(A1); // sensor 2
      break;
    }
    case '3': {
      valorSensorLeido = analogRead(A2); // sensor 3
      break;
    }
    case '4': {
      valorSensorLeido = analogRead(A3); // sensor 4
      break;
    }
    case '5': {
      valorSensorLeido = analogRead(A4); // sensor 5
      break;
    }
    case '6': {
      valorSensorLeido = analogRead(A5); // sensor 6
      break;
    }
    case '7': {
      valorSensorLeido = analogRead(A6); // sensor 7
      break;
    }
    case '8': {
      valorSensorLeido = analogRead(A7); // sensor 8
      break;
    }
    case '9': {
      valorSensorLeido = analogRead(A8); // sensor 9
      break;
    }
  }

  // calculo en grados C
  String myString = "";
  float mv = (valorSensorLeido/1024.0)*5000;
  int temp = (int)(mv / 10);  
  
  if(temp <= 9){
    myString = "0";
  }
  
  myString.concat(temp);
  return myString; 
}

void leerSensoresTemperatura(){

    if (Serial3.available()) {
      Serial3.readBytes(solicitudSensorTemperatura, 2);
      switch (solicitudSensorTemperatura[0]) {
        case 'S': { // sensores temperatura
          valorSensorRetornar = valorSensorString(solicitudSensorTemperatura[1]);
          Serial3.print(valorSensorRetornar);
          Serial1.println(valorSensorRetornar);                
          break;
        }
        case 'B': { // botones
          valorSensorRetornar = ""; 
          for(int i = 2; i <= 10; i++){ // pines botones
            if(digitalRead(i) == LOW){ // presionado
              valorSensorRetornar.concat(1);
            }else{
              valorSensorRetornar.concat(0);
            }
          }
          Serial3.print(valorSensorRetornar);
          Serial1.println(valorSensorRetornar); 
          break;
        }
      }
    }

  
//  valSendor3 = analogRead(A2); // sensor 3
//  float mv3 = (valSendor3/1024.0)*5000;
//  int temp3 = (int)(mv3 / 10);
//  myString = "S3";
//  myString.concat(temp3);
//  Serial3.println(myString);
  
//  valSendor4 = analogRead(A3); // sensor 4
//  float mv4 = (valSendor4/1024.0)*5000;
//  int temp4 = (int)(mv4 / 10);
//  
//  valSendor5 = analogRead(A4); // sensor 5
//  float mv5 = (valSendor5/1024.0)*5000;
//  int temp5 = (int)(mv5 / 10);
//  
//  valSendor6 = analogRead(A5); // sensor 6
//  float mv6 = (valSendor6/1024.0)*5000;
//  int temp6 = (int)(mv6 / 10);
//  
//  valSendor7 = analogRead(A6); // sensor 7
//  float mv7 = (valSendor7/1024.0)*5000;
//  int temp7 = (int)(mv7 / 10);
//  
//  valSendor8 = analogRead(A7); // sensor 8
//  float mv8 = (valSendor8/1024.0)*5000;
//  int temp8 = (int)(mv8 / 10);
//  
//  valSendor9 = analogRead(A8); // sensor 9
//  float mv9 = (valSendor9/1024.0)*5000;
//  int temp9 = (int)(mv9 / 10);

  
//  Serial1.println(myString.length());
}

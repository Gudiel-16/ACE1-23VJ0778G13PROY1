int matrizCompartimentos[8][8] = {{0, 0, 1, 0, 0, 1, 0, 0}, 
                                  {0, 0, 1, 0, 0, 1, 0, 0}, 
                                  {1, 1, 1, 1, 1, 1, 1, 1}, 
                                  {0, 0, 1, 0, 0, 1, 0, 0},
                                  {0, 0, 1, 0, 0, 1, 0, 0}, 
                                  {1, 1, 1, 1, 1, 1, 1, 1}, 
                                  {0, 0, 1, 0, 0, 1, 0, 0}, 
                                  {0, 0, 1, 0, 0, 1, 0, 0}};

void mostrarMatrizCompartimentos(LedControl ledControl)
{
    // Con driver
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            ledControl.setLed(0, i, j, matrizCompartimentos[i][j] == 1 ? true : false);
}

void pintarCompartimento(int valor, int numCompartimento){
  switch(numCompartimento){
    case 1: {
      matrizCompartimentos[0][0] = valor;
      matrizCompartimentos[0][1] = valor;
      matrizCompartimentos[1][0] = valor;
      matrizCompartimentos[1][1] = valor;
      break;
    }
    case 2: {
      matrizCompartimentos[0][3] = valor;
      matrizCompartimentos[0][4] = valor;
      matrizCompartimentos[1][3] = valor;
      matrizCompartimentos[1][4] = valor;
      break;
    }
    case 3: {
      matrizCompartimentos[0][6] = valor;
      matrizCompartimentos[0][7] = valor;
      matrizCompartimentos[1][6] = valor;
      matrizCompartimentos[1][7] = valor;
      break;
    }
    case 4: {
      matrizCompartimentos[3][0] = valor;
      matrizCompartimentos[3][1] = valor;
      matrizCompartimentos[4][0] = valor;
      matrizCompartimentos[4][1] = valor;
      break;
    }
    case 5: {
      matrizCompartimentos[3][3] = valor;
      matrizCompartimentos[3][4] = valor;
      matrizCompartimentos[4][3] = valor;
      matrizCompartimentos[4][4] = valor;
      break;
    }
    case 6: {
      matrizCompartimentos[3][6] = valor;
      matrizCompartimentos[3][7] = valor;
      matrizCompartimentos[4][6] = valor;
      matrizCompartimentos[4][7] = valor;
      break;
    }
    case 7: {
      matrizCompartimentos[6][0] = valor;
      matrizCompartimentos[6][1] = valor;
      matrizCompartimentos[7][0] = valor;
      matrizCompartimentos[7][1] = valor;
      break;
    }
    case 8: {
      matrizCompartimentos[6][3] = valor;
      matrizCompartimentos[6][4] = valor;
      matrizCompartimentos[7][3] = valor;
      matrizCompartimentos[7][4] = valor;
      break;
    }
    case 9: {
      matrizCompartimentos[6][6] = valor;
      matrizCompartimentos[6][7] = valor;
      matrizCompartimentos[7][6] = valor;
      matrizCompartimentos[7][7] = valor;
      break;
    }
  }

}

void updateMatrizCompartimento(char matriz[9]){
  for (int i = 0; i < 9; i++){
    if(matriz[i] == '1'){ // compartimento en uso
     pintarCompartimento(1,i+1);      
    }else{
      pintarCompartimento(0,i+1);
    }
  }
}

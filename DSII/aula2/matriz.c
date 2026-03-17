#include <stdio.h>

#define NUMVERT 5

void inicializar(int matriz[NUMVERT][NUMVERT]) {
  for (int i = 0; i < NUMVERT; i++)
    for (int j = 0; j < NUMVERT; j++)
      matriz[i][j] = 0;
}

void inserirArco(int matriz[NUMVERT][NUMVERT], int origem, int dest) {
  matriz[origem][dest] = 1;
}

void imprimeGrafoList(int matriz[NUMVERT][NUMVERT]) {
  for (int i = 0; i < NUMVERT; i++) {
    printf("[%d]->\n\t", i + 1);
    for (int j = 0; j < NUMVERT; j++) {
      // if (matriz[i][j])
      printf("  %d->%d", j + 1, matriz[i][j]);
    }
    printf(" -> *\n");
  }
}

void nosIsolados(int matriz[NUMVERT][NUMVERT]) {
  int nos[NUMVERT];
  for (int i = 0; i < NUMVERT; i++)
    nos[i] = 1;

  for (int i = 0; i < NUMVERT; i++)
    for (int j = 0; j < NUMVERT; j++)
      if (matriz[i][j]) {
        nos[i] = 0;
        nos[j] = 0;
      }
  for (int i = 0; i < NUMVERT; i++)
    if (nos[i])
      printf("No isolado = %d\n", i + 1);
}

void nosAlcancaveis(int matriz[NUMVERT][NUMVERT]) {
  int nos[NUMVERT];
  for (int i = 0; i < NUMVERT; i++)
    nos[i] = 0;

  for (int i = 0; i < NUMVERT; i++)
    for (int j = 0; j < NUMVERT; j++)
      if (matriz[i][j]) {
        nos[j] = 1;
      }
  for (int i = 0; i < NUMVERT; i++)
    if (nos[i])
      printf("No alcancavel = %d\n", i + 1);
    else
      printf("No %d nao eh alcancavel\n", i + 1);
}

void completo(int matriz[NUMVERT][NUMVERT]) {
  int ehCompleto = 1;
  for (int i = 0; i < NUMVERT; i++) {
    for (int j = 0; j < NUMVERT; j++) {
      if ((i == j && matriz[i][j]) ||
          (i != j && !matriz[i][j] && !matriz[j][i])) {
        ehCompleto = 0;
        break;
      }
    }
    if (!ehCompleto)
      break;
  }
  if (ehCompleto)
    printf("O grafo eh completo\n");
  else
    printf("O grafo NAO eh completo\n");
}

void possuiRalosFontes(int matriz[NUMVERT][NUMVERT]) {
  int ralos[NUMVERT], fontes[NUMVERT];
  for(int i=0; i<NUMVERT;i++)
    ralos[i] = fontes[i] = 0;

  for (int i = 0; i < NUMVERT; i++)
    for (int j = 0; j < NUMVERT; j++) {
        if(matriz[i][j])
          fontes[i] = 1;
        if(matriz[j][i])
          ralos[i] = 1;
    }

  for(int i=0; i<NUMVERT;i++){
    if (ralos[i] && !fontes[i]){
      printf("O Grafo POSSUI fontes!\n");
      break;
    }
  }
  for(int i=0; i<NUMVERT;i++){
    if (!ralos[i] && fontes[i]){
      printf("O Grafo POSSUI ralos!\n");
      break;
    }
  }
}

void densidade(int matriz[NUMVERT][NUMVERT]){
  double E = 0, V = NUMVERT;

  for(int i=0; i<NUMVERT; i++){
    for(int j=0; j<NUMVERT; j++){
      if(matriz[i][j])
        E++;
    }
  }

  printf("A densidade eh igual a %.2f!",E/(V*(V-1)));

}

int main() {
  int matriz[NUMVERT][NUMVERT];

  inicializar(matriz);

  inserirArco(matriz, 0, 1);
  //inserirArco(matriz, 0, 2);
  inserirArco(matriz, 0, 3);
  inserirArco(matriz, 0, 4);

  inserirArco(matriz, 1, 0);
  //inserirArco(matriz, 1, 2);
  inserirArco(matriz, 1, 3);
  inserirArco(matriz, 1, 4);

  inserirArco(matriz, 2, 1);
  inserirArco(matriz, 2, 0);
  inserirArco(matriz, 2, 3);
  inserirArco(matriz, 2, 4);

  /*
  inserirArco(matriz, 3, 1);
  inserirArco(matriz, 3, 2);
  inserirArco(matriz, 3, 0);
  inserirArco(matriz, 3, 4);
  */

  inserirArco(matriz, 4, 1);
  //inserirArco(matriz, 4, 2);
  inserirArco(matriz, 4, 3);
  inserirArco(matriz, 4, 0);

  /*
  inserirArco(matriz, 1, 0);
  inserirArco(matriz, 1, 3);
  inserirArco(matriz, 2, 1);
  inserirArco(matriz, 4, 1);
  inserirArco(matriz, 4, 3);

  inserirArco(matriz, 4, 3);
  inserirArco(matriz, 3, 4);
  */

  imprimeGrafoList(matriz);

  // nosIsolados(matriz);

  nosAlcancaveis(matriz);

  completo(matriz);

  possuiRalosFontes(matriz);

  densidade(matriz);

  return 0;
}

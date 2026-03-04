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
    if(nos[i])
        printf("No isolado = %d\n", i+1);
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
    if(nos[i])
        printf("No alcancavel = %d\n", i+1);
}

int main() {
  int matriz[NUMVERT][NUMVERT];

  inicializar(matriz);

  inserirArco(matriz, 0, 1);
  inserirArco(matriz, 1, 0);
  /*
  inserirArco(matriz, 1, 3);
  inserirArco(matriz, 2, 1);
  inserirArco(matriz, 4, 1);
  inserirArco(matriz, 4, 3);
  */

  inserirArco(matriz, 4, 3);
  inserirArco(matriz, 3, 4);

  imprimeGrafoList(matriz);

  //nosIsolados(matriz);

  nosAlcancaveis(matriz);

  return 0;
}

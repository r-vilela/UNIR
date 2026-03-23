#include <stdio.h>

#define NUMVERT 3

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


void noMaiorGrauSaidaEntrada(int matriz[NUMVERT][NUMVERT]){
  int entrada[NUMVERT], saida[NUMVERT];
  int maiorNoSaida=0, maiorNoEntrada=0;

  for(int i=0; i<NUMVERT; i++){
    entrada[i] = 0;
    saida[i] = 0;
  }

  for(int i=0; i < NUMVERT; i++){
    for(int j=0; j < NUMVERT; j++){
      if(matriz[i][j]) {
        entrada[j]++;
        saida[i]++;
      }
    }
  }

  for(int i=0; i<NUMVERT; i++){
    if( saida[i]>saida[maiorNoSaida] )
      maiorNoSaida = i;
    if( entrada[i]>entrada[maiorNoEntrada] )
      maiorNoEntrada = i;
  }

  printf("O no %d tem o maior grau %d de entrada\n", maiorNoEntrada, entrada[maiorNoEntrada]);
  printf("O no %d tem o maior grau %d de saida\n", maiorNoSaida, saida[maiorNoSaida]);

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

void transposto(int matriz1[NUMVERT][NUMVERT],int matriz2[NUMVERT][NUMVERT]){
  int transposto = 1;

  for(int i=0; i<NUMVERT; i++){
    for(int j=0; j<NUMVERT; j++){
      if(matriz1[i][j] != matriz2[j][i]){
        transposto = 0;
        break;
      }
    }
    if(!transposto)
      break;
  }

  if(transposto)
    printf("Os grafos sao TRANSPOSTOS");
  else
    printf("Os grafos sao NAO TRANSPOSTOS");
}

int main() {
  int matriz1[NUMVERT][NUMVERT];

  inicializar(matriz1);

  int matriz2[NUMVERT][NUMVERT];

  inicializar(matriz2);

  inserirArco(matriz1, 0, 2);
  inserirArco(matriz1, 0, 1);
  inserirArco(matriz1, 0, 0);

  inserirArco(matriz1, 1, 2);
  inserirArco(matriz1, 2, 1);

  //inserirArco(matriz2, 2, 1);
  //inserirArco(matriz2, 1, 1);

  inserirArco(matriz2, 2, 0);
  inserirArco(matriz2, 1, 0);

  imprimeGrafoList(matriz1);
  //imprimeGrafoList(matriz2);
  
  //nosIsolados(matriz1);

  //nosAlcancaveis(matriz1);

  //completo(matriz1);

  //possuiRalosFontes(matriz1);


  //densidade(matriz1);

  //transposto(matriz1, matriz2);
  //

  noMaiorGrauSaidaEntrada(matriz1);

  return 0;
}

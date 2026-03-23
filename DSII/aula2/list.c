#include <stdio.h>
#include <stdlib.h>

#define NUMVERT 3

typedef struct vertice {
  int id;
  struct vertice *prox;
} Vertice;

void inicializar(Vertice **listaVertice) {
  for (int i = 0; i < NUMVERT; i++)
    listaVertice[i] = NULL;
}

Vertice *criarVertice(int idt) {
  Vertice *novo = (Vertice *)malloc(sizeof(Vertice));

  novo->id = idt;
  novo->prox = NULL;

  return novo;
}

void insere(Vertice **listaVertice, int origem, int dest) {
  Vertice *novo = criarVertice(dest);
  if (listaVertice[origem] == NULL) {
    listaVertice[origem] = novo;
  } else {
    Vertice *aux = listaVertice[origem];

    while (aux->prox != NULL)
      aux = aux->prox;

    aux->prox = novo;
  }
}

void imprime(Vertice *listaVertice[]) {
  for (int i = 0; i < NUMVERT; i++) {
    if (listaVertice != NULL) {
      Vertice *aux = listaVertice[i];
      printf("[%d]\n\t", i + 1);

      while (aux != NULL) {
        printf("%d->", aux->id + 1);
        aux = aux->prox;
      }

      printf("*\n");
    } else {
      printf("[%d]->*\n", i + 1);
    }
  }
}

void destroe(Vertice *listaVertice[]) {
  for (int i = 0; i < NUMVERT; i++) {
    Vertice *aux = listaVertice[i];
    Vertice *old;
    if (aux != NULL)
      while (aux->prox != NULL) {
        old = aux;
        aux = aux->prox;
        free(old);
      }
    listaVertice[i] = NULL;
  }
}

void nosIsolados(Vertice *listaVertice[]) {
  int nos[NUMVERT];
  for (int i = 0; i < NUMVERT; i++)
    nos[i] = 1;

  for (int i = 0; i < NUMVERT; i++) {
    Vertice *aux = listaVertice[i];

    while (aux != NULL) {
      nos[aux->id] = 0;
      aux = aux->prox;
    }
  }

  for (int i = 0; i < NUMVERT; i++) {
    if (nos[i] && (listaVertice[i] == NULL)) {
      printf("No %d eh isolado\n", i + 1);
      continue;
    }
  }
}

void nosAlcancaveis(Vertice *listaVertice[]) {
  int nos[NUMVERT];
  for (int i = 0; i < NUMVERT; i++)
    nos[i] = 0;

  for (int i = 0; i < NUMVERT; i++) {
    Vertice *aux = listaVertice[i];

    while (aux != NULL) {
      nos[aux->id] = 1;
      aux = aux->prox;
    }
  }

  for (int i = 0; i < NUMVERT; i++) {
    if (nos[i])
      printf("No %d eh alcancavel\n", i + 1);
    else
      printf("No %d nao eh alcancavel\n", i + 1);
  }
}

void noMaiorMenorGrau(Vertice *listaVertice[]) {
  int nosEntrada[NUMVERT];
  int nosSaida[NUMVERT];
  int maiorSaida = 0, maiorEntrada = 0;

  for (int i = 0; i < NUMVERT; i++) {
    nosEntrada[i] = 0;
    nosSaida[i] = 0;
  }

  for (int i = 0; i < NUMVERT; i++) {
    Vertice *aux = listaVertice[i];

    while (aux != NULL) {
      nosEntrada[aux->id]++;
      nosSaida[i]++;
      aux = aux->prox;
    }
  }

  for (int i = 1; i < NUMVERT; i++) {
    if (nosEntrada[i] > nosEntrada[maiorEntrada])
      maiorEntrada = i;
    if (nosSaida[i] > nosSaida[maiorSaida])
      maiorSaida = i;
  }
  printf("O no com maior numero de saidas foi %d com %d saidas\n",
         maiorSaida + 1, nosSaida[maiorSaida]);
  printf("O no com maior numero de entradas foi %d com %d entradas\n",
         maiorEntrada + 1, nosEntrada[maiorEntrada]);
}

void grafoCompleto(Vertice *listaVertice[]) {
  int completo = 1;
  for (int i = 0; i < NUMVERT; i++) {
    if(listaVertice[i] == NULL){
      completo = 0;
      break;
    }

    for( Vertice *aux = listaVertice[i]; aux != NULL && completo; aux = aux->prox) {
      if (i == aux->id) {
        completo = 0;
        break;
      }
      for (Vertice *idAux = listaVertice[aux->id]; idAux != NULL;
      idAux = idAux->prox) {
        if (idAux->id == i) {
          completo = 1;
          break;
        } else
          completo = 0;
      }
    }
    if (!completo)
      break;
  }

  if(completo)
    printf("Grafo eh COMPLETO!\n");
  else
    printf("Grafo NAO eh COMPLETO!\n");
}

void possuiRalosFontes(Vertice *listaVertice[]) {
  int entradas[NUMVERT];
  int saidas[NUMVERT];

  for(int i=0;i<NUMVERT;i++)
    entradas[i] = saidas[i] = 0;

  for (int i = 0; i < NUMVERT; i++) {
    for( Vertice *aux = listaVertice[i]; aux != NULL; aux = aux->prox) {
      saidas[i]++;
      entradas[aux->id]++;
    }
  }

  for(int i=0;i<NUMVERT;i++)
    if(entradas[i]==0 && saidas[i]>0){
      printf("O grafo possui ralos\n");
      break;
    }

  for(int i=0;i<NUMVERT;i++)
    if(entradas[i]>0 && saidas[i]==0){
      printf("O grafo possui fontes\n");
      break;
    }
}

void densidade(Vertice *listaVertice[], int direcionado){
  double totalAresta = 0;
  int maxAresta = NUMVERT*NUMVERT;
  for (int i = 0; i < NUMVERT; i++)
    for( Vertice *aux = listaVertice[i]; aux != NULL; aux = aux->prox)
      totalAresta++;

  double densidade;
  int maxCalc = maxAresta*(maxAresta-1);


  if(direcionado)
    densidade = totalAresta/maxCalc;
  else
    densidade = (2*totalAresta)/maxCalc;

  printf("A densidade do grafo eh igual a %.3f\n", densidade);
}

void transposto(Vertice *listaVertice1[], Vertice *listaVertice2[]){
  int transposto = 1;
  for (int i = 0; i < NUMVERT; i++){
    for( Vertice *aux1 = listaVertice1[i]; aux1 != NULL; aux1 = aux1->prox){
      Vertice *aux2;
      for( aux2 = listaVertice2[aux1->id]; aux2->prox != NULL && aux2->id != i; aux2 = aux2->prox);
      if(aux2->id != i){
        transposto = 0;
        break;
      }
    }
    if(!transposto)
      break;
  }
  if (transposto)
    printf("Grafo eh transposto!\n");
  else
    printf("Grafo NAO eh transposto!\n");
}

int main() {
  Vertice *grafo[NUMVERT];

  inicializar(grafo);


  insere(grafo, 0, 2);
  insere(grafo, 0, 1);
  //insere(grafo, 0, 0);
  insere(grafo, 1, 2);
  //insere(grafo, 1, 1);
  insere(grafo, 1, 0);
  //insere(grafo, 2, 2);
  insere(grafo, 2, 1);
  insere(grafo, 2, 0);
  /*
  insere(grafo, 0, 1);
  insere(grafo, 0, 2);
  insere(grafo, 0, 3);
  // insere(grafo, 1, 0);
  insere(grafo, 3, 4);
  insere(grafo, 4, 3);
  */

  Vertice *grafo2[NUMVERT];

  inicializar(grafo2);

  insere(grafo2, 2, 0);
  insere(grafo2, 1, 0);
  insere(grafo2, 2, 1);
  insere(grafo2, 0, 1);
  insere(grafo2, 1, 2);
  insere(grafo2, 0, 2);

  transposto(grafo, grafo2);

  imprime(grafo);

  nosIsolados(grafo);
  printf("\n");
  nosAlcancaveis(grafo);
  printf("\n");
  noMaiorGrau(grafo);
  printf("\n");

  possuiRalosFontes(grafo);

  densidade(grafo, 0);

  destroe(grafo);

  return 0;
}

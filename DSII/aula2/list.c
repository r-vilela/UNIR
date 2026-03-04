#include <stdio.h>
#include <stdlib.h>

#define NUMVERT 5

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

void insere(Vertice *listaVertice[], int origem, int dest) {
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
    if (nos[i]) {
      printf("No %d eh alcancavel\n", i + 1);
      continue;
    }
  }
}

void noMaiorGrau(Vertice *listaVertice[]) {
  int nosEntrada[NUMVERT];
  int nosSaida[NUMVERT];
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

  int maiorSaida = 0, maiorEntrada = 0;

  for (int i = 1; i < NUMVERT; i++) {
    if (nosEntrada[i] > nosEntrada[maiorEntrada])
      maiorEntrada = i;
    if (nosSaida[i] > nosSaida[maiorSaida])
      maiorSaida = i;
  }
  printf("O no com maior numero de saidas foi %d com %d saidas\n", maiorSaida+1,
         nosSaida[maiorSaida]);
  printf("O no com maior numero de entradas foi %d com %d entradas\n", maiorEntrada+1,
          nosEntrada[maiorEntrada]);
}

int main() {
  Vertice *grafo[NUMVERT];

  inicializar(grafo);

  insere(grafo, 0, 1);
  insere(grafo, 0, 2);
  insere(grafo, 0, 3);
  // insere(grafo, 1, 0);
  insere(grafo, 3, 4);
  insere(grafo, 4, 3);

  imprime(grafo);

  nosIsolados(grafo);
  printf("\n");
  nosAlcancaveis(grafo);
  printf("\n");
  noMaiorGrau(grafo);

  destroe(grafo);

  return 0;
}

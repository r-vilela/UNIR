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
      printf("No %d eh isolado\n", i+1);
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
      printf("No %d eh alcancavel\n", i+1);
      continue;
    }
  }
}

int main() {
  Vertice *grafo[NUMVERT];

  inicializar(grafo);

  insere(grafo, 0, 1);
  //insere(grafo, 1, 0);
  insere(grafo, 3, 4);
  insere(grafo, 4, 3);

  imprime(grafo);

  nosIsolados(grafo);
  nosAlcancaveis(grafo);

  destroe(grafo);

  return 0;
}

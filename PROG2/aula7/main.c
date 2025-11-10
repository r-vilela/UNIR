#define TF 100000
#define MAX 999

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Algoritmos de busca
//
// EXAUSTIVA (vetor Desordenado)
// Sequencial (vetor Odenado)
// Binaria (vetor ordenado)
// Binaria Recursica (vetor ordenado)
//
// Algoritmos de Ordenacao
//
// por selecao (Selection Sort)
// por bolha (Bubble Sort)
// por insercao (Insert Sort)
// por arvore quase completa(HeapSort)
// rapida (Quick Sort)

void create(int *L) {
  for (int i = 0; i < TF; i++)
    L[i] = rand() % MAX;
}

void exibir(int *L) {
  for (int i = 0; i < TF; i++)
    printf("\t%d\n", L[i]);
}

int seqSearch(int *L, int n) {
  int i;
  for (i = 0; i < TF && L[i] > n; i++)
    ;

  return i;
}

void selectionSort(int *L) {
  int min, posMin, j;

  for (int i = 0; i < TF; i++) {
    min = L[i];
    posMin = i;
    for (j = 0; j < i; j++) {
      if (min > L[j]) {
        min = L[j];
        posMin = j;
      }
      L[posMin] = L[i];
      L[i] = min;
    }
  }
}

void bubbleSort(int *L) {
  for (int i = 0; i < TF; i++)
    for (int j = 0; j <= (TF - i); j++)
      if (L[j] < L[j + 1]) {
        L[j + 1] = L[j] + L[j + 1];
        L[j] = L[j + 1] - L[j];
        L[j + 1] = L[j + 1] - L[j];
      }
}

void insertSort(int *L) {
  int i = 0, pos, aux;

  if (L[i] < L[i + 1]) {
    L[i + 1] = L[i] + L[i + 1];
    L[i] = L[i + 1] - L[i];
    L[i + 1] = L[i + 1] - L[i];
  }

  for (i = 2; i < TF; i++) {
    aux = L[i];

    pos = seqSearch(L, aux);

    for (int j = i; j > pos; j--)
      L[j] = L[j - 1];
    L[pos] = aux;
  }
}

void quickSort(int *L) {
  for (int i = 0; i < TF; i++) {
  }
}

int main() {
    time_t start, end;
    double elapsed;
  int L[TF];
  create(L);
  printf("Criada\n");
  // exibir(L);
  time(&start);
  selectionSort(L);
  // bubbleSort(L);
  // insertSort(L);
  // selectionSort(L);
  time(&end);
  elapsed = difftime(end, start);
  exibir(L);
  printf("Ordenada em %.10f segundos\n", elapsed);
  return 0;
}

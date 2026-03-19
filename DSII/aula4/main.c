
/* Considerando uma matriz de adjacencia
 *
 * 1. Desenvolver o algoritmo de Warshall para calculo da matriz de alcancabilidade
 * 2. Desenvolver o algoritmo do desteccao de caminho Euleriano
 */

#include <stdio.h>
#define NUMVERT 5

void inicializar(int matriz[NUMVERT][NUMVERT]){
    for(int i=0; i<NUMVERT; i++)
        for(int j=0; j<NUMVERT; j++)
            matriz[i][j] = 0;
}

void insere(int matriz[NUMVERT][NUMVERT], int org, int dest){
    matriz[org][dest]++;
}

void imprime(int matriz[NUMVERT][NUMVERT]){
    for(int i=0; i<NUMVERT; i++){
        printf("\n%d -> \t", i);
        for(int j=0; j<NUMVERT; j++)
                printf(" %d ", matriz[i][j]);
    }
}

void copiar(int matriz1[NUMVERT][NUMVERT], int matriz2[NUMVERT][NUMVERT]){
    for(int i=0; i<NUMVERT; i++){
        for(int j=0; j<NUMVERT; j++)
            matriz2[i][j] = matriz1[i][j];
    }
}

void warlshall(int matriz[NUMVERT][NUMVERT]){

    printf("\n\nAlgoritmo de Warshall\n");

    int M[NUMVERT][NUMVERT];

    copiar(matriz, M);

    for(int k=-1; k<(NUMVERT-1); k++){
        printf("teste\n");
        for(int i=0; i<NUMVERT; i++)
            for(int j=0; j<NUMVERT; j++)
                M[i][j] = M[i][j] || (M[i][k+1] && M[k+1][j]);
    }

    imprime(M);
}

int main(){
    printf("AULA 4 - Estrutura de Dados 2\n");

    int matriz[NUMVERT][NUMVERT];

    inicializar(matriz);

    insere(matriz, 0, 1);
    insere(matriz, 1, 2);
    insere(matriz, 2, 3);
    insere(matriz, 2, 0);
    insere(matriz, 4, 3);
    insere(matriz, 4, 0);

    imprime(matriz);

    warlshall(matriz);
}

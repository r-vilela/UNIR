
/* Considerando uma matriz de adjacencia
 *
 * 1. Desenvolver o algoritmo de Warshall para calculo da matriz de alcancabilidade
 * 2. Desenvolver o algoritmo do desteccao de caminho Euleriano
 */

#include <stdio.h>
#define NUMVERT 4

void inicializar(int matriz[NUMVERT][NUMVERT]){
    for(int i=0; i<NUMVERT; i++)
        for(int j=0; j<NUMVERT; j++)
            matriz[i][j] = 0;
}

void insere(int matriz[NUMVERT][NUMVERT], int org, int dest){
    matriz[org][dest]++;
}

void insereNaoDirecionao(int matriz[NUMVERT][NUMVERT], int org, int dest){
    matriz[org][dest]++;
    matriz[dest][org]++;
}

void imprime(int matriz[NUMVERT][NUMVERT]){
    for(int i=0; i<NUMVERT; i++){
        printf("\n%d -> \t", i);
        for(int j=0; j<NUMVERT; j++)
                printf(" %d ", matriz[i][j]);
    }
    printf("\n");
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

void caminhoEuliriano(int matriz[NUMVERT][NUMVERT]){
    int impar=0;

    for(int i=0; i<NUMVERT; i++){
        int total=0;
        for(int j=0; j<NUMVERT; j++)
            if(matriz[i][j])
                total += matriz[i][j];
        if(total%2)
            impar++;
    }

    if(impar>2)
        printf("Nao ha caminho Euliriano neste grafo\n");
    else
        printf("Ha caminho Euliriano neste grafo\n");
}

int main(){
    printf("AULA 4 - Estrutura de Dados 2\n");

    int matriz[NUMVERT][NUMVERT];

    inicializar(matriz);

    insereNaoDirecionao(matriz, 0, 1);
    insereNaoDirecionao(matriz, 0, 3);
    insereNaoDirecionao(matriz, 1, 0);
    insereNaoDirecionao(matriz, 1, 2);
    insereNaoDirecionao(matriz, 1, 3);
    insereNaoDirecionao(matriz, 2, 1);
    insereNaoDirecionao(matriz, 2, 3);

    imprime(matriz);

    //warlshall(matriz);

    caminhoEuliriano(matriz);
}

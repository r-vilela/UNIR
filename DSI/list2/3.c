#include <stdio.h>
/*
 * Crie um programa que contenha uma matriz de float contendo 3 linhas e 3 colunas. Imprima o  endereço de cada posição dessa matriz.
 */

int main(){

    float matriz[3][3];
    int i,j;
    float *pnt;

    pnt = matriz[0];

    for(i=0;i<3;i++){
        printf("| ");
        for(j=0;j<3;j++){
            printf("%p - %p \t",&matriz[i][j], pnt++);

        }
        printf("|\n");
    }



    return 0;
}

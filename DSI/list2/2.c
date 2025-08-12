#include <stdio.h>
/*
 * Crie um programa que contenha um array de float contendo 10 elementos. Imprima o endereço de  cada posição desse array.
 */

int main(){
    float array[10];
    float *end;
    int i;

    end = array;

    printf("Aqui estao dos enderecos de um array com 10 float!\n");

    for(i=0;i<10;i++){
        printf("\t%d - endereco: %p\n", i+1, end++);
        printf("\t%d - endereco: %p\n", i+1, array[i]);//pq da esse valor
    }

    return 0;
}

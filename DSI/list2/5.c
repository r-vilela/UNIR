#include <stdio.h>
#include <stdlib.h>
/*
 * Crie um programa que:
 * - Aloque dinamicamente um array de 5 números inteiros;
 * - Peça para o usuário digitar os 5 números no espaço alocado;
 * - Mostre na tela os 5 números;
 * - Libere a memória alocada.
 */
int main(){
    int *array, i;

    array = (int *) malloc(5*sizeof(int));

    printf("Array de 5 posicoes usando alocacao dinamica\n\n");

    for(i=0;i<5;i++){
        printf("Escreva o numero da posicao %d: ", i+1);
        scanf("%d", &array[i]);
    }

    for(i=0;i<5;i++){
        printf("%d - %d\n", i+1, array[i]);
    }

    free(array);

}

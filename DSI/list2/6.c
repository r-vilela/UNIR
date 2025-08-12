#include <stdio.h>
#include <stdlib.h>
/*
 * Faça um programa que leia uma quantidade qualquer de números armazenando-os
 * na memória e  pare a leitura quando o usuário entrar com um número negativo.
 * Em seguida, imprima o vetor lido.  Use a função REALLOC.
 */

int main(){
    int *array,i=0, j;

    array = (int *) malloc(0);

    printf("Alocacao dinamica de inteiros!\n para parar o programa digite -1\n\n");

    do{
        array = realloc(array, (i+1)*sizeof(int));
        printf("Elemento %d: ", i+1);
        scanf("%d", &array[i]);
        i++;
    }while(array[i-1]>0);

    printf("Programa parado!\n\nAqui estao os numeros digitados: \n");

    for(j=0;j<i-1;j++){
        printf("%d - %d\n", j+1, array[j]);
    }

    free(array);

    return 0;
}

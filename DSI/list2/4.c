#include <stdio.h>
/*
 * Escreva um programa que imprima um vetor de inteiros na ordem inversa endereçando os  elementos com um ponteiro.
 */

int main(){
    int vetor[10];
    int *pnt, i;

    pnt = vetor+9;

    for(i=0;i<10;i++){
        printf("%d - %p\t",i+1, &vetor[i]);
        printf("%d - %p\n",10-i, pnt--);
    }

    return 0;
}

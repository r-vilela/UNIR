#include <stdio.h>
/*
 * Escreva um programa que contenha duas variáveis inteiras. Compare seus endereços e exiba o  maior endereço.
 */

int main(){
    int a,b;

    printf("Lhe direi qual variavel tem o maior endereco!\n");

    printf("Escreva um numero inteiro: ");
    scanf("%d", &a);

    printf("O endereco de %d eh %p\n", a, &a);

    printf("Escreva outro numero inteiro: ");
    scanf("%d", &b);

    printf("O endereco de %d eh %p\n", b, &b);

    if(&a>&b){
        printf("O numero %d tem o maior endereco %p", a, &a);
    }else{
        printf("O numero %d tem o maior endereco %p", b, &b);
    }

    return 0;
}

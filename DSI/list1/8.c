#include <stdio.h>

int main(){
    int vetor[10], i, total;

    printf("Escreva um vetor de numeros inteiros que eu somarei apenas os numeros pares!\n\n\n");

    for(i=0;i<sizeof(vetor)/4;i++){
        printf("Escreva o valor %d: ", i+1);
        scanf("%d", &vetor[i]);
    }

    for(i=0;i<sizeof(vetor)/4;i++){
        if(!(vetor[i]%2)){
            total+=vetor[i];
        }
    }

    printf("A soma dos valores pares do vetor eh %d\n", total);

    return 0;
}

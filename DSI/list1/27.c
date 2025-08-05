#include <stdio.h>
#define SZ 10

int main(){
    int vetor[SZ], i=0, total=0;

    printf("Somarei os numeros impares de um vetor!\n\n");

    printf("Digite os valores do vetor: \n");
    for( ;i<SZ;i++){
        printf("%d - ", i+1);
        scanf("%d", &vetor[i]);
    }

    i=0;

    while(i<SZ){
        if(vetor[i++]%2){
            total+=vetor[i];
        }
    }

    printf("A soma dos valores impares do vetor eh %d\n", total);

    return 0;
}

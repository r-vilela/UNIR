#include <stdio.h>

int main(){

    int i, num;

    printf("Amo numeros pares!1\n\n");

    printf("Dgite um numero q eu falarei todos os pares ate esse numero: ");
    scanf("%d", &num);

    printf("\nAqui estao todos os pares ate o numero %d:\n", num);
    for(i=2;i<=num;i+=2){
        printf("%d ", i);
    }

    return 0;
}

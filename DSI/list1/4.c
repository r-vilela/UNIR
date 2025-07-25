#include <stdio.h>

int main(){

    int num, i = 1, total=1;

    printf("Eu sei calcular a fatorial de qualquer numero!!!\n\n\n");

    printf("Duvida?? Entao, digite um numero inteiro: ");
    scanf("%d", &num);

    while(i <= num){
        total = total*i++;
    }

    printf("O fatorial de %d eh %d!\nBuum TOMA!", num, total);

    return 0;
}

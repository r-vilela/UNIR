#include <stdio.h>

// Nao recursiva
long fatorial(long num){
    long fato=1, i;

    for(i=num;i>1;i--){
        fato = fato*i;
    }
}

long fatorialRecurs(long num){
    if(num == 1){
        return 1;
    }

    return num * fatorialRecurs(num-1);
}

int main(){
    // uma funcao recursiva, dentro do seu codigo, chama a si propria.
    // considere o de 1 nao inteiro positivo n, escrito n!

    long n = 5;

    printf("\nfatoraial de %ld eh %ld nao usando recursividade", n, fatorial(n));

    printf("\n\nfatoraial de %ld eh %ld usando recursividade", n, fatorialRecurs(n));

}

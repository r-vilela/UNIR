#include <stdio.h>

void ordena(int *, int *, int *);
void troca(int **, int **);

int main(){

    int x1, x2, x3;

    printf("Escreva 3 numeros que eu ordenarei-os\n");

    printf("\n\nNumero 1: ");
    scanf("%d", &x1);

    printf("Numero 2: ");
    scanf("%d", &x2);

    printf("Numero 3: ");
    scanf("%d", &x3);

    ordena(&x1, &x2, &x3);

    printf("Aqui esta os numeros ordenados: %d, %d e %d\n", x1, x2, x3);

    return 0;
}

void ordena(int *x1, int *x2, int *x3){
    if(*x1 > *x2){
        troca(&x1, &x2);
    }
    if(*x2 > *x3){
        troca(&x2, &x3);
    }
    if(*x1 > *x2){
        troca(&x1, &x2);
    }
}

void troca(int **a, int **b){
    **a += **b;
    **b = **a-**b;
    **a = **a-**b;
}

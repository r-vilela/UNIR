#include <stdio.h>

void reajuste20(float *, float *);

int main(){
    // outro exemplo usando referencia
    float val_preco, val_reaj;

    do{
        printf("\nInsira o preco atual: \n");
        scanf("%f", &val_preco);
        reajuste20(&val_preco, &val_reaj);
        printf("\nO preco novo eh: %2.f\n", val_preco);
        printf("O aumento foi de %2.f\n", val_reaj);
    }while(val_preco != 0.0);
    return 0;
}

void reajuste20(float *preco, float *reaj){
    *reaj = *preco * 0.2;
    *preco *= 1.2;
}

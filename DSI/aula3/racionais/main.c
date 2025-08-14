#include <stdio.h>
#include "Racional.h"
#include <stdlib.h>

int main(){
    int op, den, num;
    Racional R1, R2, r;

    do{
        printf("Operacoes com numeros Racional\n");
        printf("\n");
        Exibir(R1);
        Exibir(R2);
        printf("\n");
        printf("---------------------------------\n");
        printf("1-Define racional 1\n");
        printf("2-Define racional 2\n");
        printf("3-Soma de 2 Racional\n");
        printf("4-Multiplique 2 racioais\n");
        printf("5-Verificar igualdade\n");
        printf("0-P/ sair\n");

        printf("Digite a opcao: ");
        scanf("%d", &op);
        system("clear");

        switch (op) {
            case 1:
                printf("Numerador: ");
                scanf("%d", &num);

                printf("Denominador: ");
                scanf("%d", &den);

                R1 = Define(num, den);
                break;
            case 2:
                printf("Numerador: ");
                scanf("%d", &num);

                printf("Denominador: ");
                scanf("%d", &den);

                R2 = Define(num, den);
                break;
            case 3:
                r=Soma(R1,R2);
                printf("O resultado da soma eh ");
                Exibir(r);

                break;
            case 4:
                r=Multiplica(R1,R2);
                printf("O resultado da multiplicacao eh ");
                Exibir(r);

                break;
            case 5:
                if(TestaIgualdade(R1, R2)){
                    printf("Sao iguais!\n");
                }else{
                    printf("Nao sao iguais!\n");
                }
                break;
        }
    }while(op!=0);

    return 0;
}

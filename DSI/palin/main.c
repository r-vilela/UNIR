#include <stdio.h>
#include <stdlib.h>
#include "palin.h"

int main(){
    Pilha *P;
    int opc;
    criar(P);
    tipo_elem te;


    do{
        printf("1-Adicionar na pilha\n");
        printf("2-Pop na pilha\n");
        printf("3-Remover da pilha\n");
        printf("4-Exibir na pilha\n");

        printf("Entre com a opcao: ");
        scanf("%d", &opc);

        system("clear");

        switch (opc) {
            case 1:
                printf("Digite o valor para ser inserido: ");
                scanf("%c", &te);

                push(P, te);
            case 2:
                printf("%c\n", pop(P));
                break;
            case 0:
                printf("Fechando Sistema!\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    }while(opc!=0);

    return 0;
}

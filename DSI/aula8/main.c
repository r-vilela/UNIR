#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(){
    Fila F;
    int opc;
    tipo_elem v;

    definir(&F);

    do{
        printf("------------------------------\n");
        printf("1-Vazia\n");
        printf("2-Inserir\n");
        printf("3-Remover\n");
        printf("4-Esvaziar\n");
        printf("5-Tamanho\n");
        printf("6-Exibir\n");
        printf("0-Sair\n");

        printf("Entre com a opcao: ");
        scanf("%d", &opc);
        system("clear");

        switch (opc) {
            case 1:
                if(vazia(&F))
                    printf("Fila vazia!\n");
                else
                    printf("Fila nao vazia!\n");
                break;
            case 2:
                printf("Entre com o valor: ");
                scanf("%d", &v);

                if(inserir(&F, v))
                    printf("Inserido com sucesso!\n");
                else
                    printf("Erro ao inserir!\n");
                break;
            case 3:
                if(remover(&F))
                    printf("Removido com susesso!\n");
                else
                    printf("Erro ao remover!\n");
                break;
            case 4:
                esvaziar(&F);
                printf("Esvaziado\n");
                break;
            case 5:
                printf("Fila com tamanho %d\n", tamanho(&F));
                break;
            case 6:
                exibir(&F);
                break;
            case 0:
                printf("Saindo\n");
                break;
            default:
                printf("Opcao invalida!\n");


        }

    }while(opc!=0);


    return 0;
}

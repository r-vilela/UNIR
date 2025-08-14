#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(){
    int opc;
    lista list;
    tipoElem V;
    int key;

    create(&list);

    do{

        printf("\n\n--------------------------\n");
        printf("1-Inserir final\n");
        printf("2-Inserir inicio\n");
        printf("3-Inserir ordenado\n");
        printf("4-Exibir lista\n");
        printf("5-Destruir lista\n");
        printf("6-Esta vazio\n");
        printf("7-Esta cheia\n");
        printf("8-Remover inicio\n");
        printf("0-Sair\n");

        printf("\nDigite a opcao: ");
        scanf("%d", &opc);

        system("clear");

        switch (opc) {
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &V.key);
                if(insertEnd(&list, V)){
                    printf("Inserido com sucesso!\n");
                }else{
                    printf("Nao foi possivel inserir!\n");
                }
                break;
            case 2:
                printf("Digite o valor: ");
                scanf("%d", &V.key);
                if(insertStart(&list, V)){
                    printf("Inserido com sucesso!\n");
                }else{
                    printf("Nao foi possivel inserir!\n");
                }
                break;
            case 3:
                printf("Digite o valor: ");
                scanf("%d", &V.key);
                if(insertSort(&list, V)){
                    printf("Inserido com sucesso!\n");
                }else{
                    printf("Nao foi possivel inserir!\n");
                }
                break;
            case 4:
                show(&list);
                break;
            case 5:
                destroy(&list);
                break;
            case 6:
                if(isEmpty(&list)){
                    printf("A lista esta vazia!\n");
                }else{
                    printf("A lista nao esta vazia!\n");
                }
                break;
            case 7:
                if(isFull(&list)){
                    printf("A lista esta cheia!\n");
                }else{
                    printf("A lista nao esta cheia!\n");
                }
                break;
            case 8:
                if(insertSort(&list, V)){
                    printf("Removido com sucesso!\n");
                }else{
                    printf("Nao foi possivel remover!\n");
                }
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }

    }while(opc!=0);

    destroy(&list);

    return 0;
}

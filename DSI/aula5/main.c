
#include <stdio.h>
#include <stdlib.h>
#include "encadeada.h"

int main(){
    int opc;
    list list;
    tipoElem V;
    int key;

    create(&list);

    do{

        printf("\n\n--------------------------\n");
        printf("1-Inserir final\n");
        printf("2-Inserir inicio\n");
        printf("3-Inserir ordenado\n");
        printf("4-Exibir list\n");
        printf("5-Destruir list\n");
        printf("6-Esta vazio\n");
        printf("7-Esta cheia\n");
        printf("8-Remover inicio\n");
        printf("9-Remover final\n");
        printf("10-Remover chave\n");
        printf("11-Pesquisa\n");
        printf("12-Pesquisa Binaria(So com list ordenados)\n");
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
                    printf("A list esta vazia!\n");
                }else{
                    printf("A list nao esta vazia!\n");
                }
                break;
            case 7:
                if(isFull(&list)){
                    printf("A list esta cheia!\n");
                }else{
                    printf("A list nao esta cheia!\n");
                }
                break;
            case 8:
                if (removeStart(&list)){
                    printf("Removido com sucesso!\n");
                }else{
                    printf("Nao foi possivel remover!\n");
                }
                break;
            case 9:
                if (removeEnd(&list)){
                    printf("Removido com sucesso!\n");
                }else{
                    printf("Nao foi possivel remover!\n");
                }
                break;
            case 10:
                printf("Digite o valor a ser eliminado: ");
                scanf("%d", &V.key);
                if(removeKey(&list, V.key)){
                    printf("Removido com sucesso!\n");
                }else{
                    printf("Nao foi possivel remover!\n");
                }
                break;
            case 11:
                printf("Digite o valor: ");
                scanf("%d", &V.key);
                if(search(&list, V.key)){
                    printf("Valor encontrado na list!\n");
                }else{
                    printf("Valor nao encontrado na list!\n");
                }
                break;
            /*case 12:
                    printf("Digite o valor: ");
                    scanf("%d", &V.key);
                    if(binarySearch(&list, V.key)){
                        printf("Valor encontrado na list!\n");
                    }else{
                        printf("Valor nao encontrado na list!\n");
                    }
                    break;
                break;*/
            default:
                printf("Opcao invalida!\n");
                break;
        }

    }while(opc!=0);

    //destroy(&list);


    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
    list L1, L2, L3;
    create(&L1);
    create(&L2);
    create(&L3);
    int opc, sel1, sel2, sel3;
    elem v;

    list lst[] = {L1, L2, L3};

    do{
        printf("-----------------------------\n");
        for(int i=0;i<3;i++){
            printf("\nLista %d = ", i+1);
            for(int j=0;j<lst[i].tam;j++){
                printf("%d ", lst[i].A[j]);
            }
        }
        printf("\n1-Add\n");
        printf("2-Sorted?\n");
        printf("3-Copy\n");
        printf("4-Copy Unique\n");
        printf("5-Search\n");
        printf("6-Invert\n");
        printf("0-Exit\n");

        printf("Entre a opcao: ");
        scanf("%d", &opc);
        system("clear");

        switch (opc) {
            case 1:
                printf("Seleciona a lista: (1-3)");
                scanf("%d", &sel1);
                if(sel1>0&&sel1<4){
                    printf("Digite o valor: ");
                    scanf("%d", &v.chave);
                    insert(&(lst[sel1-1]),v);
                }else
                    printf("Lista invalida!\n");
                break;
            case 2:
                printf("Seleciona a lista: (1-3)");
                scanf("%d", &sel1);
                if(sel1>0&&sel1<4){
                    if(isSorted(&(lst[sel1-1]))==1)
                        printf("Lista ordenada Crescentemente!\n");
                    else if(isSorted(&(lst[sel1-1]))==-1)
                        printf("Lista ordenada Descrescentemente!\n");
                    else
                        printf("Lisa nao ordenada!\n");
                }else
                    printf("Lista invalida!\n");
                break;
            case 3:
                printf("Seleciona a lista que vai copiar: (1-3)");
                scanf("%d", &sel1);
                if(sel1>0&&sel1<4){
                    printf("\nSeleciona a lista que vai colar: (1-3)");
                    scanf("%d", &sel2);
                    if(sel2>0&&sel2<4&&sel1!=sel2){
                        copy(&(lst[sel1-1]),&(lst[sel2-1]));
                    }else
                        printf("Lista invalida!\n");


                }else
                    printf("Lista invalida!\n");
                break;
            case 4:
                printf("Seleciona a lista que vai copiar: (1-3)");
                scanf("%d", &sel1);
                if(sel1>0&&sel1<4){
                    printf("\nSeleciona a lista que vai colar: (1-3)");
                    scanf("%d", &sel2);
                    if(sel2>0&&sel2<4&&sel1!=sel2){
                        copyUnq(&(lst[sel1-1]),&(lst[sel2-1]));
                    }else
                        printf("Lista invalida!\n");


                }else
                    printf("Lista invalida!\n");
                break;
            case 5:
                printf("Seleciona a lista: (1-3)");
                scanf("%d", &sel1);
                if(sel1>0&&sel1<4){
                    printf("Digite o valor a ser procurado: ");
                    scanf("%d", &v.chave);
                    int pos = search(&(lst[sel1-1]),v);
                    if(pos>=0)
                        printf("Valor encontrado na posicao %d!\n", pos);
                    else
                        printf("Valor nao encontrado!\n");
                }else
                    printf("Lista invalida!\n");
                break;
            case 6:
                printf("Seleciona a lista que vai ser invertida: (1-3)");
                scanf("%d", &sel1);
                if(sel1>0&&sel1<4){
                    printf("\nSeleciona a lista invertida: (1-3)");
                    scanf("%d", &sel2);
                    if(sel2>0&&sel2<4&&sel1!=sel2){
                        invert(&(lst[sel1-1]),&(lst[sel2-1]));
                    }else
                        printf("Lista invalida!\n");
                }else
                    printf("Lista invalida!\n");
                break;

            case 0:
                printf("Saindo do programa!\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    }while(opc!=0);


    return 0;
}

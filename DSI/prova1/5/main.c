#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
    list L1, L2, L3;
    cnt_list C;
    create(&L1);
    create(&L2);
    create(&L3);
    int opc, sel1, sel2, sel3;
    elem v;

    C.tam=0;

    list lst[] = {L1, L2, L3};

    do{
        printf("-----------------------------\n");
        for(int i=0;i<3;i++){
            printf("\nLista %d = ", i+1);
            for(int j=0;j<lst[i].tam;j++){
                printf("%d ", lst[i].A[j]);
            }
        }
        printf("\nLista Contagem ");
        for(int j=0;j<C.tam;j++){
            printf("%d - %d |", C.C[j].chave, C.C[j].count);
        }
        printf("\n1-Add\n");
        printf("2-Sorted?\n");
        printf("3-Copy\n");
        printf("4-Copy Unique\n");
        printf("5-Search\n");
        printf("6-Invert\n");
        printf("7-Join\n");
        printf("8-Count Elem\n");
        printf("9-Max and Min times\n");
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
            case 7:
                printf("Seleciona a primeira lista: (1-3)");
                scanf("%d", &sel1);
                if(sel1>0&&sel1<4){
                    printf("\nSeleciona a segunda lista para juntar: (1-3)");
                    scanf("%d", &sel2);
                    if(sel2>0&&sel2<4&&sel1!=sel2){
                        printf("\nSeleciona a lista armazenar a lista juntada: (1-3)");
                        scanf("%d", &sel3);
                        if(sel3>0&&sel3<4&&sel2!=sel3&&sel1!=sel3){
                            join(&(lst[sel1-1]),&(lst[sel2-1]),&(lst[sel3-1]));
                        }else
                            printf("Lista invalida!\n");
                    }else
                        printf("Lista invalida!\n");
                }else
                    printf("Lista invalida!\n");
                break;
            case 8:
                printf("Seleciona a lista para criar a contagem: (1-3)");
                scanf("%d", &sel1);
                if(sel1>0&&sel1<4){
                    createCount(&(lst[sel1-1]),&C);
                }else
                    printf("Lista invalida!\n");
                break;
            case 9:
                printf("Seleciona a lista para achar o max e min: (1-3)");
                scanf("%d", &sel1);
                if(sel1>0&&sel1<4){
                    createCount(&(lst[sel1-1]),&C);
                    extreme(&C);
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

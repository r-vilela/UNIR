#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TF 4

typedef struct node{
    char descricao[15];
    struct node *prox;
}Node;

typedef struct{
    char tipo[10];
    Node *head;
}List;

void create(List *L){
    char tipos[4][15] = {"Alimentacao", "Higiene", "Limpeza", "Vestuario"};
    for(int i=0;i<TF;i++){
        strcpy(L[i].tipo,tipos[i]);
        L[i].head=NULL;
    }
}

void destroy(List *L){
    Node *n, *p;
    for(int i=0;i<TF;i++)
        for(n=L[i].head;n!=NULL;p=n,n=n->prox,free(p));
}

void show(List *L, int p){
    Node *n;
    printf("Tipo: %s\n\t", L[p].tipo);
    for(n=L[p].head;n!=NULL;n=n->prox)
        printf("%s ", n->descricao);
    printf("\n");

}

int insert(List *L, int p, char *desc){
    if(p>3)
        return 0;
    Node *n;
    strcpy(n->descricao, desc);
    n->prox = L[p].head;
    L[p].head = n;
}

int main(){
    int opc, tipo;
    char desc[15];
    List L[TF];

    create(L);

    do{
        printf("------------------------\n");
        printf("\tSISTEMA DE MERCADO\n");
        printf("\n1-Inserir Produto\n");
        printf("2-Consultar todos os produtos cadastrados de um tipo\n");
        printf("3-Contar quantos produtos tem cadastrado em cada tipo\n");
        printf("0-Sair\n");

        printf("Insira a opcao: ");
        scanf("%d", &opc);

        system("clear");

        switch (opc) {
            case 1:
                printf("Digite o tipo que deseja inserir: ");
                scanf("%d", &tipo);

                printf("Digite a descricao: ");
                scanf(" ^[\n]",desc);

                insert(L, tipo, desc);
                break;
            case 2:
                printf("Digite o tipo que deseja consultar: ");
                scanf("%d", &tipo);
                show(L, tipo);
                break;
            case 3:
                printf("Contar\n");
                break;
            case 0:
                printf("Saindo . . .\n");
                break;
            default:
                printf("Opcao Invalida!\n");
        }

    }while(opc!=0);

    destroy(L);

}

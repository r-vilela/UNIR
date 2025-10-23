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

void show(List *L, char p){
    int i;
    for(i=0;i<TF&&L[i].tipo[0]!=p;i++);
    if(i!=TF){
        Node *n;
        printf("Tipo: %s\n\t", L[i].tipo);
        if(L[i].head==NULL)
            printf("Nao ha produtos na lista!\n");
        else
            for(n=L[i].head;n!=NULL;n=n->prox)
                printf("%s ", n->descricao);
        printf("\n");
    }else{
        printf("Tipo nao existe!\n\n");
    }

}

int insert(List *L, char p, char *desc){
    int i;
    for(i=0;i<TF&&L[i].tipo[0]!=p;i++);
    if(i==TF)
        return 0;
    Node *n = (Node *) malloc(sizeof(Node));;
    strcpy(n->descricao, desc);
    n->prox = L[i].head;
    L[i].head = n;
    return 1;
}

int count(List *L, char p){
    int i,c;
    for(i=0;i<TF&&L[i].tipo[0]!=p;i++);
    if(i!=TF){
        Node *n;
        if(L[i].head==NULL)
            printf("Nao ha produtos na lista!\n");
        else{
            for(n=L[i].head,c=0;n!=NULL;n=n->prox, c++);
            printf("o tipo %s tem %d produtos cadastrados!\n", L[i].tipo, c);
        }
        printf("\n");
    }else{
        printf("Tipo nao existe!\n\n");
    }

}

int main(){
    int opc;
    char desc[15], p;
    List L[TF];

    create(L);

    do{
        printf("-----------------------------------------\n");
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
                scanf(" %c", &p);

                printf("Digite a descricao: ");
                scanf(" %[^\n]",desc);

                if(insert(L, p, desc))
                    printf("Inserido com sucesso!\n\n");
                else
                    printf("Erro ao inserir! \nVerifique o tipo selecionado!\n\n");
                break;
            case 2:
                printf("Digite o tipo que deseja consultar: ");
                scanf(" %c", &p);
                show(L, p);
                break;
            case 3:
                printf("Digite o tipo voce deseja contar: ");
                scanf(" %c", &p);
                count(L, p);
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

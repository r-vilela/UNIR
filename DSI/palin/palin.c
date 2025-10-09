#include "palin.h"
#include <stdio.h>
#include <stdlib.h>

void criar(Pilha *P){
    P->topo = NULL;
}

int vazia(Pilha *P){
    if(P->topo==NULL)
        return 1;
    return 0;
}

int cheia(Pilha *P);

int push(Pilha *P, tipo_elem v){
    No *node = (No *) malloc(sizeof(No));
    node->info = v;
    node->prox = P->topo;
    P->topo = node;
    return 1;
}

tipo_elem pop(Pilha *P){
    if(vazia(P))
        return NULL;
    No *node = P->topo;
    P->topo = node->prox;
    return node;
    free(node);
}

void popup(Pilha *P){
    if(vazia(P))
        return NULL;
    No *node = P->topo;
    P->topo = node->prox;
    free(node);
}

tipo_elem top(Pilha *P){
    return P->topo;
}

void esvaziar(Pilha *P){
    if(vazia(P))
        printf("Pilha Vazia!\n");
    No *node;

    for(node = P->topo;node!=NULL;P->topo=P->topo->prox,free(node),node=P->topo);
    printf("Pilha Vazia!\n");

}

void exibir(Pilha *P){
    if(vazia(P))
        printf("Pilha Vazia!\n");
    /*No *node;

    for(node = P->topo;node!=NULL;node=node->prox){
        printf("- %c\n", node->info);
    };*/
    exibirRec(P->topo);

    printf("Fim da pilha!\n");
}

void exibirRec(No *n){
    if(!n==NULL){
        printf("\t- %c\n", n->info);
        exibirRec(n->prox);
    }
}

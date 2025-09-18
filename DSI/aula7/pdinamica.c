#include "pdinamica.h"
#include <stdio.h>
#include <stdlib.h>

void criar(Pilha *P){
    P->topo=NULL;
}

int vazia(Pilha *P){
    return (P->topo==NULL);
}

int cheia(Pilha *P);

int push(Pilha *P, tipo_elem v){
    No *aux = (No *) malloc(sizeof(No));
    if(!aux)
        return 0;

    aux->prox = P->topo;
    aux->info = v;
    P->topo = aux;

    return 1;
}

tipo_elem pop(Pilha *P){
    No *aux = P->topo;

    P->topo = aux->prox;

    tipo_elem ele = aux->info;
    free(aux);

    return ele;
}

void popup(Pilha *P){
    No *aux = P->topo;

    P->topo = aux->prox;

    free(aux);
}

tipo_elem top(Pilha *P){
    return (P->topo->info);
}

void esvaziar(Pilha *P){
    No *n;

    for( ;P->topo!=NULL;n=P->topo, P->topo=n->prox, free(n));
}

void exibir(Pilha *P){
    exibirRec(P->topo);
}

void exibirRec(No *n){
    if(n->prox!=NULL)
        exibirRec(n->prox);
    printf("%c", n->info);
}

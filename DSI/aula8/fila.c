#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

void definir(Fila *F){
    F->inicio = F->fim = NULL;
}

int vazia(Fila *F){
    return (F->inicio == NULL);
}

int inserir(Fila *F, tipo_elem c){
    No *n = (No *) malloc(sizeof(No));
    if(!n)
        return 0;
    n->info = c;
    n->prox = NULL;

    if(vazia(F))
        F->inicio = F->fim = n;
    else
        F->fim->prox = n;
    F->fim = n;

    return 1;
};

int remover(Fila *F){
    No *n;
    if(vazia(F))
        return 0;

    n = F->inicio;

    F->inicio = n->prox;
    free(n);
    n=NULL;

    return 1;
}


int tamanho(Fila *F){
    No *n;
    int i=0;

    for(n=F->inicio;n!=NULL;n=n->prox, i++);

    return i;

}

void esvaziar(Fila *F){
    No *n, *p;

    for(n=F->inicio;n!=NULL;p=p,free(p),n=n->prox);

}

void exibir(Fila *F){
    No *n;
    int i=0;

    for(n=F->inicio;n!=NULL;n=n->prox,i++)
        printf("%d - %d\n", i, n->info);
}


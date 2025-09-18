#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void criar(Lista_d *l){
    l->tam = 0;
    l->head->elem.n=0;
    l->head->prox=NULL;
};

Lista_d* criar2(){
    Lista_d *l = (Lista_d *) malloc(sizeof(sizeof(Lista_d)));

    l->tam = 0;
    l->head->elem.n=0;
    l->head->prox=NULL;

    return l;
};

int destruir(Lista_d *l){
    if(vazia(l))
        return 0;

    return destruir_rec(l>head);
};

int destruir_rec(No* n){
    if(n == NULL){
        return 1;
    }

    destruir_rec(n->prox);
    free(n);
    return 1;

}

int destruir2(Lista_d **l){
    if(vazia(l))
        return 0;



};

int vazia(Lista_d *l){
    return l->tam;
};
void exbir(Lista_d *l);
int tamanho(Lista_d *l);

int inserir_inicio(Lista_d *l,Tipo_elem valor);
int inserir_inicio(Lista_d *l,Tipo_elem valor);
int inserir_ordenado(Lista_d *l,Tipo_elem valor);
int remover_inicio(Lista_d *l);
int remover_final(Lista_d *l);
int remover_rec(Lista_d **l, int valor);
int buscar(Lista_d *l);


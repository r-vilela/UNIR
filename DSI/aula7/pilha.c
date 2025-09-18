#include "pilha.h"
#include <stdio.h>

void criar(Pilha *P){
    P->topo = -1;
}

int vazia(Pilha *P){
    return (P->topo==-1);
}

int cheia(Pilha *P){
    return (P->topo==MAX-1);
}

int push(Pilha *P, tipo_elem v){
    if(cheia(P))
        return 0;
    P->A[++(P->topo)]=v;

    return 1;
}

tipo_elem pop(Pilha *P){
    if(vazia(P))
        return 0;
    return P->A[(P->topo)--];
}

void popup(Pilha *P){
    if(!vazia(P))
        P->topo--;
}

tipo_elem top(Pilha *P){
    if(vazia(P))
        return ' ';
    return P->A[P->topo];
};

int esvaziar(Pilha *P){
    if(vazia(P))
        return 0;
    criar(P);
    return 1;
}

void exibir(Pilha *P){
    for(int i=0;i<=P->topo;i++){
        printf("%c\n", P->A[i]);
    }
}

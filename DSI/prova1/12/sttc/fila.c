#include <stdio.h>

#include "fila.h"

void create(Fila *F){
    F->head=0;
    F->tail=0;
}

int insert(Fila *F, int v){
    if(isFull(F))
        return 0;
    F->v[F->tail] = v;
    F->tail=(F->tail+1)%n;

    return 1;
}

int isFull(Fila *F){
    return (F->head==(F->tail+1)%n);
}

int isEmpty(Fila *F){
    return (F->head==F->tail);
}

int first(Fila *F){
    if(isEmpty(F))
        return -1;

    return (F->v[F->head]);
}

int delete(Fila *F){
    if(isEmpty(F))
        return 0;

    F->head = (F->head+1)%n;
    return 1;
}

void show(Fila *F){
    printf("\n\t");
    for(int i=F->head;i!=F->tail;i=(i+1)%n)
        printf("%d-%d ", i, F->v[i]);
    printf("\n");
}



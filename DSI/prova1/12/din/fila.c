#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

void create(Fila *F){
    F->head = NULL;
    F->tail = NULL;
}

void insert(Fila *F, int v){
    Node *n = malloc(sizeof(Node));
    n->info = v;
    n->next = NULL;

    if(isEmpty(F)){
        F->tail = n;
        F->head = n;
    }else{
        F->tail->next = n;
        F->tail = n;
    }
}

int isEmpty(Fila *F){
    return (F->tail==NULL||F->head==NULL);
}

int first(Fila *F){
    if(isEmpty(F))
        return -1;
    return (F->head->info);
}

int delete(Fila *F){
    if(isEmpty(F))
        return 0;

    Node *n = F->head;
    F->head = F->head->next;
    printf("%d\n", F->tail==NULL);
    free(n);
    return 1;
}

void destroy(Fila *F){
    Node *n, *p;

    for(n=F->head;n!=NULL;p=n,n=n->next,free(p));

    create(F);
}

void show(Fila *F){
    Node *n;

    printf("\t");
    for(n=F->head;n!=NULL;n=n->next)
        printf("%d ", n->info);
    printf("\n");

}

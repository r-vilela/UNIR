#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void create(List *L){
    L->head = NULL;
};

int add(List *L, int key){
    Elem *v = L->head;
    Elem *new = (Elem *) malloc(sizeof(Elem));
    new->key = key;
    L->head = new;
    new->next = v;

};


void show(List *L){
    Elem *v = L->head;

    if(v!=NULL){
        printf("\t");
        for( ;v!=NULL;v = v->next)
            printf("%d ", v->key);
        printf("\n");
    }
};

int cp(List *L1, List *L2){
    Elem *v = L1->head;
    destroy(L2);

    if(v!=NULL){
        for( ;v!=NULL;v = v->next){
            add(L2,v->key);
        }
        return 1;
    }

    printf("List 1 is empty!\n");
    return 0;
};

int cpUnique(List *L1, List *L2);

int invert(List *L1, List *L2);

void destroy(List *L){
    Elem *v = L->head, *p;
    for( ;v!=NULL;p = v, v = v->next, free(p));
}


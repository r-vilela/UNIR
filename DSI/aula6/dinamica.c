#include <stdio.h>
#include <stdlib.h>
#include "dinamica.h"

/*
 * Lista Encadeada Dinamica
 */

int create(list *L){
    L->head = NULL;
    return 1;
};

int isFull(list *L);

int isEmpty(list *L){
    return (!L->head);
};

int insertSort(list *L, tipoElem newElem){
    if(isEmpty(L))
        return (insertStart(L, newElem));

    node *n;
    node *m;
    for(n=(L->head), m=NULL;n->next!=NULL&&(n->next)->info.key<=newElem.key;m=n,n=n->next);

    if(m==NULL)
        return (insertStart(L, newElem));

    node *p = (node *) malloc(sizeof(node));
    if(!p)
        return 0;
    p->info=newElem;
    p->next=n;

    m->next=p;

    return 1;
}

int insertStart(list *L, tipoElem newElem){
    node *n;
    n = (node *) malloc(sizeof(node));
    if(!n)
        return 0;
    n->info = newElem;
    n->next = L->head;
    L->head=n;
    return 1;
};

int insertEnd(list *L, tipoElem newElem){
    if(isEmpty(L))
        return (insertStart(L, newElem));

    node *p = (node *) malloc(sizeof(node));
    if(!p)
        return 0;
    p->info=newElem;
    p->next=NULL;

    node *n;
    for(n=(L->head);n->next!=NULL;n=n->next);

    n->next=p;

    return 1;
};

int removeStart(list *L){
    if(isEmpty(L))
        return 0;

    node *n;
    n=L->head;
    L->head = n->next;

    free(n);

    return 1;

};

int removeEnd(list *L){
    if(isEmpty(L))
        return 0;

    node *n = L->head;
    node *m=NULL;
    /*
    for(n=L->head;n->next!=null;n=n->next, m=n);

    if(!m)
        return (removeStart(L));

    n->next = NULL;
    free(m);
    */

    return (removeEndRec(L, &n, &m));
}

int removeEndRec(list *L, node **n, node **m){
    if(n==NULL)
        return 0;
    if((*n)->next==NULL){
        printf("Hello\n");
        if(m!=NULL){
            (*m)->next=NULL;
        }else{
            L->head = NULL;
        }
        free(*n);
        return 1;
    }
    return (removeEndRec(L, &((*n)->next), &(*n)));
}

int removeKey(list *L, int key){
    if(isEmpty(L))
        return 0;

    node *m;
    node *n;

    for(m=NULL, n=L->head;n!=NULL&&p->info.key!=key;q=p,p=p->next);

    if(n==NULL)
        return 0;

    if(q==NULL)
        return (removeStart(L));

    m->next = n->next;

    free(n);

    return 1;

};

int search(list *L, int key);

int binarySearch(list *L, int key);

void destroy(list *L){
    destroyRec(&(L->head));
};

void destroyRec(node **n){
    if(*n){
        node *aux = (*n)->next;
        free(*n);
        destroyRec(&aux);
    }
}

void show(list *L){
    if(isEmpty(L)){
        printf("Lista vazia!\n");
    }else{
        node *aux;
        int i=1;
        for( aux = L->head;aux!=NULL; aux=aux->next, i++)
            printf("%d - %d\n", i, (aux->info).key);
    }
};
int size(list *L){
    return (sizeRec(L->head));
}

int sizeRec(node *n){
    if(!n)
        return 0;

    return (1+sizeRec(n->next));

};

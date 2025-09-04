
#include <stdio.h>
#include "encadeada.h"

/*
 * Lista Encadeada
 */

int create(list *L){
    L->start=NIL;
    L->avl=0;
    int i;
    for(i=0;i<MAX-1;i++)
        L->A[i].next=i+1;
    L->A[i].next=NIL;

    return 1;
}

int isFull(list *L){
    return (L->avl==NIL);
}

int isEmpty(list *L){
    return (L->start==NIL);
}

int insertSort(list *L, tipoElem newElem){
    int atual, ant=NIL, aux;

    if(isFull(L))
        return 0;

    if(isEmpty(L))
        return insertStart(L, newElem);

    for(atual=L->start;atual!=NIL&&L->A[atual].info.key<newElem.key;ant=atual, atual=L->A[atual].next);

    if(ant==NIL)
        return insertStart(L, newElem);
    printf("%d\n", isEmpty(L));

    aux=L->avl;
    L->avl=L->A[aux].next;

    L->A[aux].info=newElem;
    L->A[aux].next=atual;
    L->A[ant].next=aux;

    return 1;
}

int insertStart(list *L, tipoElem newElem){
    int aux;
    if(isFull(L))
        return 0;

    aux=L->avl;
    L->avl=L->A[aux].next;
    L->A[aux].info=newElem;
    L->A[aux].next=L->start;
    L->start=aux;

    return 1;
}

int insertEnd(list *L, tipoElem newElem){
    int atual, aux;
    if(isFull(L))
        return 0;

    if(isEmpty(L))
        return insertStart(L, newElem);

    for(atual=L->start;L->A[atual].next!=NIL;atual=L->A[atual].next);

    aux = L->avl;
    L->avl=L->A[aux].next;

    L->A[aux].info=newElem;
    L->A[aux].next=NIL;
    L->A[atual].next=aux;

    return 1;
}

int removeStart(list *L){
    int aux;
    if(isEmpty(L))
        return 0;

    aux=L->start;
    L->start = L->A[aux].next;
    L->A[aux].next = L->avl;
    L->avl=aux;
    return 1;
}

int removeEnd(list *L){
    int atual, ant;
    if(isEmpty(L))
        return 0;

    for(atual=L->start;L->A[atual].next!=NIL;ant=atual,atual=L->A[atual].next);

    if(ant==NIL){
        L->start=NIL;
    }else{
        L->A[ant].next=NIL;
    }

    L->A[atual].next=L->avl;
    L->avl=atual;

    return 1;
}

int removeKey(list *L, int key){
    int ant=NIL, atual;
    if(isEmpty(L))
        return 0;

    for(atual=L->start;atual!=NIL&&L->A[atual].info.key!=key;ant=atual,atual=L->A[atual].next);

    if(ant==NIL)
        return removeStart(L);
    if(atual==NIL)
        return 0;

    L->A[ant].next=L->A[atual].next;
    L->A[atual].next = L->avl;
    L->avl=atual;

    return 1;
}

int search(list *L, int key){
    int atual;
    if(isEmpty(L))
        return 0;

    for(atual=L->start;atual!=NIL&&L->A[atual].info.key!=key;atual=L->A[atual].next);

    return (atual!=NIL);
};

int binarySearch(list *L, int key);

int destroy(list *L){
    return create(L);
}

void show(list *L){
    int i;
    if(isEmpty(L))
        printf("The list is empty!\n");
    else{
        for(i=L->start;i!=NIL; i=L->A[i].next){
            printf("%d\n", L->A[i].info.key);
        }
    }
}

int size(list *L){
    int i, tam;

    for(i=L->start, tam=0;i!=NIL;i=L->A[i].next, tam++);

    return tam;


}

#include <stdio.h>
#include "list.h"

/*
 * Lista Estatica Sequencial
 */

int create(lista *L){
    L->nelem=0;

    return 1;

};

int isFull(lista *L){
    return (L->nelem==MAX);

};

int isEmpty(lista *L){
    return (L->nelem==0);
};

int insertSort(lista *L, tipoElem newElem){
    if(isFull(L)){
        return 0;
    }
    if(isEmpty(L)){
        return (insertStart(L,newElem));
    }
    int i;

    for(i=L->nelem;i>0&&L->A[i-1].key>newElem.key;i--){
        L->A[i]=L->A[i-1];
    }

    L->A[i]=newElem;
    L->nelem++;
    return 1;
};

int insertStart(lista *L, tipoElem newElem){
    int i=L->nelem;
    if(isFull(L)){
        return 0;
    }

    for(i=L->nelem;i>0;i--){
        L->A[i] = L->A[i-1];
    }

    L->A[0]=newElem;
    L->nelem++;
    return 1;
};

int insertEnd(lista *L, tipoElem newElem){
    if(isFull(L)){
        return 0;
    }
    L->A[L->nelem++] = newElem;
    return 1;

};

int removeStart(lista *L){
    if(isEmpty(L)){
        return 0;
    }

    L->nelem--;
    for(int i=0;i<L->nelem;i++){
        L->A[i] = L->A[i+1];
    }
    return 1;

};

int removeEnd(lista *L){
    if(isEmpty(L)){
        return 0;
    }
    L->nelem--;
    return 1;

};

int removeKey(lista *L, int key){
    int i;
    if(isEmpty(L)){
        return 0;
    }

    for(i=0;i<L->nelem&&key!=L->A[i].key;i++);

    if(i==L->nelem){
        return 0;// nao achou
    }

    L->nelem--;

    for(int i=0;i<L->nelem;i++){
        L->A[i] = L->A[i+1];
    }

    return 1;
};

int search(lista *L, int key){
    int i;
    if(isEmpty(L)){
        return 0;
    }

    for(i=0;i<L->nelem&&key!=L->A[i].key;i++);

    return (i<L->nelem);

};

int binarySearch(lista *L, int key){
    int start=0, end=L->nelem-1;

    int middle;

    while(end>=start){
        middle=(end+start)/2;
        if(L->A[middle].key==key){
            return 1;
        }
        if(L->A[middle].key>key){
            end=middle-1;
        }else{
            start=middle+1;
        }
    }
    return 0;

}

int destroy(lista *L){
    L->nelem=0;
    return 1;
};

void show(lista *L){
    int i;

    if(isEmpty(L)){
        printf("Lista vazia!\n");
    }else{
        for(i=0;i<L->nelem;i++){
            printf("%d ", L->A[i].key);
        }
    }

};

int size(lista *L){
    return L->nelem;
}



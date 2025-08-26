#include <stdio.h>
#include "static.h"

int create(list *L){
    L->nElem=0;

    return 1;
};

int add(list *L, typeElem elem){
    L->A[L->nElem]=elem;
    L->nElem++;
    return 1;

};

int rmv(list *L, typeElem elem){
    int i,aux;
    aux=L->nElem;
    if(L->nElem){
        for(i=0;i<L->nElem;i++){
            if(L->A[i].key==elem.key){
                L->nElem--;
                for( ;i<L->nElem;i++){
                    L->A[i]=L->A[i+1];
                }
                break;
            }
        };

        if(aux==L->nElem)
            return 0;

        return 1;
    }else{
        return -1;
    }

};

void show(list *L){
    int i;
    printf("|");
    for(i=0;i<L->nElem;i++){
        printf(" %d ",L->A[i]);
    }
    printf("|\n");
};

int isSorted(list *L){
    int i, ord;
    if(L->nElem > 1){
        for(i=0;i<L->nElem-1;i++){
            if(L->A[i].key<=L->A[i+1].key){
                ord=1;
                continue;
            }else{
                ord=0;
                break;
            }
        }

        if(ord)
            return ord;

        for(i=0;i<L->nElem-1;i++){
            if(L->A[i].key>=L->A[i+1].key){
                ord=-1;
                continue;
            }else{
                ord=0;
                break;
            }
        }

        return ord;

    }else{
        return 1;
    }

};

int copy(list *L1, list *L2){
    int i;

    if(L1->nElem){
        for(i=0;i<L1->nElem;i++){
            L2->A[i]=L1->A[i];
        }
        L2->nElem=L1->nElem;
        return 1;
    }
    return 0;

};

int find(list *L, typeElem elem){
    int i;
    for(i=L->nElem;i>0&&elem.key!=L->A[i-1].key;i--);

    return i!=0;
};

int copyUnique(list *L1, list *L2){
    int i;

    if(L1->nElem){
        L2->A[0]=L1->A[0];
        L2->nElem=1;
        for(i=0;i<L1->nElem;i++){
            if(!find(&(*L2),L1->A[i])){
                L2->A[i]=L1->A[i];
                L2->nElem++;
            }
        }
        return 1;
    }
    return 0;
};

int copyInvert(list *L1, list *L2){

};


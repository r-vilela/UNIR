#include "lista.h"
#include <stdio.h>

void create(list *L1){
    L1->tam=0;
}

int isSorted(list *L1){
    int c=1;
    if(L1->tam<=1)
        return 0;

    if(L1->A[0].chave>L1->A[1].chave)
        c=-1;

    for(int i=0;i<((L1->tam)-1);i++){
        if(c==1){
            if(L1->A[i].chave<L1->A[i+1].chave)
                continue;
            else{
                c=0;
                break;
            }
        }else{
            if(L1->A[i].chave>L1->A[i+1].chave)
                continue;
            else{
                c=0;
                break;
            }
        }
    }

    return c;
}

int insert(list *L1, elem v){
    if(L1->tam==TF)
        return 0;

    L1->A[L1->tam] = v;
    L1->tam++;
    return 1;
}

int search(list *L1, elem v){
    int i;
    for(i=0;i<(L1->tam)&&L1->A[i].chave!=v.chave;i++);

    if(L1->A[i].chave==v.chave)
        return i;
    else
        return -1;
}

int size(list *L1){
    return (L1->tam);
}

void copy(list *L1,list *L2){
    for(int i=0;i<(L1->tam);i++){
        L2->A[i] = L1->A[i];
    }

    L2->tam = L1->tam;
}

void copyUnq(list *L1,list *L2){
    int j=0;
    for(int i=0;i<(L1->tam);i++){

        if(search(L2,(L1->A[i]))==-1)
            L2->A[j++] = L1->A[i];
            L2->tam = j;
    }
}

void invert(list *L1,list *L2){
    L2->tam=0;
    for(int i=(L1->tam)-1;i>=0;i--)
        insert(L2,L1->A[i]);
}

void join(list *L1,list *L2,list *L3){
    int s1 = isSorted(L1), s2 = isSorted(L2);
    if(s1 == s2&&S1!=0){
        copy(L1,L3);
        for(int i=0;i<(L2->tam);i++){
            if(c==1){
                for(int j=0;j<
            }else{
            }

        }
    }else
        printf("As listas nao estao com a mesma ordenacao \nou nao estao ordenadas!\n");
}

void countElem(list *L1);

void extreme(list *L1);

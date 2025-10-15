#include "list.h"
#include <stdio.h>

void create(list *l){
    l->ult=0;
};

int empty(list *l){
    return (!(l->ult));
}

int full(list *l){
    return (l->ult==n);
}

int insert(list *l, int a){
    int i;
    if(full(l))
        return -1;

    if(!empty(l)){
        for(i=0;l->v[i]!=a&&i<l->ult;i++);
        if(i!=l->ult)
            return 0;
    }

    l->v[l->ult] = a;
    l->ult++;
    return 1;
}

int delete(list *l, int a){
    int i,j;
    if(empty(l))
        return -1;

    for(i=0;l->v[i]!=a&&i<l->ult;i++);
    if(i==l->ult)
        return 0;
    for(j=i+1;j<l->ult;l->v[i]=l->v[j],i=j,j++);
    l->ult--;
    return 1;

};

int search(list *l, int a){
    int i;
    if(empty(l))
        return -1;

    for(i=0;l->v[i]!=a&&i<l->ult;i++);
    if(i==l->ult)
        return 0;
    return i+1;
}

int searchSent(list *l, int a){
    int i;
    if(empty(l))
        return -1;
    l->v[l->ult+1]=a;

    for(i=0;l->v[i]!=a;i++);
    if(i>l->ult)
        return 0;
    return i+1;
}

void show(list *l){

    printf("\t");
    for(int i=0;i<l->ult;i++)
        printf("%d ", l->v[i]);
}

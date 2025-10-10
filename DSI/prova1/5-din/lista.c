#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void create(List *L){
    L->head = NULL;
};

void add(List *L, int key){
    Elem *v = L->head;
    Elem *new = (Elem *) malloc(sizeof(Elem));
    new->key = key;
    L->head = new;
    new->next = v;

};

void addEnd(List *L, int key){
    Elem *v = L->head;
    Elem *o = v;

    Elem *new = (Elem *) malloc(sizeof(Elem));
    new->key = key;

    if(v==NULL)
        L->head = new;

    else{
        for( ;v!=NULL;o=v,v=v->next);

        o->next = new;
    }

}

void addSort(List *L, int sort, int key){
}

void show(List *L){
    Elem *v = L->head;

    if(v!=NULL){
        printf("\t");
        for( ;v!=NULL;v = v->next)
            printf("%d ", v->key);
        printf("\n");
    }
};

int size(List *L){
    Elem *v = L->head;
    int c=0;

    if(v!=NULL){
        for( ;v!=NULL;v = v->next,c++);
    }
    return c;

}

int cp(List *L1, List *L2){
    Elem *v = L1->head;
    destroy(L2);

    if(v!=NULL){
        for( ;v!=NULL;v = v->next){
            addEnd(L2,v->key);
        }
        return 1;
    }

    printf("List 1 is empty!\n");
    return 0;
};

int isList(List *L1, int key){
    Elem *v = L1->head;

    for( ;v!=NULL;v = v->next)
        if(v->key==key)
            return 1;
    return 0;

}

int isSort(List *L1){
    Elem *v = L1->head;
    Elem *n = v->next;
    int resp=0;

    if(size(L1)<=1)
        return resp;

    if((v->key)>=(n->key)){
        resp=-1;
        for( ;n!=NULL; ){
            if((v->key)>=(n->key)){
                v=v->next;
                n=v->next;
            }else{
                resp=0;
                break;
            }
        }
    }
    if(resp!=0)
        return resp;

    v = L1->head;
    n = v->next;
    if((v->key)<=(n->key)){
        resp=1;
        for( ;n!=NULL; ){
            if((v->key)<=(n->key)){
                v=v->next;
                n=v->next;
            }else{
                resp=0;
                break;
            }
        }
    }

    return resp;

}

int cpUnique(List *L1, List *L2){
    Elem *v = L1->head;
    destroy(L2);

    if(v!=NULL){
        for( ;v!=NULL;v = v->next){
            if(!isList(L2,v->key))
                addEnd(L2,v->key);
        }
        return 1;
    }

    printf("List 1 is empty!\n");
    return 0;
}

int joinSort(List *L1, List *L2, List *L3){
    destroy(L3);

    int sort = isSort(L1);
    Elem *v1=L1->head, *v2=L2->head;

    if(sort!=0)
        if(sort==isSort(L2)){
            if(sort==1){
                while(v1!=NULL && v2!=NULL){
                    if(v1->key>v2->key){
                        addEnd(L3,v2->key);
                        v2=v2->next;
                    }else{
                        addEnd(L3,v1->key);
                        v1=v1->next;
                    }
                }
                if(v1==NULL){
                    while(v2!=NULL){
                        addEnd(L3,v2->key);
                        v2=v2->next;
                    }
                }else{
                    while(v1!=NULL){
                        addEnd(L3,v1->key);
                        v1=v1->next;
                    }
                }
            }else{
                while(v1!=NULL || v2!=NULL){
                    if(v1->key<v2->key){
                        addEnd(L3,v2->key);
                        v2=v2->next;
                    }else{
                        addEnd(L3,v1->key);
                        v1=v1->next;
                    }
                }
                if(v1==NULL){
                    while(v2!=NULL){
                        addEnd(L3,v2->key);
                        v2=v2->next;
                    }
                }else{
                    while(v1!=NULL){
                        addEnd(L3,v1->key);
                        v1=v1->next;
                    }
                }
            }

        }else
            printf("Are not sorted!\n");
    else
        printf("Are not sorted!\n");

}

int invert(List *L1, List *L2){
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
}

void destroy(List *L){
    Elem *v = L->head, *p;
    for( ;v!=NULL;p = v, v = v->next, free(p));
    L->head = NULL;
}


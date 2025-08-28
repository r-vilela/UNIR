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
        return 0;
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
    int i;

    if(L1->nElem){
        L2->nElem=L1->nElem;
        for(i=0;i<L2->nElem;i++){
            L2->A[i]=L1->A[(L2->nElem-1)-i];
        }
        return 1;
    }
    return 0;
};

int cmbSorted(list *L1,list *L2,list *L3){
    int i, j;
    if(isSorted(&(*L1))==1&&isSorted(&(*L2))==1){
        for(i=0;i<L1->nElem; ){
            for(j=0;j<L2->nElem; ){
                if(L1->A[i].key>=L2->A[j].key){
                    L3->A[i+j]=L2->A[j];
                    j++;
                }else{
                    L3->A[i+j]=L1->A[i];
                    i++;
                }
            }
        }
        L3->nElem=L1->nElem+L2->nElem;
    }
};

int countList(list *L1, cntElem *cnt, int *nCnt){
    int i, aux;
    if(L1->nElem){
        cnt[0].elem=L1->A[0];
        cnt[0].count=0;
        *nCnt=1;
        for(i=0,aux=0;i<L1->nElem;i++){
            if(L1->A[i].key!=cnt[aux].elem.key){
                aux=aux+1;
                cnt[aux].elem=L1->A[i];
                cnt[aux].count=1;
                (*nCnt) = (*nCnt)+1;
            }else{
                cnt[aux].count++;
            }
        }
        return 1;
    }
    return 0;
};

int showCount(cntElem *cnt, int nCnt){
    int i;
    printf("\n|");
    for(i=0;i<nCnt;i++){
        printf(" Elem: %d Cnt: %d |", cnt[i].elem.key, cnt[i].count);
    }
    printf("\n");
};

int binarySearch(list *L1, int key){
    int i, end=L1->nElem, mid, str=0;
    if(L1->nElem){
        if(isSorted(&(*L1))==1){
            mid=(end+str)/2;
            for( ;L1->A[mid].key!=key&&str<=end;mid=(end+str)/2){
                if(L1->A[mid].key>key){
                    end=mid-1;
                }else{
                    str=mid+1;
                }
            }
            if(str>end){
                return 10;
            }
            return mid+1;
        }
        return -1;
    }
    return 0;
};

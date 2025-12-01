#include <stdio.h>
#include <stdlib.h>
#define TF 10

void populate(int *v){
    for(int i=0;i<TF;i++)
        v[i] = rand() % 10;
}

void show(int *v){
    for(int i=0;i<TF;i++)
        printf("%d ", v[i]);
    printf("\n");
}

void troca(int *i, int *j){
    int aux= (*i);
    (*i) = (*j);
    (*j) = aux;
}

void qckSort(int *v, int inc, int fim){
    int i=inc, f=fim;
    printf("\n\ninc = %d, fim = %d\n", inc, fim);

    do{
        show(v);
        for( ;v[i]<=v[f];f--);
        if(i<=f){
            troca(&(v[i]), &(v[f]));
            i++;
        }
        show(v);

        for( ;v[i]<=v[f];i++);
        if(i<=f){
            troca(&(v[i]), &(v[f]));
            f--;
        }
        show(v);
    }while(i<f);
    printf("i = %d, f = %d\n", i, f);

    if(i<fim){
        printf(" i=%d maior que o fim=%d\n", i+1, fim);
        qckSort(v, i+1, fim);
    }

    if(inc<f){
        printf("inc=%d maior que o f=%d\n", inc, f-1);
        qckSort(v, inc, f-1);
    }
}

int main()
{
    int v[TF];

    populate(v);

    show(v);

    qckSort(v, 0, (TF-1));

    show(v);


    return 0;
}

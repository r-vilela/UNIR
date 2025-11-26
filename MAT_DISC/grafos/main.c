#include <stdio.h>
#include <stdlib.h>
#define TF 3

void populate(int v[TF][TF]){
    for(int i=0;i<TF;i++){
        for(int j=0;j<TF;j++)
            v[i][j] = rand() % 10;
    }
}

void show(int v[TF][TF]){
    for(int i=0;i<TF;i++){
        printf("[");
        for(int j=0;j<TF;j++)
            printf(" %d", v[i][j]);
        printf(" ]\n");
    }
}

int main(){
    int v[TF][TF];

    populate(v);

    show(v);

    return 0;
}

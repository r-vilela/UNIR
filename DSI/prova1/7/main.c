#include <stdio.h>

void inverter(int *v,int n){
    int p;
    for(int i=0;i<(int)n/2;i++){
        p=v[i];
        v[i]=v[n-i-1];
        v[n-i-1]=p;
    }
}

int main(){
    int n=6,  v[n];

    printf("Digite os valores da lista: \n");
    for(int i=0;i<n;i++){
        printf("\t%d : ", i+1);
        scanf("%d", &v[i]);
    }

    printf("Lista original!\n\t");
    for(int i=0;i<n;i++)
        printf("%d ", v[i]);
    printf("\n");

    inverter(v, n);

    printf("Lista invertida!\n\t");
    for(int i=0;i<n;i++)
        printf("%d ", v[i]);

    return 1;
}

#include <stdio.h>
#define TF 3

int main(){
    int matriz[TF][TF],i,j,prod;

    printf("Escreva uma matriz que eu lhe direi o produto das colunas de cada linha!\n");

    printf("\n\nMatriz:\n");
    for(i=0;i<TF;i++){
        printf("Linha %d:\n", i+1);
        for(j=0;j<TF;j++){
            printf("\tColuna %d: ", j+1);
            scanf("%d", &matriz[i][j]);
        }
    }

    for(i=0;i<TF;i++){
        printf("O produto da linha %d eh ", i+1);

        prod=1;
        for(j=0;j<TF;j++){
            prod=prod*matriz[i][j];
        }
        printf("%d\n", prod);
    }

    return 0;
}

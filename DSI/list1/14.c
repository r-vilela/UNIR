#include <stdio.h>

int main(){
    int matrix[4][4], i, j, aux;

    printf("Escreva uma matrix que direi qual eh o menor valor nela!\n\n");

    printf("Matrix:\n");

    for(i=0;i<4;i++){
        printf("\tLinha %d: \n", i+1);
        for(j=0;j<4;j++){
            printf("\t\tColuna %d: ", j+1);
            scanf("%d", &matrix[i][j]);
        }
    }

    aux = matrix[0][0];

    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(matrix[i][j]<aux){
                aux=matrix[i][j];
            }
        }
    }

    printf("O maior numero da matrix eh %d!\n", aux);

    return 0;
}

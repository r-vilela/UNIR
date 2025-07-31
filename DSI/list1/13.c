#include <stdio.h>

int main(){
    int matrix[4][4], i, j, aux=-1;

    printf("Escreva uma matrix que direi qual eh o maior valor nela!\n\n");

    printf("Matrix:\n");

    for(i=0;i<4;i++){
        printf("\tLinha %d: \n", i+1);
        for(j=0;j<4;j++){
            printf("\t\tColuna %d: ", j+1);
            scanf("%d", &matrix[i][j]);
        }
    }

    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(matrix[i][j]>aux){
                aux=matrix[i][j];
            }
        }
    }

    printf("O maior numero da matrix eh %d!\n", aux);

    return 0;
}

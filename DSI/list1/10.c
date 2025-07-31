#include <stdio.h>

int main(){
    int matrixA[4][4], matrixB[4][4], i, j;

    printf("Digite os valores de 2 matrizes 4x4, que eu farei a soma delas!!\n\n");

    printf("Matrix A: \n");
    for(i=0;i<sizeof(matrixA)/4/4; i++){
        printf("\tInsira os valores da linha %d: \n", i+1);
        for(j=0;j<sizeof(matrixA)/4/4;j++){
            printf("\t\tValor %d: ", j+1);
            scanf("%d", &matrixA[i][j]);
        }
    }

    printf("Matrix B: \n");
    for(i=0;i<sizeof(matrixB)/4/4; i++){
        printf("\tInsira os valores da linha %d: \n", i+1);
        for(j=0;j<sizeof(matrixB)/4/4;j++){
            printf("\t\tValor %d: ", j+1);
            scanf("%d", &matrixB[i][j]);
        }
    }

    printf("A soma das duas matrizes eh:\n");
    for(i=0;i<sizeof(matrixB)/4/4; i++){
        printf("|");
        for(j=0;j<sizeof(matrixB)/4/4;j++){
            if(j==3){
                printf("%d\t", matrixA[i][j]+matrixB[i][j]);
            }
            printf("%d\t", matrixA[i][j]+matrixB[i][j]);
        }
        printf("|\n");
    }

    return 0;
}

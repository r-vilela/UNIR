#include <stdio.h>

int main(){
    int matrix[4][4], i, j;

    printf("Farei o calculo dos numeros na diagonal principal!\n");

    printf("Digite aa matrix: \n");

    printf("Matrix: ");
    for(i=0;i<4;i++){
        printf("Linha %d: \n", i+1);
        for(j=0;j<4;j++){
            printf("\tColuna %d: ", j+1);
            scanf("%d", &matrix[i][j]);
        }
    }

    j=0;

    for(i=0;i<4;i++){
        j+=matrix[i][i];
    }

    printf("A soma dos numeros na diagonal principal da matrix eh %d\n", j);

    return 0;
}

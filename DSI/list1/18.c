#include <stdio.h>

int main(){
    int matrix[5][5],i,j;

    printf("Somarei os numeros da diagonal secundaria de uma matrix!\n");

    printf("Digite os valored da matrix:\n");

    for(i=0;i<5;i++){
        printf("\tLinha %d:\n ", i+1);
        for(j=0;j<5;j++){
            printf("\t\tColuna %d: ", j+1);
            scanf("%d", &matrix[i][j]);
        }
    }

    j=0;

    for(i=0;i<5;i++){
        j+=matrix[i][4-i];
    }

    printf("A soma da diagonal secundaria eh igual a %d\n", j);

    return 0;
}

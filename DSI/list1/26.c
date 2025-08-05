#include <stdio.h>
#define SZ 4

int main(){
    int matriz[SZ][SZ],i,j;

    printf("Digite os valores de uma matriz que eu retornarei apenas as posicoes dos valores pares!\n\n");

    printf("Matriz: \n");
    for(i=0;i<SZ;i++){
        printf("\tLinha %d: \n", i+1);
        for(j=0;j<SZ;j++){
            printf("\t\tColuna %d: ", j+1);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\n-------------------------------\n");
    printf("Os numeros pares sao: \n");
    for(i=0;i<SZ;i++){
        for(j=0;j<SZ;j++){
            if(!(matriz[i][j]%2)){
                printf("\t%d - (%d, %d)\n", matriz[i][j], i+1, j+1);
            }

        }
    }

    return 0;
}

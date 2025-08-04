#include <stdio.h>

int main(){
    int matriz[2][2],i,j;

    printf("Verificador de Matrizes Simetricas\n\n");

    printf("Digite uma matriz que eu direi que se eh simetrica ou nao\n");

    printf("Matriz: \n");

    for(i=0;i<2;i++){
        printf("\tLinha %d: \n", i+1);
        for(j=0;j<2;j++){
            printf("\t\tColuna %d: ", j+1);
            scanf("%d", &matriz[i][j]);
        }
    }

    for(i=0;i<2;i++){
        printf("| ");
        for(j=0;j<2;j++){
            printf("%d  ", matriz[i][j]);
        }
        printf("|\n");
    }

    printf("\n");

    for(i=0;i<2;i++){
        printf("| ");
        for(j=0;j<2;j++){
            printf("%d  ", matriz[j][i]);
        }
        printf("|\n");
    }

    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            if(matriz[i][j]!=matriz[j][i]){
                break;
            }
        }
    }

    if(i==2,j==2){
        printf("Sao Simetricos\n");
    }else{
        printf("Nao sao Simetricos\n");
    }

    return 0;
}

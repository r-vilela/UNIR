#include <stdio.h>
#define SZ 5

int main(){
    int matriz[SZ][SZ], i, j;

    printf("Eu sei que uma matriz eh diagonal ou nao!\n\n");

    printf("Se duvida entao faca um teste ai!\n");
    printf("Entre os valor da matraz: \n");
    for(i=0;i<SZ;i++){
        printf("Linha %d: \n", i+1);
        for(j=0;j<SZ;j++){
            printf("\tColuna %d: ", j+1);
            scanf("%d", &matriz[i][j]);
        }
    }

    for(i=0;i<SZ;i++){
        for(j=0;j<SZ;j++){
            if(i!=j){
                if(matriz[i][j]==0){
                    continue;
                }else{
                    i=SZ+1;
                    break;
                }
            }
        }
    }

    if(i>SZ){
        printf("Nao eh uma matriz diagonal!\n");
    }else{
        printf("Eh uma matriz diagonal!\n");
    }


    return 0;
}
